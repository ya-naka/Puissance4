#ifndef PUISSANCE_H_INCLUDED
#define PUISSANCE_H_INCLUDED

struct Puissance{
    char *tab;
    unsigned int nbLignes, nbColonnes;
    unsigned int gagne;
    char recPartie;
};

//d�finit le nombre de lignes de la grille de jeu
void setNbLignes(Puissance*, unsigned int nbLignes);
//retourne le nombre de lignes de la grille de jeu
unsigned int getNbLignes(const Puissance*);
//d�finit le nombre de colonnes de la grille de jeu
void setNbColonnes(Puissance*, unsigned int nbColonnes);
//retourne le nombre de colonnes de la grille de jeu
unsigned int getNbColonnes(const Puissance*);
//d�finit le statut de la partie, 1 si un puissance est d�tect� sinon 0
void setGagne(Puissance*, unsigned int gagne);
//retourne le statut de la partie
unsigned int getGagne(const Puissance*);
//d�finit une valeur selon si le joueur veut recommencer une partie, 'o' ou 'O' pour recommencer
void setRecPartie(Puissance*, char recommence);
//retourne recPartie
char getRecPartie(const Puissance*);
//demande au joueur de choisir la taille de la grille et initialise nbLignes et nbColonnes
void setDimensionGrille(Puissance*);
//d�finit la valeur d'une case de la grille selon la ligne et la colonne
void setTabXY(Puissance*, unsigned int ligne, unsigned int colonne, char symbole);
//retourne la valeur d'une case de la grille selon la ligne et la colonne
char getTabXY(const Puissance*, unsigned int ligne, unsigned int colonne);

//initialise la grille de jeu
void initTab(Puissance*);
//initialise l'objet Puissance
void initPuissance(Puissance*);

//convertit un indice de la forme ligne-colonne en indice r�el du tableau
unsigned int xy2i(const Puissance*, unsigned int ligne, unsigned int colonne);
//convertit l'indice r�el du tableau en indice ligne-colonne
void i2xy(const Puissance*, unsigned int i, unsigned int* ligne, unsigned int* colonne);

//convertit l'affichage de la grille en une cha�ne de caract�res
char* toString(const Puissance*);
//affiche la grille de jeu
void afficheGrille(const Puissance*);
/*affiche un message au joueur :
    's' s�lection d'une colonne
	'l' s�lection du nombre de lignes de la grille
	'c' s�lection du nombre de colonnes de la grille
	'v' erreur chiffre invalide
	'r' erreur colonne remplie
	'p' tableau rempli, fin de partie
	'm' s�lection mode de jeu */
void afficheMessage(char typeInstruction);

//teste toutes les possibilit�s de puissance, retourne 1 si un puissance est trouv�
unsigned int puissance4(const Puissance*, char symbole, unsigned int ligne, unsigned int colonne);
//recherche d'un puissance verticalement dans une colonne donn�e
unsigned int puissanceVert(const Puissance*, char symbole, unsigned int colonne);
//recherche d'un puissance horizontalement sur une ligne donn�e
unsigned int puissanceHori(const Puissance*, char symbole, unsigned int ligne);
//recherche d'un puissance sur toutes les diagonales, d'au moins 4 cases, partant du haut gauche
unsigned int puissanceDiag1(const Puissance*, char symbole);
//recherche d'un puissance sur toutes les diagonales, d'au moins 4 cases, partant du haut droit
unsigned int puissanceDiag2(const Puissance*, char symbole);

//retourne le nombre de fois o� le symbole est pr�sent dans une colonne donn�e
unsigned int sommePointsVert(const Puissance*, unsigned int colonne, char symbole);
//retourne le nombre de fois o� le symbole est pr�sent sur une ligne donn�e
unsigned int sommePointsHori(const Puissance*, unsigned int ligne, char symbole);
//retourne 4 si au moins 4 symboles ont �t� trouv�s dans au moins une diagonale haut gauche
unsigned int sommePointsDiag1(const Puissance*, char symbole);
//retourne 4 si au moins 4 symboles ont �t� trouv�s dans au moins une diagonale haut droit
unsigned int sommePointsDiag2(const Puissance*, char symbole);
// le nombre de fois o� le symbole est pr�sent dans une diagonale haut gauche donn�e
unsigned int calculSommePointsDiag1(const Puissance*, char symbole, unsigned int ligne, unsigned int colonne);
// le nombre de fois o� le symbole est pr�sent dans une diagonale haut droit donn�e
unsigned int calculSommePointsDiag2(const Puissance*, char symbole, unsigned int ligne, unsigned int colonne);

//retourne 1 si le symbole est pr�sent dans 4 cases adjacentes � l'horizontale, � partir de la position colonne
unsigned int testLigne(const Puissance*, char symbole, unsigned int colonne, unsigned int ligne);
//retourne 1 si le symbole est pr�sent dans 4 cases adjacentes � la verticale, � partir de la position ligne
unsigned int testColonne(const Puissance*, char symbole, unsigned int colonne, unsigned int ligne);
//retourne 1 si le symbole est pr�sent dans 4 cases successives sur la diagonale haut gauche, � partir de la position ligne colonne
unsigned int testDiag1(const Puissance*, char symbole, unsigned int ligne, unsigned int colonne);
//retourne 1 si le symbole est pr�sent dans 4 cases successives sur la diagonale haut droit, � partir de la position ligne colonne
unsigned int testDiag2(const Puissance*, char symbole, unsigned int ligne, unsigned int colonne);

//retourne 1 si la saisie du joueur est valide
unsigned int coupCorrect(const Puissance*, int colonne);
//retourne 1 si la saisie du joueur est comprise entre 1 et nbColonnes
unsigned int verifSaisie(const Puissance*, unsigned int colonne);
//retourne 1 si une case est disponible dans une colonne donn�e
unsigned int caseDisponible(const Puissance*, unsigned int colonne);
//retourne 1 si toutes les cases du tableau sont remplies
unsigned int tableauPlein(const Puissance*);
//retourne la premiere ligne disponible pour une colonne donn�e, sinon 0
unsigned int chercheLignes(Puissance* p, int colonne);
//place le jeton sur la bonne ligne, retourne la ligne
unsigned int placeCoup(Puissance*, char symbole, int colonne);
//retourne 1 si une partie est termin�e
unsigned int partieTerminee(const Puissance*);
//saisie pour refaire une partie
void saisieRecPartie(Puissance*);
//saisie choix du mode de jeu
void saisieModeJeu(char *choix);

//initialisation personnalis�e de Puissance pour les tests
void initPuissanceTest(Puissance*);

#endif // PUISSANCE_H_INCLUDED
