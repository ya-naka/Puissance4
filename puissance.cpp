#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include "puissance.h"

void setNbLignes(Puissance* p, unsigned int nbLignes){
    p->nbLignes = nbLignes;
}

unsigned int getNbLignes(const Puissance* p){
    return p->nbLignes;
}

void setNbColonnes(Puissance* p, unsigned int nbColonnes){
    p->nbColonnes = nbColonnes;
}

unsigned int getNbColonnes(const Puissance* p){
    return p->nbColonnes;
}

void setGagne(Puissance* p, unsigned int gagne){
    p->gagne = gagne;
}

unsigned int getGagne(const Puissance* p){
    return p->gagne;
}

void setRecPartie(Puissance* p, char recommence){
    p->recPartie = recommence;
}

char getRecPartie(const Puissance* p){
    return p->recPartie;
}

void setDimensionGrille(Puissance* p){
    unsigned int nbColonnes, nbLignes;
    afficheMessage('c');
    fflush(stdout);
    scanf("%d", &nbColonnes);
    afficheMessage('l');
    fflush(stdout);
    scanf("%d", &nbLignes);
    setNbColonnes(p, nbColonnes);
    setNbLignes(p, nbLignes);
}

void initTab(Puissance* p){
    for(unsigned int i = 0; i < (p->nbLignes * p->nbColonnes); ++i){
        p->tab[i] = '.';
    }
}

void initPuissance(Puissance* p){
    setDimensionGrille(p);
    setGagne(p, 0);
    setRecPartie(p, 'n');
    p->tab = (char*) malloc (getNbLignes(p) * getNbColonnes(p) * sizeof(char));
    initTab(p);
}

void setTabXY(Puissance* p, unsigned int ligne, unsigned int colonne, char symbole){
    unsigned int i = xy2i(p, ligne, colonne);
    p->tab[i] = symbole;
}

char getTabXY(const Puissance* p, unsigned int ligne, unsigned int colonne){
    return p->tab[xy2i(p, ligne, colonne)];
}

unsigned int xy2i(const Puissance* p, unsigned int ligne, unsigned int colonne){
    return (p->nbColonnes * (ligne-1)) + (colonne-1);
}

void i2xy (const Puissance* p, unsigned int i, unsigned int* ligne, unsigned int* colonne){
    *ligne = ((unsigned int)i/p->nbColonnes) + 1;
    *colonne = (i%p->nbColonnes)+1;
}

char* toString(const Puissance* p){
    unsigned int taille = 8*(getNbLignes(p)*getNbColonnes(p)) + 5*getNbLignes(p) + 9*getNbColonnes(p) + 15;
    unsigned int lgr = 0;
    char *s = (char*)malloc(taille+1);
    const char* sep = "\n";
    lgr += sprintf(s+lgr, "Puissance 4\n");
    for(unsigned int i = 1; i <= getNbLignes(p); ++i){
        lgr += sprintf(s+lgr ,"%s ", sep);
        for(unsigned int k = 1; k <= getNbColonnes(p); ++k){
            lgr += sprintf(s+lgr, "%s", " ---");
        }
        lgr += sprintf(s+lgr, "%s", sep);
        for(unsigned int j = 1; j <= getNbColonnes(p); ++j){
            lgr += sprintf(s+lgr, " | %c", getTabXY(p, i, j));
            if(j == getNbColonnes(p)){
                lgr+= sprintf(s+lgr, " |");
            }
        }
        if(i == getNbLignes(p)){
            lgr += sprintf(s+lgr, "%s ", sep);
            for(unsigned int k = 1; k <= getNbColonnes(p); ++k){
                lgr += sprintf(s+lgr, "%s", " ---");
            }
        }
    }

    lgr += sprintf(s+lgr, "%s", sep);
        for(unsigned int i = 1; i <= getNbColonnes(p); ++i){
                if(i <= 10){
                    lgr += sprintf(s+lgr, "   %i", i);
                }else{
                    lgr += sprintf(s+lgr, "  %i", i);
                }
        }
    return s;
}

void afficheGrille(const Puissance* p){
    system("cls");
    printf("%s", toString(p));
}

