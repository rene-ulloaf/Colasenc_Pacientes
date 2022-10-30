#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
//#include "llegada.h"
//#include "preatencion.h"


#define true 1
#define false 0

int colaIsEmpty(void);
int colaSize(void);
int colaSizeH(void);
int colaDelH(void);
PRE cIni(void);
void colaPush(PRE *ppre);
PRE *colaPop(void);

//cola de prioridad
PRE heap[300+1];

#endif // TRANSACCIONES_H_INCLUDED
