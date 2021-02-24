#include "puissance.h"
#include "unittest.h"

void puissanceTest(){
    Puissance p;
    initPuissanceTest(&p);
    //teste la fonction setTabXY()
    printf("\ntest setTabXY\n");
    setTabXY(&p, 1,1, 'X');
    assertEquals('X', p.tab[0], "tab[0] = 'X'");
    setTabXY(&p, 1,1, 'O');
    assertEquals('O', p.tab[0], "tab[0] = 'O'");
    setTabXY(&p, 1,7, 'A');
    assertEquals('A', p.tab[6], "tab[6] = 'A'");
    setTabXY(&p, 5,5, 'B');
    assertEquals('B', p.tab[32], "tab[32] = 'B'");

    //teste la fonction xy2i()
    printf("\ntest xy2i\n");
    assertEquals(0u, xy2i(&p, 1, 1), "xy2i(1,1)");
    assertEquals(16u, xy2i(&p, 3,3), "xy2i(3,3)");
    assertEquals(41u, xy2i(&p, 6, 7), "xy2i(6,7)");

    //teste la fonction verifSaisie()
    printf("\ntest verifSaisie\n");
    assertTrue(verifSaisie(&p, 1), "verifSaisie(1)");
    assertFalse(verifSaisie(&p, 8), "verifSaisie(8)");
    assertTrue(verifSaisie(&p, 7), "verifSaisie(7)");

    //teste la fonction caseDisponible()
    printf("\ntest caseDisponible\n");
    initTab(&p);
    assertTrue(caseDisponible(&p, 1), "caseDisponible(1)");
    for(unsigned int i = 1; i <= getNbLignes(&p); ++i){
        setTabXY(&p, i, 1, 'X');
    }
    assertFalse(caseDisponible(&p, 1), "caseDisponible(1)");
    setTabXY(&p, getNbLignes(&p), 2, 'O');
    assertTrue(caseDisponible(&p, 2), "caseDisponible(2)");

    //teste la fonction coupCorrect
    printf("\ntest coupCourrect\n");
    assertFalse(coupCorrect(&p, 1), "coupCorrect(1)");
    assertTrue(coupCorrect(&p, 2), "coupCorrect(2)");
    assertFalse(coupCorrect(&p, 8), "coupCorrect(8)");

    //teste la fonction tableauPlein()
    printf("\ntest tableauPlein\n");
    assertFalse(tableauPlein(&p), "tableauPlein(p)");
    for(unsigned int i = 1; i <= getNbLignes(&p); ++i){
        for(unsigned int j = 1; j <= (unsigned int)getNbColonnes(&p); ++j){
            setTabXY(&p, i, j, 'X');
        }
    }
    assertTrue(tableauPlein(&p), "tableauPlein(p)");
    setTabXY(&p, 1, 1, '.');
    assertFalse(tableauPlein(&p), "tableauPlein(p)");

    //teste la fonction placeCoup()
    printf("\ntest placeCoup\n");
    setTabXY(&p, 1, 1, 'X');
    assertEquals(0u, placeCoup(&p, 'O', 1), "placeCoup('O', 1)");
    initTab(&p);
    assertEquals(getNbLignes(&p), placeCoup(&p, 'O', 2), "placeCoup('O', 2)");
    assertEquals(getNbLignes(&p)-1, placeCoup(&p, 'X', 2), "placeCoup('X', 2)");

    //teste la fonction sommePointsVert()
    printf("\ntest sommePointsVert\n");
    initTab(&p);
    assertEquals(0u, sommePointsVert(&p, 1, 'X'), "sommePointsVert(1, 'X')");
    assertEquals(getNbLignes(&p), sommePointsVert(&p, 2, '.'), "sommePointsVert(2, '.')");

    //teste la fonction sommePointsHori()
    printf("\ntest sommePointsHori\n");
    assertEquals(0u, sommePointsHori(&p, 1, 'X'), "sommePointsHori(1, 'X')");
    assertEquals((unsigned int)getNbColonnes(&p), sommePointsHori(&p, 2, '.'), "sommePointsHori(2, '.')");

    //teste la fonction sommePointsDiag1()
    printf("\ntest sommePointsDiag1\n");
    assertEquals(getNbLignes(&p), sommePointsDiag1(&p, '.'), "sommePointsDiag1('.')");
    assertEquals(0u, sommePointsDiag1(&p, 'X'), "sommePointsDiag1('X')");

    //teste la fonction sommePointsDiag2()
    printf("\ntest sommePointsDiag1\n");
    assertEquals(getNbLignes(&p), sommePointsDiag2(&p, '.'), "sommePointsDiag2('.')");
    assertEquals(0u, sommePointsDiag2(&p, 'X'), "sommePointsDiag2('X')");

    //teste la fonction puissanceVert()
    printf("\ntest puissanceVert\n");
    assertFalse(puissanceVert(&p, 'X', 2), "puissanceHori('X', 2)");
    assertTrue(puissanceVert(&p, '.', 3), "puissanceHori('.', 3)");
    setTabXY(&p, 2, 1, 'X');
    setTabXY(&p, 3, 1, 'X');
    setTabXY(&p, 4, 1, 'X');
    setTabXY(&p, 5, 1, 'X');
    assertTrue(puissanceVert(&p, 'X', 1), "puissanceVert('X', 1)");
    setTabXY(&p, 2, 1, 'O');
    setTabXY(&p, 6, 1, 'X');
    assertTrue(puissanceVert(&p, 'X', 1), "puissanceVert('X', 1)");

    //teste la fonction puissanceHori()
    printf("\ntest puissanceHori\n");
    initTab(&p);
    assertFalse(puissanceHori(&p, 'X', 1), "puissanceHori('X', 1)");
    assertTrue(puissanceHori(&p, '.', 5), "puissanceHori('.', 5)");
    setTabXY(&p, 1, 1, 'O');
    setTabXY(&p, 1, 2, 'O');
    setTabXY(&p, 1, 3, 'O');
    setTabXY(&p, 1, 4, 'O');
    assertTrue(puissanceHori(&p, 'O', 1), "puissanceHori('O', 1)");
    setTabXY(&p, 1, 3, 'X');
    setTabXY(&p, 1, 5, 'O');
    assertFalse(puissanceHori(&p, 'O', 1), "puissanceHori('O', 1)");

    //teste la fonction puissanceDiag1()
    printf("\ntest puissanceDiag1\n");
    initTab(&p);
    assertTrue(puissanceDiag1(&p, '.'), "puissanceDiag1('.')");
    assertFalse(puissanceDiag1(&p, 'X'), "puissanceDiag1('X')");
    setTabXY(&p, 1, 1, 'O');
    setTabXY(&p, 2, 2, 'O');
    setTabXY(&p, 3, 3, 'O');
    setTabXY(&p, 4, 4, 'O');
    assertTrue(puissanceDiag1(&p, 'O'), "puissanceDiag1('O')");
    setTabXY(&p, 3, 3, 'X');
    setTabXY(&p, 5, 5, 'O');
    assertFalse(puissanceDiag2(&p, 'O'), "puissanceDiag1('O')");

    //teste la fonction puissanceDiag2()
    printf("\ntest puissanceDiag2\n");
    initTab(&p);
    assertTrue(puissanceDiag2(&p, '.'), "puissanceDiag2('.')");
    assertFalse(puissanceDiag2(&p, 'X'), "puissanceDiag2('X')");
    setTabXY(&p, 1, 5, 'O');
    setTabXY(&p, 2, 4, 'O');
    setTabXY(&p, 3, 3, 'O');
    setTabXY(&p, 4, 2, 'O');
    assertTrue(puissanceDiag2(&p, 'O'), "puissanceDiag2('O')");
    setTabXY(&p, 3, 3, 'X');
    setTabXY(&p, 5, 1, 'O');
    assertFalse(puissanceDiag2(&p, 'O'), "puissanceDiag2('O')");

    //teste la fonction puissance4()
    printf("\ntest puissance4\n");
    initTab(&p);
    assertTrue(puissance4(&p, '.', 1, 1), "puissance4('.', 1, 1)");
    assertFalse(puissance4(&p, 'X', 2, 1), "puissance4('X', 2, 1)");
    setTabXY(&p, 1, 5, 'X');
    setTabXY(&p, 2, 4, 'X');
    setTabXY(&p, 3, 3, 'X');
    setTabXY(&p, 4, 2, 'X');
    assertTrue(puissance4(&p, 'X', 3, 3), "puissance4('X', 3, 3)");
    setTabXY(&p, 1, 5, 'O');
    assertFalse(puissance4(&p, 'X', 2, 4), "puissance4('X', 2, 4)");

}
