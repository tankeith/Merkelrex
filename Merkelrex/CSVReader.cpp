//
//  CSVReader.cpp
//  Merkelrex
//
//  Created by Keith Tan on 14/11/21.
//

#include <iostream>
#include <fstream>
#include "CSVReader.hpp"

CSVReader::CSVReader()
{
    
}

std::vector<OrderBookEntry> CSVReader::readCSV(std::string csvFilename)
{
    std::vector<OrderBookEntry> entries;
    std::ifstream csvFile{csvFilename};
    std::string line;
    
    if (csvFile.is_open())
    {
        while (std::getline(csvFile, line))
        {
            try{
                OrderBookEntry obe = stringsToOBE(tokenise(line, ','));
                entries.push_back(obe);
            }
            catch (const std::exception& e)
            {
                std::cout << "CSVReader::read CSV bad data" << std::endl;
            }
        } // end of while
    }
    std::cout << "CSVReader::readCSV read " << entries.size() << " entries" << std::endl;
    return entries;
}

std::vector<std::string> CSVReader::tokenise(std::string csvLine, char separator)
{
    std::vector<std::string> tokens;
    signed int start, end;  // used to delineate position of the tokens
    std::string token;

    start = csvLine.find_first_not_of(separator, 0);
    do{
        end = csvLine.find_first_of(separator, start);  // next separator after start
        if (start == csvLine.length() || start == end)
            break;
        if (end >= 0)
            token = csvLine.substr(start, end - start);
        else
            token = csvLine.substr(start, csvLine.length() - start);
        tokens.push_back(token);

        start = end + 1;
    }
    while (end > 0);
    return tokens;
}

OrderBookEntry CSVReader::stringsToOBE(std::vector<std::string> tokens) // pass it a vector of strings from tokenise and convert it to appropriate data to send it into the constructor for an OrderBookEntry
{
    double price, amount;
    if (tokens.size() != 5) // checks if the token has 5 elements
    {
        std::cout << "Bad line " << std::endl;
        throw std::exception{};
    }
    try
    {
        price = std::stod(tokens[3]);
        amount = std::stod(tokens[4]);
    }
    catch(const std::exception& e) // if it can't convert the strings into doubles then it's going to catch the exception and throw the exception (below)
    {
        std::cout << "CSVReader::stringsToOBE Bad float! " << tokens[3] << std::endl;
        std::cout << "CSVReader::stringsToOBE Bad float! " << tokens[4] << std::endl;
        throw;
    }
    
    OrderBookEntry obe
        {price,
        amount,
        tokens[0], // timestamp
        tokens[1], // product type
        OrderBookEntry::stringToOrderBookType(tokens[2])}; // bid or offer
    
    return obe;
}

OrderBookEntry CSVReader::stringsToOBE(std::string priceString,
                                   std::string amountString,
                                   std::string timestamp,
                                   std::string product,
                                   OrderBookType orderType)
{
    // try to convert the price and amount into doubles. The rest of the data are in the correct types already
    double price, amount;
    try
    {
        price = std::stod(priceString);
        amount = std::stod(amountString);
    }
    catch(const std::exception& e) // if it can't convert the strings into doubles then it's going to catch the exception and throw the exception (below)
    {
        std::cout << "CSVReader::stringsToOBE Bad float! " << priceString << std::endl;
        std::cout << "CSVReader::stringsToOBE Bad float! " << amountString << std::endl;
        throw;
    }

    // instantiate OrderBookEntry
    OrderBookEntry obe
        {price,
        amount,
        timestamp, // timestamp
        product, // product type
        orderType}; // bid or offer

    return obe;
}
