#include <stdio.h>
#include <stdlib.h>
#include "Recursos.h"
#include "cola.h"
#include "Atencion.h"
#include "Evaluacion.h"

void MenuPrincipal();

int sel;
int main(void) {
    MenuPrincipal();
    return 0;
}

void MenuPrincipal(){

        Titulopantallas("               MENU PRINCIPAL                  ");
        printf("\t [ 1 ] Ingreso Pacientes \n");
        printf("\t [ 2 ] Listado Pacientes Evaluados     \n");
        printf("\t [ 3 ] Atencion en BOXER por prioridad \n");
        printf("\t [ 4 ] Cuantos Faltan                  \n");
        printf("\t [ 5 ] Ver siguiente paciente          \n");
        printf("\n\n");
        printf("\t ===================================================================\n");
        printf("\t [ 9] Guardar y Salir                                \n\n\n\n");
        printf("\t Ingrese su Opcion : ");
        scanf("%d",&sel);

            if(sel==1){
                do{
                    Ingreso_Evaluacion();
                    printf("\n\n\n");
                    printf("\n\t Desea ingresar Un nuevo Paciente....[S/N]  : ");
                    scanf("%s",&SiNo);
                    if (SiNo=='n' || SiNo=='N'){
                        break;
                    }
                }while(SiNo=='s' || SiNo=='S');
                MenuPrincipal();
            }
             else if(sel==2){
                Titulopantallas("\t LISTADO DE PACIENTES EN ESPERA");
                listaPacientesEvaluados();
                printf("\n\n\n\n\t Presione cualquier tecla para continuar");
                getchar();getchar();
                MenuPrincipal();
            }
             else if(sel==3){
                Atencion_En_Boxer_Por_Prioridad();
                getchar();getchar();
                MenuPrincipal();
            }
            else if(sel==4){
               cuantosPRE();
                 MenuPrincipal();
            }
            else if(sel==5){
                 verPRE();
                 getchar();
                 MenuPrincipal();
            }

            else if(sel==9 ){

                printf("\n\n");

            }
            else{
                getchar();
                getchar();
                MenuPrincipal();
            }
}























