#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parcial.h"
#include <conio.h>
#include "entidad1.h"
#include "entidad2.h"



int mostrarTipos(eTipo tipos[], int tam_t)
{

 int todoOk = 0;

 if(tipos != NULL && tam_t > 0)
 {

    system("cls");

    printf("|===========================|\n");
    printf("|        LISTA TIPOS        |\n");
    printf("|===========================|\n");
    printf("|   Id       Tipos          |\n");
    printf("|---------------------------|\n");

    for(int i = 0 ; i < tam_t ; i++){

        printf("| %d   |     %-7s      |\n", tipos[i].id, tipos[i].descripcion);



    }
    todoOk=1;

 }


return todoOk;
}

int mostrarColores(eColor colores[], int tam_c)
{

 int todoOk = 0;

 if(colores != NULL && tam_c > 0){

    system("cls");

    printf("|===========================|\n");
    printf("|       LISTA COLORES       |\n");
    printf("|===========================|\n");
    printf("|  Id       Colores         |\n");
    printf("|---------------------------|\n");

    for(int i = 0 ; i < tam_c ; i++){

    printf("| %d       %-10s    |\n", colores[i].id, colores[i].nombreColor);



    }
   todoOk=1;

 }


return todoOk;
}

int mostrarServicios(eServicio servicios[], int tam_s)
{

 int todoOk = 0;

 if(servicios != NULL && tam_s > 0){

    system("cls");

    printf("|================================|\n");
    printf("|       LISTA SERVICIOS          |\n");
    printf("|================================|\n");
    printf("| Id   |  Servicios  |  Precios  |\n");
    printf("|--------------------------------|\n");

    for(int i = 0 ; i < tam_s ; i++){

        printf("|%d |  %-10s |   %d     |\n", servicios[i].id, servicios[i].descripcion,servicios[i].precio);



    }
    printf("\n");
   todoOk=1;

 }


return todoOk;
}

int harcodearMotos(int* pId, eMoto vec[],int tam, int cant)
{
	int retorno =  0;
	eMoto almacenMotos[] = {{100,"Peugeot",1000,10000,50,1,10,0},
						    {101,"Peugeot",1001,10001,750,2,11,0},
						    {102,"Peugeot",1002,10002,500,10,12,0},
						    {103,"Peugeot",1000,10002,750,9,13,0},
						    {104,"Peugeot",1003,10002,750,8,14,0},
					        {105,"Peugeot",1003,10002,50,7,13,0},
						    {106,"Peugeot",1001,10001,125,6,11,0}

			};

	if(vec!=NULL && tam>0 && cant<=tam && cant<=10)
	{
		for(int i=0; i<cant; i++)
		{
			vec[i] = almacenMotos[i];
			*pId = *pId + 1;
		}

		retorno = 1;
	}
	return retorno;
}

int mostrarTiposLista(eTipo tipos[], int tam_t)
{

    int todoOk = 0;


    if(tipos != NULL && tam_t > 0)
    {

        system("cls");
        printf("=================================\n");
        printf("|         LISTAR TIPOS          | \n");
        printf("|===============================|\n");


        for(int i = 0 ; i < tam_t ; i++)
        {
           printf("|           %-7s             |\n",tipos[i].descripcion);
        }
        printf("\n\n");

        todoOk=1;

    }

    return todoOk;
}

int mostrarColoresLista(eColor colores[], int tam_c)
{

    int todoOk = 0;


    if(colores != NULL && tam_c > 0)
    {

        system("cls");
        printf("=================================\n");
        printf("|         LISTAR COLORES        | \n");
        printf("|===============================|\n");


        for(int i = 0 ; i < tam_c ; i++)
        {
           printf("|           %-7s             |\n",colores[i].nombreColor);
        }
        printf("\n\n");

        todoOk=1;

    }

    return todoOk;
}

int mostrarServiciosLista(eServicio servicios[], int tam_s)
{

    int todoOk = 0;


    if(servicios != NULL && tam_s > 0)
    {

        system("cls");
        printf("=================================\n");
        printf("|       LISTAR SERVICIOS        | \n");
        printf("|===============================|\n");
        printf("|   Servicios      Precios      |\n");
        printf("|-------------------------------|\n");


        for(int i = 0 ; i < tam_s ; i++)
        {
           printf("|     %-8s      %d         |\n",servicios[i].descripcion,servicios[i].precio);
        }
        printf("\n\n");

        todoOk=1;

    }

    return todoOk;
}
int cargarDescripcionTipos(int id, char descripcion[],eTipo tipos[], int tam_t)
{

 int todoOk = 0;
 int flag=-1;
 if(descripcion != NULL && tipos != NULL && tam_t > 0)
    {


    for(int i = 0 ; i < tam_t ; i++){

        if(tipos[i].id==id){

            strcpy(descripcion, tipos[i].descripcion);
            flag=0;
            break;
            todoOk = 1;;
        }

    }
    if(flag)
    {
        todoOk=-1;
    }


 }


return todoOk;
}

