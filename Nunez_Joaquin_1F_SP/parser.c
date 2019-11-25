#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eComputer.h"
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"


/** \brief Parsea los datos los datos de los envios desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */
int parser_ComputerFromText(FILE* pFile , LinkedList* pArrayList)
{
    int ret = 0;
    int r;
    char idStr[50];
    char descripcionStr[50];
    char precioStr[50];
    char idTipoStr[50];

    if(pFile == NULL)
    {
        printf("El archivo no existe\n");
        system("pause");
    }
    do
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]",idStr,descripcionStr,precioStr,idTipoStr);
        if(r==4)
        {
            eComputer* auxComputer = eComputer_new();
            auxComputer = eComputer_newParameters(idStr,descripcionStr,precioStr,idTipoStr);
            ll_add(pArrayList,auxComputer);
            ret = 1;
        }
        break;
    }
    while(!feof(pFile));


    fclose(pFile);
    return ret;
}
