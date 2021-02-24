#ifndef PUISSANCE_H_INCLUDED
#define PUISSANCE_H_INCLUDED

struct Puissance{
    char *tab;
    unsigned int nbLignes, nbColonnes;
    unsigned int gagne;
    char recPartie;
};

//définit le nombre de lignes de la grille de jeu
void setNbLignes(Puissance*, unsigned int nbLignes);
//retourne le nombre de lignes de la grille de jeu
unsigned int getNbLignes(const Puissance*);
//définit le nombre de colonnes de la grille de jeu
void setNbColonnes(Puissance*, unsigned int nbColonnes);
//retourne le nombre de colonnes de la grille de jeu
unsigned int getNbColonnes(const Puissance*);
//définit le statut de la partie, 1 si un puissance est détecté sinon 0
void setGagne(Puissance*, unsigned int gagne);
//retourne le statut de la partie
unsigned int getGagne(const Puissance*);
//définit une valeur selon si le joueur veut recommencer une partie, 'o' ou 'O' pour recommencer
void setRecPartie(Puissance*, char recommence);
//retourne recPartie
char getRecPartie(const Puissance*);
//demande au joueur de choisir la taille de la grille et initialise nbLignes et nbColonnes
void setDimensionGrille(Puissance*);
//définit la valeur d'une case de la grille selon la ligne et la colonne
void setTabXY(Puissance*, unsigned int ligne, unsigned int colonne, char symbole);
//retourne la valeur d'une case de la grille selon la ligne et la colonne
char getTabXY(const Puissance*, unsigned int ligne, unsigned int colonne);

//initialise la grille de jeu
void initTab(Puissance*);
//initialise l'objet Puissance
void initPuissance(Puissance*);

//convertit un indice de la forme ligne-colonne en indice réel du tableau
unsigned int xy2i(const Puissance*, unsigned int ligne, unsigned int colonne);
//convertit l'indice réel du tableau en indice ligne-colonne
void i2xy(const Puissance*, unsigned int i, unsigned int* ligne, unsigned int* colonne);

//convertit l'affichage de la grille en une chaîne de caractères
char* toString(const Puissance*);
//affiche la grille de jeu
void afficheGrille(const Puissance*);
/*affiche un message au joueur :
    's' sélection d'une colonne
	'l' sélection du nombre de lignes de la grille
	'c' sélection du nombre de colonnes de la grille
	'v' erreur chiffre invalide
	'r' erreur colonne remplie
	'p' tableau rempli, fin de partie
	'm' sélection mode de jeu */
void afficheMessage(char typeInstruction);

//teste toutes les possibilités de puissance, retourne 1 si un puissance est trouvé
unsigned int puissance4(const Puissance*, char symbole, unsigned int ligne, unsigned int colonne);
//recherche d'un puissance verticalement dans une colonne donnée
unsigned int puissanceVert(const Puissance*, char symbole, unsigned int colonne);
//recherche d'un puissance horizontalement sur une ligne donnée
unsigned int puissanceHori(const Puissance*, char symbole, unsigned int ligne);
//recherche d'un puissance sur toutes les diagonales, d'au moins 4 cases, partant du haut gauche
unsigned int puissanceDiag1(const Puissance*, char symbole);
//recherche d'un puissance sur toutes les diagonales, d'au moins 4 cases, partant du haut droit
unsigned int puissanceDiag2(const Puissance*, char symbole);

//retourne le nombre de fois où le symbole est présent dans une colonne donnée
unsigned int sommePointsVert(const Puissance*, unsigned int colonne, char symbole);
//retourne le nombre de fois où le symbole est présent sur une ligne donnée
unsigned int sommePointsHori(const Puissance*, unsigned int ligne, char symbole);
//retourne 4 si au moins 4 symboles ont été trouvés dans au moins une diagonale haut gauche
unsigned int sommePointsDiag1(const Puissance*, char symbole);
//retourne 4 si au moins 4 symboles ont été trouvés dans au moins une diagonale haut droit
unsigned int sommePointsDiag2(const Puissance*, char symbole);
// le nombre de fois où le symbole est présent dans une diagonale haut gauche donnée
unsigned int calculSommePointsDiag1(const Puissance*, char symbole, unsigned int ligne, unsigned int colonne);
// le nombre de fois où le symbole est présent dans une diagonale haut droit donnée
unsigned int calculSommePointsDiag2(const Puissance*, char symbole, unsigned int ligne, unsigned int colonne);

//retourne 1 si le symbole est présent dans 4 cases adjacentes à l'horizontale, à partir de la position colonne
unsigned int testLigne(const Puissance*, char symbole, unsigned int colonne, unsigned int ligne);
//retourne 1 si le symbole est présent dans 4 cases adjacentes à la verticale, à partir de la position ligne
unsigned int testColonne(const Puissance*, char symbole, unsigned int colonne, unsigned int ligne);
//retourne 1 si le symbole est présent dans 4 cases successives sur la diagonale haut gauche, à partir de la position ligne colonne
unsigned int testDiag1(const Puissance*, char symbole, unsigned int ligne, unsigned int colonne);
//retourne 1 si le symbole est présent dans 4 cases successives sur la diagonale haut droit, à partir de la position ligne colonne
unsigned int testDiag2(const Puissance*, char symbole, unsigned int ligne, unsigned int colonne);

//retourne 1 si la saisie du joueur est valide
unsigned int coupCorrect(const Puissance*, int colonne);
//retourne 1 si la saisie du joueur est comprise entre 1 et nbColonnes
unsigned int verifSaisie(const Puissance*, unsigned int colonne);
//retourne 1 si une case est disponible dans une colonne donnée
unsigned int caseDisponible(const Puissance*, unsigned int colonne);
//retourne 1 si toutes les cases du tableau sont remplies
unsigned int tableauPlein(const Puissance*);
//retourne la premiere ligne disponible pour une colonne donnée, sinon 0
unsigned int chercheLignes(Puissance* p, int colonne);
//place le jeton sur la bonne ligne, retourne la ligne
unsigned int placeCoup(Puissance*, char symbole, int colonne);
//retourne 1 si une partie est terminée
unsigned int partieTerminee(const Puissance*);
//saisie pour refaire une partie
void saisieRecPartie(Puissance*);
//saisie choix du mode de jeu
void saisieModeJeu(char *choix);

//initialisation personnalisée de Puissance pour les tests
void initPuissanceTest(Puissance*);

#endif // PUISSANCE_H_INCLUDED
