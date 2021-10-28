//
//  OrderBookEntry.hpp
//  Merkelrex
//
//  Created by Keith Tan on 28/10/21.
//

#ifndef OrderBookEntry_hpp
#define OrderBookEntry_hpp

#include <stdio.h>
#include <string>

#endif /* OrderBookEntry_hpp */

enum class OrderBookType{bid, ask};

class OrderBookEntry
{
    public:
        OrderBookEntry(double _price,
                       double _amount,
                       std::string _timestamp,
                       std::string _product,
                       OrderBookType _orderType);
        double price;
        double amount;
        std::string timestamp;
        std::string product;
        OrderBookType orderType;
};
