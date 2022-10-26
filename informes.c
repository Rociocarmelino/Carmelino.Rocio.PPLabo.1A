#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parcial.h"
#include <conio.h>
#include "entidad1.h"
#include "entidad2.h"
#include "validaciones.h"
#include "informes.h"



int menuInformes(int*pOpcion)
{
    int opcion;

    if(pOpcion != NULL)
    {
        system("cls");
        printf("|=================================================|\n");
        printf("                  MENU INFORMES                   |\n");
        printf("|=================================================|\n\n");
        printf("1- Colores de motos seleccionadas por el usuario\n");
        printf("2- Tipos de motos seleccionadas por el usuario\n");
        printf("3- Motos de mayor cilindrada\n");
        printf("4- Motos separadas por tipo\n");
        printf("5- Motos del color y tipo elegido\n");
        printf("6- Color mas elegido por el cliente\n");
        printf("7- Trabajos a una moto\n");
        printf("8- Suma de trabajos a una moto\n");
        printf("9- Servicios a una moto\n");
        printf("10- Servicios en fecha elegida\n");
        printf("11- Salir\n");
        printf("Ingrese opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);

        *pOpcion=opcion;

    }



    return *pOpcion;
}


int colorSeleccionadoPorUsuario(eMoto lista[],int tam_m,eColor colores[],int tam_c,eTipo tipos[],int tam_t,eCliente clientes[],int tamcl)
{
    int retorno=0;
    int idEntero;
    if(lista != NULL && tam_m >0 && colores != NULL && tam_c>0 && tipos != NULL && tam_t > 0 && clientes != NULL && tamcl >0)
    {
        mostrarColores(colores,tam_c);
        printf("Ingrese Id del color: ");
        scanf("%d",&idEntero);
        while(!validarIdColores(idEntero,colores,tam_c))
        {
            printf("Ingrese nuevamente Id: ");
            scanf("%d",&idEntero);
        }
        system("cls");
        printf("|=====================================================================|\n");
        printf("|                 LISTA DE COLORES ELEGIDOS                           |\n");
        printf("|=====================================================================|\n");

        for(int i=0; i<tam_m; i++)
        {
            if(!lista[i].isEmpty && lista[i].idColor==idEntero)
            {
                mostrarMoto(lista[i],tipos,tam_t,colores,tam_c,clientes,tamcl);
                retorno=1;
            }
        }
    }

    return retorno;
}


int tipoSeleccionadoPorUsuario(eMoto lista[],int tam_m,eColor colores[],int tam_c,eTipo tipos[],int tam_t,eCliente clientes[],int tamcl)
{
    int retorno=0;
    int idEntero;
    if(lista != NULL && tam_m >0 && colores != NULL && tam_c>0 && tipos != NULL && tam_t > 0)
    {
        mostrarTipos(tipos,tam_t);
        printf("Ingrese Id del Tipo: ");
        scanf("%d",&idEntero);
        while(!validarIdTipos(idEntero,tipos,tam_t))
        {
            printf("Ingrese nuevamente Id: ");
            scanf("%d",&idEntero);
        }
        system("cls");
        printf("|=====================================================================|\n");
        printf("|                 LISTA DE TIPOS ELEGIDOS                             |\n");
        printf("|=====================================================================|\n");
        printf("| Id   |   Marca   |   Tipos    |  Colores  |  Cilindrada |  Puntaje  |\n");
        printf("|---------------------------------------------------------------------|\n");

        for(int i=0; i<tam_m; i++)
        {
            if(!lista[i].isEmpty && lista[i].idTipo==idEntero)
            {
                mostrarMoto(lista[i],tipos,tam_t,colores,tam_c,clientes,tamcl);
                retorno=1;
            }
        }
    }

    return retorno;
}

int mostrarMotosPorTipos(eMoto lista[],int tam_m,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tamcl)
{
    int retorno=0;
    int flag=1;

    if(lista != NULL && tam_m >0 && tipos != NULL && tam_t > 0 && colores != NULL && tam_c >0 && clientes != NULL && tamcl >0)
    {
        system("cls");
        printf("     LISTA DE MOTOS POR TIPO      \n");

        for(int i=0; i<tam_t; i++)
        {
            printf("======================================================================|\n");
            printf("   TIPO: %-8s                                                     |\n",tipos[i].descripcion);
            printf("======================================================================|\n");


            for(int j=0; j<tam_m; j++)
            {

                if(!lista[j].isEmpty && lista[j].idTipo== tipos[i].id)
                {
                    mostrarMoto(lista[j],tipos,tam_t,colores,tam_c,clientes,tamcl);
                    flag=0;

                }
            }
            if(flag)
            {
                printf("No hay motos de esa marca\n");
            }
        }


    }

    return retorno;
}

int mayorCilindrada(eMoto lista[],int tam_m,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tamcl)
{
    int retorno=0;
    int mayorCilindrada;
    int flag=1;


    if(lista != NULL && tam_m >0 && tipos != NULL && tam_t > 0 && colores != NULL && tam_c > 0 && clientes != NULL && tamcl >0)
    {
        for(int i=0; i<tam_m; i++)
        {
            if(!lista[i].isEmpty)
            {
                if(flag || lista[i].cilindrada > mayorCilindrada)
                {
                    mayorCilindrada=lista[i].cilindrada;
                    flag=0;

                }
            }
        }

        system("cls");
        printf("|=====================================================================|\n");
        printf("|                      MOTO MAYOR CILINDRADA                          |\n");
        printf("|=====================================================================|\n");
        printf("| Id   |   Marca   |   Tipos    |  Colores  |  Cilindrada |  Puntaje  |\n");
        printf("|---------------------------------------------------------------------|\n");

        for(int j=0; j<tam_m; j++)
        {
            if(!lista[j].isEmpty && lista[j].cilindrada == mayorCilindrada)
            {
                mostrarMoto(lista[j],tipos,tam_t,colores,tam_c,clientes,tamcl);

            }
        }


        retorno=1;

    }

    return retorno;
}

int mostrarColorTipoElegido(eMoto lista[],int tam_m,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tamcl)
{
    int retorno=0;
    int auxIdColor;
    int auxTipo;
    int contador=0;
    int flag=1;

    if(lista != NULL && tam_m >0 && tipos != NULL && tam_t >0 && colores != NULL && tam_c >0 && clientes != NULL && tamcl >0)
    {
        mostrarColores(colores,tam_c);
        printf("Ingrese Id Color: ");
        scanf("%d",&auxIdColor);
        while(!validarIdColores(auxIdColor,colores,tam_c))
        {
            printf("ID incorrecto , vuelva a intentarlo: ");
            scanf("%d",&auxIdColor);
        }

        mostrarTipos(tipos,tam_t);
        printf("Ingrese Id Tipo: ");
        scanf("%d",&auxTipo);
        while(!validarIdTipos(auxTipo,tipos,tam_t))
        {
            printf("ID incorrecto , vuelva a intentarlo: ");
            scanf("%d",&auxTipo);
        }

        system("cls");
        printf("|=====================================================================|\n");
        printf("|               MOTOS DEL TIPO Y COLOR ELEGIDO                        |\n");
        printf("|=====================================================================|\n");
        printf("| Id   |   Marca   |   Tipos    |  Colores  |  Cilindrada |  Puntaje  |\n");
        printf("|---------------------------------------------------------------------|\n");

        for(int i=0; i<tam_m; i++)
        {
            if(!lista[i].isEmpty && lista[i].idColor== auxIdColor && lista[i].idTipo== auxTipo)
            {
                mostrarMoto(lista[i],tipos,tam_t,colores,tam_c,clientes,tamcl);
                contador++;
                flag=0;
                retorno=1;
            }
        }

    }

    if(flag)
    {
        printf("No hay motos del tipo y color elegido\n");
    }
    else
    {
         printf("Cantidad de motos con el tipo y color elegido son %d\n",contador);
    }

    return retorno;

}

int trabajosMotos(eMoto lista[],int tam_m,eTrabajo trabajo[],int tam_tr,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eServicio servicios[],int tam_s,eCliente clientes[],int tamcl)
{
    int retorno=0;
    int auxMoto;
    int flag=1;

    if(lista != NULL && tam_m > 0 && trabajo != NULL && tam_tr >0 && tipos != NULL && tam_t >0 && colores != NULL && tam_c >0 && clientes != NULL && tamcl >0)
    {
        mostrarMotos(lista,tam_m,tipos,tam_t,colores,tam_c,clientes,tamcl);

        printf("Ingrese Id: ");
        scanf("%d",&auxMoto);
        while(!validarIdMotos(auxMoto,lista,tam_m))
        {
            printf("ID incorrecto , vuelva a intentarlo: ");
            scanf("%d",&auxMoto);
        }

        system("cls");
        printf("|============================================================|\n");
        printf("|                   LISTAR TRABAJOS                          | \n");
        printf("|============================================================|\n");
        printf("|   Id   |  IdMoto  |   Marca   |   Servicio   |    Fecha    |\n");
        printf("|------------------------------------------------------------|\n");
        for(int i=0; i<tam_tr; i++)
        {
            if(!trabajo[i].isEmpty && trabajo[i].idMoto==auxMoto)
            {
                mostrarTrabajo(trabajo[i],lista,tam_m,servicios,tam_s);
                flag=0;
                retorno=1;
            }
        }
    }

    if(flag)
    {
        printf("No hay trabajos en esa moto\n");
    }

    return retorno;
}


int sumaImporteMotos(eMoto lista[],int tam_m,eTrabajo trabajo[],int tam_tr,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eServicio servicios[],int tam_s,eCliente clientes[],int tamcl)
{
    int retorno=0;
    int auxMoto;
    int flag=1;
    int acumuladorPrecioServicios=0;

    if(lista != NULL && tam_m > 0 && trabajo != NULL && tam_tr >0 && tipos != NULL && tam_t >0 && colores != NULL && tam_c >0 && clientes != NULL && tamcl >0)
    {
        mostrarMotos(lista,tam_m,tipos,tam_t,colores,tam_c,clientes,tamcl);

        printf("Ingrese Id: ");
        scanf("%d",&auxMoto);
        while(!validarIdMotos(auxMoto,lista,tam_m))
        {
            printf("ID incorrecto , vuelva a intentarlo: ");
            scanf("%d",&auxMoto);
        }

        system("cls");

        for(int i=0; i<tam_tr; i++)
        {
            for(int j=0; j<tam_s; j++)
            {

                if(!trabajo[i].isEmpty && trabajo[i].idMoto==auxMoto && trabajo[i].idServicio==servicios[j].id)
                {

                    acumuladorPrecioServicios = acumuladorPrecioServicios + servicios[j].precio;
                    flag=0;
                    retorno=1;
                }
            }

        }

    }

    if(flag)
    {
        printf("|---------------------------------- |\n\n");
        printf("|No hay servicios en la moto elegida|\n\n");
        printf("|---------------------------------- |\n");
    }
    else
    {
        printf("|================================================================================|\n");
        printf("|              SUMA DE LOS SERVICIOS REALIZADOS A LA MOTO ELEGIDA                |\n");
        printf("|================================================================================|\n");
        printf("|  El precio total de los servicios realizados a esa moto es %d                 |\n",acumuladorPrecioServicios);
        printf("|--------------------------------------------------------------------------------|\n");
    }

    return retorno;
}


int serviciosMotosYlaFecha(eMoto lista[],int tam_m,eTrabajo trabajo[],int tam_tr,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eServicio servicios[],int tam_s)
{
    int retorno=0;
    int auxServicio;
    int flag=1;

    if(lista != NULL && tam_m > 0 && trabajo != NULL && tam_tr >0 && tipos != NULL && tam_t >0 && colores != NULL && tam_c >0)
    {
        mostrarServicios(servicios,tam_s);

        printf("Ingrese Id: ");
        scanf("%d",&auxServicio);
        while(!validarIdServicios(auxServicio,servicios,tam_s))
        {
            printf("ID incorrecto , vuelva a intentarlo: ");
            scanf("%d",&auxServicio);
        }

        system("cls");
        printf("|============================================================|\n");
        printf("|                   LISTAR SERVICIOS                         | \n");
        printf("|============================================================|\n");
        printf("|   Id   |  IdMoto  |   Marca   |   Servicio   |    Fecha    |\n");
        printf("|------------------------------------------------------------|\n");
        for(int i=0; i<tam_tr; i++)
        {
            if(trabajo[i].idServicio==auxServicio)
            {
                mostrarTrabajo(trabajo[i],lista,tam_m,servicios,tam_s);
                flag=0;
                retorno=1;
            }
        }
    }

    if(flag)
    {
        printf("|---------------------------------- |\n\n");
        printf("|    No se realizaron servicios     | \n\n");
        printf("|---------------------------------- |\n");
    }


    return retorno;
}


int serviciosFecha(eMoto lista[],int tam_m,eTrabajo trabajo[],int tam_tr,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eServicio servicios[],int tam_s)
{
    int retorno=0;

    int auxDia;
    int auxMes;
    int auxAnio;
    int flag=1;


    if(lista != NULL && tam_m && trabajo != NULL && tam_tr > 0 && tipos != NULL && tam_t > 0 && colores != NULL && tam_c >0 && servicios != NULL && tam_s >0)
    {
        system("cls");
        printf("Ingrese Fecha: ");
        scanf("%d/%d/%d",&auxDia,&auxMes,&auxAnio);
        while(!validarFecha(auxDia,auxMes,auxAnio))
        {
            printf("Ingrese una fecha correcta: ");
            scanf("%d/%d/%d",&auxDia,&auxMes,&auxAnio);
        }


        system("cls");
        printf("|============================================================|\n");
        printf("|                   LISTAR SERVICIOS                         | \n");
        printf("|============================================================|\n");
        printf("|   Id   |  IdMoto  |   Marca   |   Servicio   |    Fecha    |\n");
        printf("|------------------------------------------------------------|\n");
        for(int i=0; i<tam_tr; i++)
        {
            if(!trabajo[i].isEmpty && trabajo[i].fecha.dia == auxDia && trabajo[i].fecha.mes == auxMes  && trabajo[i].fecha.anio == auxAnio)
            {
                mostrarTrabajo(trabajo[i],lista,tam_m,servicios,tam_s);
                flag=0;
                retorno=1;
            }
        }

    }


    if(flag)
    {
        printf("|---------------------------------- |\n\n");
        printf("|    No se realizaron servicios     | \n\n");
        printf("|---------------------------------- |\n");
    }

    return retorno;

}

int colorMasElegido(eMoto lista[],int tam_m,eColor colores[],int tam_c)
{
    int retorno=0;
    int contador[]={0,0,0,0,0};
    int mayor;

    if(lista != NULL && tam_m >0 && colores != NULL && tam_c >0)
    {
        system("cls");



        for(int i=0;i<tam_c;i++)
        {
            for(int j=0;j<tam_m;j++)
            {
                if(!lista[j].isEmpty && lista[j].idColor == colores[i].id)
                {
                    contador[i]++;
                }
            }
        }

        for(int i=0;i<tam_c;i++)
        {
            if(i==0 || contador[i]>mayor)
            {
                mayor=contador[i];
            }
        }

        printf("|================================================================================|\n");
        printf("|                       EL COLOR MAS ELEGIDO                                     |\n");
        printf("|================================================================================|\n\n");
        for(int i=0;i<tam_c;i++)
        {
            if(contador[i]== mayor)
            {

                printf("      El color mas elegido es %s                                                \n",colores[i].nombreColor);
            }
        }

       retorno=1;
    }

    return retorno;
}


