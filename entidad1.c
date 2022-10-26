#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parcial.h"
#include <conio.h>
#include "entidad1.h"
#include "entidad2.h"
#include "validaciones.h"


int inicializar(eMoto lista[],int tam)
{
    int retorno=0;
    if(lista != NULL && tam > 0)
    {
        for(int i=0;i<tam;i++)
        {
            lista[i].isEmpty=1;
        }
        retorno=1;
    }
    return retorno;
}


int altaMoto(int*pId,eMoto lista[], int tam,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tamcl)
{

    int retorno = 0;
    int indice;
    eMoto auxMoto;


    if(pId != NULL && lista != NULL && tam > 0 && tipos != NULL && tam_t >0 && colores != NULL && tam_c >0 && clientes != NULL && tamcl>0)
    {

        system("cls");
        printf("|=============================|\n");
        printf("|         ALTA MOTOS          |\n");
        printf("|=============================|\n");

        indice=buscarLibre(lista, tam);

        if(indice == -1)
        {

            printf("No hay lugar en el sistema.\n");



        }
        else
        {

          cargarMoto(&auxMoto,tipos,tam_t,colores,tam_c,clientes,tamcl);
          auxMoto.id = *pId;
          (*pId)++;

          auxMoto.isEmpty=0;

          lista[indice]=auxMoto;


          retorno=1;
        }


    }



    return retorno;
}

int cargarMoto(eMoto* pMoto,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tamcl)
{

    int todoOk = 0;
    char auxMarca[20];
    int auxEntero;

    if(pMoto != NULL && tipos != NULL && tam_t >0 && colores != NULL && tam_c >0 && clientes != NULL && tamcl >0)
    {


        printf("Ingrese Marca: ");
        fflush(stdin);
        gets(auxMarca);
        strcpy(pMoto->marca,auxMarca);

        mostrarTipos(tipos,tam_t);
        printf("Ingrese Tipo: ");
        scanf("%d",&auxEntero);
        while(!validarIdTipos(auxEntero,tipos,tam_t))
        {
           printf("ID incorrecto , vuelva a intentarlo: ");
           scanf("%d",&auxEntero);
        }
        pMoto->idTipo=auxEntero;

        mostrarColores(colores,tam_c);
        printf("Ingrese Color: ");
        scanf("%d",&auxEntero);
        while(!validarIdColores(auxEntero,colores,tam_c))
        {
           printf("ID incorrecto , vuelva a intentarlo: ");
           scanf("%d",&auxEntero);
        }
        pMoto->idColor=auxEntero;

        printf("Ingrese Cilindrada: ");
        scanf("%d",&auxEntero);
        while(!validarCilindrada(auxEntero))
        {
            printf("Dato incorrecto ,ingrese cilindrada nuevamente: ");
            scanf("%d",&auxEntero);
        }
        pMoto->cilindrada=auxEntero;

        printf("Ingrese Puntaje: ");
        scanf("%d",&auxEntero);
        while(!validarRangoEnteros(auxEntero,1,10))
        {
          printf("Ingrese nuevamente puntaje: ");
          scanf("%d",&auxEntero);
        }
        pMoto->puntaje=auxEntero;

        mostrarClientes(clientes,tamcl);
        printf("Ingrese Id Cliente: ");
        scanf("%d",&auxEntero);
        while(!validarIdClientes(auxEntero,clientes,tamcl))
        {
           printf("ID incorrecto , vuelva a intentarlo: ");
           scanf("%d",&auxEntero);
        }
        pMoto->idCliente=auxEntero;

        pMoto->isEmpty = 0;

        todoOk = 1;

    }
    return todoOk;
}


int mostrarMotos(eMoto lista[], int tam_m,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tamcl)
{

    int todoOk = 0;
    int flag=1;

    if(lista != NULL && tam_m > 0 && tipos != NULL && tam_t > 0 && colores != NULL && tam_c >0 && clientes != NULL && tamcl > 0)
    {

        system("cls");

        printf("|========================================================================================|\n");
        printf("|                            LISTAR MOTOS                                                | \n");
        printf("|========================================================================================|\n");
        printf("| Id   |   Marca   |   Tipos    |  Colores  |  Cilindrada |  Puntaje  |  Nombre Cliente  |\n");
        printf("|----------------------------------------------------------------------------------------|\n");
        for(int i = 0 ; i < tam_m ; i++)
        {
            if(!lista[i].isEmpty)
            {
                mostrarMoto(lista[i],tipos,tam_t,colores,tam_c,clientes,tamcl);

                flag=0;
                todoOk = 1;

            }
        }
        printf("\n\n");

        if(flag)
        {
            printf("No hay motos para mostrar\n");
        }

    }

    return todoOk;
}

