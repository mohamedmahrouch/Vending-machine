#ifndef WIDESLOT_H_INCLUDED
#define WIDESLOT_H_INCLUDED


#include "Slot.h"

class WideSlot : public Slot {
private:
    int motor1Id;
    int motor2Id;

public:
    WideSlot(int id, char* productName, int price, int motor1Id, int motor2Id);

    virtual void drop() override;
};




#endif // WIDESLOT_H_INCLUDED
