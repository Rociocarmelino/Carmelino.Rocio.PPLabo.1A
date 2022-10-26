#ifndef ENTIDAD1_H_INCLUDED
#define ENTIDAD1_H_INCLUDED


#endif // ENTIDAD1_H_INCLUDED


/** \brief Imprime las motos con todos sus campos
 *
 * \param moto eMoto recibe una moto
 * \param tipos[] eTipo estructura tipo
 * \param tam_t int tamaño del array tipo
 * \param colores[] eColor estructura color
 * \param tam_c int tamaño del array de color
 * \param clientes[] eCliente estructura cliente
 * \param tamcl int tamaño del array clientes
 * \return int devuelve 1 si salio todo bien o 0 si salio todo mal
 *
 */
int mostrarMoto(eMoto moto,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tamcl);


/** \brief Imprime la lista de motos
 *
 * \param lista[] eMoto estructura moto
 * \param tam_m int tamaño del array motos
 * \param tipos[] eTipo estructura tipo
 * \param tam_t int tamaño del array tipos
 * \param colores[] eColor estructura color
 * \param tam_c int tamaño del array de colores
 * \param clientes[] eCliente estructura cliente
 * \param tamcl int tamaño del array clientes
 * \return int devuelve 1 si salio todo bien o 0 si salio todo mal
 *
 */
int mostrarMotos(eMoto lista[], int tam_m,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tamcl);


/** \brief Busca un espacio libre es la estructura moto
 *
 * \param lista[] eMoto estructura moto
 * \param tam_m int tamaño del array de motos
 * \return int Si encontro espacio retorna el indice y si no encontro espacio retorna -1
 *
 */
int buscarLibre(eMoto lista[],int tam_m);


/** \brief Busca una moto cargada y se fija si coincide el id con el id que se ingreso
 *
 * \param lista[] eMoto estructura moto
 * \param tam int tamaño de la estructura moto
 * \param id int valor del id que se ingreso
 * \return int Si encontro la moto con el mismo id retorna el indice y si no retorna -1
 *
 */
int buscarMoto(eMoto lista[],int tam,int id);


/** \brief Modifica el campo de una moto que se dio de alta
 *
 * \param lista[] eMoto estructura moto
 * \param tam int tamaño del array de motos
 * \param colores[] eColor estructura color
 * \param tam_c int tamaño del array colores
 * \param tipos[] eTipo estrutura tipo
 * \param tam_t int tamaño del array tipos
 * \param clientes[] eCliente estructura cliente
 * \param tamcl int tamaño del array de clientes
 * \return int devuelve 1 si salio todo bien o 0 si salio todo mal
 *
 */
int modificarMotos(eMoto lista[],int tam,eColor colores[],int tam_c,eTipo tipos[],int tam_t,eCliente clientes[],int tamcl);



/** \brief Se da de baja una moto que esta cargada en el sistema
 *
 * \param lista[] eMoto estructura moto
 * \param tam int tamaño del array de motos
 * \param tipos[] eTipo estructura tipo
 * \param tam_t int tamaño del array tipos
 * \param colores[] eColor estructura color
 * \param tam_c int tamaño del array de colores
 * \param clientes[] eCliente estructura cliente
 * \param tamcl int tamaño del array de clientes
 * \return int devuelve 1 si salio todo bien o 0 si salio todo mal
 *
 */
int bajaMoto(eMoto lista[],int tam,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tamcl);


/** \brief Inicia todos los campos de la estructura moto , los pone en 1
 *
 * \param lista[] eMoto estructura moto
 * \param tam int tamaño del array de motos
 * \return int devuelve 1 si salio todo bien o 0 si salio todo mal
 *
 */
int inicializar(eMoto lista[],int tam);


/** \brief Imprime el menu de modificacion
 *
 * \return int retorna la opcion elegida
 *
 */
int menuModificacion();


/** \brief carga en el sistema todos los datos de las motos
 *
 * \param pMoto eMoto* recibe un puntero donde se van a guardar los datos ingresados
 * \param tipos[] eTipo estructura tipo
 * \param tam_t int tamaño del array tipos
 * \param colores[] eColor estructura color
 * \param tam_c int tamaño del array de colores
 * \param clientes[] eCliente estructura cliente
 * \param tamcl int tamaño del array de clientes
 * \return int  devuelve 1 si salio todo bien o 0 si salio todo mal
 *
 */
int cargarMoto(eMoto* pMoto,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tamcl);



/** \brief Da de alta las motos
 *
 * \param int*pId recibe un puntero al valor del id de motos
 * \param lista[] eMoto estructura moto
 * \param tam int tamaño de la estructura motos
 * \param tipos[] eTipo estructura tipo
 * \param tam_t int tamaño del array de tipos
 * \param colores[] eColor estructura color
 * \param tam_c int tamaño del array de colores
 * \param clientes[] eCliente estructura cliente
 * \param tamcl int tamaño del array de clientes
 * \return int devuelve 1 si salio todo bien o 0 si salio todo mal
 *
 */
int altaMoto(int*pId,eMoto lista[], int tam,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tamcl);

