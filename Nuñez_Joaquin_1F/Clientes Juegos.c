#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "Clientes Juegos.h"

//FUNCIONES JUEGOS
void hardcodeoJuegos(eJuego* list)
{
    eJuego nuevosJuegos[] =
    {
        {1,"FIFA 20",4599,0},
        {2,"Call of Duty",3000,0},
        {3,"Clash Royale",2500,0},
        {4,"Trapping",1700,0},
        {5,"PES 2020",3999,0},

    };
    for(int i = 0; i< 5; i++)
    {
        list[i] = nuevosJuegos[i];
    }
}

int sortJuegos(eJuego list[], int len)
{
    eJuego auxJuego;
    int ret;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len -1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(strcmp(list[i].descripcion,list[j].descripcion) > 0 && list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {
                    auxJuego = list[i];
                    list[i] = list[j];
                    list[j] = auxJuego ;
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

void showJuego(eJuego list)
{
    printf("\n%d\t%s\t$%0.2f\n",list.codigoDelJuego,list.descripcion,list.importeDelJuego);

}

void showJuegos(eJuego list[],int len)
{
    printf("\n\nCODIGO\tDESCRIPCION\tIMPORTE\n\n");

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            showJuego(list[i]);
        }
    }

}

int findJuego(eJuego list[], int len, int id)
{
    int ret ;

    for(int i=0; i < len; i++)
    {

        if( list[i].codigoDelJuego == id && list[i].isEmpty == 0)
        {
            ret = i;
            break;
        }
        else
        {
            ret = -1;
        }
    }
    return ret;

}



//FUNCIONES CLIENTES

int menuClientes( )
{
    char auxOption[2];
    int option;
    system("cls") ;
    printf("\n\t\t*** CLIENTES ***\n\n");
    printf("1-ALTA\n");
    printf("2-MODIFICAR\n") ;
    printf("3-BAJA\n");
    printf("4-LISTAR\n\n") ;
    printf("5-VOLVER\n\n") ;
    while(!function_getStringNumeros("Ingresar opcion: ",auxOption))
    {
        printf("\n*** ERROR *** Debe ingresar un numero del 1 al 5. \n") ;
        system("pause") ;

    }
    option = atoi(auxOption) ;
    return option;
}

int menuModificarClientes( )
{
    char auxOption[2];
    int option;
    printf("\n\n*** Modificar Clientes ***\n\n1 - Apellido\n2 - Nombre\n3 - Sexo\n4 - Domicilio\n5 - Telefono\n\n6 - Regresar al menu principal\n\n");
    while(!function_getStringNumeros("Ingrese opcion: ",auxOption))
    {
        printf("*** Error *** Debe ingresar un numero.\n");
        system("pause");
        printf("\n");
    }
    option = atoi(auxOption);
    return option;

}

void hardcodeoClientes(eClientes* list)
{

    eClientes clientesNuevos[]=
    {
        {1,"Riquelme","Juan","Masculino","San Martin 915",1136823896,0},
        {2,"Palermo","Martin","Masculino","Brandsen 605",1136553824,0},
        {3,"Cordoba","Oscar","Masculino","Arcos 906",1145923896,0},
        {4,"Otto","Rocio","Femenino","Rodriguez 337",1152967818,0},
        {5,"Duki","Rosa","Femenino","Antezana 247",1112345896,0},
    };
    for(int i = 0; i< 5; i++)
    {
        list[i] = clientesNuevos[i];
    }
};


int initClientes(eClientes list[], int len)
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

int searchEmpty(eClientes list[],int len)
{
    int index = -1;
    for(int i=0; i<len ; i++)
    {
        if( list[i].isEmpty == 1)
        {
            index = i ;
            break;
        }
    }
    return index ;
}

int findCliente(eClientes list[], int len, int id)
{
    int ret ;

    for(int i=0; i < len; i++)
    {

        if( list[i].codigoDeCliente == id && list[i].isEmpty == 0)
        {
            ret = i;
            break;
        }
        else
        {
            ret = -1;
        }
    }
    return ret;

}

void showCliente(eClientes list)
{
    printf("\n%d\t%s\t%s\t%s\t%s\t%d\n",list.codigoDeCliente,list.apellidoCliente,list.nombreCliente,list.sexoCliente,list.domicilioCliente,list.telefono);

}

void showClientes(eClientes list[],int len)
{
    printf("\n\nCODIGO\tAPELLIDO NOMBRE\tSEXO\tDOMICILIO\tTELEFONO\n\n");

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            showCliente(list[i]);
        }
    }

}


