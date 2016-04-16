//
//  GrawŻycie.c
//  Gra w życie
//
//  Created by Ania on 15.03.2016.
//  Copyright © 2016 Ania. All rights reserved.
//

#include "GrawŻycie.h"
#include "array.h"
#include <stdio.h>


int Stan(int** tab, int x, int y){
    
    return tab[x][y];
    
}

int Sąsiedzi(int **tab, int x, int y){
    int żywi = 0;
    int i, j;
    for (i= (x-1); i<= (x+1); i++){
        for (j=(y-1); j<=(y+1); j++){
            if (Stan(tab, i, j) == ŻYWA){
                ++żywi;
            }
        }
    }
    if (Stan(tab, x, y)==ŻYWA) {
        żywi--;
    }
    return żywi;
}


int** Pokolenie (int** tab, int WIERSZE, int KOLUMNY){
    int i, j;
    int** tablica = create(WIERSZE, KOLUMNY);
    fillMatrix(tablica, WIERSZE, KOLUMNY, MARTWA);
    for (i=1; i<WIERSZE-1; i++){
        for (j=1; j<KOLUMNY-1; j++) {
            if(Stan(tab, i, j)==MARTWA){
                if (Sąsiedzi(tab, i, j) == 3) {
                    insert(tablica, i, j, ŻYWA);
                }
            }
            else{
                if (Sąsiedzi(tab, i, j) == 2 || Sąsiedzi(tab, i, j) == 3) {
                    insert(tablica, i, j, ŻYWA);
                }
            }
        }
    }
    delete(&tab, WIERSZE);
    
    return tablica;
}
