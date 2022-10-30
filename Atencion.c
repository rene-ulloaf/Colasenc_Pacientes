#include <stdio.h>
#include <stdlib.h>
#include "Atencion.h"
#include "cola.h"
#include "Recursos.h"

PRE *colaPrioridad ;
PRE limpia;

void  Atencion_En_Boxer_Por_Prioridad(void){
    PRE *paciente;
    PRE pAtendido;
    int finalHeap, padre, i;

    //Enviar desde Evaluacion a heap x  prioridad para atender pacientes en el pabellon de la  muerte
    limpiapantalla();
    Titulopantallas("\t ATENDIENDO PACIENTES SEGUN PRIORIDAD");
    while (colaIsEmpty() == false) {
        paciente =colaPop();
        printf("\n\t Enviando a Cola de Prioridad, Paciente... %d %s", paciente->prioridad, paciente->nombre);
        getchar();
        colaPrioridad = AgregarPaciente(heap, *paciente);
        Borra_de_Evaluacion(paciente);
    }
    printf("\n");

    if (colaSizeH() < 0){

        limpiapantalla();
        Titulopantallas("\t REGISTRO ANTENCION PACIENTES PRE EVALUADOS");
        printf("\n\n\n\n\n\n\t No existen Pacientes para Atencion\n\n");
    }else{

        finalHeap =colaSizeH();

        //ordena heap
        while (finalHeap > 0){
            padre =((finalHeap - 1) / 2);

            if (heap[padre].prioridad < heap[finalHeap].prioridad){
                *paciente =heap[padre];
                heap[padre] =heap[finalHeap];
                heap[finalHeap] =*paciente;
            }

            finalHeap =finalHeap -1;
        }

        pAtendido =atenderPaciente(heap);
        printf("\n\t ----------------------------------------------------------------------");
        printf("\n\t !!!ATENCION!! \n");
        printf("\n\t  INGRESO A BOX DE ATENCION PACIENTE :");
        printf("\n\t prioridad=%i \n\t rut=%s nombre=%s  \n\t prevision=%s \n\t edad=%i \n\t dolencia=%s \n\t especialidad=%s",pAtendido.prioridad,pAtendido.rut, pAtendido.nombre, pAtendido.prevision, pAtendido.edad, pAtendido.dolencia, pAtendido.especialidad);
        printf("\n\t ----------------------------------------------------------------------");
        printf("\n");

        finalHeap =colaDelH();

        //eliminar paciente atendido en colaPrioridad;
        for (i=0;i<=finalHeap;++i){
            heap[i] =heap[i+1];
            heap[i+1] =limpia;
       }

        //ordena heap
        while (finalHeap > 0){
            padre =((finalHeap - 1) / 2);

            if (heap[padre].prioridad < heap[finalHeap].prioridad){
                *paciente =heap[padre];
                heap[padre] =heap[finalHeap];
                heap[finalHeap] =*paciente;
            }

            finalHeap =finalHeap -1;
        }

    }
}

void Borra_de_Evaluacion(PRE *ppre) {
  free(ppre);
  ppre =NULL;
}

PRE *AgregarPaciente(PRE *colaPrioridad, PRE paciente){
    PRE tmp=paciente;

    int cH =colaSizeH();
    heap[cH] =tmp;
    return colaPrioridad;
}































void detallePre(void){
    PRE *ppre =NULL;

    while (colaIsEmpty() == false) {
        ppre =colaPop();
        printf("\nCola en Espera : %d", ppre->ppre);
        ppre =ppre->ppre;
        Borra_de_Evaluacion(ppre);
    }
}


int cuantosFaltan(PRE *colaPrioridad, char *paciente){
    int i;
    int cH =colaSizeH();
   // char pcte =paciente;

    for (i=0;i<=cH;++i){
        if (strcmp(paciente,heap[i].rut)==0){
            return i;
        }
    }
    return -1;
}

PRE verSiguientePaciente(PRE *colaPrioridad){
    PRE tmp;

    tmp =heap[0];

    return tmp;
}

void cuantosPRE(void){
    int cantFalta=0;
    char paciente[10+1];

    printf("\nPACIENTE EN COLA ");
    printf("\nRut (largo max. 10) : ");
    scanf("%s",paciente);

    cantFalta =cuantosFaltan(heap,paciente);
    if (cantFalta==-1){
        printf("\n-----------------------");
        printf("\nPaciete Inexistente !!!");
        printf("\n-----------------------");
    }else{
        printf("\n--------------------------------------------------------------");
        printf("\nFaltan %i Pacientes para atender a paciente consultado", cantFalta);
        printf("\n--------------------------------------------------------------");
    }

}

void verPRE(void){
    PRE tmp;

    printf("\nSIGUIENTE PACIENTE QUE SERA ATENDIDO");

    tmp =verSiguientePaciente(heap);
    if (colaSizeH() < 0){
        printf("\nNo existen Pacientes para Atencion");
    }else{
        printf("\nperioridad=%i rut=%s nombre=%s  prevision=%s edad=%i dolencia=%s especialidad=%s",tmp.prioridad, tmp.rut, tmp.nombre, tmp.prevision, tmp.edad, tmp.dolencia, tmp.especialidad);
    }
}

/*
void listaPRE(void){
    int i, final;

    if (final == colaSizeH() < 0){
        printf("No Existen Pacientes en BOXER \n");
    }else{
        for (i=0;i<=final;++i) {
            printf("Paciente:\n");
            printf("\tprioridad=%i, rut=%s, nombre=%s,  prevision=%s, edad=%i, dolencia=%s, especialidad=%s\n",heap[i].prioridad, heap[i].rut, heap[i].nombre,  heap[i].edad, heap[i].dolencia, heap[i].especialidad);
        }
    }
}
*/
PRE atenderPaciente(PRE *colaPrioridad){
    PRE tmp;

    tmp =heap[0];

    return tmp;
}

