#ifndef LLEGADA_H_INCLUDED
#define LLEGADA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "Evaluacion.h"

void  Atencion_En_Boxer_Por_Prioridad(void);
void Borra_de_Evaluacion(PRE *ppre);            //void borraPre(PRE *ppre);
PRE *AgregarPaciente(PRE *colaPrioridad, PRE paciente);



void detallePre(void);

int cuantosFaltan(PRE *colaPrioridad, char *paciente);
PRE verSiguientePaciente(PRE *colaPrioridad);
void cuantosPRE(void);
void verPRE(void);
PRE atenderPaciente(PRE *colaPrioridad);



#endif // LLEGADA_H_INCLUDED
