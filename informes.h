#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED


/** \brief
 *
 * \param lista[] eMoto
 * \param tam_m int
 * \param colores[] eColor
 * \param tam_c int
 * \param tipos[] eTipo
 * \param tam_t int
 * \param clientes[] eCliente
 * \param tamcl int
 * \return int
 *
 */
int colorSeleccionadoPorUsuario(eMoto lista[],int tam_m,eColor colores[],int tam_c,eTipo tipos[],int tam_t,eCliente clientes[],int tamcl);


/** \brief
 *
 * \param lista[] eMoto
 * \param tam_m int
 * \param colores[] eColor
 * \param tam_c int
 * \param tipos[] eTipo
 * \param tam_t int
 * \param clientes[] eCliente
 * \param tamcl int
 * \return int
 *
 */
int tipoSeleccionadoPorUsuario(eMoto lista[],int tam_m,eColor colores[],int tam_c,eTipo tipos[],int tam_t,eCliente clientes[],int tamcl);

/** \brief
 *
 * \param int*pOpcion
 * \return int
 *
 */
int menuInformes(int*pOpcion);


/** \brief
 *
 * \param lista[] eMoto
 * \param tam_m int
 * \param tipos[] eTipo
 * \param tam_t int
 * \param colores[] eColor
 * \param tam_c int
 * \param clientes[] eCliente
 * \param tamcl int
 * \return int
 *
 */
int mostrarMotosPorTipos(eMoto lista[],int tam_m,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tamcl);


/** \brief
 *
 * \param lista[] eMoto
 * \param tam_m int
 * \param tipos[] eTipo
 * \param tam_t int
 * \param colores[] eColor
 * \param tam_c int
 * \param clientes[] eCliente
 * \param tamcl int
 * \return int
 *
 */
int mayorCilindrada(eMoto lista[],int tam_m,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tamcl);


/** \brief
 *
 * \param lista[] eMoto
 * \param tam_m int
 * \param tipos[] eTipo
 * \param tam_t int
 * \param colores[] eColor
 * \param tam_c int
 * \param clientes[] eCliente
 * \param tamcl int
 * \return int
 *
 */
int mostrarColorTipoElegido(eMoto lista[],int tam_m,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tamcl);


/** \brief
 *
 * \param lista[] eMoto
 * \param tam_m int
 * \param trabajo[] eTrabajo
 * \param tam_tr int
 * \param tipos[] eTipo
 * \param tam_t int
 * \param colores[] eColor
 * \param tam_c int
 * \param servicios[] eServicio
 * \param tam_s int
 * \param clientes[] eCliente
 * \param tamcl int
 * \return int
 *
 */
int trabajosMotos(eMoto lista[],int tam_m,eTrabajo trabajo[],int tam_tr,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eServicio servicios[],int tam_s,eCliente clientes[],int tamcl);


/** \brief
 *
 * \param lista[] eMoto
 * \param tam_m int
 * \param trabajo[] eTrabajo
 * \param tam_tr int
 * \param tipos[] eTipo
 * \param tam_t int
 * \param colores[] eColor
 * \param tam_c int
 * \param servicios[] eServicio
 * \param tam_s int
 * \param clientes[] eCliente
 * \param tamcl int
 * \return int
 *
 */
int sumaImporteMotos(eMoto lista[],int tam_m,eTrabajo trabajo[],int tam_tr,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eServicio servicios[],int tam_s,eCliente clientes[],int tamcl);


/** \brief
 *
 * \param lista[] eMoto
 * \param tam_m int
 * \param trabajo[] eTrabajo
 * \param tam_tr int
 * \param tipos[] eTipo
 * \param tam_t int
 * \param colores[] eColor
 * \param tam_c int
 * \param servicios[] eServicio
 * \param tam_s int
 * \return int
 *
 */
int serviciosMotosYlaFecha(eMoto lista[],int tam_m,eTrabajo trabajo[],int tam_tr,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eServicio servicios[],int tam_s);


/** \brief
 *
 * \param lista[] eMoto
 * \param tam_m int
 * \param trabajo[] eTrabajo
 * \param tam_tr int
 * \param tipos[] eTipo
 * \param tam_t int
 * \param colores[] eColor
 * \param tam_c int
 * \param servicios[] eServicio
 * \param tam_s int
 * \return int
 *
 */
int serviciosFecha(eMoto lista[],int tam_m,eTrabajo trabajo[],int tam_tr,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eServicio servicios[],int tam_s);


/** \brief
 *
 * \param lista[] eMoto
 * \param tam_m int
 * \param colores[] eColor
 * \param tam_c int
 * \return int
 *
 */
int colorMasElegido(eMoto lista[],int tam_m,eColor colores[],int tam_c);
