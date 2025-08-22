#include "dropCheck.h"

bool DropCheck::productReleased() {

    int randomValue = rand() % 10;


    return randomValue < 9;
}