int cargarDescripcionColores(int id, char nombreColor[],eColor colores[], int tam_c)
{

 int todoOk = 0;
 int flag=-1;
 if(nombreColor != NULL && colores != NULL && tam_c > 0)
    {


    for(int i = 0 ; i < tam_c ; i++){

        if(colores[i].id==id){

            strcpy(nombreColor, colores[i].nombreColor);
            flag=0;
            break;
            todoOk = 1;

        }
    }
    if(flag)
    {
        todoOk=-1;
    }


 }


return todoOk;
}


int cargarDescripcionMarca(int id, char descripcionMarca[],eMoto lista[], int tam_m)
{

 int todoOk = 0;
 int flag=-1;
 if(descripcionMarca != NULL && lista != NULL && tam_m > 0)
    {


    for(int i = 0 ; i < tam_m ; i++){

        if(lista[i].id==id){

            strcpy(descripcionMarca, lista[i].marca);
            flag=0;
            break;
            todoOk = 1;

        }
    }
    if(flag)
    {
        todoOk=-1;
    }


 }


return todoOk;
}

int cargarDescripcionServicios(int id, char descripcionServicio[],eServicio servicios[],int tam_s)
{

 int todoOk = 0;
 int flag=-1;
 if(descripcionServicio != NULL && servicios != NULL && tam_s > 0)
    {


    for(int i = 0 ; i < tam_s ; i++){

        if(servicios[i].id==id){

            strcpy(descripcionServicio, servicios[i].descripcion);
            flag=0;
            break;
            todoOk = 1;

        }
    }
    if(flag)
    {
        todoOk=-1;
    }


 }


return todoOk;
}



int confirmarSalida(char* pVariable, char confirma, char rechaza)
{

    int todoOk = 0;
    char rta;

    if(pVariable != NULL)
    {

        printf("Esta seguro de que desea salir?: ");
        fflush(stdin);
        scanf("%c", &rta);

        if(rta == 's')
        {

            *pVariable = confirma;

        }
        else
        {

            *pVariable = rechaza;

        }

        todoOk = 1;



    }




    return todoOk;
}



char mostrarMenu()
{

    char opcion;

    system("cls");

    printf("|=============================|\n");
    printf("|      MENU DE OPCIONES       |\n");
    printf("|=============================|\n");
    printf("| A- Alta Moto                |\n");
    printf("| B- Modificar Moto           |\n");
    printf("| C- Baja Moto                |\n");
    printf("| D- Listar Motos             |\n");
    printf("| E- Listar Tipos             |\n");
    printf("| F- Listar Colores           |\n");
    printf("| G- Listar Servicios         |\n");
    printf("| H- Alta Trabajo             |\n");
    printf("| I- Listar trabajos          |\n");
    printf("| J- Submenu Informes         |\n");
    printf("| K- Salir                    |\n");
    printf(" Ingrese opcion: ");
    fflush(stdin);
    scanf("%c", &opcion);
    opcion=tolower(opcion);



    return opcion;
}


int mostrarClientes(eCliente clientes[],int tamcl)
{

 int todoOk = 0;

 if(clientes != NULL && tamcl > 0){

    system("cls");

    printf("|=====================================|\n");
    printf("|       LISTA CLIENTES                |\n");
    printf("|=====================================|\n");
    printf("| Id   |  Nombre Cliente  |  Sexo     |\n");
    printf("|-------------------------------------|\n");

    for(int i = 0 ; i < tamcl ; i++){

        printf("|%d    |  %-8s        |   %c       |\n", clientes[i].id,clientes[i].nombre,clientes[i].sexo);



    }
    printf("\n");
   todoOk=1;

 }


return todoOk;
}

int cargarDescripcionClientes(int id, char nombreCliente[],eCliente clientes[],int tamcl)
{

 int todoOk = 0;
 int flag=-1;
 if(nombreCliente != NULL && clientes != NULL && tamcl > 0)
    {


    for(int i = 0 ; i < tamcl ; i++){

        if(clientes[i].id==id){

            strcpy(nombreCliente, clientes[i].nombre);
            flag=0;
            break;
            todoOk = 1;

        }
    }
    if(flag)
    {
        todoOk=-1;
    }


 }


return todoOk;
}







