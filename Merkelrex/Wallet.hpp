//
//  Wallet.hpp
//  Merkelrex
//
//  Created by Keith Tan on 8/12/21.
//

#include <string>
#include <map>

class Wallet // constructor
{
public:
    Wallet();
    /** insert currency into wallet*/
    void insertCurrency(std::string type, double amount);
    /** check if wallet contains this much currency or more*/
    bool containsCurrency(std::string type, double amount);
    /** generate string representation of the wallet*/
    std::string toString();
    
private:
    /** data structure mapping from string to double*/
    std::map<std::string, double> currencies;
};
