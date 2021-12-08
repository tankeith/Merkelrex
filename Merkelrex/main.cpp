//
//  main.cpp
//  Merkelrex
//
//  Created by Keith Tan on 13/10/21.
//

#include <iostream>
#include <string>
#include <vector>
#include "OrderBookEntry.hpp"
#include "MerkelMain.hpp"
#include "CSVReader.hpp"
#include "Wallet.hpp"

int main()
{
    MerkelMain app{};
    app.init();
//    Wallet wallet;
//    wallet.insertCurrency("BTC", 10);
//    wallet.insertCurrency("USDT", 10000);
//    std::cout << "Wallet has BTC " << wallet.containsCurrency("USDT", 10) << std::endl;
//    std::cout << wallet.toString() << std::endl;
//    wallet.removeCurrency("USDT", 1000);
//    std::cout << wallet.toString() << std::endl;
    
//    std::vector<double> prices;
//    std::vector<double> amounts;
//    std::vector<std::string> timestamps;
//    std::vector<std::string> products;
//    std::vector<OrderBookType> orderTypes;
//
//    prices.push_back(5000.01);
//    amounts.push_back(0.001);
//    timestamps.push_back("2020/03/17 17:01:24.884492");
//    timestamps.push_back("ETH/BTC");
//    orderTypes.push_back(OrderBookType::bid);
//
//    std::cout << "prices: " << prices[0] << std::endl;
//    std::cout << "sizeof unsigned short " << sizeof(unsigned short) << std::endl;
    
//
//    while (true)
//    {
//        printMenu();
//        int userOption = getUserOption();
//        processUserOption(userOption);
//    }
    


    
//    order1.price = 100000;
//    order1.amount = 0.002;
//    order1.timestamp = "2020/03/17 17:01:24.884492";
//    order1.product = "BTC/USDT";
//    order1.orderType = OrderBookType::bid;
    
//    // 2. Iterate by reference (access original version in the vector)
//    // Iterate over all the elements in orders
//    for (OrderBookEntry& order : orders)
//    {
//        std::cout << "The price is " << order.price << std::endl; // work on original version
//    }
//
//    // 2. Classic array syntax
//    for (unsigned int i = 0; i < orders.size(); ++i)
//    {
//        std::cout << "The price is " << orders[i].price << std::endl; // work on original version
//    }
//
//    // 3. Object style syntax
//    for (unsigned int i = 0; i < orders.size(); ++i)
//    {
//        std::cout << "The price is " << orders.at(i).price << std::endl;
//    }
//
    
//    std::cout << "The price is " << orders[0].price << std::endl;
//    std::cout << "The price is " << orders[1].price << std::endl;
    
//    std::cout << "The amount is " << orders[].amount << std::endl;
//    std::cout << "The timestamp is " << order1.timestamp << std::endl;
//    std::cout << "The product is " << order1.product << std::endl;
//    std::cout << "The order type is " << static_cast<std::underlying_type<OrderBookType>::type>(order1.orderType) << std::endl;
    
    return 0;
}
