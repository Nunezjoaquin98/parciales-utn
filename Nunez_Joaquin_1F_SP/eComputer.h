typedef struct{

    int id;
    char descripcion[256];
    int precio;
    int idTipo;

}eComputer;

//Seters
int eComputer_setId(eComputer* this, int idStr);
int eComputer_setDescripcion(eComputer* this, char* descripcionStr);
int eComputer_setPrecio(eComputer* this, int precioStr);
int eComputer_setTipo(eComputer* this, int tipoStr);

//Geters
int eComputer_getId(eComputer* this);
char eComputer_getDescripcion(eComputer* this,char* descripcionStr);
int eComputer_getPrecio(eComputer* this);
int eComputer_getIdTipo(eComputer* this);


eComputer* eComputer_new();
eComputer* eComputer_newParameters(char* idStr,char* descripcionStr,char* precioStr,char* idTipoStr);

int compareComputers(void* pComputerA,void* pComputerB);
