#ifndef PREATENCION_H_INCLUDED
#define PREATENCION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

//Datos que contiene cada nodo de preatencion
struct preatencion {
    int prioridad;
    char rut[10+1];
    char nombre[30+1];
    char prevision[12+1];
    int edad;
    char dolencia[50+1];
    char especialidad[20+1];
    struct preatencion *ppre;
};
typedef struct preatencion PRE;

void listaPacientesEvaluados(void);
void Ingreso_Evaluacion(void);
PRE *crearPreatencion(int prioridad,
                      char *rut,
                      char *nombre,
                      char *prevision,
                       int edad,
                      char *dolencia,
                      char *especialidad);


void MenuPrincipal();
#endif // CLIENTES_H_INCLUDED
