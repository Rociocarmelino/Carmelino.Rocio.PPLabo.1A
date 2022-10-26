#ifndef ENTIDAD2_H_INCLUDED
#define ENTIDAD2_H_INCLUDED




#endif // ENTIDAD2_H_INCLUDED


/** \brief Da de alta un trabajo
 *
 * \param int*pId recibe un puntero al id de trabajo
 * \param trabajos[] eTrabajo estructura trabajo
 * \param tam_tr int tamaño del array de trabajos
 * \param lista[] eMoto estructura moto
 * \param tam_m int tamaño del array de  motos
 * \param servicios[] eServicio estructura servicio
 * \param tam_s int tamaño del araay de servicios
 * \param tipos[] eTipo estructura tipo
 * \param tam_t int tamaño del array de tipos
 * \param colores[] eColor estructura color
 * \param tam_c int tamaño del array de colores
 * \param clientes[] eCliente estructura color
 * \param tamcl int tamaño del array colores
 * \return int devuelve 1 si salio todo bien o 0 si salio todo mal
 *
 */
int altaTrabajo(int*pId,eTrabajo trabajos[], int tam_tr,eMoto lista[],int tam_m,eServicio servicios[],int tam_s,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tamcl);


/** \brief carga en el sistema todos los datos de los trabajos
 *
 * \param pTrabajo eTrabajo* recibe un puntero donde se van a guardar los datos ingresados
 * \param lista[] eMoto estructura moto
 * \param tam_m int tamaño del array de motos
 * \param servicios[] eServicio estructura servicio
 * \param tam_s int tamaño del array de servicios
 * \param tipos[] eTipo estructura tipo
 * \param tam_t int tamaño del array de tipos
 * \param colores[] eColor estructura color
 * \param tam_c int tamaño del array de colores
 * \param clientes[] eCliente estructura clientes
 * \param tamcl int tamaño del array de clientes
 * \return int devuelve 1 si salio todo bien o 0 si salio todo mal
 *
 */
int cargarTrabajo(eTrabajo* pTrabajo,eMoto lista[],int tam_m,eServicio servicios[],int tam_s,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tamcl);

/** \brief
 *
 * \param trabajos[] eTrabajo
 * \param tam_tr int
 * \return int
 *
 */
int buscarLibreTrabajo(eTrabajo trabajos[],int tam_tr);

/** \brief
 *
 * \param trabajo eTrabajo
 * \param lista[] eMoto
 * \param tam_m int
 * \param servicios[] eServicio
 * \param tam_s int
 * \return int
 *
 */
int mostrarTrabajo(eTrabajo trabajo,eMoto lista[],int tam_m,eServicio servicios[],int tam_s);

/** \brief
 *
 * \param trabajos[] eTrabajo
 * \param tam_t int
 * \param lista[] eMoto
 * \param tam_m int
 * \param servicios[] eServicio
 * \param tam_s int
 * \return int
 *
 */
int mostrarTrabajos(eTrabajo trabajos[],int tam_t,eMoto lista[],int tam_m,eServicio servicios[],int tam_s);

/** \brief
 *
 * \param trabajos[] eTrabajo
 * \param tam_tr int
 * \return int
 *
 */
int inicializarTrabajos(eTrabajo trabajos[],int tam_tr);



