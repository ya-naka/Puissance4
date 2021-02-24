#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

struct Joueur{
    char* nom;
    char symbole;
    unsigned int colonneChoisie;
    unsigned int joue; //1 si c'est le tour du joueur, 0 sinon
    unsigned int ligne;
    unsigned int estOrdinateur;
};

//définit le nom du joueur
void setNom(Joueur*, char* nom);
//retourne le nom du joueur
char* getNom(const Joueur*);
//définit le symbole du joueur
void setSymbole(Joueur*, char symbole);
//retourne le symbole du joueur
char getSymbole(const Joueur*);
//définit la colonne choisie par le joueur
void setColonneChoisie(Joueur*, unsigned int colonne);
//retourne la colonne choisie par le joueur
unsigned int getColonneChoisie(const Joueur *);
//définit si le joueur est en train de jouer
void setJoue(Joueur*, unsigned int joue);
//retourne 1 si le joueur est en train de jouer
unsigned int getJoue(const Joueur*);
//définit la ligne sur laquelle le jeton du joueur a été placé
void setLigne(Joueur*, unsigned int ligne);
//retourne la ligne sur laquelle le jeton du joueur a été placé
unsigned int getLigne(const Joueur*);
//définit si le joueur est un ordinateur
void setEstOrdinateur(Joueur* j, unsigned int valeur);
//retourne 1 si le joueur est un ordinateur
unsigned int getEstOrdinateur(const Joueur* j);
//retourne le joueur qui est en train de jouer
Joueur getJoueurActif(Joueur*, Joueur*);

//interchange la valeur de joue entre les deux joueurs
void changeJoueurActif(Joueur*, Joueur*);
//saisie du nom du joueur
char* saisieNom();

//initialisation de Joueur
void initJoueur(Joueur*, char symbole, unsigned int joue);
//initialisation de Joueur si c'est un ordinateur
void initOrdinateur(Joueur*, char symbole, unsigned int joue);

/*affiche un message au joueur :
    't' tour suivant
    's' sélection d'une colonne
    'g' joueur gagnant */
void afficheMessageJoueur(Joueur* j, char typeMessage);
//choix de la colonne par le joueur
void saisieCoup(Joueur*);

#endif // JOUEUR_H_INCLUDED
