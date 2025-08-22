#ifndef SLOT_H_INCLUDED
#define SLOT_H_INCLUDED

#include <iostream>
#include <string>

class Slot {
private:
    std::string productName;
    int id;
    int numProducts;
    int price;
    class Motor* motor1;
    class Motor* motor2;

public:
    Slot(int slotId, std::string productName, int price, int motor1Id=0, int motor2Id = 0);
    Slot();
    ~Slot();
    virtual void drop();
    int getPrice() const;
    void setPrice(int price);
    int getNumProducts() const;
    void setNumProducts(int numProducts);
    int getId() const;
    std::string getProductName() const;
    void setProductName(std::string productName);
};




#endif // SLOT_H_INCLUDED
