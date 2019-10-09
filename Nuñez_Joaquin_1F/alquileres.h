typedef struct
{
    int codigoDeAlquiler;
    eJuego codigoJuego;
    eClientes codigoCliente;
    eFecha fechaDeAlquiler;
    int isEmpty;
}eAlquileres;


int initAlquileres(eAlquileres list[], int len);

int searchEmptyAlquiler(eAlquileres list[],int len);

void mostrarAlquiler(eAlquileres listAlq,int lenAlq,eJuego listJuego[],int lenJuegos,eClientes listCliente[],int lenClien);

void showAlquileres(eAlquileres listAlq[],int lenAlq,eJuego listJuego[],int lenJuegos,eClientes listCliente[],int lenClien);

int addAlquiler(eClientes listClientes[],int tamClie,eJuego listJuego[],int tamJuego,eAlquileres listAlq[],int tamAlq);

int menuAlquileres ( );

void hardcodeoAlquileres(eAlquileres* list);
