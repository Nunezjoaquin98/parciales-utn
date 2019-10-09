#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "Clientes Juegos.h"
#include "fecha.h"
#include "alquileres.h"
#include "informes.h"


int menuInformes()
{
    char auxOption[2];
    int option;
    system("cls") ;
    printf("\n\t\t*** MENU INFORMES ***\n\n");
    printf("7-Promedio y Total de los importes de los juegos alquilados\n") ;
    printf("8-\n") ;
    printf("9-Listar todos los clientes que alquilaron un juego determinado\n") ;
    printf("10-Listar todos los juegos que fueron alquilados por un cliente determinado\n") ;
    printf("11-\n") ;
    printf("12-\n") ;
    printf("13-Listar todos los juegos alquilados en una fecha determinada\n");
    printf("14-Listar todos los clientes que realizaron al menos un alquiler en una fecha determinada\n") ;
    printf("15-Listar todos los juegos ordenados por Importe(descendente), utilizando el metodo de burbujeo mas eficiente.\n") ;
    printf("16-Listar todos los clientes ordenados por apellido(ascendente), utilizando el metodo de insercion.\n\n") ;
    printf("17-VOLVER AL MENU PRINCIPAL\n\n") ;
    while(!function_getStringNumeros("Ingresar opcion: ",auxOption))
    {
        printf("\n*** ERROR *** Debe ingresar un numero del 1 al 3. \n") ;
        system("pause") ;

    }
    option = atoi(auxOption) ;
    return option;
}

void function_promedioTotalJuegos (eJuego listJuegos[],int lenJuegos, eAlquileres listAlq[],int lenAlq)
{
    float contImporte = 0;
    float promedioFinal = 0;
    float auxImporteJuego = 0;
    int codigoJuego;
    int contJuegos = 0;
    int indexJuego;

    for(int i = 0;i < lenAlq;i++)
    {
        if(listAlq[i].isEmpty == 0)
        {

           codigoJuego = listAlq[i].codigoJuego.codigoDelJuego ;//copio el codigo del juego
           indexJuego = findJuego(listJuegos,lenJuegos,codigoJuego);//busco la posicon en el array de juegos

            //obtengo precio del juego y lo guardo en la variable aux
           auxImporteJuego = listJuegos[indexJuego].importeDelJuego;
           contImporte = (contImporte + auxImporteJuego);
           contJuegos++;
        }
    }

    //calculo el promedio y lo muestro
    promedioFinal = contImporte / contJuegos;

    printf("\n\nEl promedio total de los juegos alquilados es: $%0.2f\nEl total de los importes de los juegos alquilados es: $%0.2f",promedioFinal,contImporte);

}

void listarClientesDeJuego(eJuego listJuegos[],int lenJuegos,eClientes listClientes[],int lenClientes,eAlquileres listAlquileres[],int lenAlquileres)
{
    char auxCodigoJuego[5];
    int indexJuego,indexCliente,codigoCliente;
    int contadorCliente = 0;

    system("cls");
    printf("\nSeleccione el juego a buscar:\n");
    showJuegos(listJuegos,lenJuegos);
    while(!function_getStringNumeros("\nIngrese el codigo del Juego: ",auxCodigoJuego))
    {
        printf("\n***ERROR*** Debe ingresar solo numeros\n\n");
    }

    indexJuego = findJuego(listJuegos,lenJuegos,atoi(auxCodigoJuego));

    printf("\n\nLista de todos los clientes que alquilaron el juego %s: \n",listJuegos[indexJuego].descripcion);
    printf("\n\nCODIGO\tAPELLIDO NOMBRE\tSEXO\tDOMICILIO\tTELEFONO\n\n");

    //ahora que tenemos el index del juego, recorremos la lista de alquileres

    for(int i = 0; i < lenAlquileres; i++)
    {
        if(atoi(auxCodigoJuego) == listAlquileres[i].codigoJuego.codigoDelJuego && listAlquileres[i].isEmpty == 0)
        {
            codigoCliente = listAlquileres[i].codigoCliente.codigoDeCliente;//copio el codigo del cliente
            indexCliente = findCliente(listClientes,lenClientes,codigoCliente);//busco la posicon en el array de clientes
            printf("\n");
            showCliente(listClientes[indexCliente]); // muestro el cliente
            printf("\n");
            contadorCliente++;
        }


    }

    if(contadorCliente == 0)
    {
        printf("Nadie");
    }

}

void listarJuegosDeCliente(eJuego listJuego[],int lenJuego,eClientes listClientes[],int lenClientes,eAlquileres listAlquileres[],int lenAlquileres)
{
    char auxCodigoCliente[5];
    int indexJuego,indexCliente,codigoJuego;
    int contadorJuegos = 0;

    system("cls");
    printf("Seleccione el cliente a buscar:\n");
    printf("\n\nCODIGO\tAPELLIDO NOMBRE\tSEXO\tDOMICILIO\tTELEFONO\n\n");
    showClientes(listClientes,lenClientes);
    while(!function_getStringNumeros("Ingrese el codigo del cliente: ",auxCodigoCliente))
    {
        printf("\n***ERROR*** Debe ingresar solo numeros\n\n");
    }

    indexCliente = findCliente(listClientes,lenClientes,atoi(auxCodigoCliente));
    printf("\n\nLista de juegos alquilados por el cliente %s %s: \n",listClientes[indexCliente].nombreCliente,listClientes[indexCliente].apellidoCliente);
    printf("\n\n\nCODIGO\tDESCRIPCION\tIMPORTE\n\n");
    //ahora que tenemos el index del cliente, recorremos la lista de alquilres

    for(int i = 0; i < lenAlquileres; i++)
    {
        if(atoi(auxCodigoCliente) == listAlquileres[i].codigoCliente.codigoDeCliente && listAlquileres[i].isEmpty == 0)
        {
            codigoJuego = listAlquileres[i].codigoJuego.codigoDelJuego;//copio el codigo del juego
            indexJuego = findJuego(listJuego,lenJuego,codigoJuego); //busco la posicon en el array de juegos
            showJuego(listJuego[indexJuego]); // muestro el juego
            printf("\n");
            contadorJuegos++;
        }


    }

    if(contadorJuegos == 0)
    {
        printf("\nNingun juego solicitado.\n");
        system("pause");
    }


}


