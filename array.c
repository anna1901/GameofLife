//
//  array.c
//  Gra w życie
//
//  Created by Ania on 15.03.2016.
//  Copyright © 2016 Ania. All rights reserved.
//

#include "array.h"
#include <stdio.h>
#include <stdlib.h>



void delete(int*** ptab, int n){
    int i;
    for(i = 0; i < n; i++){
        free((*ptab)[i]);
    }
    free(*ptab);
    *ptab = NULL;
}

int** create(int wiersze, int kolumny){
    
    int i;
    int** tab;
    tab = (int**)malloc(wiersze*sizeof(int*));
    if(tab==NULL)
        return 0;
    
    for(i=0;i<wiersze; i++)
    {
        tab[i] =(int*) malloc(kolumny*sizeof(int));
        if(tab[i]==NULL)
        {
            delete(&tab,i);
            return NULL;
        }
    }
    return tab;
}

int** resize(int** tab, int wiersze, int kolumny, int dodaj_w, int dodaj_k){
    int i, j;
    int nowe_w = wiersze + dodaj_w;
    int nowe_k = kolumny + dodaj_k;
    int** tablica = create(nowe_w, nowe_k);
    for(i = 0; i < wiersze; i++){
        for(j = 0; j < kolumny; j++){
            tablica[i][j] = tab[i][j];
        }
    }
    for(i = wiersze; i < nowe_w; i++){
        for(j = 0; j < kolumny; j++){
            tablica[i][j] = 0;
        }
    }
    for(i = 0; i < nowe_w; i++){
        for(j = kolumny; j < nowe_k; j++){
            tablica[i][j] = 0;
        }
    }
    delete(&tab, wiersze);
    return tablica;
}


int at(int** tab, int X, int Y){
    return tab[X][Y];
}

void insert(int** tab, int wiersz, int kolumna, int wartość){
   
    tab[wiersz][kolumna]= wartość;
    
}

int** fillMatrix(int** tab, int WIERSZE, int KOLUMNY, int wartość){
    int i, j;
    for(i = 0; i < WIERSZE; i++){
        for(j = 0; j < KOLUMNY; j++){
            tab[i][j] = wartość;
        }
    }
    return tab;
}

void viewMatrix(int** tab, int WIERSZE, int KOLUMNY){
    int i, j;
    for (i=0; i<WIERSZE; i++){
        for (j=0; j<KOLUMNY; j++) {
            printf("%2c", at(tab, i, j));
        }
        printf("\n");
    }
}





