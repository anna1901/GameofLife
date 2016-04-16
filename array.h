//
//  array.h
//  Gra w życie
//
//  Created by Ania on 15.03.2016.
//  Copyright © 2016 Ania. All rights reserved.
//

#ifndef array_h
#define array_h

#include <stdio.h>

int** create(int, int);
int** resize(int**, int, int, int, int);
void insert(int**, int, int, int);
int** fillMatrix(int**, int, int, int);
void viewMatrix(int**, int, int);
int at(int**,int, int);
void delete(int***, int);


#endif /* array_h */
