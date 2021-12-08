//
//  CSVReader.hpp
//  Merkelrex
//
//  Created by Keith Tan on 14/11/21.
//

#pragma once
#include "OrderBookEntry.hpp"
#include <string>
#include <vector>

class CSVReader
{
public:
    CSVReader(); // constructor    
    static std::vector<OrderBookEntry> readCSV(std::string csvFile); // stateless function that doesn't rely on any instance of csvReader called readCSV that's going to return vector of OrderBookEntry objects
    static std::vector<std::string> tokenise(std::string csvLine, char separator);
    
    // overloads original function in private that takes only vector inputs
    static OrderBookEntry stringsToOBE(std::string price,
                                       std::string amount,
                                       std::string timestamp,
                                       std::string product,
                                       OrderBookType OrderBookType);    
private:
    static OrderBookEntry stringsToOBE(std::vector<std::string> strings); // we pass it strings which we get from tokenise
};
