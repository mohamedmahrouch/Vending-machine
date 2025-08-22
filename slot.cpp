#include "slot.h"
#include "motor.h"

Slot::Slot()
    : id(0), productName(""), price(0), numProducts(0), motor1(nullptr), motor2(nullptr) {}

Slot::Slot(int slotId, std::string productName, int price, int motor1Id, int motor2Id)
    : id(slotId), productName(productName), price(price), numProducts(0), motor1(nullptr), motor2(nullptr) {
    motor1 = new Motor(motor1Id);
    if (motor2Id != 0) {
        motor2 = new Motor(motor2Id);
    }
}

Slot::~Slot() {
    delete motor1;
    delete motor2;
}

void Slot::drop() {
    if (motor1) {
        motor1->trigger();
    }
    if (motor2) {
        motor2->trigger();
    }
    std::cout << getProductName() << " livré à partir du logement " << getId() << std::endl;
}

int Slot::getPrice() const {
    return price;
}

void Slot::setPrice(int price) {
    this->price = price;
}

int Slot::getNumProducts() const {
    return numProducts;
}

void Slot::setNumProducts(int numProducts) {
    this->numProducts = numProducts;
}

int Slot::getId() const {
    return id;
}

std::string Slot::getProductName() const {
    return productName;
}

void Slot::setProductName(std::string productName) {
    this->productName = productName;
}
