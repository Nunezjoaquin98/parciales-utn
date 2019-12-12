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
    int sort;
    LinkedList* listaComputer = ll_newLinkedList();
    LinkedList* eComputerFilter = ll_newLinkedList();
    char pathArch[13]= "filtrado.csv";


    do
    {
        switch(menu())
        {
        case 1:
            if(controller_loadFromText("datos_SP_1F.csv",listaComputer))
            {
                system("cls");
                printf("Se cargo correctamente...\n\n");
                system("pause");
            }
            else
            {
                system("cls");
                printf("No se pudo cargar correctamente...\n");
                system("pause");
            }
            break;
        case 2:
            system("cls");
            sort = ll_sort(listaComputer,eComputer_comparaTipos,1);
            if(sort == 0)
            {
                printf("Se ha ordenado correctamente...\n\n");
                system("pause");
            }
            else
            {
                printf("No se pudo ordenar correctamente...\n\n");
                system("pause");
            }
            break;
        case 3:
            system("cls");
            controller_ListEComputer(listaComputer);
            break;

        case 4:
            system("cls");
            ll_map(listaComputer, eComputer_tipoComputer);
            controller_ListEComputer(listaComputer);
            break;
        case 5:
            eComputerFilter = ll_filter(listaComputer,eComputer_filter);
            controller_ListEComputer(eComputerFilter);
            break;

        case 6:
            controller_saveAsText(pathArch,eComputerFilter);
            break;
        case 7:
            printf("Saliendo...");
            salir = 1;
            break;
        default:
            printf("\nErorr debe ingresar un numero del 1 al 7.\n\n");
            system("pause");
            system("cls");
            break;
        }

    }
    while(salir == 0);

    return 0;
}
