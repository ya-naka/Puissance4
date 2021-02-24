#include <malloc.h>
#include "minmax.h"

void setTabLignes(Minmax* m, unsigned int ligne, unsigned int colonne){
    m->tabLignes[colonne] = ligne;
}

unsigned int getTabLignes(Minmax* m, unsigned colonne){
    return m->tabLignes[colonne];
}

void setTabMax(Minmax* m, unsigned int colonne, unsigned int valeur){
    m->tabMax[colonne] = valeur;
}

unsigned int getTabMax(Minmax* m, unsigned int colonne){
    return m->tabMax[colonne];
}

void initPuissanceMM(Minmax* m, Puissance* p){
    (m->p).nbColonnes = getNbColonnes(p);
    (m->p).nbLignes = getNbLignes(p);
    (m->p).gagne = getGagne(p);
    (m->p).recPartie = getRecPartie(p);
    (m->p).tab = (char*) malloc (getNbColonnes(&(m->p)) * getNbLignes(&(m->p)) * sizeof(char));
    updateTabPuissanceMM(m, p);
}

void initTabsMM(Minmax* m){
    m->tabLignes = (unsigned int*) malloc (getNbColonnes(&(m->p)) * sizeof(unsigned int));
    m->tabMax = (unsigned int*) malloc (getNbColonnes(&(m->p)) * sizeof(unsigned int));

    for(unsigned int i = 0; i < getNbColonnes(&(m->p)); ++i){
        m->tabLignes[i] = 0;
        m->tabMax[i] = 0;
    }
}

void initMinMax(Minmax* m, Puissance* p){
    initPuissanceMM(m, p);
    initTabsMM(m);
}

void updateTabPuissanceMM(Minmax* m, Puissance* p){
    for(unsigned int i = 1; i <= getNbLignes(p); ++i){
        for(unsigned int j = 1; j <= getNbColonnes(p); ++j){
            setTabXY(&(m->p), i, j, getTabXY(p, i, j));
        }
    }
}

void updateTabLignes(Minmax* m){
    for(unsigned int i = 0; i < getNbColonnes(&(m->p)); ++i){
        setTabLignes(m, chercheLignes(&(m->p), i+1), i);
    }
}

void updateTabMax(Minmax* m, Puissance* p, char symbole){
    for(unsigned int i = 1; i <= getNbColonnes(&(m->p)); ++i){
        setTabMax(m, i-1, compteMax(m, p, symbole, i));
    }
}

unsigned int puissanceMM(Minmax* m, Puissance *p, char symbole){
    if(getNbColonnes(&(m->p)) >= 4 && getNbLignes(&(m->p)) >= 4){
        for(unsigned int i = 1; i <= getNbColonnes(&(m->p)); ++i){
            if(getTabLignes(m, i-1)){
                setTabXY(&(m->p), getTabLignes(m, i-1), i, symbole);
                if(puissance4(&(m->p), symbole, getTabLignes(m, i-1), i)){
                    return i;
                }
            }
            updateTabPuissanceMM(m, p);
        }
    }
    return 0;
}

unsigned int compteMax(Minmax* m, Puissance* p, char symbole, unsigned int colonne){
    unsigned int compte = 0;
    if(getTabLignes(m, colonne-1)){
        updateTabPuissanceMM(m, p);
        setTabXY(&(m->p), getTabLignes(m, colonne-1), colonne, symbole);
        puissanceHoriMM(m, symbole, getTabLignes(m, colonne-1), colonne, &compte);
        puissanceVertiMM(m, symbole, getTabLignes(m, colonne-1), colonne, &compte);
        puissanceDiag1MM(m, symbole, getTabLignes(m, colonne-1), colonne, &compte);
        puissanceDiag2MM(m, symbole, getTabLignes(m, colonne-1), colonne, &compte);

    }
    return compte;
}

