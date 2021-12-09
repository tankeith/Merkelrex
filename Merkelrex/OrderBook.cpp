//
//  OrderBook.cpp
//  Merkelrex
//
//  Created by Keith Tan on 6/12/21.
//

#include "OrderBook.hpp"
#include "CSVReader.hpp"
#include <map>

/** construct, reading a csv data file */
OrderBook::OrderBook(std::string filename)
{
    orders = CSVReader::readCSV(filename);
}
/** return vector of all known products in the dataset*/
std::vector<std::string> OrderBook::getKnownProducts()
{
    std::vector<std::string> products;
    
    //declare variable of type map, mapping between strings and booleans
    std::map<std::string, bool> prodMap;
    
    // iterate over every order and put it into the map, overwriting
    for (OrderBookEntry& e : orders)
    {
        prodMap[e.product] = true;
    }
    
    // flatten the map into a vector of strings
    for (auto const& e : prodMap) // setting to auto because we don't really care, const cos data doesn't need to be changed
    {
        products.push_back(e.first); // e.first will give us the key, e.last will give us the value
    }
    
    return products;
}
/** return vector of Orders according to the sent filters*/
std::vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type,
                                      std::string product,
                                      std::string timestamp)
{
    std::vector<OrderBookEntry> orders_sub;
    for (OrderBookEntry& e : orders)
    {
        if (e.orderType == type &&
            e.product == product &&
            e.timestamp == timestamp)
        {
            orders_sub.push_back(e);
        }
    }
    return orders_sub;
}

double OrderBook::getHighPrice(std::vector<OrderBookEntry>& orders)
{
    double max = orders[0].price;
    for (OrderBookEntry& e : orders)
    {
        if (e.price > max) max = e.price;
    }
    return max;
}

double OrderBook::getLowPrice(std::vector<OrderBookEntry>& orders)
{
    double min = orders[0].price;
    for (OrderBookEntry& e : orders)
    {
        if (e.price < min) min = e.price;
    }
    return min;
}

std::string OrderBook::getEarliestTime()
{
    return orders[0].timestamp;
}

std::string OrderBook::getNextTime(std::string timestamp)
{
    std::string next_timestamp = "";
    for (OrderBookEntry& e : orders) // iterate over the orders
    {
        if (e.timestamp > timestamp) // if we find an order with timestamp greater (later) than timestamp
        {
            next_timestamp = e.timestamp; // store it and finish looping
            break;
        }
    }
    if (next_timestamp == "") // if we don't find then we send it back to the first order
    {
        next_timestamp = orders[0].timestamp;
    }
    return next_timestamp;
}

void OrderBook::insertOrder(OrderBookEntry& order)
{
    orders.push_back(order); // puts order at the end of vector of orders
    std::sort(orders.begin(), orders.end(), OrderBookEntry::compareByTimestamp); // sorts orders by timestamp in ascending order
}

// matching engine algorithm
std::vector<OrderBookEntry> OrderBook::matchAsksToBids(std::string product, std::string timestamp)
{
    // pull out 2 sets of orderbook items from orders
    // asks = orderbook.asks in this timeframe
    std::vector<OrderBookEntry> asks = getOrders(OrderBookType::ask,
                                                 product,
                                                 timestamp);
    
    // bids = orderbook.bids in this timeframe
    std::vector<OrderBookEntry> bids = getOrders(OrderBookType::bid,
                                                 product,
                                                 timestamp);
    // sales = []
    std::vector<OrderBookEntry> sales;
    // sort asks lowest first
    std::sort(asks.begin(), asks.end(), OrderBookEntry::compareByPriceAsc);
    // sort bids highest first
    std::sort(bids.begin(), bids.end(), OrderBookEntry::compareByPriceDesc);
 
    // for ask in asks
    for (OrderBookEntry& ask : asks)
    {
        // for bid in bids
        for (OrderBookEntry& bid : bids)
        {
            if (bid.price >= ask.price) // a successful match, we have 3 possible scenarios as follows
            {
                // sale = new order()
                // sale.price = ask.price
                OrderBookEntry sale{ask.price, 0, timestamp, product, OrderBookType::asksale};
    
                if (bid.username == "simuser")
                {
                    sale.username = "simuser";
                    sale.orderType = OrderBookType::bidsale;
                }
                if (ask.username == "simuser")
                {
                    sale.username = "simuser";
                    sale.orderType = OrderBookType::asksale;
                }
                
                if (bid.amount == ask.amount) // bid completely clears ask
                {
                    sale.amount = ask.amount;
                    sales.push_back(sale);
                    bid.amount = 0; // reset bid so that it's not processed again
                    break; // we don't need to process this ask anymore, so we break and process next ask
                }
                if (bid.amount > ask.amount) // ask is completely fulfilled, slice the bid
                {
                    sale.amount = ask.amount;
                    sales.push_back(sale);
                    bid.amount = bid.amount - ask.amount; // we adjust the bid in place so that it can be used to process the next ask
                    break; // ask is completely fulfilled, so go to next ask
                }
                if (bid.amount < ask.amount) // bid is completely fulfilled, slice the ask
                {
                    sale.amount = bid.amount;
                    sales.push_back(sale);
                    ask.amount = ask.amount - bid.amount; // update the bid and allow further bids to process the remaining amount
                    bid.amount = 0; // make sure the bid is not processed again
                    continue; // some ask remains so go to the next bid
                }
            }
        }
    }
    return sales;
}
