//
//  OrderBookEntry.cpp
//  Merkelrex
//
//  Created by Keith Tan on 28/10/21.
//

#include "OrderBookEntry.hpp"

OrderBookEntry::OrderBookEntry(double _price,
               double _amount,
               std::string _timestamp,
               std::string _product,
               OrderBookType _orderType,
               std::string _username) // no need to rewrite default specifier here as it's only needed in the header file
// initialization list
: price(_price),
  amount(_amount),
  timestamp(_timestamp),
  product(_product),
  orderType(_orderType),
  username(_username) // takes the username and assigning onto the username variable inside the object
{
    
}

OrderBookType OrderBookEntry::stringToOrderBookType(std::string s)
{
    if (s == "ask")
    {
        return OrderBookType::ask;
    }
    if (s == "bid")
    {
        return OrderBookType::bid;
    }
    return OrderBookType::unknown;
}