void afficheMessage(char typeInstruction){
    switch(typeInstruction){
        case 's':
            printf("\n\nS%clectionnez une colonne : ", 130);
            break;
        case 'l':
            printf("Choisissez le nombre de lignes de la grille : ");
            break;
        case 'c':
            printf("Choisissez le nombre de colonnes de la grille : ");
            break;
        case 'v':
            printf("Veuillez s%clectionner un chiffre valide.", 130);
            afficheMessage('s');
            break;
        case 'r' :
            printf("La colonne s%clectionn%ce est remplie.", 130, 130);
            afficheMessage('s');
            break;
        case 'p':
            printf("\nToutes les colonnes du tableau sont remplies.\nPartie termin%ce.\n", 130);
            break;
        case 'm':
            printf("\nVoulez-vous jouer contre l'ordinateur ? (O/N) ");
            break;
    }
}

unsigned int puissance4(const Puissance* p, char symbole, unsigned int ligne, unsigned int colonne){
    if(!puissanceHori(p, symbole, ligne)){
        if(!puissanceVert(p, symbole, colonne)){
            if(!puissanceDiag1(p, symbole)){
                return puissanceDiag2(p, symbole);
            }
        }
    }
    return 1;
}

unsigned int puissanceVert(const Puissance* p, char symbole, unsigned int colonne){
    if(sommePointsVert(p, colonne, symbole) >= 4){
        for(unsigned int i = getNbLignes(p)-3; i >= 1; --i){
            if(testColonne(p, symbole, i, colonne)){
                return 1;
            }
        }
    }
    return 0;
}

unsigned int puissanceHori(const Puissance* p, char symbole, unsigned int ligne){
    if(sommePointsHori(p, ligne, symbole) >= 4){
        for(unsigned int i = getNbColonnes(p)-3; i >= 1; --i){
            if(testLigne(p, symbole, ligne, i)){
                return 1;
            }
        }
    }
    return 0;
}

unsigned int puissanceDiag1(const Puissance* p, char symbole){
    if(sommePointsDiag1(p, symbole) >= 4){
        for(unsigned int i = 1; i <= getNbLignes(p)-3; ++i){
            for(unsigned int j = 1; j <= getNbColonnes(p)-3; ++j){
                if(testDiag1(p, symbole, i, j)){
                    return 1;
                }
            }
        }
    }
    return 0;
}

unsigned int puissanceDiag2(const Puissance* p, char symbole){
    if(sommePointsDiag2(p, symbole) >= 4){
        for(unsigned int i = 1; i <= getNbLignes(p)-3; ++i){
            for(unsigned int j = getNbColonnes(p); j >= 4; --j){
                if(testDiag2(p, symbole, i, j)){
                    return 1;
                }
            }
        }
    }
    return 0;
}

unsigned int sommePointsVert(const Puissance* p, unsigned int colonne, char symbole){
    unsigned int sommePoints = 0;

    if(getNbLignes(p) >= 4){
        for(unsigned int i = 1; i <= getNbLignes(p); ++i){
            if(getTabXY(p, i, colonne) == symbole){
                ++sommePoints;
            }
        }
    }
    return sommePoints;
}

unsigned int sommePointsHori(const Puissance* p, unsigned int ligne, char symbole){
    unsigned int sommePoints = 0;

    if(getNbColonnes(p) >= 4){
        for(unsigned int i = 1; i <= getNbColonnes(p); ++i){
            if(getTabXY(p, ligne, i) == symbole){
                ++sommePoints;
            }
        }
    }
    return sommePoints;
}

unsigned int sommePointsDiag1(const Puissance* p, char symbole){
    unsigned int sommePoints;

    for(unsigned int i = 1; i <= getNbLignes(p)-3; ++i){
        sommePoints = 0;
        if(i == 1){
            for(unsigned int j = 1; j <= getNbColonnes(p)-3; ++j){
                sommePoints = calculSommePointsDiag1(p, symbole, i,j);
                if(sommePoints >= 4){
                    return sommePoints;
                }
            }
        }else{
            sommePoints = calculSommePointsDiag1(p, symbole, i, 1);
            if(sommePoints >= 4){
                return sommePoints;
            }
        }
    }
    return sommePoints;
}

unsigned int sommePointsDiag2(const Puissance* p, char symbole){
    unsigned int sommePoints;

    for(unsigned int i = 1; i <= getNbLignes(p)-3; ++i){
        sommePoints = 0;
        if(i == 1){
            for(unsigned int j = getNbColonnes(p); j >= 4; --j){
                sommePoints = calculSommePointsDiag2(p, symbole, i,j);
                if(sommePoints >= 4){
                    return sommePoints;
                }
            }
        }else{
            sommePoints = calculSommePointsDiag2(p, symbole, i, getNbColonnes(p));
            if(sommePoints >= 4){
                return sommePoints;
            }
        }
    }
    return sommePoints;
}

