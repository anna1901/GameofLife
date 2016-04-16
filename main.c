//
//  main.c
//  Gra w życie
//
//  Created by Ania on 15.03.2016.
//  Copyright © 2016 Ania. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "GrawŻycie.h"
#define WIERSZE 30
#define KOLUMNY 40



int main() {
    FILE* plik = fopen("~/text.txt", "rb");
    printf("jestem tu 1");
    if (plik != NULL){
        int i, x, y;
        int** tab0 = create(WIERSZE, KOLUMNY);
        fillMatrix(tab0, WIERSZE, KOLUMNY, MARTWA);
        printf("jestem tu 2");
        while (!feof(plik)) {
            fscanf(plik, "%d", &x);
            fscanf(plik, "%d", &y);
            insert(tab0, x, y, ŻYWA);
        }
        viewMatrix(tab0, WIERSZE, KOLUMNY);
        for (i=0; i<20; i++) {
            tab0 = Pokolenie(tab0, WIERSZE, KOLUMNY);
            viewMatrix(tab0, WIERSZE, KOLUMNY);
        }
    }
    if (plik == NULL){
        printf("Nie udało się otworzyć pliku\n");
    }
    fclose(plik);
       
    return 0;
}