int mostrarMoto(eMoto moto,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tamcl)
{

    int retorno=0;
    char descripcion[20];
    char nombreColor[20];
    char nombreCliente[20];


    cargarDescripcionTipos(moto.idTipo,descripcion,tipos,tam_t);
    cargarDescripcionColores(moto.idColor,nombreColor,colores,tam_c);
    cargarDescripcionClientes(moto.idCliente,nombreCliente,clientes,tamcl);



    if(tipos != NULL && tam_t > 0 && colores != NULL && tam_c > 0 && clientes != NULL && tamcl > 0)
    {

        printf("|%d   |  %-8s |   %-7s  |   %-6s  |    %3d      |     %2d    |    %-8s      |\n",
           moto.id,
           moto.marca,
           descripcion,
           nombreColor,
           moto.cilindrada,
           moto.puntaje,
           nombreCliente

           );

        retorno=1;

    }


   return retorno;


}

int buscarLibre(eMoto lista[],int tam_m)
{

    int indice=-1;
    if(lista != NULL && tam_m >0)
    {
        for(int i=0;i<tam_m;i++)
        {
            if(lista[i].isEmpty)
            {
                indice=i;
                break;
            }

        }

    }
    return indice;
}


int modificarMotos(eMoto lista[],int tam,eColor colores[],int tam_c,eTipo tipos[],int tam_t,eCliente clientes[],int tamcl)
{
    int retorno=0;
    int indice;
    int id;
    char confirma;
    int auxColor;
    int auxPuntaje;


    if(lista != NULL && tam >0 && colores != NULL && tam_c > 0)
    {
        system("cls");
        printf("|==================================|\n");
        printf("|          MODIFICAR MOTOS         |\n");
        printf("|==================================|\n");
        printf("Ingrese Id: ");
        scanf("%d", &id);

        indice=buscarMoto(lista,tam,id);

        if(indice == -1)
        {
            printf("El id: %d no esta registrado en el sistema\n",id);
        }
        else
        {
            mostrarMoto(lista[indice],tipos,tam_t,colores,tam_c,clientes,tamcl);
            printf("Confirma modificacion?: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma== 's')
            {
                switch(menuModificacion())
                {
                case 1:
                    mostrarColores(colores,tam_c);
                    printf("Ingrese nuevo color: ");
                    scanf("%d",&auxColor);
                    lista[indice].idColor=auxColor;
                    break;
                case 2:
                    printf("Ingrese nuevo puntaje: ");
                    scanf("%d",&auxPuntaje);
                    lista[indice].puntaje=auxPuntaje;
                    break;
                default:
                    printf("Opcion Incorrecta\n");

                }
                retorno=1;
            }
            else
            {
               printf("Modificacion cancelada por el usuario\n");
            }
        }
    }
    return retorno;
}
int menuModificacion()
{

    int opcion;

    system("cls");

    printf("======================|\n");
    printf("  MENU MODIFICACION   |\n");
    printf("======================|\n");
    printf("1- Color              |\n");
    printf("2- Puntaje            |\n");
    printf("======================|\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);



    return opcion;
}

int buscarMoto(eMoto lista[],int tam,int id)
{
    int indice=-1;
    if(lista != NULL && tam > 0)
    {
        for(int i=0;i<tam;i++)
        {
            if(!lista[i].isEmpty && lista[i].id==id)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int bajaMoto(eMoto lista[],int tam,eTipo tipos[],int tam_t,eColor colores[],int tam_c,eCliente clientes[],int tamcl)
{
    int retorno=0;
    int indice;
    int id;
    char confirma;
    if(lista != NULL && tam >0)
    {
        system("cls");
        printf("|======================================|\n");
        printf("|             BAJA MOTOS               |\n");
        printf("|======================================|\n");
        mostrarMotos(lista,tam,tipos,tam_t,colores,tam_c,clientes,tamcl);
        printf("Ingrese Id: ");
        scanf("%d", &id);

        indice=buscarMoto(lista,tam,id);

        if(indice == -1)
        {
            printf("El id: %d no esta registrado en el sistema",id);
        }
        else
        {
            mostrarMoto(lista[indice],tipos,tam_t,colores,tam_c,clientes,tamcl);
            printf("Confirma baja?: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma== 's')
            {
                lista[indice].isEmpty=1;
                retorno=1;
            }
            else
            {
               printf("Baja cancelada por el usuario\n");
            }
        }
    }
    return retorno;
}


