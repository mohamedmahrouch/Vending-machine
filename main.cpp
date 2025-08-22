#include <iostream>
#include <iomanip>
#include "automat.h"
#include "CoinSlot.h"

int main() {
    Automat automat(20, 15); // 2 emplacements, 5 produits max par emplacement
    CoinSlot coinSlot;

    // Ajout de quelques slots à l'automate automatiquement
    for (int i = 1; i <= 15; ++i) {
        std::string productName ="Product" + std::to_string(i);
        int id = i; // Prix de chaque produit
        int numProducts = 6; // Nombre de produits par emplacement

        automat.addSlot(productName, 10 * i, id, numProducts, 10); // Ajoute un emplacement avec l'ID i, contenant 15 produits de nom "ProductX", avec les moteurs d'ID 1 et 2
        automat.fill(i, numProducts); // Remplit l'emplacement i avec 15 produits
    }

    std::cout << "|-----------------------------------------------------------------------------------------------------------------------------|" << std::endl;
    std::cout << "|                                            Bienvenue a notre Distributeur de Snacks                                         |" << std::endl;
    std::cout << "|-----------------------------------------------------------------------------------------------------------------------------|" << std::endl;
    std::cout << "|       Emplacement                |   Produit                    |  Prix                   |                 Stock           |" << std::endl;
    std::cout << "+----------------------------------+------------------------------+-------------------------+---------------------------------+" << std::endl;

    // Affichage des détails des emplacements
    for (int i = 1; i <= 15; ++i) {
        Slot* slot = automat.searchSlot(i);
        if (slot) {
            std::cout << "|         " << std::setw(12) << i << "             |  " << std::setw(18) << std::left << slot->getProductName() << "          |   " << std::setw(15) << slot->getPrice() << "       |    " << std::setw(15) << slot->getNumProducts() << "              |" << std::endl;
        } else {
            std::cout << "|          " << std::setw(12) << i << "            |  " << std::setw(18) << std::left << "N/A" << "     |   " << std::setw(15) << "N/A" << "    |   " << std::setw(15) << "N/A" << "           |" << std::endl;
        }
    }
    std::cout << "+----------------------------------+------------------------------+-------------------------+---------------------------------+" << std::endl;

    // Choix d'un produit et ajout d'argent
    int slotId, money;

    // Vérification de la disponibilité du slot
    std::cout << "+-----------------------------------+------------------------------+-------------------------+---------------------------------+" << std::endl;
    std::cout << "|  _________________________________________________             ______________________________________                        |" << std::endl;
    std::cout << "| |  Choisissez un emplacement (1 JUSQUA 15) : ";
    std::cin >> slotId;
    std::cout << "  |                                                    |        | Entrez le montant d'argent :";
    coinSlot.updateCoinAmount();
    std::cout << std::endl;
    std::cout << "| |                                                    |        |                                       |                      |" << std::endl;
    std::cout << "| |_________________________________________________   |        |______________________________________ |                      |" << std::endl;
    std::cout << "|                                                                                                                              |" << std::endl;
    std::cout << "|------------------------------------------------------------------------------------------------------------------------------|" << std::endl;

    if (automat.isAvailable(slotId)) {
        Slot* slot = automat.searchSlot(slotId);
        if (slot) {
            // Effectuer la transaction
            int totalPrice = slot->getPrice();

            if (coinSlot.getCoinAmount() >= totalPrice) {

                std::cout << "+-----------------------------------+------------------------------+-------------------------+---------------------------------+" << std::endl;
                std::cout << "                                      Vous avez choisi le produit :[" << slot->getProductName() << "]au prix de : {" << slot->getPrice() << "} cents." << std::endl;

                std::cout << "|------------------------------------------------------------------------------------------------------------------------------|" << std::endl;
                std::cout << "+-----------------------------------+------------------------------+-------------------------+---------------------------------+" << std::endl;
                std::cout << "                                     OPERATION :  Transaction reussie.!!!!" << std::endl;
                std::cout << "|------------------------------------------------------------------------------------------------------------------------------|" << std::endl;


        std::cout << "+-----------------------------------+------------------------------+-------------------------+---------------------------------+" << std::endl;
        std::cout << "|  _________________________________________________             ______________________________________                        |" << std::endl;
        std::cout << "| |                 *         *                        |        |                                       |                      |" << std::endl;
        std::cout << "| |                 *         *                        |        | " ;coinSlot.returnCoins(totalPrice);std::cout << "|" << std::endl;
        std::cout << "| |_________________*_________*_____________________   |        |______________________________________ |                      |" << std::endl;
        std::cout << "|                                                                                                                              |" << std::endl;
        std::cout << "|------------------------------------------------------------------------------------------------------------------------------|" << std::endl;
        std::cout << "|                                             MR: mohamed MAHROUCH                    |" << std::endl;
        std::cout << "|______________________________________________________________________________________________________________________________|" << std::endl;
            } else {
                std::cout << "+-----------------------------------+------------------------------+-------------------------+---------------------------------+" << std::endl;
                std::cout << "                                     OPERATION :  Transaction annulee. Montant insuffisant.!!!!" << std::endl;
                std::cout << "|------------------------------------------------------------------------------------------------------------------------------|" << std::endl;
                std::cout << "+-----------------------------------+------------------------------+-------------------------+---------------------------------+" << std::endl;
                std::cout << "                                     OPERATION :  Transaction Echoue.!!!!" << std::endl;
                std::cout << "|------------------------------------------------------------------------------------------------------------------------------|" << std::endl;

        std::cout << "+-----------------------------------+------------------------------+-------------------------+---------------------------------+" << std::endl;
        std::cout << "|  _________________________________________________             ______________________________________                        |" << std::endl;
        std::cout << "| |                 *         *                        |        |                                                    |         |" << std::endl;
        std::cout << "| |                 *         *                        |        |  ";coinSlot.returnCoins(totalPrice);
        std::cout << "|" << std::endl;
        std::cout << "| |_________________*_________*_____________________   |        |______________________________________              |         |" << std::endl;
        std::cout << "|                                                                                                                              |" << std::endl;
        std::cout << "|------------------------------------------------------------------------------------------------------------------------------|" << std::endl;
        std::cout << "|                                             MR: mohamed MAHROUCH                    |" << std::endl;
        std::cout << "|______________________________________________________________________________________________________________________________|" << std::endl;
            }


 }
    }
    return 0;

}
