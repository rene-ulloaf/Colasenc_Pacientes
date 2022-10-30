#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

PRE *colaIni=NULL;
PRE *colaFin=NULL;

int cCola =0;
int cHeap =-1;

//verifica si la cola esta vacia
int colaIsEmpty(void) {
    if (colaIni == NULL) {
        return true;
    }
    return false;
}

//agrega transaccion al final del heap
void colaPush(PRE *ppre) {
    if (ppre == NULL) {
        return;
    }
    ++cCola;
    if (colaIni == NULL) {
        colaIni =ppre;
        colaFin =colaIni;
    } else {
        colaFin->ppre=ppre;
        colaFin=ppre;
    }
}

//procesa transaccion de la cola
PRE *colaPop(void) {
    if (colaIni == NULL) {
        return NULL;
    } else {
        PRE *ptmp =colaIni;
        colaIni =colaIni->ppre;
        --cCola;
        ++cHeap;
        return ptmp;
    }
}


//tama�o de la cola
int colaSize(void) {
    return cCola;
}
//tama�o del heap
int colaSizeH(void) {
    return cHeap;
}
//tama�o del heap
int colaDelH(void) {
    --cHeap;
    return cHeap;
}


PRE cIni(void) {
    PRE *ptmp =colaIni;
    return ptmp;
}

