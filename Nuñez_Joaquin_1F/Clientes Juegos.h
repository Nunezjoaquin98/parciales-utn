typedef struct
{
    int codigoDelJuego;
    char descripcion[51];
    float importeDelJuego;
    int isEmpty;
}eJuego;

typedef struct
{
    int codigoDeCliente;
    char apellidoCliente[31];
    char nombreCliente[31];
    char sexoCliente[13];
    char domicilioCliente[51];
    int telefono;
    int isEmpty;
}eClientes;

// funciones de juegos

void hardcodeoJuegos(eJuego* list);

int sortJuegos(eJuego list[], int len);

void showJuego(eJuego list);

void showJuegos(eJuego list[],int len);

int findJuego(eJuego list[], int len, int id);

float obtenerPrecioJuego(eJuego listJuego[],int lenJuego,int codigo);

//funciones de clientes

int menuClientes( );

int menuModificarClientes( );

void hardcodeoClientes(eClientes* list);

int initClientes(eClientes list[], int len);

int searchEmpty(eClientes list[],int len);

int findCliente(eClientes list[], int len, int id);

void showCliente(eClientes list);

void showClientes(eClientes list[],int len);

int addCliente(eClientes list[], int len);

void modifyCliente(eClientes list[], int len);

int removeCliente(eClientes list[], int len,int id) ;

int sortClientes(eClientes list[], int len);
