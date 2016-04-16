//
//  GrawŻycie.h
//  Gra w życie
//
//  Created by Ania on 15.03.2016.
//  Copyright © 2016 Ania. All rights reserved.
//

#ifndef GrawZ_ycie_h
#define GrawZ_ycie_h

#include <stdio.h>
#define ŻYWA 1
#define MARTWA 0

int Sąsiedzi(int**, int, int);
int** Pokolenie(int**, int, int);
int Stan(int**, int, int);
void Wyczyść();

#endif /* GrawZ_ycie_h */
