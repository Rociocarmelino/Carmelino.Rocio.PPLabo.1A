#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parcial.h"
#include <conio.h>
#include "entidad1.h"
#include "entidad2.h"
#include "validaciones.h"



int validarCaracter(char valor,char a,char b)
{
    int retorno=0;

    if(valor == a || valor == b)
    {

        retorno=1;
    }

    return retorno;
}


int validarRangoEnteros(int valor,int minimo,int maximo)
{
    int retorno=0;

    if(valor >=minimo && valor <= maximo)
    {
        retorno=1;
    }

    return retorno;
}
/*
int validarLargoStrings(char pString[],int largo)
{
    int retorno=0;
    char auxCad[20];

    if(pString != NULL && largo >0)
    {
       while(strlen(pString) > largo)
        {
             printf("Nombre demasiado largo. Reingrese nombre: ");
             fflush(stdin);
             gets(auxCad);
        }
     strcpy(pString,auxCad);
     retorno=1;

    }
    return retorno;
}*/


int validarIdTipos(int iD,eTipo tipos[],int tam_t)
{
    int retorno=0;

    if(tipos != NULL && tam_t >0)
    {
        for(int i=0;i<tam_t;i++)
        {
            if(tipos[i].id==iD)
            {
                retorno=1;
                break;
            }
        }

    }
    return retorno;
}

int validarIdColores(int iD,eColor colores[],int tam_c)
{
    int retorno=0;

    if(colores != NULL && tam_c >0)
    {
        for(int i=0;i<tam_c;i++)
        {
            if(colores[i].id==iD)
            {
                retorno=1;
                break;
            }
        }

    }
    return retorno;
}

int validarIdServicios(int iD,eServicio servicios[],int tam_s)
{
    int retorno=0;

    if(servicios != NULL && tam_s >0)
    {
        for(int i=0;i<tam_s;i++)
        {
            if(servicios[i].id==iD)
            {
                retorno=1;
                break;
            }
        }

    }
    return retorno;
}

int validarCilindrada(int valor)
{
    int retorno=0;

    if(valor == 50 || valor == 125 || valor == 500 || valor == 600 || valor == 750)
    {
        retorno=1;
    }

    return retorno;
}



int validarIdMotos(int iD,eMoto lista[],int tam_m)
{
    int retorno=0;

    if(lista != NULL && tam_m >0)
    {
        for(int i=0;i<tam_m;i++)
        {
            if(lista[i].id==iD)
            {
                retorno=1;
                break;
            }
        }

    }
    return retorno;

}

int validarFecha(int valorDia, int valorMes, int valorAnio)
{
	int retorno = 0;
	int fechaCorrecta = 0;


	    if ( valorMes >= 1 && valorMes <= 12)
	    {
	        switch ( valorMes )
	        {
	            case  1 :
	            case  3 :
	            case  5 :
	            case  7 :
	            case  8 :
	            case 10 :
	            case 12 :
	            	if ( valorDia >= 1 && valorDia <= 31 )
	            			{
	                          fechaCorrecta = 1;
	            			}
	                      break;

	            case  4 :
	            case  6 :
	            case  9 :
	            case 11 :
	            	if ( valorDia >= 1 && valorDia <= 30 )
	            			{
	            				fechaCorrecta = 1;
	            			}
	                      break;

	            case  2 :
	            	if ( valorDia >= 1 && valorDia <= 29 )
	            			{
	            	 	 	 	 fechaCorrecta = 1;
	            			}
	        }
	    }

	    if(fechaCorrecta)
	    {
	    	retorno = 1;
	    }

	return retorno;
}

int validarIdClientes(int iD,eCliente clientes[],int tamcl)
{
    int retorno=0;

    if(clientes != NULL && tamcl >0)
    {
        for(int i=0;i<tamcl;i++)
        {
            if(clientes[i].id==iD)
            {
                retorno=1;
                break;
            }
        }

    }
    return retorno;
}
