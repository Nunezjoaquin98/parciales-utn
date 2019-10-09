#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "Clientes Juegos.h"
#include "fecha.h"
#include "alquileres.h"

int initAlquileres(eAlquileres list[], int len)
{
    int ret = 0;

    if(list != NULL && len > 0)
    {

        for(int i=0; i < len; i++)
        {

            list[i].isEmpty = 1;
        }
    }
    else
    {
        ret = -1;
    }

    return ret;

}


int searchEmptyAlquiler(eAlquileres list[],int len)
{
    int index = -1;
    for(int i=1; i<len ; i++)
    {
        if( list[i].isEmpty == 1)
        {
            index = i ;
            break;
        }
    }
    return index ;
}

int addAlquiler(eClientes listClientes[],int tamClie,eJuego listJuego[],int tamJuego,eAlquileres listAlq[],int tamAlq)
{
    int ret,index,indexJuego,indexCliente;
    eAlquileres newAlquiler;
    char auxJuego[3];
    char auxCliente[4];
    char anio[5];
    char mes[5];
    char dia[5];


    if(listAlq != NULL && tamAlq > 0)
    {
        system("cls");
        fflush(stdin);
        index = searchEmptyAlquiler(listAlq,tamAlq);
        printf("\t\t***ALTA DE ALQUILER***");
        if(index == -1)
        {
            printf("\nNo hay lugar en el sistema. \n") ;
            ret = -1 ;
            system("pause");

        }
        else
        {


            printf("\nNuevo alquiler, CODIGO numero %d. \n\n",index) ;

            // SE LE HACE SELECCIONAR UN JUEGO AL USUARIO
            do
            {
                printf("\nSeleccionar el juego alquiladp:\n");
                showJuegos(listJuego,tamJuego);
                while(!function_getStringNumeros("\n\nIngrese el numero de codigo del JUEGO: ",auxJuego))
                {
                    printf("Error el codigo debe tener solo numeros.\n\n");
                    system("pause");
                }
                indexJuego = findJuego(listJuego,tamJuego,atoi(auxJuego));
                if(indexJuego == -1)
                {
                    printf("\n***ERROR*** El codigo del juego es incorrecto");
                }
                else
                {
                    system("cls");
                    printf("\n\nEl juego seleccionado es:\n");
                    printf("\n\n\nCODIGO\tDESCRIPCION\tIMPORTE\n\n");
                    showJuego(listJuego[indexJuego]);
                }

            }
            while(indexJuego == -1);

            // carga de Cliente
            printf("\nSeleccionar el cliente que realizo el alquiler:\n");
            showClientes(listClientes,tamClie);
            do
            {
                while(!function_getStringNumeros("\nIngrese el numero de codigo del cliente: ",auxCliente))
                {
                    printf("\nError el codigo debe tener solo numeros.\n\n");
                    system("pause");
                }
                indexCliente = findCliente(listClientes,tamClie,atoi(auxCliente));
                if(indexCliente == -1)
                {
                    printf("\n***ERROR*** Codigo incorrecto\n");
                    system("pause");
                }
                else
                {
                    printf("\nEl cliente seleccionado es:\n");
                    printf("\n\nCODIGO\tAPELLIDO NOMBRE\tSEXO\tDOMICILIO\tTELEFONO\n\n");
                    showCliente(listClientes[indexCliente]);
                }

            }
            while(indexCliente == -1);

            //carga de la fecha
            printf("\n\nIngresar fecha del alquiler:\n");
            ingresarDia(dia);
            ingresarMes(mes);
            ingresarAnio(anio);

            //se copian todos los datos al nuevo Alquiler
            newAlquiler.codigoDeAlquiler = index;
            newAlquiler.codigoJuego = listJuego[indexJuego];
            newAlquiler.codigoCliente = listClientes[indexCliente];
            newAlquiler.fechaDeAlquiler.dia = atoi(dia);
            newAlquiler.fechaDeAlquiler.mes = atoi(mes);
            newAlquiler.fechaDeAlquiler.anio = atoi(anio);
            newAlquiler.isEmpty = 0;
            listAlq[index] = newAlquiler;
            system("cls");
            mostrarAlquiler(listAlq[index],tamAlq,listJuego,tamJuego,listClientes,tamClie);
            printf("\n\n");


        }
    }
    else
    {
        ret = -1 ;
    }
    return ret;
}

void mostrarAlquiler(eAlquileres listAlq,int lenAlq,eJuego listJuego[],int lenJuegos,eClientes listCliente[],int lenClien)
{
    int indexJuego,indexCliente;

    printf("\t\t-ALQUILER-\n\nCodigo del alquiler: %d\nFecha del alquiler: %d/%d/%d\n\n",listAlq.codigoDeAlquiler,listAlq.fechaDeAlquiler.dia,listAlq.fechaDeAlquiler.mes,listAlq.fechaDeAlquiler.anio);

    indexJuego = findJuego(listJuego,lenJuegos,listAlq.codigoJuego.codigoDelJuego); // se busca la posicion del juego

    printf("\t\t Juego \nDescripcion: %s\nImporte: $%0.2f \n\n",listJuego[indexJuego].descripcion,listJuego[indexJuego].importeDelJuego);

    indexCliente = findCliente(listCliente,lenClien,listAlq.codigoCliente.codigoDeCliente);
    printf("\t\t Cliente \nApellido y nombre: %s %s\nCodigo del cliente: %d",listCliente[indexCliente].apellidoCliente,listCliente[indexCliente].nombreCliente,listCliente[indexCliente].codigoDeCliente);

}


void showAlquileres(eAlquileres listAlq[],int lenAlq,eJuego listJuego[],int lenJuegos,eClientes listCliente[],int lenClien)
{

    for(int i=0; i<lenAlq; i++)
    {
        if(listAlq[i].isEmpty == 0)
        {
            printf("\n");
            mostrarAlquiler(listAlq[i],lenAlq,listJuego,lenJuegos,listCliente,lenClien);
            printf("\n_________________________________________________________________________\n");
        }
    }

}


int menuAlquileres ( )
{
    char auxOption[2];
    int option;
    system("cls") ;
    printf("\n\t\t*** ALQUILERES ***\n\n");
    printf("1-ALTA ALQUILER\n");
    printf("2-MOSTRAR ALQUILERES\n\n") ;
    printf("3-VOLVER\n\n");
    while(!function_getStringNumeros("Ingresar opcion: ",auxOption))
    {
        printf("\n*** ERROR *** Debe ingresar un numero del 1 al 3. \n") ;
        system("pause") ;

    }
    option = atoi(auxOption) ;
    return option;
}


void hardcodeoAlquileres(eAlquileres* list)
{
    eAlquileres nuevosAlquileres[] =
    {
        {1,{1,"FIFA 20",4599,0},{1,"Riquelme","Juan","Masculino","San Martin 915",1136823896,0},{12,12,2019},0},
        {2,{1,"FIFA 20",4599,0},{4,"Otto","Rocio","Femenino","Rodriguez 337",1152967818,0},{01,05,2019},0},
        {3,{1,"FIFA 20",4599,0},{1,"Riquelme","Juan","Masculino","San Martin 915",1136823896,0},{28,04,2019},0},
        {4,{3,"Clash Royale",2500,0},{2,"Palermo","Martin","Masculino","Brandsen 605",1136553824,0},{02,05,2018},0},
        {5,{4,"Trapping",1700,0},{5,"Duki","Rosa","Femenino","Antezana 247",1112345896,0},{12,12,2019},0},
    };
    for(int i = 0; i< 5; i++)
    {
        list[i] = nuevosAlquileres[i];
    }
}
