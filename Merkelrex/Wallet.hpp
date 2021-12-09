//
//  Wallet.hpp
//  Merkelrex
//
//  Created by Keith Tan on 8/12/21.
//

#pragma once
#include <string>
#include <map>
#include "OrderBookEntry.hpp"

class Wallet // constructor
{
public:
    Wallet();
    /** insert currency into wallet*/
    void insertCurrency(std::string type, double amount);
    /** remove currency from wallet*/
    bool removeCurrency(std::string type, double amount); // bool to show whether it was removed or not
    /** check if wallet contains this much currency or more*/
    bool containsCurrency(std::string type, double amount);
    /** checks if the wallet can cope with this ask or bid*/
    bool canFulfillOrder(const OrderBookEntry order);
    /** update the contents of the wallet, assumes the order was made by the owner of the wallet*/
    void processSale(OrderBookEntry& sale);
    /** generate string representation of the wallet*/
    std::string toString();
    
private:
    /** map is the data type used to store the currencies and their amounts; it maps from string to double*/
    std::map<std::string, double> currencies;
};
