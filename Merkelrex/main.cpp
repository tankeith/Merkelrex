//
//  main.cpp
//  Merkelrex
//
//  Created by Keith Tan on 13/10/21.
//

#include <iostream>
#include <string>
#include <vector>

enum class OrderBookType{bid, ask};

class OrderBookEntry
{
    public:
        OrderBookEntry(double _price,
                       double _amount,
                       std::string _timestamp,
                       std::string _product,
                       OrderBookType _orderType)
        : price(_price),
          amount(_amount),
          timestamp(_timestamp),
          product(_product),
          orderType(_orderType)
        {

        }
        double price;
        double amount;
        std::string timestamp;
        std::string product;
        OrderBookType orderType;
};

void printMenu()
{
    // 1 print help
    std::cout << "1: Print help " << std::endl;
    // 2 print exchange stats
    std::cout << "2: Print exchange stats " << std::endl;
    // 3 make an offer
    std::cout << "3: Make an offer " << std::endl;
    // 4 make a bid
    std::cout << "4: Make a bid " << std::endl;
    // 5 print wallet
    std::cout << "5: Print wallet " << std::endl;
    // 6 continue
    std::cout << "6: Continue " << std::endl;
    
    std::cout << "==============" << std::endl;
}

void printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers." << std::endl;
}

void printMarketStats()
{
    std::cout << "Market looks good" << std::endl;
}

void enterOffer()
{
    std::cout << "Make an offer" << std::endl;
}

void enterBid()
{
    std::cout << "Make a bid" << std::endl;
}

void printWallet()
{
    std::cout << "Your wallet is empty" << std::endl;
}

void gotoNextTimeFrame()
{
    std::cout << "Going to next timeframe" << std::endl;
}

int getUserOption()
{
    int userOption;
    
    std::cout << "Type in 1-6" << std::endl;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

void processUserOption(int userOption)
{
    if (userOption == 0) // bad input
    {
        std::cout << "Invalid choice. Choose 1-6" << std::endl;
    }
    if (userOption == 1)
    {
        printHelp();
    }
    if (userOption == 2)
    {
        printMarketStats();
    }
    if (userOption == 3)
    {
        enterOffer();
    }
    if (userOption == 4)
    {
        enterBid();
    }
    if (userOption == 5)
    {
        printWallet();
    }
    if (userOption == 6)
    {
        gotoNextTimeFrame();
    }
}

int main(int argc, const char * argv[]) {

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
    
    std::vector<OrderBookEntry> orders;

    orders.push_back( OrderBookEntry{10000,
                        0.002,
                        "2020/03/17 17:01:24.884492",
                        "BTC/USDT",
                        OrderBookType::bid}
                                     );
    
    orders.push_back( OrderBookEntry{5000,
                        0.002,
                        "2020/03/17 17:01:24.884492",
                        "BTC/USDT",
                        OrderBookType::bid}
                                     );
    
//    OrderBookEntry order1{10000,
//                          0.002,
//                          "2020/03/17 17:01:24.884492",
//                          "BTC/USDT",
//                          OrderBookType::bid}; // creates an object

    
//    order1.price = 100000;
//    order1.amount = 0.002;
//    order1.timestamp = "2020/03/17 17:01:24.884492";
//    order1.product = "BTC/USDT";
//    order1.orderType = OrderBookType::bid;
    
    // 2. Iterate by reference (access original version in the vector)
    // Iterate over all the elements in orders
    for (OrderBookEntry& order : orders)
    {
        std::cout << "The price is " << order.price << std::endl; // work on original version
    }
    
    // 2. Classic array syntax
    for (unsigned int i = 0; i < orders.size(); ++i)
    {
        std::cout << "The price is " << orders[i].price << std::endl; // work on original version
    }
    
    // 3. Object style syntax
    for (unsigned int i = 0; i < orders.size(); ++i)
    {
        std::cout << "The price is " << orders.at(i).price << std::endl;
    }
    
    
//    std::cout << "The price is " << orders[0].price << std::endl;
//    std::cout << "The price is " << orders[1].price << std::endl;
    
//    std::cout << "The amount is " << orders[].amount << std::endl;
//    std::cout << "The timestamp is " << order1.timestamp << std::endl;
//    std::cout << "The product is " << order1.product << std::endl;
//    std::cout << "The order type is " << static_cast<std::underlying_type<OrderBookType>::type>(order1.orderType) << std::endl;
    
    return 0;
}
