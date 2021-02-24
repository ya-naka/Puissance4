#include <stdio.h>
#include <string.h>

#include "minmaxTest.h"
#include "unittest.h"

void minmaxTest(Minmax* m, Puissance* p){
    initPuissance(p);
    initMinMax(m, p);

    //tests setTabLignes
    setTabLignes(m, 4u, 0);
    setTabLignes(m, 6u, 1);
    setTabLignes(m, 5u, getNbColonnes(p)-1);
    assertEquals(4u, m->tabLignes[0], "setTabLignes(m, 4u, 0)");
    assertEquals(6u, m->tabLignes[1], "setTabLignes(m, 6u, 1)");
    assertEquals(5u, m->tabLignes[getNbColonnes(p)-1], "setTabLignes(m, 5u, getNbColonnes(p)-1)");

    //tests getTabLignes
    assertEquals(4u, getTabLignes(m, 0), "getTabLignes(m, 0)");
    assertEquals(6u, getTabLignes(m, 1), "getTabLignes(m, 1)");
    assertEquals(5u, getTabLignes(m, getNbColonnes(p)-1), "getTabLignes(m, getColonnes(p)-1)");

    //tests updateTabPuissanceMM
    setTabXY(p, 1, 1, 'X');
    updateTabPuissanceMM(m, p);
    assertEquals('X', getTabXY(p, 1, 1), "updateTabPuissance 1");

    setTabXY(p, 3, 4, 'O');
    updateTabPuissanceMM(m, p);
    assertEquals('O', getTabXY(p, 3, 4), "updateTabPuissance 2");

    setTabXY(p, 5, 6, 'a');
    updateTabPuissanceMM(m, p);
    assertEquals('a', getTabXY(p, 5, 6), "updateTabPuissance 3");

    //tests updateTabLignes
    initTab(p);
    updateTabPuissanceMM(m, p);
    updateTabLignes(m);
    assertEquals(5u, getTabLignes(m, 0), "updateTabLignes 1");

    setTabXY(p, 5, 1, 'X');
    updateTabPuissanceMM(m, p);
    updateTabLignes(m);
    assertEquals(4u, getTabLignes(m, 0), "updateTabLignes 2");

    //tests updateTabMax
    initTab(p);
    updateTabPuissanceMM(m, p);
    updateTabLignes(m);
    updateTabMax(m, p, 'X');
    assertEquals(3u, getTabMax(m, 0), "getTabMax(m, p, 'X')");
    assertEquals(4u, getTabMax(m, 1), "getTabMax(m, p, 'X')");
    assertEquals(5u, getTabMax(m, 2), "getTabMax(m, p, 'X')");
    assertEquals(5u, getTabMax(m, 3), "getTabMax(m, p, 'X')");
    assertEquals(4u, getTabMax(m, 4), "getTabMax(m, p, 'X')");
    assertEquals(3u, getTabMax(m, 5), "getTabMax(m, p, 'X')");

    //test choixColonne
    assertEquals(3u, choixColonneMM(m, p, 'X'), "choixColonneMM(m, p, 'X')");
}


