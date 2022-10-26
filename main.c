#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parcial.h"
#include <conio.h>
#include "entidad1.h"
#include "entidad2.h"
#include "validaciones.h"
#include "informes.h"

#define TAM_M 6
#define TAM_T 4
#define TAM_C 5
#define TAM_S 4
#define TAM_TR 6
#define TAMCL 5


int main()
{
    char seguir='s';

    int nextIdMoto=100;
    int nextIdTrabajo=1;
    int opcion;
    int contador=0;



    eMoto lista[TAM_M];

    eTrabajo trabajos[TAM_TR];


    eTipo tipos[TAM_T]=
    {
        {1000,"Enduro"},
        {1001,"Chopera"},
        {1002,"Scooter"},
        {1003,"Vintage"}
    };

    eColor colores[TAM_C]=
    {
        {10000,"Gris"},
        {10001,"Negro"},
        {10002,"Azul"},
        {10003,"Blanco"},
        {10004,"Rojo"}

    };

    eServicio servicios[TAM_S]=
    {
        {20000,"Limpieza",450},
        {20001,"Ajuste",300},
        {20002,"Balanceo",150},
        {20003,"Cadena",390}

    };

     eCliente clientes[TAMCL]=
    {
        {10,"Juan",'m'},
        {11,"Carolina",'f'},
        {12,"Bianca",'f'},
        {13,"Joaquin",'m'},
        {14,"Carla",'f'}

    };



    inicializar(lista,TAM_M);
    inicializarTrabajos(trabajos,TAM_TR);
    harcodearMotos(&nextIdMoto,lista,TAM_M,4);


    do
    {
        switch(mostrarMenu())
        {
        case 'a':
            if(altaMoto(&nextIdMoto,lista,TAM_M,tipos,TAM_T,colores,TAM_C,clientes,TAMCL))
            {
                printf("Alta exitosa\n");
                contador++;
            }
            else
            {
                printf("Fallo el alta\n");
            }
            break;
        case 'b':
            if(contador > 0 || contador ==0)
            {
                if(modificarMotos(lista,TAM_M,colores,TAM_C,tipos,TAM_T,clientes,TAMCL))
                {
                    printf("Modificacion exitosa\n");
                }
                else
                {
                    printf("Fallo la modificacion\n");
                }

            }
            else
            {
                printf("Debe dar de alta una moto\n");
            }

            break;
        case 'c':
            if(contador > 0 || contador==0)
            {
                if(bajaMoto(lista,TAM_M,tipos,TAM_T,colores,TAM_C,clientes,TAMCL))
                {
                    printf("Baja Moto\n");
                    contador--;
                }
                else
                {
                    printf("Fallo la baja\n");
                }

            }
            else
            {
                printf("Debe dar de alta una moto\n");
            }

            break;
        case 'd':
            if(contador > 0 || contador==0)
            {
                mostrarMotos(lista,TAM_M,tipos,TAM_T,colores,TAM_C,clientes,TAMCL);

            }
            else
            {
               printf("Debe dar de alta una moto\n");
            }
            break;
        case 'e':
            mostrarTiposLista(tipos,TAM_T);
            break;
        case 'f':
            mostrarColoresLista(colores,TAM_C);
            break;
        case 'g':
            mostrarServiciosLista(servicios,TAM_S);
            break;
        case 'h':
            if(altaTrabajo(&nextIdTrabajo,trabajos,TAM_TR,lista,TAM_M,servicios,TAM_S,tipos,TAM_T,colores,TAM_C,clientes,TAMCL))
            {
                printf("Se realizo el alta correctamente\n");
            }
            else
            {
                printf("Hubo un error en el alta\n");
            }
            break;
        case 'i':
            if(mostrarTrabajos(trabajos,TAM_TR,lista,TAM_M,servicios,TAM_S))
            {
                printf("Se mostro correctamente\n");
            }
            else
            {
                printf("Hubo un error al mostrar\n");
            }
            break;
        case 'j':
            if(contador >0)
            {

                do
            {
                switch(menuInformes(&opcion))
                {
                case 1:
                    colorSeleccionadoPorUsuario(lista,TAM_M,colores,TAM_C,tipos,TAM_T,clientes,TAMCL);
                    break;
                case 2:
                    tipoSeleccionadoPorUsuario(lista,TAM_M,colores,TAM_C,tipos,TAM_T,clientes,TAMCL);
                    break;
                case 3:
                    mayorCilindrada(lista,TAM_M,tipos,TAM_T,colores,TAM_C,clientes,TAMCL);
                    break;
                case 4:
                    mostrarMotosPorTipos(lista,TAM_M,tipos,TAM_T,colores,TAM_C,clientes,TAMCL);
                    break;
                case 5:
                    mostrarColorTipoElegido(lista,TAM_M,tipos,TAM_T,colores,TAM_C,clientes,TAMCL);
                    break;
                case 6:
                    colorMasElegido(lista,TAM_M,colores,TAM_C);
                    break;
                case 7:
                    trabajosMotos(lista,TAM_M,trabajos,TAM_TR,tipos,TAM_T,colores,TAM_C,servicios,TAM_S,clientes,TAMCL);
                    break;
                case 8:
                    sumaImporteMotos(lista,TAM_M,trabajos,TAM_TR,tipos,TAM_T,colores,TAM_C,servicios,TAM_S,clientes,TAMCL);
                    break;
                case 9:
                    serviciosMotosYlaFecha(lista,TAM_M,trabajos,TAM_TR,tipos,TAM_T,colores,TAM_C,servicios,TAM_S);
                    break;
                case 10:
                    serviciosFecha(lista,TAM_M,trabajos,TAM_TR,tipos,TAM_T,colores,TAM_C,servicios,TAM_S);
                    break;
                case 11:
                    break;
                default:
                    printf("opcion incorrecta\n");
                    break;
                }

                system("pause");
            }
            while(opcion != 11);



            }
            else
            {
                printf("Debe dar de alta una moto\n");
            }

            break;
        case 'k':
            confirmarSalida(&seguir,'n','s');
            break;
        }
        system("pause");

    }
    while(seguir == 's');

    return 0;
}
