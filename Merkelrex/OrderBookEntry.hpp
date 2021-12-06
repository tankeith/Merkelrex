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
    
    // data members holding data coming in through the constructor
    double price;
    double amount;
    std::string timestamp;
    std::string product;
    OrderBookType orderType;
};
