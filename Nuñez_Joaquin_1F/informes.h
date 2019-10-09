
int menuInformes();
/** \brief Menu de opciones de los informes
 *
 * \return Opcion ingresada
 *
 */

void function_promedioTotalJuegos (eJuego listJuegos[],int lenJuegos, eAlquileres listAlq[],int lenAlq);

void listarClientesDeJuego(eJuego listJuegos[],int lenJuegos,eClientes listClientes[],int lenClientes,eAlquileres listAlquileres[],int lenAlquileres);

void listarJuegosDeCliente(eJuego listJuego[],int lenJuego,eClientes listClientes[],int lenClientes,eAlquileres listAlquileres[],int lenAlquileres);

int listarJuegosPorImporteBurbujeo(eJuego listJuego[], int lenJuego);

void listarClientesPorInsercion(eClientes list[], int len) ;

void juegoEnFechaDeterminada(eAlquileres listAlquileres[],int lenAlq,eJuego listJuego[],int lenJuego);

void clienteEnFechaDeterminada(eAlquileres listAlquileres[],int lenAlq,eClientes listClientes[],int lenCliente);
