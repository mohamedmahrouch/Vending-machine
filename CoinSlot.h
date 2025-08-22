#ifndef COINSLOT_H_INCLUDED
#define COINSLOT_H_INCLUDED

#include <iostream>

using namespace std;
class CoinSlot {
private:
    int coinAmount;
    const int coinValues[8] = {200, 100, 50, 20, 10, 5,2, 1};

public:
    CoinSlot();
    int updateCoinAmount();
    int getCoinAmount();
    void clear();
    void returnCoins(int price);
};

#endif // COINSLOT_H_INCLUDED
