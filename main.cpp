#include <stdio.h>
#include "puissance.h"
#include "joueur.h"
#include "puissanceTest.h"
#include "minmax.h"
#include "minmaxTest.h"

int main()
{
    Minmax m;
    Puissance p;
    Joueur j1, j2, jActif;

    //minmaxTest(&m, &p);
    //puissanceTest();


    do{
        char choix;
        saisieModeJeu(&choix);

        initPuissance(&p);
        initMinMax(&m, &p);

        initJoueur(&j1, 'X', 1);
        if(choix == 'o' || choix =='O'){
            initOrdinateur(&j2, 'O', 0);
        }else{
            initJoueur(&j2, 'O', 0);
        }

        afficheGrille(&p);

        while(!getGagne(&p)){
            jActif = getJoueurActif(&j1, &j2);

            if(!getEstOrdinateur(&jActif)){
                afficheMessageJoueur(&jActif, 't');

                do{
                    saisieCoup(&jActif);
                }while(!coupCorrect(&p, getColonneChoisie(&jActif)));

                setLigne(&jActif, placeCoup(&p, getSymbole(&jActif), getColonneChoisie(&jActif)));

            }else{
                updateTabPuissanceMM(&m, &p);
                updateTabLignes(&m);
                setColonneChoisie(&j2, choixColonneMM(&m, &p, getSymbole(&jActif)));
                setLigne(&j2, getTabLignes(&m, getColonneChoisie(&j2)-1));
                placeCoupMM(&m, &p, getColonneChoisie(&j2), getSymbole(&jActif));
            }

            afficheGrille(&p);

            if(getNbColonnes(&p) >= 4 && getNbLignes(&p) >= 4){
                setGagne(&p, puissance4(&p, getSymbole(&jActif), getLigne(&jActif), getColonneChoisie(&jActif)));
            }

            if(partieTerminee(&p)){
                break;
            }

            changeJoueurActif(&j1, &j2);
        }

        if(getGagne(&p)){
            afficheMessageJoueur(&jActif, 'g');
        }else{
            afficheMessage('p');
        }

        saisieRecPartie(&p);
    }while(getRecPartie(&p) == 'o' || getRecPartie(&p) == 'O');

    return 0;
}
