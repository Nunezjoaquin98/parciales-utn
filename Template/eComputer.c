#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eComputer.h"
#include "LinkedList.h"
#define RETURN_OK 1
#define RETURN_ERROR 0



/*Setters*/
int eComputer_setId(eComputer* this, int id)
{
    int ret;
    ret = RETURN_ERROR;

    if(id > 0 && this != NULL)
    {
        this->id = id;
        ret = RETURN_OK;
    }
    return ret;
}

int eComputer_setDescripcion(eComputer* this, char* descripcion)
{
    int ret;
    ret = RETURN_ERROR;

    if(this != NULL)
    {
        strcpy(this->descripcion, descripcion);
        ret = RETURN_OK;
    }
    return ret;
}
int eComputer_setPrecio(eComputer* this, float precio)
{
    int ret;
    ret = RETURN_ERROR;

    if(this != NULL)
    {
        this->precio = precio;
        ret = RETURN_OK;
    }
    return ret;
}
int eComputer_setIdTipo(eComputer* this, int idTipo)
{
    int ret;
    ret = RETURN_ERROR;

    if(idTipo > 0 && this != NULL)
    {
        this->idTipo = idTipo;
        ret = RETURN_OK;
    }
    return ret;
}


/*Getters*/
int eComputer_getId(eComputer* this)
{
    int ret;

    if(this != NULL)
    {
        ret = this->id;
    }
    return ret;
}

char* eComputer_getDescripcion(eComputer* this)
{
    return this->descripcion;
}

float eComputer_getPrecio(eComputer* this)
{
    int ret;

    if(this != NULL)
    {
        ret = this->precio;
    }
    return ret;
}

int eComputer_getIdTipo(eComputer* this)
{
    int ret;
    if(this != NULL)
    {
        ret = this->idTipo;;
    }
    return ret;
}


/*Otras funciones*/


eComputer* eComputer_new()
{

    eComputer* pComp = (eComputer *) calloc ( 1, sizeof (eComputer));
    if(pComp == NULL)
    {
        printf("No hay espacio suficiente para liberar o reiniciar el programa ... \n\n");
        system("pause");
    }
    return pComp;
}

eComputer* eComputer_newParametros(char* idStr, char* descripcionStr, char* precioStr, char* idTipoStr)
{
    eComputer* pComp = eComputer_new();

    eComputer_setId(pComp, atoi(idStr));
    eComputer_setDescripcion(pComp, descripcionStr);
    eComputer_setPrecio(pComp, atof(precioStr));
    eComputer_setIdTipo(pComp, atoi(idTipoStr));

    return pComp;
}


int eComputer_comparaTipos(void* pTipo1,void* pTipo2)
{
    if(((eComputer*)pTipo1)->idTipo > ((eComputer*)pTipo2)->idTipo)
    {
        return 1;
    }
    if(((eComputer*)pTipo1)->idTipo < ((eComputer*)pTipo2)->idTipo)
    {
        return -1;
    }
    return 0;
}

void  eComputer_showComputer(eComputer* this)
{
    char desktop [8]= "DESKTOP";
    char laptop [7]= "LAPTOP";
    int idTipo = eComputer_getIdTipo(this);

    if(this != NULL )
    {
        if (idTipo == 1)
        {
            printf(" %4d  %10s  %4f  %s\n\n ", eComputer_getId(this), eComputer_getDescripcion(this), eComputer_getPrecio(this),
                   desktop);
        }
        else if (idTipo == 2)
        {
            printf(" %4d  %10s  %4f  %s\n\n ", eComputer_getId(this), eComputer_getDescripcion(this), eComputer_getPrecio(this),
                   laptop);
        }


    }
}
void  eComputer_showComputers(eComputer* this)
{
    eComputer* pComp;
    int len;
    len = ll_len(this);
    if(this != NULL )
    {
        for(int i=0; i<len; i++)
        {
            pComp = (eComputer*)ll_get(this, i);
            eComputer_showComputer(pComp);
        }
    }
    else
    {
        printf("No hay computadoras cargadas\n\n");
        system("pause");
    }
}

int  eComputer_idValido(int idTipo)
{
    int ret = RETURN_ERROR ;

    if (idTipo == 1 )
    {
        ret = RETURN_OK ;
    }
    return ret;
}

float eComputer_tipoComputer(void* computer)
{
    float ret;

      if(eComputer_idValido(((eComputer*)computer)->idTipo))
       {
            ret = ((eComputer*)computer)->precio = (((eComputer*)computer)->precio * 0.10) + ((eComputer*)computer)->precio;
       }
       else
       {
            ret = ((eComputer*)computer)->precio = (((eComputer*)computer)->precio * 0.20) + ((eComputer*)computer)->precio;
       }

    return ret;

}

int eComputer_filter(void* computers, int idTipo)
{
    int ret = 2;
    void* filterIdTipo;

    if(((eComputer*)computers)->idTipo == 2 )
    {
        filterIdTipo = ((eComputer*)computers);
        ret = 0;
    }
    else if(((eComputer*)computers)->idTipo == 1)
    {
        filterIdTipo = ((eComputer*)computers);
        ret = 1;
    }

    return ret;
}
