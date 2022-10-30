#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Recursos.h"

void Titulopantallas(char *Texto){
    limpiapantalla();
    printf("\t Control de Atencion de Pacientes, Ud. nuestra prioridad 2.0  \n\t Modulo de Gestion \n\n");
    printf("\t ===================================================================\n");
    printf("\t %s  \n",Texto);
    printf("\t ===================================================================\n");
}
void MensajeNOdatos(){
    printf("\n\n\n\n\n\n\t Atencion : ");
    printf("\n\t No hay datos registrados \n\n\n");
    return;
}
void limpiapantalla(){
    int i=0;
    for (i=1;i<40;i++){
        printf("\n");
    }
}

int ValidaRutConDigito(int a,char *b){
    /*--------------------------------------------------------
    Esta funcion retornara :
     0 si el rut ingresado es válido
     1 si esta malo
    -------------------------------------------------------- */

    int M=0,S=1;
    int i;
    char x;
    char RutRev[10+1];
    for ( i=0; i<11;i++){
        RutRev[i]="";
    }
    for(;a;a/=10){ S=(S+a%10*(9-M++%6))%11;  }
    x=S?S+47:75;
    strcpy(RutRev,strupr(strrev(b)));
    strrev(b);
    if ( x==RutRev[0] ){
        return 0;
    }
    else{
        return 1;
    }
}

