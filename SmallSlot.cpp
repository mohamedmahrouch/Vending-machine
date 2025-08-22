#include "SmallSlot.h"
#include <iostream>

SmallSlot::SmallSlot(int slotId, const std::string& productName, int price) : Slot(slotId, productName, price) {}

void SmallSlot::drop() {
    std::cout << getProductName() << " livr� � partir du logement " << getId() << std::endl;
}
