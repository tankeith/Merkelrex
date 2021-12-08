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
/** return vector of Orders acording to the sent filters*/
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


