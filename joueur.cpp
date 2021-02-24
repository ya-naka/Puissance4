#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "joueur.h"


void setNom(Joueur* joueur, char* nom){
    joueur->nom = nom;
}

char* getNom(const Joueur* joueur){
    return joueur->nom;
}

void setSymbole(Joueur* joueur, char symbole){
    joueur->symbole = symbole;
}

char getSymbole(const Joueur* joueur){
    return joueur->symbole;
}

void setColonneChoisie(Joueur* joueur, unsigned int colonne){
    joueur->colonneChoisie = colonne;
}

unsigned int getColonneChoisie(const Joueur * joueur){
    return joueur->colonneChoisie;
}

void setJoue(Joueur* joueur, unsigned int joue){
    joueur->joue = joue;
}

unsigned int getJoue(const Joueur* joueur){
    return joueur->joue;
}

void setLigne(Joueur* joueur, unsigned int ligne){
    joueur->ligne = ligne;
}

unsigned int getLigne(const Joueur* joueur){
    return joueur->ligne;
}

void setEstOrdinateur(Joueur* j, unsigned int valeur){
    j->estOrdinateur = valeur;
}

unsigned int getEstOrdinateur(const Joueur* j){
    return j->estOrdinateur;
}

Joueur getJoueurActif(Joueur* j1, Joueur* j2){
    if(getJoue(j1)){
        return *j1;
    }else{
        return *j2;
    }
}

void changeJoueurActif(Joueur* j1, Joueur* j2){
    setJoue(j1, !getJoue(j1));
    setJoue(j2, !getJoue(j2));
}

char* saisieNom(){
    printf("Saisissez le nom du joueur : ");
    char *nom = (char*)malloc(20*sizeof(char));
    fflush(stdout);
    scanf("%s", nom);
    return nom;
}

void initJoueur(Joueur* j, char symbole, unsigned int joue){
    setNom(j, saisieNom());
    setSymbole(j, symbole);
    setJoue(j, joue);
    setEstOrdinateur(j, 0);
}

void initOrdinateur(Joueur* j, char symbole, unsigned int joue){
    setNom(j, "Ordinateur");
    setSymbole(j, symbole);
    setJoue(j, joue);
    setEstOrdinateur(j, 1);
}

void afficheMessageJoueur(Joueur* j, char typeMessage){
    switch(typeMessage){
    case 't':
       printf("\n\nAu tour de %s.", getNom(j));
       afficheMessageJoueur(j, 's');
        break;
    case 's':
        printf("\nS%clectionnez une colonne : ", 130);
        break;
    case 'g':
        printf("\n\n%s a gagn%c !!", getNom(j), 130);
    }
}

void saisieCoup(Joueur* joueur){
    unsigned int colonne;
    fflush(stdout);
    scanf("%d", &colonne);
    setColonneChoisie(joueur, colonne);
}
