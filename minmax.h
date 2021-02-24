#ifndef MINMAX_H_INCLUDED
#define MINMAX_H_INCLUDED
#include <stdio.h>

#include "puissance.h"

struct Minmax{
    Puissance p; //copie du puissance du main
    unsigned int *tabLignes; //stocke la première ligne disponible pour chaque colonne
    unsigned int *tabMax; //stocke la valeur de max pour chaque colonne à la ligne tabLignes
};

//définit la valeur de tabLignes à l'indice colonne
void setTabLignes(Minmax* m, unsigned int ligne, unsigned int colonne);
//retourne la valeur de tabLignes à l'indice colonne
unsigned int getTabLignes(Minmax* m, unsigned colonne);
//définit la valeur de tabMax à l'indice colonne
void setTabMax(Minmax* m, unsigned int colonne, unsigned int valeur);
//retourne la valeur de tabMax à l'indice colonne
unsigned int getTabMax(Minmax* m, unsigned int colonne);

//initialisation du Puissance de Minmax
void initPuissanceMM(Minmax* m, Puissance* p);
//initialisation de tabLignes et tabMax
void initTabsMM(Minmax* m);
//initialisation de Minmax
void initMinMax(Minmax* m, Puissance* p);

//copie tab de Puissance dans le tab du Puissance de Minmax
void updateTabPuissanceMM(Minmax* m, Puissance* p);
//met à jour tabLignes en fonction de l'état de la grille de jeu
void updateTabLignes(Minmax* m);
//met à jour tabMax en fonction de l'état de la grille de jeu
void updateTabMax(Minmax* m, Puissance* p, char symbole);

//retourne la colonne si un puissance peut être joué dès ce tour, sinon 0
unsigned int puissanceMM(Minmax* m, Puissance *p, char symbole);

//calcule la valeur de max
unsigned int compteMax(Minmax* m, Puissance* p, char symbole, unsigned int colonne);
//retourne 1 si un puissance est possible horizontalement pour une position de départ donnée
unsigned int testLigneMM(Minmax* m, char symbole, unsigned int ligne, unsigned int colonne);
//retourne 1 si un puissance est possible verticalement pour une position de départ donnée
unsigned int testColonneMM(Minmax* m, char symbole, unsigned int ligne, unsigned int colonne);
//retourne 1 si un puissance est possible en diagonale haut gauche pour une position de départ donnée
unsigned int testDiag1MM(Minmax* m, char symbole, unsigned int ligne, unsigned int colonne);
//retourne 1 si un puissance est possible en diagonale haut droit pour une position de départ donnée
unsigned int testDiag2MM(Minmax* m, char symbole, unsigned int ligne, unsigned int colonne);

//incrémente la valeur de compte à chaque fois qu'un puissance est possible horizontalement
void puissanceHoriMM(Minmax* m, char symbole, int ligne, int colonne, unsigned int* compte);
//incrémente la valeur de compte à chaque fois qu'un puissance est possible verticalement
void puissanceVertiMM(Minmax* m, char symbole, int ligne, int colonne, unsigned int* compte);
//incrémente la valeur de compte à chaque fois qu'un puissance est possible en diagonale haut gauche
void puissanceDiag1MM(Minmax* m, char symbole, int ligne, int colonne, unsigned int* compte);
//incrémente la valeur de compte à chaque fois qu'un puissance est possible en diagonale haut droit
void puissanceDiag2MM(Minmax* m, char symbole, int ligne, int colonne, unsigned int* compte);

//retourne l'indice de la case ayant la plus grande valeur
unsigned int plusGrand(Minmax* m);

//retourne la case que l'ordinateur doit jouer
unsigned int choixColonneMM(Minmax* m, Puissance* p, char symbole);
//place le jeton de l'ordinateur dans la colonne de la grille de jeu
void placeCoupMM(Minmax* m, Puissance* p, unsigned int colonne, char symbole);

#endif // MINMAX_H_INCLUDED
