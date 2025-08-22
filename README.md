# Projet Distributeur Automatique (Vending Machine)

Ce projet implémente un système de distributeur automatique en C++. Il simule les fonctionnalités d'une machine de vente, incluant la gestion des pièces, la sélection des produits et la distribution.

## Structure du Projet

Le projet est organisé en plusieurs classes qui gèrent différents aspects du distributeur :

- `automat` : Contrôleur principal du distributeur
- `CoinSlot` : Gestion des pièces et paiements
- `DropCheck` : Vérification de la distribution des produits
- `Keypad` : Interface utilisateur pour la sélection des produits
- `motor` : Contrôle des moteurs de distribution
- `slot` : Gestion des emplacements de produits
  - `SmallSlot` : Emplacements pour petits produits
  - `WideSlot` : Emplacements pour grands produits

## Compilation et Exécution

Le projet utilise CodeBlocks comme IDE (fichier projet : HHHH.cbp).

Pour compiler et exécuter le projet :
1. Ouvrez le projet dans CodeBlocks
2. Compilez le projet (F9)
3. Exécutez le programme (F10)

## Fichiers du Projet

- `main.cpp` : Point d'entrée du programme
- `*.h` : Fichiers d'en-tête définissant les classes
- `*.cpp` : Fichiers d'implémentation des classes
- `bin/Debug/` : Dossier contenant l'exécutable
- `obj/Debug/` : Dossier contenant les fichiers objets

## Fonctionnalités

- Insertion et validation des pièces
- Sélection des produits via le clavier
- Gestion de différents types d'emplacements (petits et grands)
- Contrôle des moteurs pour la distribution
- Vérification de la distribution des produits

## Développement

Ce projet a été développé en C++ et utilise les concepts de la programmation orientée objet tels que :
- L'héritage (SmallSlot et WideSlot héritant de slot)
- L'encapsulation (membres privés et publics)
- La composition (relations entre les différentes classes)
