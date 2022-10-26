#ifndef PARCIAL_H_INCLUDED
#define PARCIAL_H_INCLUDED

typedef struct{

    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int id;
    char descripcion[20];
    int isEmpty;
}eTipo;
typedef struct{
    int id;
    char nombreColor[20];
    int isEmpty;
}eColor;

typedef struct{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    int cilindrada;
    int puntaje;
    int idCliente;

    int isEmpty;

}eMoto;


typedef struct{

    int id;
    char descripcion[25];
    int precio;
    int isEmpty;

}eServicio;

typedef struct{

    int id;
    int idMoto;
    int idServicio;
    eFecha fecha;
    int isEmpty;

}eTrabajo;

typedef struct{

    int id;
    char nombre[20];
    char sexo;

}eCliente;


#endif // PARCIAL_H_INCLUDED

/** \brief Imprime el menu principal
 *
 * \return char retorna la opcion elegida
 *
 */
char mostrarMenu();




/** \brief muestra los tipos
 *
 * \param tipos[] eTipo estructura tipos
 * \param tam_t int tamaño del array tipos
 * \return int devuelve 1 si salio todo bien o 0 si salio todo mal
 *
 */


int mostrarTipos(eTipo tipos[], int tam_t);


/** \brief muestra los colores
 *
 * \param colores[] eColor estructura colores
 * \param tam_c int tamaño del array colores
 * \return int devuelve 1 si salio todo bien o 0 si salio todo mal
 *
 */
int mostrarColores(eColor colores[], int tam_c);


/** \brief Imprime la lista de los tipos con su descripcion
 *
 * \param tipos[] eTipo estructura tipos
 * \param tam_t int tamaño del array tipos
 * \return int devuelve 1 si salio todo bien o 0 si salio todo mal
 *
 */
int mostrarTiposLista(eTipo tipos[], int tam_t);


/** \brief Muestra los servicios
 *
 * \param servicios[] eServicio estructura servicios
 * \param tam_s int  tamaño del array servicios
 * \return int devuelve 1 si salio todo bien o 0 si salio todo mal
 *
 */
int mostrarServicios(eServicio servicios[], int tam_s);


/** \brief Muestra los clientes
 *
 * \param clientes[] eCliente
 * \param tamcl int estructura clientes
 * \return int devuelve 1 si salio todo bien o 0 si salio todo mal
 *
 */
int mostrarClientes(eCliente clientes[], int tamcl);


/** \brief Harcodeo de los datos de la estructura motos
 *
 * \param pId int* recibe un puntero al id de motos para que se autoincremente
 * \param vec[] eMoto estructura motos
 * \param tam int tamaño del array de motos
 * \param cant int cantidad de motos que quiero que se harcodeen
 * \return int devuelve 1 si salio todo bien o 0 si salio todo mal
 *
 */
int harcodearMotos(int* pId, eMoto vec[],int tam, int cant);

/** \brief Imprime la lista de los colores con su descripcion
 *
 * \param colores[] eColor estructura color
 * \param tam_c int tamaño del array colores
 * \return int devuelve 1 si salio todo bien o 0 si salio todo mal
 *
 */
int mostrarColoresLista(eColor colores[], int tam_c);


/** \brief Imprime la lista de los servicios con su descripcion
 *
 * \param servicios[] eServicio estructura servicio
 * \param tam_s int tamaño del array servicios
 * \return int devuelve 1 si salio todo bien o 0 si salio todo mal
 *
 */
int mostrarServiciosLista(eServicio servicios[], int tam_s);


/** \brief Si el id que se ingreso es igual a un id de tipos , imprime su descripcion
 *
 * \param id int recibe un valor id
 * \param descripcion[] char vector donde se va a guardar la descipcion del tipo
 * \param tipos[] eTipo estructura tipo
 * \param tam_t int tamaño del array tipos
 * \return int devuelve 1 si salio todo bien o 0 si salio todo mal
 *
 */
int cargarDescripcionTipos(int id, char descripcion[],eTipo tipos[], int tam_t);


/** \brief Si el id que se ingreso es igual a un id de colores , imprime su descripcion
 *
 * \param id int recibe un valor id
 * \param nombreColor[] char vector donde se va a guardar la descipcion del color
 * \param colores[] eColor estructura color
 * \param tam_c int tamaño del array colores
 * \return int devuelve 1 si salio todo bien o 0 si salio todo mal
 *
 */
int cargarDescripcionColores(int id, char nombreColor[],eColor colores[], int tam_c);


/** \brief Si el id que se ingreso es igual a un id de servicios, imprime su descripcion
 *
 * \param id int recibe un valor id
 * \param descripcionServicio[] char vector donde se va a guardar la descipcion del servicio
 * \param servicios[] eServicio estructura servicio
 * \param tam_s int tamaño del array servicios
 * \return int devuelve 1 si salio todo bien o 0 si salio todo mal
 *
 */
int cargarDescripcionServicios(int id, char descripcionServicio[],eServicio servicios[],int tam_s);




/** \brief Si el id que se ingreso es igual a un id de clientes, imprime su nombre
 *
 *
 * \param id int recibe un valor id
 * \param nombreCliente[] char vector donde se va a guardar la descipcion del servicio
 * \param clientes[] eCliente estructura cliente
 * \param tamcl int tamaño del array clientes
 * \return int devuelve 1 si salio todo bien o 0 si salio todo mal
 *
 *
 */
int cargarDescripcionClientes(int id, char nombreCliente[],eCliente clientes[],int tamcl);


/** \brief Confirma la salida del usuario
 *
 * \param pVariable char* recibe un puntero
 * \param confirma char recibe un valor
 * \param rechaza char recibe un valor
 * \return int devuelve 1 si salio todo bien o 0 si salio todo mal
 *
 */
int confirmarSalida(char* pVariable, char confirma, char rechaza);


/** \brief Si el id que se ingreso es igual a un id de marcas, imprime su nombre
 *
 * \param id int recibe un valor id
 * \param descripcionMarca[] char vector donde se va a guardar la descipcion del servicio
 * \param lista[] eMoto estructura moto
 * \param tam_m int tamaño del array de motos
 * \return int devuelve 1 si salio todo bien o 0 si salio todo mal
 *
 */
int cargarDescripcionMarca(int id, char descripcionMarca[],eMoto lista[], int tam_m);




