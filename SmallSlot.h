#ifndef SMALLSLOT_H_INCLUDED
#define SMALLSLOT_H_INCLUDED

#include "slot.h"
#include <string>

class SmallSlot : public Slot {
public:
    SmallSlot(int slotId, const std::string& productName, int price);
    virtual void drop() override;
};

#endif // SMALLSLOT_H_INCLUDED
