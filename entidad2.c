#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parcial.h"
#include <conio.h>
#include "entidad1.h"
#include "entidad2.h"
#include "validaciones.h"



int altaTrabajo(int*pId,eTrabajo trabajos[], int tam_tr,eMoto lista[],int tam_m,eServicio servicios[],int tam_s,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tamcl)
{

    int retorno = 0;
    int indice;
    eTrabajo auxTrabajo;
    int flag=1;


    if( pId != NULL && trabajos != NULL && tam_tr > 0 && lista != NULL && tam_m >0 && servicios != NULL && tam_s >0 && tipos != NULL && tam_t >0 && colores != NULL && tam_c >0)
    {

        system("cls");
        printf("|=============================|\n");
        printf("|         ALTA TRABAJOS       |\n");
        printf("|=============================|\n");

        indice=buscarLibreTrabajo(trabajos, tam_tr);

        for(int i=0;i<tam_m;i++)
        {
            if(!lista[i].isEmpty)
            {
                flag=0;
            }
        }

        if(flag)
        {
            printf("No hay motos en el sistema\n");
        }
        else
        {
            if(indice == -1)
            {

                printf("No hay lugar en el sistema.\n");



            }
            else
            {

              cargarTrabajo(&auxTrabajo,lista,tam_m,servicios,tam_s,tipos,tam_t,colores,tam_c,clientes,tamcl);
              auxTrabajo.id = *pId;
              (*pId)++;

              auxTrabajo.isEmpty=0;

              trabajos[indice]=auxTrabajo;


              retorno=1;
            }


        }

    }




    return retorno;
}


int buscarLibreTrabajo(eTrabajo trabajos[],int tam_tr)
{

    int indice=-1;
    if(trabajos != NULL && tam_tr >0)
    {
        for(int i=0;i<tam_tr;i++)
        {
            if(trabajos[i].isEmpty)
            {
                indice=i;
                break;
            }

        }

    }
    return indice;
}

int cargarTrabajo(eTrabajo* pTrabajo,eMoto lista[],int tam_m,eServicio servicios[],int tam_s,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tamcl)
{

    int todoOk = 0;
    int auxEntero;
    int auxDia;
    int auxMes;
    int auxAnio;

    if(pTrabajo != NULL && lista != NULL && tam_m >0 && servicios != NULL && tam_s && clientes != NULL && tamcl>0 && tipos != NULL && tam_t >0 && colores != NULL && tam_c >0)
    {

        mostrarMotos(lista,tam_m,tipos,tam_t,colores,tam_c,clientes,tamcl);
        printf("Ingrese Id: ");
        scanf("%d",&auxEntero);
        while(!validarIdMotos(auxEntero,lista,tam_m))
        {
            printf("Id incorrecto , ingrese nuevamente: ");
            scanf("%d",&auxEntero);
        }
        pTrabajo->idMoto=auxEntero;

        mostrarServicios(servicios,tam_s);
        printf("Ingrese Id: ");
        scanf("%d",&auxEntero);
        while(!validarIdServicios(auxEntero,servicios,tam_s))
        {
            printf("Id incorrecto , ingrese nuevamente: ");
            scanf("%d",&auxEntero);
        }
        pTrabajo->idServicio=auxEntero;

        printf("Ingrese Fecha: ");
        scanf("%d/%d/%d",&auxDia,&auxMes,&auxAnio);
        while(!validarFecha(auxDia,auxMes,auxAnio))
        {
           printf("Ingrese Fecha: ");
           scanf("%d/%d/%d",&auxDia,&auxMes,&auxAnio);
        }
        pTrabajo->fecha.dia=auxDia;
        pTrabajo->fecha.mes=auxMes;
        pTrabajo->fecha.anio=auxAnio;

        todoOk = 1;

    }
    return todoOk;
}



int mostrarTrabajos(eTrabajo trabajos[],int tam_tr,eMoto lista[],int tam_m,eServicio servicios[],int tam_s)
{

    int todoOk = 0;
    int flag=1;

    if(lista != NULL && tam_m > 0 && trabajos != NULL && tam_tr > 0 && servicios != NULL && tam_s > 0)
    {

        system("cls");

        printf("|============================================================|\n");
        printf("|                   LISTAR TRABAJOS                          | \n");
        printf("|============================================================|\n");
        printf("|   Id   |  IdMoto  |   Marca   |   Servicio   |    Fecha    |\n");
        printf("|------------------------------------------------------------|\n");
        for(int i = 0 ; i < tam_tr ; i++)
        {
            if(!trabajos[i].isEmpty)
            {
                mostrarTrabajo(trabajos[i],lista,tam_m,servicios,tam_s);

                flag=0;
                todoOk = 1;

            }
        }
        printf("\n\n");

    }
    if(flag)
    {
        system("cls");
        printf("No hay trabajos para mostrar\n");
    }

    return todoOk;
}

int mostrarTrabajo(eTrabajo trabajo,eMoto lista[],int tam_m,eServicio servicios[],int tam_s)
{

    int retorno=0;
    char descripcionMarca[20];
    char nombreServicio[20];


    cargarDescripcionMarca(trabajo.idMoto,descripcionMarca,lista,tam_m);
    cargarDescripcionServicios(trabajo.idServicio,nombreServicio,servicios,tam_s);


    if(lista != NULL && tam_m > 0 && servicios != NULL && tam_s > 0)
    {

        printf("|   %d    |   %d    |  %-9s|   %-6s   |  %02d/%02d/%d |\n",
           trabajo.id,
           trabajo.idMoto,
           descripcionMarca,
           nombreServicio,
           trabajo.fecha.dia,
           trabajo.fecha.mes,
           trabajo.fecha.anio
           );

        retorno=1;

    }


   return retorno;


}

int inicializarTrabajos(eTrabajo trabajos[],int tam_tr)
{
    int retorno=0;
    if(trabajos != NULL && tam_tr > 0)
    {
        for(int i=0;i<tam_tr;i++)
        {
            trabajos[i].isEmpty=1;
        }
        retorno=1;
    }
    return retorno;
}


