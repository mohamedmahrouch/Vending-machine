#include "Keypad.h"
#include <iostream>

int Keypad::getSelection() {
    int selection;
         cout << "Entrez le numéro de l'emplacement du produit : ";
         cin >> selection;
    return selection;
}
