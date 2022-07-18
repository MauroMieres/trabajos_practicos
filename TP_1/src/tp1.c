/*
 ============================================================================
 Name        : tp1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void)
{
	setbuf(stdout, NULL);
    int opcion;
    int x;
    float y;
    float z;
    int flagKilometros=0;
    int flagPrecios=0;
    int flagCalculos=0;

    do
    {
        Menu();
        opcion=IngresarEntero("Ingrese una opcion: ");
        switch(opcion)
        {
        case 1:
            system("cls");
            printf("1. Ingresar kilometros: ");
            scanf("%d",&x);
            flagKilometros=1;
            break;

        case 2:
            system("cls");
            printf("2. Ingresar precio de vuelos: \n\n");
            printf("Precio vuelo Aerolineas: ");
            scanf("%f",&y);
            printf("Precio vuelo Latam: ");
            scanf("%f",&z);
            flagPrecios=1;
            break;

        case 3:
            if(flagKilometros==0||flagPrecios==0)
            {
                system("cls");
                printf("Falta ingresar datos.\n");
                system("pause");
                break;
            }
            else
            {
                Menu3();
                flagCalculos=1;
                system("pause");
            }
            break;

        case 4:
            if(flagCalculos==0)
            {
                printf("No se puede informar sin hacer los calculos! ");
                system("pause");
                break;
            }
            else
            {
                system("cls");
                printf("KMs Ingresados: %d km\n\n",x);
                printf("Precio Aerolineas: $%.2f\n",y);
                Descontar(&y,0.10,"a) Precio con tarjeta de debito: $");
                Aumentar(&y,0.25,"b) Precio con tarjeta de credito: $");
                CalcularPrecioBitcoin(&y,"c) Precio pagando con bitcoin: ");
                CalcularPrecioKilometro(&y,&x,"d) Mostrar precio unitario: $");
                printf("\n");
                printf("Precio Latam: $%.2f\n",z);
                Descontar(&z,0.10,"a) Precio con tarjeta de debito: $");
                Aumentar(&z,0.25,"b) Precio con tarjeta de credito: $");
                CalcularPrecioBitcoin(&z,"c) Precio pagando con bitcoin: ");
                CalcularPrecioKilometro(&z,&x,"d) Mostrar precio unitario: $");
                system("pause");
            }
            break;

        case 5:
            HardcodearViajes(&x,&y,&z,&flagKilometros,&flagPrecios,&flagCalculos);
            printf("Carga forzada exitosa! Ver resultados en opcion 4\n");
            system("pause");
            break;

        case 6:
            printf("6. Salir.\n");
            system("pause");
            break;

        default:
            system("cls");
            printf("Opcion invalida! \n");
        }
    }
    while(opcion!=6);
    return 0;
}



