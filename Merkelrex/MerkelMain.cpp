//
//  MerkelMain.cpp
//  Merkelrex
//
//  Created by Keith Tan on 30/10/21.
//

#include <iostream>
#include <vector>
#include "MerkelMain.hpp"
#include "OrderBookEntry.hpp"

// constructor
MerkelMain::MerkelMain()
{

}


// init function there so that an explicit call can be made to initialize the whole program, rather than just have the program start just with the calling of a constructor
void MerkelMain::init()
{
    int input;
    while (true)
    {
        loadOrderBook();
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void MerkelMain::loadOrderBook()
{
    orders.push_back( OrderBookEntry{100,
                        0.002,
                        "2020/03/17 17:01:24.884492",
                        "BTC/USDT",
                        OrderBookType::bid}
                                     );

    orders.push_back( OrderBookEntry{200,
                        0.002,
                        "2020/03/17 17:01:24.884492",
                        "BTC/USDT",
                        OrderBookType::bid}
                                     );
//
//    OrderBookEntry order1{10000,
//                          0.002,
//                          "2020/03/17 17:01:24.884492",
//                          "BTC/USDT",
//                          OrderBookType::bid}; // creates an object
}

void MerkelMain::printMenu()
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

void MerkelMain::printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers." << std::endl;
}

void MerkelMain::printMarketStats()
{
    std::cout << "Orderbook contains: " << orders.size() << " entries" << std::endl;
    
    for (unsigned int i = 0; i < orders.size(); ++i)
    {
        std::cout << "The entries are: " << orders.at(i).price << std::endl;
    }    
}

void MerkelMain::enterOffer()
{
    std::cout << "Make an offer" << std::endl;
}

void MerkelMain::enterBid()
{
    std::cout << "Make a bid" << std::endl;
}

void MerkelMain::printWallet()
{
    std::cout << "Your wallet is empty" << std::endl;
}

void MerkelMain::gotoNextTimeFrame()
{
    std::cout << "Going to next timeframe" << std::endl;
}

int MerkelMain::getUserOption()
{
    int userOption;
    
    std::cout << "Type in 1-6" << std::endl;
    std::cin >> userOption;
    std::cout << "You chose: " << userOption << std::endl;
    return userOption;
}

void MerkelMain::processUserOption(int userOption)
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

