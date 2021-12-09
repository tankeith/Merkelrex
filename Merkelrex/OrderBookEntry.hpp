//
//  OrderBookEntry.hpp
//  Merkelrex
//
//  Created by Keith Tan on 28/10/21.
//

#pragma once
#include <string>

enum class OrderBookType{bid, ask, unknown, asksale, bidsale};

class OrderBookEntry
{
public:
    // define constructor
    OrderBookEntry(double _price,
                   double _amount,
                   std::string _timestamp,
                   std::string _product,
                   OrderBookType _orderType,
                   std::string username = "dataset"); // means that the default value of the string is set to "dataset" if we don't pass a string as username
    
    // function that converts string into OrderBookType
    static OrderBookType stringToOrderBookType(std::string s);
    
    // function that sorts orders in the OrderBook by timestamp (from earliest to latest)
    static bool compareByTimestamp(const OrderBookEntry& e1, const OrderBookEntry& e2)
    {
        return e1.timestamp < e2.timestamp;
    }
    
    // sorts orders by price from asc to desc and vice versa
    static bool compareByPriceAsc(OrderBookEntry& e1, OrderBookEntry& e2)
    {
        return e1.price < e2.price;
    }
    static bool compareByPriceDesc(OrderBookEntry& e1, OrderBookEntry& e2)
    {
        return e1.price > e2.price;
    }
    
    // data members holding data coming in through the constructor
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
    std::string username;
};
