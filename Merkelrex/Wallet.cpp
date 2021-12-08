//
//  Wallet.cpp
//  Merkelrex
//
//  Created by Keith Tan on 8/12/21.
//

#include <iostream>
#include "Wallet.hpp"
#include "CSVReader.hpp"

Wallet::Wallet()
{
    
}

void Wallet::insertCurrency(std::string type, double amount)
{
    double balance;
    if (amount < 0) // check if amount is greater than 0
    {
        throw std::exception{};
    }
    if (currencies.count(type) == 0) // type not existent yet
    {
        balance = 0; // initialize it to 0
    }
    else // type exists
    {
        balance = currencies[type];
    }
    balance += amount;
    currencies[type] = balance;
}

bool Wallet::removeCurrency(std::string type, double amount)
{
    if (amount < 0) // if asked to remove a negative amount
    {
        return false;
    }
    if (currencies.count(type) == 0) // if we don't have any of that currency in the wallet
    {
        std::cout << "No currency for " << type << std::endl;
        return false;
    }
    else // it's there, but do we have enough?
    {
        if (containsCurrency(type, amount)) // we have enough
            {
                std::cout << "Removing " << type << ": " << amount << std::endl;
                currencies[type] -= amount;
                return true;
            }
        else // have the currency but not enough
            return false;
    }
}

bool Wallet::containsCurrency(std::string type, double amount)
{
    if (currencies.count(type) == 0) // type not existent yet
        return false;
    else
    {
        return currencies[type] >= amount;
    }
}

std::string Wallet::toString()
{
    std::string s; // stores string message as we build it
    for(std::pair<std::string, double> pair : currencies) // std::pair used to represent one of the items in the map
    {
        std::string currency = pair.first; // the first item out of the pair
        double amount = pair.second; // the second item out of the pair
        s += currency + " : " + std::to_string(amount) + "\n"; // std::to_string converts from double to string
    }
    return s;
}

bool Wallet::canFulfillOrder(const OrderBookEntry order)
{
    // split product up
    std::vector<std::string> currs = CSVReader::tokenise(order.product, '/');
    
    // ask
    if (order.orderType == OrderBookType::ask)
    {
        double amount = order.amount; // from formula C1 * amount
        std::string currency = currs[0]; // the first currency
        std::cout << "Wallet::canFulfillOrder " << currency << " : " << amount << std::endl;
        return containsCurrency(currency, amount);
    }
    // bid
    if (order.orderType == OrderBookType::bid)
    {
        double amount = order.amount * order.price; // from formula C2 * order * price
        std::string currency = currs[1]; // the second currency
        std::cout << "Wallet::canFulfillOrder " << currency << " : " << amount << std::endl;
        return containsCurrency(currency, amount);
    }
    return false;
}
