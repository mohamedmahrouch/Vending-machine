#ifndef AUTOMAT_H_INCLUDED
#define AUTOMAT_H_INCLUDED


#include "coinSlot.h"
#include "Keypad.h"
#include "DropCheck.h"
#include "slot.h"

class Automat {
private:
    Slot* slots;
    int numSlots;
    int numProductsPerSlot;
    Slot* cached;
    CoinSlot coinSlot;
    Keypad keypad;
    DropCheck dropCheck;

public:
    Automat(int numSlots, int numProductsPerSlot);
    ~Automat();
    Slot* searchSlot(int slotId);
    bool addSlot(std::string productName,int price, int slotId, int motorId1, int motorId2);
    bool addSlot( std::string productName, int price, int slotId, int motorId);
    bool addSlot( Slot& slot);
    void changeSlot(int slotId, std::string name, int price);
    int getPrice(int slotId);
    int getNumPieces(int slotId);
    bool isAvailable(int slotId);
    bool dropSlot(int slotId);
    void fillAll();
    void fill(int slotId, int numProducts);
};




#endif // AUTOMAT_H_INCLUDED
