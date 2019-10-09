#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "Clientes Juegos.h"
#include "fecha.h"
#include "alquileres.h"
#include "informes.h"
#define TAMCLIENTES 100
#define TAMJUEGOS 5
#define TAMAALQ 100
int main()
{
//declaro las variables
    char salir = 'n';
    char salirAlquiler = 'n';
    char salirInformes = 'n';
    eClientes clientes[TAMCLIENTES];
    eJuego juegos[TAMJUEGOS];
    eAlquileres alquileres[TAMAALQ];

    initClientes(clientes,TAMCLIENTES); //se inicializa todos los isEmpty en 1 indicando que estan vacios
    initAlquileres(alquileres,TAMAALQ);
    hardcodeoClientes(clientes);//se hardcodean clientes juegos y alquileres
    hardcodeoJuegos(juegos);
    hardcodeoAlquileres(alquileres);

    do
    {
        switch(menu())
        {
        case 1://clientes

            switch(menuClientes())
            {
            case 1:
                addCliente(clientes,TAMCLIENTES); //ALTA CLIENTE
                break;
            case 2:
                modifyCliente(clientes,TAMCLIENTES); // MODIFICAR CLIENTE
                break;
            case 3:
                removeCliente(clientes,TAMCLIENTES,0); //BAJA CLIENTE
                break;
            case 4:
                sortClientes(clientes,TAMCLIENTES); // LISTAR CLIENTES
                showClientes(clientes,TAMCLIENTES);
                system("pause");
                break;
            }
            break;

        case 2: //juegos
            sortJuegos(juegos,TAMJUEGOS);
            showJuegos(juegos,TAMJUEGOS);
            system("pause");
            break;

        case 3: //alquileres
            do
            {
                switch(menuAlquileres())
                {
                case 1:
                    addAlquiler(clientes,TAMCLIENTES,juegos,TAMJUEGOS,alquileres,TAMAALQ);
                    printf("\n\n");
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    showAlquileres(alquileres,TAMAALQ,juegos,TAMJUEGOS,clientes,TAMCLIENTES);
                    printf("\n\n");
                    system("pause");
                    break;
                case 3:
                    salirAlquiler = 's';
                    printf("\n\nVolviendo al menu principal...\n\n");
                    system("pause");
                    break;
                }
            }
            while(salirAlquiler == 'n');
            break;

        case 4: //informes
            do
            {
                switch(menuInformes())
                {
                case 7: //falta
                    function_promedioTotalJuegos(juegos,TAMJUEGOS,alquileres,TAMAALQ);
                    printf("\n\n");
                    system("pause");
                    break;
                case 9:
                    system("cls");
                    listarClientesDeJuego(juegos,TAMJUEGOS,clientes,TAMCLIENTES,alquileres,TAMAALQ);
                    printf("\n\n");
                    system("pause");
                    break;
                case 10:
                    system("cls");
                    listarJuegosDeCliente(juegos,TAMJUEGOS,clientes,TAMCLIENTES,alquileres,TAMAALQ);
                    printf("\n\n");
                    system("pause");
                    break;

                case 13:
                    system("cls");
                    juegoEnFechaDeterminada(alquileres,TAMAALQ,juegos,TAMJUEGOS);
                    printf("\n\n");
                    system("pause");
                    break;

                case 14:
                    system("cls");
                    clienteEnFechaDeterminada(alquileres,TAMAALQ,clientes,TAMCLIENTES);
                    printf("\n\n");
                    system("pause");
                    break;

                case 15:
                    system("cls");
                    listarJuegosPorImporteBurbujeo(juegos,TAMJUEGOS);
                    showJuegos(juegos,TAMJUEGOS);
                    printf("\n\n");
                    system("pause");
                    break;

                case 16:
                    system("cls");
                    listarClientesPorInsercion(clientes,TAMCLIENTES);
                    showClientes(clientes,TAMCLIENTES);
                    printf("\n\n");
                    system("pause");
                    break;
                case 17:
                    salirInformes = 's';
                    printf("\n\nVolviendo al menu principal...\n\n");
                    system("pause");
                    break;

                }




            }
            while(salirInformes == 'n');
            break;

        case 5:
            salir = 's';
            printf("\n\nSaliendo...\n\n");
            system("pause");
            break;


        default:
            printf("*** ERROR *** Debe ingresar un numero del 1 al 4\n\n") ; // el default se utiliza por si se ingresa un numero que no sea del 1 al 8
            system("pause");
            system("cls");
            break;

        }
    }
    while(salir == 'n');

    return 0;
}
