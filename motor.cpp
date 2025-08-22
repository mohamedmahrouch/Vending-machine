#include "motor.h"
#include <iostream>

Motor::Motor(int id) : id(id) {}

void Motor::trigger() {
    std::cout << "Moteur " << id << " est activé" << std::endl;
}
