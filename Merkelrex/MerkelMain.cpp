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
#include "CSVReader.hpp"

// constructor
MerkelMain::MerkelMain()
{

}


// init function there so that an explicit call can be made to initialize the whole program, rather than just have the program start just with the calling of a constructor
void MerkelMain::init()
{
    int input;
    currentTime = orderBook.getEarliestTime();
    while (true)
    {
        printMenu();
        input = getUserOption();
        processUserOption(input);
    }
}

void MerkelMain::printMenu()
{
    // 1 print help
    std::cout << "1: Print help " << std::endl;
    // 2 print exchange stats
    std::cout << "2: Print exchange stats " << std::endl;
    // 3 make an ask
    std::cout << "3: Make an ask " << std::endl;
    // 4 make a bid
    std::cout << "4: Make a bid " << std::endl;
    // 5 print wallet
    std::cout << "5: Print wallet " << std::endl;
    // 6 continue
    std::cout << "6: Continue " << std::endl;
    
    std::cout << "==============" << std::endl;
    
    std::cout << "Current time is: " << currentTime << std::endl;
}

void MerkelMain::printHelp()
{
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers." << std::endl;
}

void MerkelMain::printMarketStats()
{
    for (std::string const& p : orderBook.getKnownProducts())
    {
        std::cout << "Product: " << p << std::endl;
        
        // print number of entries for each product
        std::vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask,
                                                                  p,
                                                                  currentTime);
        std::cout << "Asks seen: " << entries.size() << std::endl;
        std::cout << "Max ask: " << OrderBook::getHighPrice(entries) << std::endl;
        std::cout << "Min ask: " << OrderBook::getLowPrice(entries) << std::endl;
    }
//    std::cout << "Orderbook contains: " << orders.size() << " entries" << std::endl;
//    unsigned int bids = 0;
//    unsigned int asks = 0;
//    for (OrderBookEntry& e: orders)
//    {
//        if (e.orderType == OrderBookType::ask)
//        {
//            asks++;
//        }
//        if (e.orderType == OrderBookType::bid)
//        {
//            bids++;
//        }
//    }
//    std::cout << "OrderBook asks: " << asks << " bids: " << bids << std::endl;

    
    //    for (unsigned int i = 0; i < orders.size(); ++i)
//    {
//        std::cout << "The entries are: " << orders.at(i).price << std::endl;
//    }
}

void MerkelMain::enterAsk()
{
    std::cout << "Make an ask - enter the amount: product, price, amount, e.g. ETH/BTC,200,0.5" << std::endl;
    std::string input;

    // clears console input buffer from previous streaming operation where we entered 3, which was followed by the endl; character which was stored in the buffer
//    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, input);
    
    std::vector<std::string> tokens = CSVReader::tokenise(input, ',');
    if (tokens.size() != 3)
    {
        std::cout << "MerkelMain::enterAsk Bad input! " << input << std::endl;
    }
    else
    {
        try
        {
            OrderBookEntry obe = CSVReader::stringsToOBE(tokens[1], tokens[2], currentTime, tokens[0], OrderBookType::ask);
        } catch (const std::exception& e)
        {
            std::cout << "MerkelMain::enterAsk Bad input " << std::endl;
        }
        
    }
    std::cout << "You typed: " << input << std::endl;
}

void MerkelMain::enterBid()
{
    std::cout << "Make a bid - enter the amount" << std::endl;
}

void MerkelMain::printWallet()
{
    std::cout << "Your wallet is empty" << std::endl;
}

void MerkelMain::gotoNextTimeFrame()
{
    std::cout << "Going to next timeframe" << std::endl;
    currentTime = orderBook.getNextTime(currentTime);
}

int MerkelMain::getUserOption()
{
    int userOption = 0;
    std::string line;
    std::cout << "Type in 1-6" << std::endl;
    std::getline(std::cin, line);
    try{
    userOption = std::stoi(line); // stringtoint
    } catch(const std::exception& e)
    {
        //
    }
//    std::cin >> userOption;
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
        enterAsk();
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

