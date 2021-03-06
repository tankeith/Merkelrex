//
//  MerkelMain.hpp
//  Merkelrex
//
//  Created by Keith Tan on 30/10/21.
//

#pragma once
#include <vector>
#include "OrderBookEntry.hpp"
#include "OrderBook.hpp"
#include "Wallet.hpp"

class MerkelMain
{
    public:
        MerkelMain();
        /** Call this to start the sim */
        void init();
    private:
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterAsk();
        void enterBid();
        void printWallet();
        void gotoNextTimeFrame();
        int getUserOption();
        void processUserOption(int userOption);
    
    std::string currentTime;
//    OrderBook orderBook{"test.csv"};
    OrderBook orderBook{"20200317.csv"};
    
    Wallet wallet;
};
