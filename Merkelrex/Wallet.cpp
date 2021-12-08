//
//  Wallet.cpp
//  Merkelrex
//
//  Created by Keith Tan on 8/12/21.
//

#include "Wallet.hpp"

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
    return "oink";
}
