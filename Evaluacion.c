#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Evaluacion.h"
#include "cola.h"
#include "Recursos.h"

void Ingreso_Evaluacion(void){
    PRE *ppre =NULL;
    limpiapantalla();
    Titulopantallas("\t REGISTRO INGRESO PACIENTES ");

    int  prioridad;
    char rut[10+1];
    char nombre[50+1];
    char prevision[12+1];
     int edad;
    char dolencia[50+1];
    char especialidad[20+1];

    //Ingreso de Prioridad de atencion
    do{
        printf("\n\t Ingese Prioridad de atencion,  [0] para Salir : ");
        scanf("%i",&prioridad);
        //C�dgo para validar si numero de asignacion ya fue entregado a otro paciente
        if (prioridad==0){
            break;
        }
    }while (prioridad<=0);
    if (prioridad>0){
        //Ingreso del Rut del paciente
        int z;
        do {
            printf("\n\t Ingrese Rut 99999999-X  : ") ; fflush(stdin); gets(rut);
            z=atoi(rut);
            if ( ValidaRutConDigito(z,rut)==1){
                printf("\n\t ERROR: Rut del paciente ingresado no es v�lido, por favor reintente...");
            }
        }
        while (ValidaRutConDigito(z,rut)==1 );
        //Ingreso del nombre del paciente
        do{
            printf ("\t Ingrese el Nombre       : ") ; fflush(stdin); gets(nombre);
        }while (strlen(nombre)==0);

        printf("\t Sistema de  prevision   : "); fflush(stdin); gets(prevision);
        printf("\t Edad del paciente       : "); scanf("%i",&edad);
        printf("\t Sintomas                : "); fflush(stdin); gets(dolencia);
        printf("\t Especialidad            : "); fflush(stdin); gets(especialidad);

        //printf("\n\n\n\t presione cualquier tecla para continuar \n\n\n ");
        ppre =crearPreatencion(prioridad, rut, nombre, prevision,edad, dolencia, especialidad);
        //Agregar registro en la cola del heap
        colaPush(ppre);
    }
}


// Crea un Registro del tipo estructura con cada dato del paciente
// para luego agregarlo al Heap
PRE *crearPreatencion(int prioridad,
                      char *rut,
                      char *nombre,
                      char *prevision,
                       int edad,
                      char *dolencia,
                      char *especialidad) {

     PRE *C= (PRE *) malloc(sizeof(PRE));

            C->prioridad =prioridad;
     strcpy(C->rut,rut);
     strcpy(C->nombre,nombre);
     strcpy(C->prevision,prevision);
     strcpy(C->dolencia,dolencia);
            C->edad=edad;
     strcpy(C->especialidad,especialidad);
            C->ppre = NULL;

     return C;
}



void listaPacientesEvaluados(void) {
    PRE *tmp;

    if (colaIsEmpty() == true){
        printf("\n\n\n\t !!! No existen Pacientes Registrados en lista de espera  !!!\n\n\n\n");
    }
    else{
        *tmp = cIni();
        printf("\n\t Num   Rut           Nombre           Especialidad ");
        printf("\n\t Pri   Paciente      Pciente                       ");
        printf("\n\t ------------------------------------------------------------------- ");
        while (tmp != NULL) {
            printf("\n\t %3i %10s %30s %s",tmp->prioridad, tmp->rut, tmp->nombre,tmp->especialidad);
            tmp =tmp->ppre;
        }
    }
}
