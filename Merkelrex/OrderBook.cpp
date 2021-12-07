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
    return orders_sub;
}
