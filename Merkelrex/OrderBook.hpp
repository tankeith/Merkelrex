//
//  OrderBook.hpp
//  Merkelrex
//
//  Created by Keith Tan on 6/12/21.
//

#pragma once
#include "OrderBookEntry.hpp"
#include "CSVReader.hpp"
#include <string>
#include <vector>

class OrderBook
{
public:
    /** construct, reading a csv data file */
    OrderBook(std::string filename);
    /** return vector of all known products in the dataset*/
    std::vector<std::string> getKnownProducts();
    /** return vector of Orders acording to the sent filters*/
    std::vector<OrderBookEntry> getOrders(OrderBookType type,
                                          std::string product,
                                          std::string timestamp);
    
    /** returns the earliest time in the orderbook*/
    std::string getEarliestTime();
    
    /** returns the next time after the sent time in the orderbook. If there is no next timestamp, wraps around to the start*/
    std::string getNextTime(std::string timestamp);
    
    // static cos we're going to pass it a set of orders that it will operate on
    static double getHighPrice(std::vector<OrderBookEntry>& orders);
    static double getLowPrice(std::vector<OrderBookEntry>& orders);
    
private:
    std::vector<OrderBookEntry> orders;
};
