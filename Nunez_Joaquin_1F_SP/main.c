#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "eComputer.h"
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"



int main()
{
    int salir = 0;
    LinkedList* listaComputer = ll_newLinkedList();
    do
    {
        switch(menu())
        {
        case 1:
            if(controller_loadFromText("datos_SP_1F.csv",listaComputer))
            {
                system("cls");
                printf("Se cargo correctamente...\n");
                system("pause");
            }else
            {
                system("cls");
                printf("No se pudo cargar correctamente...\n");
                system("pause");
            }
            break;
        case 2:

                if(ll_sort(listaComputer,compareComputers,1))
                {
                    system("cls");
                    printf("\nSe ordeno de manera ascendente correctamente\n");
                    system("pause");
                    break;
                }
                break;
                /*ll_map(listaDominios,setearTipoPorCriterio(listaDominios));
                system("cls");
                system("pause");
                break;
                */
        case 3:
                printf("\nSaliendo...\n\n");
                salir = 1;
                break;
        default:
                printf("\nERROR - Debe ingresar un numero del 1 al 3.\n");
                system("pause");
                system("cls");
                break;
                    }
    }
    while(salir == 0);

    return 0;

}
