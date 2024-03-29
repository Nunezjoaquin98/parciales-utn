#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eComputer.h"
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"


/** \brief Carga los datos de las computadoras desde el archivo .csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayList)
{
    int ret;
    ret = 0;

    FILE* pFile = fopen(path, "r");
    if(pFile != NULL)
    {
      ret = parser_ComputerFromText(pFile,pArrayList);
    }
    else
    {
        printf("El Archivo No Existe\n\n");
        system("pause");
    }

    return ret;
}


/** \brief Listar computadoras
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
/*
int controller_ListEDominio(LinkedList* pArrayList)
{
    int ret = 0;
    int len;
    len = ll_len(pArrayList);

    if(pArrayList != NULL)
    {
        if(len != 0)
        {
            printf("ID Dominio Anio Tipo\n\n");
            for(int i = 0; i < len; i++)
            {
                eDominio_showDominios(pArrayList);
                ret = 1;
                break;
            }
            system("pause");
        }
        else
        {
            printf("No hay datos\n\n");
            system("pause");
        }
    }
    return ret;
}
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i,cant;
    cant = ll_len(pArrayListEmployee);
    Employee* lista;
    for (i=1;i<cant;i++){
        lista = (Employee*)ll_get(pArrayListEmployee,i);
        printf("%d\t %s\t %d\t %d\n",employee_getId(lista),employee_getNombre(lista),employee_getHorasTrabajadas(lista),employee_getSueldo(lista));
    }
    return 1;
}**/


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
 /*
int controller_saveAsText(char* path , LinkedList* pArrayList)
{
    int ret;
    ret = RETURN_ERROR;

    FILE* pFile;
    pFile = fopen(path, "w");
    eDominio* pDom;


    if(pArrayList != NULL)
    {
        for(int i = 0; i<ll_len(pArrayList);i++)
        {
            pDom = (eDominio*)ll_get(pArrayList, i);
            fprintf(pFile, "%4d  %s  %d  %c\n",pDom->id ,pDom->dominio ,pDom->anio, pDom->tipo);
        }
        fclose(pFile);
        ret = RETURN_OK;
    }

    else
    {
        printf("No hay Datos\n");
        system("pause");
    }

    return ret;
}

*/
