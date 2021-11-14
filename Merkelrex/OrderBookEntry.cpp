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
               OrderBookType _orderType)
// initialization list
: price(_price),
  amount(_amount),
  timestamp(_timestamp),
  product(_product),
  orderType(_orderType)
{
    
}
