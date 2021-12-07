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
private:
    std::vector<OrderBookEntry> orders;
};