int addCliente(eClientes list[], int len)
{
    eClientes newCliente;
    int ret,index,sex;
    char auxName[31];
    char auxLastName[31];
    char auxSex[10];
    char auxTelefono[10] ;
    char auxDomicilio[31];

    if(list != NULL && len > 0)
    {
        system("cls");
        fflush(stdin);
        index = searchEmpty(list,len) ;
        printf("\n\t------- Alta Cliente -------\n\n");

        if(index == -1)
        {
            printf("No hay lugar en el sistema. \n") ;
            ret = -1 ;
            system("pause");

        }
        else
        {
            printf("\nNuevo cliente, codigo numero %d. \n\n",index) ;
            newCliente.codigoDeCliente = index ;
            while(!function_getStringLetras("Ingrese el nombre del cliente: ",auxName)) //nombre
            {
                printf("El nombre solo debe tener letras.\n\n") ;
                system("pause");
                system("cls");

            }
            while(!function_getStringLetras("\nIngrese el apellido del cliente: ",auxLastName)) //apellido
            {
                printf("El apellido debe tener solo letras.\n\n") ;
                system("pause");
                system("cls");

            }

            do
            {
                while(!function_getStringNumeros("\n\tSELLECION DE GENERO \nIngrese 1 si es MASCULINO o 2 si es FEMENINO: ",auxSex)) //seleccionar genero
                {
                    printf("**** Error ****Debe ingresar el numero 1 o 2\n\n");
                    system("pause");
                    system("cls");
                }
                sex = atoi(auxSex);
                if(sex == 1)
                {
                    strcpy(auxSex,"Masculino");
                }
                else if(sex == 2)
                {
                    strcpy(auxSex,"Femenino");
                }

            }
            while(!(sex == 1 || sex == 2));


            printf("\nIngrese el domicilio del cliente: ");
            fflush(stdin);
            gets(auxDomicilio); // Domicilio

            while(!function_getStringNumeros("\nIngrese un telefono(solo numeros): ",auxTelefono)) //telefono
            {
                printf("**** Error **** Debe contener solo numeros\n\n");
                system("pause");
                system("cls");

            }

            // se copian todos los datos del nuevo cliente

            strcpy(newCliente.nombreCliente,auxName) ;
            strcpy(newCliente.apellidoCliente,auxLastName) ;
            strcpy(newCliente.sexoCliente,auxSex);
            newCliente.telefono = atoi(auxTelefono) ;
            strcpy(newCliente.domicilioCliente,auxDomicilio);
            newCliente.isEmpty = 0;
            list[index] = newCliente ;
            system("pause");
            system("cls");
            printf("\n\nCLIENTE DADO DE ALTA CON EXITO:\n\n");
            printf("\n\nCODIGO\tAPELLIDO\tNOMBRE\tSEXO\tDOMICILIO\tTELEFONO\n\n");
            showCliente(list[index]);
            printf("\n\n\n");
            system("pause");
            ret = 0 ;
        }
    }
    else
    {
        ret = -1 ;
    }
    return ret;
}