//(punto 15)

int listarJuegosPorImporteBurbujeo(eJuego listJuego[], int lenJuego)
{
    eJuego auxJuego;
    int ret;

    if(listJuego != NULL && lenJuego > 0)
    {
        for(int i = 0; i < lenJuego -1; i++)
        {
            for(int j=i+1; j<lenJuego; j++)
            {
                if(listJuego[i].importeDelJuego < listJuego[j].importeDelJuego && listJuego[i].isEmpty == 0 && listJuego[j].isEmpty == 0)
                {
                    auxJuego   = listJuego[i];
                    listJuego[i] = listJuego[j];
                    listJuego[j] = auxJuego ;
                }

            }

            ret = 1;

        }
    }
    else
    {
        ret = -1;
    }


    return ret;

}


void listarClientesPorInsercion(eClientes list[], int len)
{

    int i, j;
    eClientes auxCliente;

    for (i = 1; i < len; i++)
    {
        auxCliente = list[i];
        j = i - 1;
        while (strcmp(auxCliente.apellidoCliente,list[j].apellidoCliente) < 0)
        {
            list[j + 1] = list[j];
            j--;
        }
        list[j + 1] = auxCliente;
    }
}


void juegoEnFechaDeterminada(eAlquileres listAlquileres[],int lenAlq,eJuego listJuego[],int lenJuego)
{
    char auxDia[3];
    char auxMes[3];
    char auxAnio[5];
    int codigoJuego,indexJuego;
    int contadorAlquiler = 0;

    system("cls");
    printf("\n\tFecha a buscar:\n");
    ingresarDia(auxDia);
    ingresarMes(auxMes);
    ingresarAnio(auxAnio);
    system("pause");
    system("cls");
    printf("\n\n\nLos juegos alquilados en la fecha %s/%s/%s son:\n\n",auxDia,auxMes,auxAnio);
    printf("\n\nCODIGO\tDESCRIPCION\tIMPORTE\n\n");
    for(int i=0; i<lenAlq; i++)
    {
        if(listAlquileres[i].isEmpty == 0)
        {
            if(atoi(auxDia)==listAlquileres[i].fechaDeAlquiler.dia && atoi(auxMes)==listAlquileres[i].fechaDeAlquiler.mes && atoi(auxAnio)==listAlquileres[i].fechaDeAlquiler.anio)
            {
            codigoJuego = listAlquileres[i].codigoJuego.codigoDelJuego;//copio el codigo del juego
            indexJuego = findJuego(listJuego,lenJuego,codigoJuego); //busco la posicon en el array de juegos
            showJuego(listJuego[indexJuego]); // muestro el juego
            printf("__________________________________________________________\n");
            contadorAlquiler++;
            }


        }


    }



    if(contadorAlquiler == 0)
    {
        printf("\nNo se realizo ningun alquiler en ese dia.\n\n");
        system("pause");
    }
}


void clienteEnFechaDeterminada(eAlquileres listAlquileres[],int lenAlq,eClientes listClientes[],int lenCliente)
{
    char auxDia[3];
    char auxMes[3];
    char auxAnio[5];
    int codigoCliente,indexCliente;
    int contadorAlquiler = 0;

    system("cls");
    printf("Fecha a buscar:\n");
    ingresarDia(auxDia);
    ingresarMes(auxMes);
    ingresarAnio(auxAnio);
    system("pause");
    system("cls");
    printf("\n\n\nLos clientes que realizaron alquiler en el dia %s/%s/%s son:\n\n",auxDia,auxMes,auxAnio);
    printf("\n\nCODIGO\tAPELLIDO NOMBRE\tSEXO\tDOMICILIO\tTELEFONO\n\n");

    for(int i=0; i<lenAlq; i++)
    {
        if(listAlquileres[i].isEmpty == 0)
        {
            if(atoi(auxDia)==listAlquileres[i].fechaDeAlquiler.dia && atoi(auxMes)==listAlquileres[i].fechaDeAlquiler.mes && atoi(auxAnio)==listAlquileres[i].fechaDeAlquiler.anio)
            {
            codigoCliente = listAlquileres[i].codigoCliente.codigoDeCliente;//copio el codigo del cliente
            indexCliente = findCliente(listClientes,lenCliente,codigoCliente); //busco la posicon en el array de cliente
            showCliente(listClientes[indexCliente]); // muestro el cliente
            printf("__________________________________________________________\n");
            contadorAlquiler++;
            }

        }




    }
    if(contadorAlquiler == 0)
    {
        printf("\nNo se realizo ningun alquiler en ese dia.\n\n");
        system("pause");
    }


}

