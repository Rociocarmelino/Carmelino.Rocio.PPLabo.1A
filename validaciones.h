#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED


/** \brief
 *
 * \param valor char
 * \param a char
 * \param b char
 * \return int
 *
 */
int validarCaracter(char valor,char a,char b);


/** \brief
 *
 * \param valor int
 * \param minimo int
 * \param maximo int
 * \return int
 *
 */
int validarRangoEnteros(int valor,int minimo,int maximo);


/** \brief
 *
 * \param pString[] char
 * \param largo int
 * \return int
 *
 */
int validarLargoStrings(char pString[],int largo);


/** \brief
 *
 * \param iD int
 * \param tipos[] eTipo
 * \param tam_t int
 * \return int
 *
 */
int validarIdTipos(int iD,eTipo tipos[],int tam_t);


/** \brief
 *
 * \param iD int
 * \param colores[] eColor
 * \param tam_c int
 * \return int
 *
 */
int validarIdColores(int iD,eColor colores[],int tam_c);


/** \brief
 *
 * \param valor int
 * \return int
 *
 */
int validarCilindrada(int valor);


/** \brief
 *
 * \param iD int
 * \param servicios[] eServicio
 * \param tam_s int
 * \return int
 *
 */
int validarIdServicios(int iD,eServicio servicios[],int tam_s);


/** \brief
 *
 * \param iD int
 * \param lista[] eMoto
 * \param tam_m int
 * \return int
 *
 */
int validarIdMotos(int iD,eMoto lista[],int tam_m);


/** \brief
 *
 * \param valorDia int
 * \param valorMes int
 * \param valorAnio int
 * \return int
 *
 */
int validarFecha(int valorDia, int valorMes, int valorAnio);


/** \brief
 *
 * \param iD int
 * \param eCliente[]
 * \param tamcl int
 * \return int
 *
 */
int validarIdClientes(int iD,eCliente[],int tamcl);