void modifyCliente(eClientes list[], int len)
{
    int id,index,sexo;
    char salir = 'n';

    char auxCodigo[5];
    char newLastName[31] ;
    char newName[31];
    char newSex[3];
    char newDomicilio[51];
    char newTelefono[16];


    system("cls");
    printf("\t\t  *** Modificar  Cliente ***\n\n");
    showClientes(list,len);
    if(!function_getStringNumeros("\nIngrese el codigo del cliente: ",auxCodigo))
    {
        printf("*** ERROR *** El codigo debe contener solo numeros.\n") ;
    }

    id = atoi(auxCodigo) ;
    index = findCliente(list, len, id);


    if( index == -1)
    {
        printf("\n\nNo hay ningun cliente con codigo %d.\n\n", id);
        system("pause");
    }
    else
    {


        showCliente(list[index]) ;
        do
        {
            system("cls");
            showCliente(list[index]);
            switch(menuModificarClientes())
            {
            case 1:
                showCliente(list[index]);
                printf("\n\n");
                //modificar apellido
                while(!function_getStringLetras("Ingrese nuevo apellido: ",newLastName))
                {
                    printf("*** ERROR *** El apellido debe tener solo letras.\n\n");
                }
                strcpy(list[index].apellidoCliente,newLastName);
                printf("\n\n        ***Modificacion exitosa***\n\n");
                system("pause");
                system("cls");
                break ;
            case 2:
                // Modifica nombre
                while(!function_getStringLetras("Ingrese nuevo nombre: ",newName))
                {
                    printf("*** Error *** El nombre debe tener solo letras.");
                }
                strcpy(list[index].nombreCliente,newName);
                printf("\n\n        ***Modificacion exitosa***\n\n");
                system("pause");
                system("cls");
                break ;
            case 3:
                // modifica genero
                showCliente(list[index]);
                printf("\n\n");
                do
                {
                    while(!function_getStringNumeros("\n\tSELLECION DE GENERO \nIngrese 1 si es MASCULINO o 2 si es FEMENINO: ",newSex))
                    {
                        printf("**** Error ****Debe ingresar el numero 1 o 2\n\n");
                        system("pause");
                        system("cls");
                    }
                    sexo = atoi(newSex);
                    if(sexo == 1)
                    {
                        strcpy(newSex,"Masculino");
                    }
                    else if(sexo == 2)
                    {
                        strcpy(newSex,"Femenino");
                    }

                }
                while(!(sexo == 1 || sexo == 2));
                strcpy(list[index].sexoCliente,newSex);
                printf("\n\n        ***Modificacion exitosa***\n\n");
                system("pause");
                system("cls") ;
                break ;
            case 4:
                //MODIFICA DOMICILIO
                showCliente(list[index]);
                printf("\n\tModificar Domicilio\n\nIngrese el nuevo domicilio:");
                fflush(stdin);
                gets(newDomicilio);
                strcpy(list[index].domicilioCliente,newDomicilio);
                printf("\n\n        ***Modificacion exitosa***\n\n");
                system("pause");
                system("cls") ;
                break ;

            case 5:
                // MODIFICA TELEFONO
                showCliente(list[index]);
                printf("\n\n");
                while(!function_getStringNumeros("Ingrese nuevo telefono sin puntos ni comas: ",newTelefono))
                {
                    printf("*** ERROR *** El telefono debe contener solo numeros.\n\n") ;
                }
                list[index].telefono = atoi(newTelefono);
                printf("\n\n        ***Modificacion exitosa***\n\n");
                system("pause");
                system("cls") ;
                break ;


            case 6:
                printf("\n\t***Regresando***\n\n");
                salir = 's';
                system("pause");
                system("cls");
                break;
            default:
                printf("*** ERROR *** Debe ingresar un numero del 1 al 6.\n");
                system("pause");
                break;
            }
        }
        while(salir == 'n');
    }
}

int removeCliente(eClientes list[], int len,int id)
{
    char auxId[10];
    char auxYes[10];
    int yes,index,ret;

    if(list != NULL && len > 0)
    {
        do
        {
            system("cls");
            printf("\t\t  ***Baja de Cliente***\n");
            showClientes(list,len);
            while(!function_getStringNumeros("\n\nIngrese el codigo del cliente a borrar: ",auxId))
            {
                printf("***Error*** Debe ingresar un numero.\n");
                system("pause");
            }
            id = atoi(auxId);
            index = findCliente(list,len,id);
            if( index == -1)
            {
                printf("No hay ningun cliente con codigo %d.\n\n", id);
                system("pause");
            }
            else
            {
                showCliente(list[index]);

                while(!function_getStringNumeros("\nEs este el cliente que desea borrar?\nIngrese 1 si es correcto / Otro numero si es incorrecto: ",auxYes))
                {
                    printf("***Error*** Debe ingresar un numero.\n");
                    system("pause");
                }
                yes = atoi(auxYes);
                if(yes == 1)
                {
                    system("cls");
                    printf("El cliente ha sido borrado con exito!\n");
                    system("pause");
                    list[index].isEmpty = 1 ;
                }
                else
                {
                    printf("Baja cancelada.\n");
                    system("pause");
                }

            }


        }
        while(index == -1);

    }
    else
    {
        ret = -1;
    }

    return ret;
}


int sortClientes(eClientes list[], int len)
{
    eClientes auxCliente;
    int ret;

    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len -1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(strcmp(list[i].apellidoCliente,list[j].apellidoCliente) > 0 && list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {
                    auxCliente = list[i];
                    list[i] = list[j];
                    list[j] = auxCliente ;
                }
                else if(strcmp(list[i].apellidoCliente,list[j].apellidoCliente) == 0 && strcmp(list[i].nombreCliente,list[j].nombreCliente)>0 && list[i].isEmpty == 0 && list[j].isEmpty == 0)
                {
                    auxCliente = list[i];
                    list[i] = list[j];
                    list[j] = auxCliente ;
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
