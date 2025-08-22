#include "CoinSlot.h"


CoinSlot::CoinSlot() {
    coinAmount = 0;
}

int CoinSlot::updateCoinAmount() {
    int input;
    std::cout << " ";
    std::cin >> input;

    if (input >= 0) {
        coinAmount += input;
        return input;
    } else {
        return -1;
    }
}

int CoinSlot::getCoinAmount() {
    return coinAmount;
}

void CoinSlot::clear() {
    coinAmount = 0;
}

void CoinSlot::returnCoins(int price) {
    int change = coinAmount - price;
    if (change < 0) {
        std::cout << "   Montant insuffisant,retirer votre argent " << std::endl;

        return;
    }

    std::cout << "RESTE  : " << std::endl;
    for (int i = 0; i < 8; ++i) {
        int count = change / coinValues[i];
        if (count > 0) {
          std::cout << "| |                 *         *                        |        |      ";  std::cout << count << " x " << coinValues[i] << " cents" << std::endl;
            change %= coinValues[i];
        }
    }
    clear();
}
