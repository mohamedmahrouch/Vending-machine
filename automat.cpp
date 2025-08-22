#include "automat.h"

Automat::Automat(int numSlots, int numProductsPerSlot)
    : numSlots(numSlots), numProductsPerSlot(numProductsPerSlot), cached(nullptr) {
    slots = new Slot[numSlots];
}

Automat::~Automat() {
    delete[] slots;
}

Slot* Automat::searchSlot(int slotId) {
    if (cached && cached->getId() == slotId)
        return cached;

    for (int i = 0; i < numSlots; ++i) {
        if (slots[i].getId() == slotId) {
            cached = &slots[i];
            return &slots[i];
        }
    }

    return nullptr;
}

bool Automat::addSlot(std::string productName, int price,int slotId, int motorId1, int motorId2) {
    for (int i = 0; i < numSlots; ++i) {
        if (slots[i].getId() == slotId) {
            return false;
        }
    }

    for (int i = 0; i < numSlots; ++i) {
        if (slots[i].getId() == 0) {
            slots[i] = Slot(slotId, productName, price, motorId1, motorId2);
            return true;
        }
    }

    return false;
}

void Automat::changeSlot(int slotId, std::string name, int price) {
    Slot* slot = searchSlot(slotId);
    if (slot) {
        slot->setProductName(name);
        slot->setPrice(price);
    }
}

int Automat::getPrice(int slotId) {
    Slot* slot = searchSlot(slotId);
    return (slot) ? slot->getPrice() : -1;
}

int Automat::getNumPieces(int slotId) {
    Slot* slot = searchSlot(slotId);
    return (slot) ? slot->getNumProducts() : -1;
}

bool Automat::isAvailable(int slotId) {
    Slot* slot = searchSlot(slotId);
    return (slot) ? (slot->getNumProducts() > 0) : false;
}

bool Automat::dropSlot(int slotId) {
    Slot* slot = searchSlot(slotId);
    if (slot && slot->getNumProducts() > 0) {
        slot->drop();
        return true;
    }
    return false;
}

void Automat::fillAll() {
    for (int i = 0; i < numSlots; ++i) {
        slots[i].setNumProducts(numProductsPerSlot);
    }
}

void Automat::fill(int slotId, int numProducts) {
    Slot* slot = searchSlot(slotId);
    if (slot) {
        slot->setNumProducts(numProducts);
    }
}
bool Automat::addSlot( std::string productName, int price, int slotId, int motorId) {
    if (slotId >= 1 && slotId <= numSlots) {
        slots[slotId - 1] = Slot(slotId, productName, price, motorId, 0);
        return true;
    }
    return false;
}

bool Automat::addSlot( Slot& slot) {
    int slotId = slot.getId();
    if (slotId >= 1 && slotId <= numSlots) {
        slots[slotId - 1] = slot;
        return true;
    }
    return false;
}