unsigned int testLigneMM(Minmax* m, char symbole, unsigned int ligne, unsigned int colonne){
    for(unsigned int i = colonne; i < colonne+4; ++i){
        if(getTabXY(&(m->p), ligne, i) != symbole && getTabXY(&(m->p), ligne, i) != '.'){
            return 0;
        }
    }
    return 1;
}

unsigned int testColonneMM(Minmax* m, char symbole, unsigned int ligne, unsigned int colonne){
    for(unsigned int i = ligne; i < ligne+4; ++i){
      if(getTabXY(&(m->p), i, colonne) != symbole && getTabXY(&(m->p), i, colonne) != '.'){
         return 0;
      }
   }
   return 1;
}

unsigned int testDiag1MM(Minmax* m, char symbole, unsigned int ligne, unsigned int colonne){
    unsigned int j = colonne;
    for(unsigned int i = ligne; i < ligne+4; ++i){
        if(getTabXY(&(m->p), i, j) != symbole && getTabXY(&(m->p), i, j) != '.'){
            return 0;
        }
        ++j;
    }
    return 1;
}

unsigned int testDiag2MM(Minmax* m, char symbole, unsigned int ligne, unsigned int colonne){
    unsigned int j = colonne;
    for(unsigned int i = ligne; i < ligne+4; ++i){
        if(getTabXY(&(m->p), i, j) != symbole && getTabXY(&(m->p), i, j) != '.'){
            return 0;
        }
        --j;
    }
    return 1;
}

void puissanceHoriMM(Minmax* m, char symbole, int ligne, int colonne, unsigned int* compte){
    for(int i = -3; i + colonne <= colonne; ++i){
        if(i+colonne >= 1 && i+colonne <= (int)getNbColonnes(&(m->p))-3 && testLigneMM(m, symbole, ligne, i+colonne)){
            ++(*compte);
        }
    }
}

void puissanceVertiMM(Minmax* m, char symbole, int ligne, int colonne, unsigned int* compte){
    for(int i = -3; i+ligne <= ligne; ++i){
        if(i+ligne >= 1 && i+ligne <= (int)getNbLignes(&(m->p))-3 && testColonneMM(m, symbole, i+ligne, colonne)){
            ++(*compte);
        }
    }
}

void puissanceDiag1MM(Minmax* m, char symbole, int ligne, int colonne, unsigned int* compte){
    for(int i = -3; i + colonne <= colonne && i + ligne <= ligne; ++i){
        if(i+colonne <= (int)getNbColonnes(&(m->p))-3 && i+ligne <= (int)getNbLignes(&(m->p))-3){
            if(i+colonne >= 1 && i+ligne >= 1 && testDiag1MM(m, symbole, i+ligne, i+colonne)){
                ++(*compte);
            }
        }
    }
}

void puissanceDiag2MM(Minmax* m, char symbole, int ligne, int colonne, unsigned int* compte){
    for(int i = 3; i >= 0; --i){
        if(ligne-i <= (int)getNbLignes(&(m->p))-3 && colonne+i >= 4){
            if(colonne+i <= (int)getNbColonnes(&(m->p)) && ligne-i >= 1){
                ++(*compte);
            }
        }
    }
}

unsigned int plusGrand(Minmax* m){
    unsigned int pg = 0;
    unsigned int j = 0;
    for(unsigned int i = 0; i < getNbColonnes(&(m->p)); ++i){
        if(getTabMax(m, i) > pg){
            pg = getTabMax(m, i);
            j = i;
        }
    }
    return j+1;
}

unsigned int choixColonneMM(Minmax* m, Puissance* p, char symbole){
    updateTabMax(m, p, symbole);
    return plusGrand(m);
}

void placeCoupMM(Minmax* m, Puissance* p, unsigned int colonne, char symbole){
    unsigned int colPuissance = puissanceMM(m, p, symbole);
    if(colPuissance){
        setTabXY(p, getTabLignes(m, colPuissance), colPuissance, symbole);
    }else{
        setTabXY(p, getTabLignes(m, colonne-1), colonne, symbole);
    }
}

