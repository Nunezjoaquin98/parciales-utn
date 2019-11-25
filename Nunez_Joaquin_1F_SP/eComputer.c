#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eComputer.h"
#include "LinkedList.h"
#include "Controller.h"
#include "parser.h"

//Seters
int eComputer_setId(eComputer* this, int idStr)
{
    int ret = 0;

    if(idStr > 0 && this != NULL)
    {
        this->id = idStr;
        ret = 1;
    }
    return ret;
}


int eComputer_setDescripcion(eComputer* this, char* descripcionStr)
{
    int ret = 0;

    if(this != NULL)
    {
        strcpy(this->descripcion, descripcionStr);
        ret = 1;
    }
    return ret;
}

int eComputer_setPrecio(eComputer* this, int precioStr)
{
    int ret = 0;

    if(this != NULL)
    {
        this->precio = precioStr;
        ret = 1;
    }
    return ret;
}

int eComputer_setTipo(eComputer* this, int tipoStr)
{
    int ret = 0;

    if(this != NULL)
    {
        this->idTipo = tipoStr;
        ret = 1;
    }
    return ret;
}



//Geters
int eComputer_getId(eComputer* this)
{
    int ret = 0;
    if(this != NULL)
    {
        ret = this->id;
    }
    return ret;
}

char eComputer_getDescripcion(eComputer* this,char* descripcionStr)
{
    int ret = 0;

    if(this != NULL)
    {
        strcpy(descripcionStr,this->descripcion);
        ret = 1;

    }

    return ret;
}

int eComputer_getPrecio(eComputer* this)
{
    int ret = 0;
    if(this != NULL)
    {
        ret = this->precio;
    }
    return ret;
}

int eComputer_getIdTipo(eComputer* this)
{
    int ret = 0;
    if(this != NULL)
    {
        ret = this->idTipo;
    }
    return ret;
}

//Otros

eComputer* eComputer_new()
{
    eComputer* pComputer = (eComputer *) calloc ( 1, sizeof (eComputer));
    if(pComputer == NULL)
    {
        printf("No hay espacio suficiente!\n\n ");
        system("pause");
    }

    return pComputer;
}

eComputer* eComputer_newParameters(char* idStr,char* descripcionStr,char* precioStr,char* idTipoStr)
{
    eComputer* pComputer = eComputer_new();
    eComputer_setId(pComputer,atoi(idStr));
    eComputer_setDescripcion(pComputer,descripcionStr);
    eComputer_setPrecio(pComputer,atoi(precioStr));
    eComputer_setTipo(pComputer,atoi(idTipoStr));

    return pComputer;
}


int compareComputers(void* pComputerA,void* pComputerB)
{
if(((eComputer*)pComputerA)->idTipo > ((eComputer*)pComputerB)->idTipo)
{
 return 1;
}
if(((eComputer*)pComputerA)->idTipo < ((eComputer*)pComputerB)->idTipo)
{
 return -1;
}
return 0;
}