unsigned int calculSommePointsDiag1(const Puissance* p, char symbole, unsigned int ligne, unsigned int colonne){
    unsigned int sommePoints = 0;
    unsigned int j = colonne;
    for(unsigned int i = ligne; i <= getNbLignes(p) && j <= getNbColonnes(p); ++i){
        if(getTabXY(p, i, j) == symbole){
            ++sommePoints;
        }
        ++j;
    }
    return sommePoints;
}

unsigned int calculSommePointsDiag2(const Puissance* p, char symbole, unsigned int ligne, unsigned int colonne){
    unsigned int sommePoints = 0;
    unsigned int j = colonne;
    for(unsigned int i = ligne; i <= getNbLignes(p) && j >= 1; ++i){
        if(getTabXY(p, i, j) == symbole){
            ++sommePoints;
        }
        --j;
    }
    return sommePoints;
}

unsigned int testLigne(const Puissance* p, char symbole, unsigned int ligne, unsigned int colonne){
    for(unsigned int i = colonne; i < colonne+4; ++i){
        if(getTabXY(p, ligne, i) != symbole){
            return 0;
        }
    }
    return 1;
}

unsigned int testColonne(const Puissance* p, char symbole, unsigned int ligne, unsigned int colonne){
    for(unsigned int i = ligne; i < ligne+4; ++i){
      if(getTabXY(p, i, colonne) != symbole){
         return 0;
      }
   }
   return 1;
}

unsigned int testDiag1(const Puissance* p, char symbole, unsigned int ligne, unsigned int colonne){
    unsigned int j = colonne;
    for(unsigned int i = ligne; i < ligne+4; ++i){
        if(getTabXY(p, i, j) != symbole){
            return 0;
        }
        ++j;
    }
    return 1;
}
unsigned int testDiag2(const Puissance* p, char symbole, unsigned int ligne, unsigned int colonne){
    unsigned int j = colonne;
    for(unsigned int i = ligne; i < ligne+4; ++i){
        if(getTabXY(p, i, j) != symbole){
            return 0;
        }
        --j;
    }
    return 1;
}

unsigned int coupCorrect(const Puissance* p, int colonne){
    if(!verifSaisie(p, colonne)){
        afficheMessage('v');
        return 0;
    }else{
        if(!caseDisponible(p, colonne)){
            afficheMessage('r');
            return 0;
        }
    }
    return 1;
}

unsigned int verifSaisie(const Puissance* p, unsigned int colonne){
    for(unsigned int i = 1; i <= getNbColonnes(p); ++i){
        if(colonne == i){
            return 1;
        }
    }
    return 0;
}

unsigned int caseDisponible(const Puissance* p, unsigned int colonne){
    for(unsigned int i = 1; i <= getNbColonnes(p); ++i){
        if(getTabXY(p, i, colonne) == '.'){
            return 1;
        }
    }
    return 0;
}

unsigned int tableauPlein(const Puissance* p){
    for(unsigned int i = 1; i <= getNbColonnes(p); ++i){
        if(caseDisponible(p, i)){
            return 0;
        }
    }
    return 1;
}

unsigned int chercheLignes(Puissance* p, int colonne){
    for(unsigned int i = getNbLignes(p); i >= 1; --i){
        if(getTabXY(p, i, colonne) == '.'){
            return i;
        }
    }
    return 0;
}

unsigned int placeCoup(Puissance* p, char symbole, int colonne){
    unsigned int ligne = chercheLignes(p, colonne);
    if(ligne){
        setTabXY(p, ligne, colonne, symbole);
    }
    return ligne;
}

unsigned int partieTerminee(const Puissance* p){
    if(getGagne(p)){
        return 1;
    }else if(tableauPlein(p)){
        return 1;
    }
    return 0;
}

void saisieRecPartie(Puissance* p){
    char saisie;
    printf("\nVoulez-vous refaire une partie ? (O/N) ");
    fflush(stdout);
    scanf(" %c", &saisie);
    setRecPartie(p, saisie);
}

void saisieModeJeu(char *choix){
    afficheMessage('m');
    fflush(stdout);
    scanf("%c", choix);
}

void initPuissanceTest(Puissance* p){
    setNbColonnes(p, 7);
    setNbLignes(p, 6);
    setGagne(p, 0);
    setRecPartie(p, 'n');
    p->tab = (char*) malloc (p->nbLignes * p->nbColonnes * sizeof(char));
    initTab(p);
}
