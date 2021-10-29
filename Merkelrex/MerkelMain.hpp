//
//  MerkelMain.hpp
//  Merkelrex
//
//  Created by Keith Tan on 30/10/21.
//

#ifndef MerkelMain_hpp
#define MerkelMain_hpp

#include <stdio.h>

#endif /* MerkelMain_hpp */

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
        void enterOffer();
        void enterBid();
        void printWallet();
        void gotoNextTimeFrame();
        int getUserOption();
        void processUserOption(int userOption);
};
