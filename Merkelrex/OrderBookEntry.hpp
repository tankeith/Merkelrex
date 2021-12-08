//
//  OrderBookEntry.hpp
//  Merkelrex
//
//  Created by Keith Tan on 28/10/21.
//

#pragma once
#include <string>

enum class OrderBookType{bid, ask, unknown};

class OrderBookEntry
{
public:
    // define constructor
    OrderBookEntry(double _price,
                   double _amount,
                   std::string _timestamp,
                   std::string _product,
                   OrderBookType _orderType);
    
    // function that converts string into OrderBookType
    static OrderBookType stringToOrderBookType(std::string s);
    
    // function that sorts orders in the OrderBook by timestamp (from earliest to latest)
    static bool compareByTimestamp(OrderBookEntry& e1, OrderBookEntry& e2)
    {
        return e1.timestamp < e2.timestamp;
    }
    
    // data members holding data coming in through the constructor
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
};
