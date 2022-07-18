/*
 * funciones.c
 *
 *  Created on: 8 abr. 2022
 *      Author: knofl
 */

#include <stdio.h>
#include <stdlib.h>
#define BTC 4606954.55

void HardcodearViajes(int*kilometros,float*precio1,float*precio2,int*flagKm,int*flagPrecios,int*flagCalculos)
{
    (*kilometros)=7090;
    (*precio1)=162965;
    (*precio2)=159339;
    (*flagKm)=1;
    (*flagPrecios)=1;
    (*flagCalculos)=1;
}

void CalcularPrecioKilometro(float*precio,int*kilometros,char mensaje[])
{
    float precioKilometro= (*precio)/(*kilometros);
    printf(mensaje);
    printf(" %.2f\n",precioKilometro);
}

void Descontar(float*numero,float descuento,char mensaje[])
{
    float nuevoNumero=(*numero)-((*numero)*descuento);
    printf(mensaje);
    printf(" %.2f\n",nuevoNumero);
}

void Aumentar(float*numero,float aumento,char mensaje[])
{
    float nuevoNumero=(*numero)*(aumento+1);
    printf(mensaje);
    printf(" %.2f\n",nuevoNumero);
}

void CalcularPrecioBitcoin(float*precio,char mensaje[])
{
    float nuevoPrecio = (*precio)/BTC;
    printf(mensaje);
    printf(" %.2f BTC\n",nuevoPrecio);
}

void Menu(void)
{
    system("cls");
    printf(" ----- Menu de opciones -----\n\n");
    printf("1. Ingresar kilometros.\n");
    printf("2. Ingresar precio de vuelos.\n");
    printf("3. Calcular todos los costos.\n");
    printf("4. Informar resultados.\n");
    printf("5. Carga forzada de datos.\n");
    printf("6. Salir.\n");
}

void Menu3(void)
{
    system("cls");
    printf("Se hicieron los siguientes calculos:\n\n");
    printf("a) Tarjeta de debito (descuento 10 porciento)\n");
    printf("b) Tarjeta de credito (interes 25 porciento \n");
    printf("c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n");
    printf("d) Mostrar precio por km (precio unitario)\n");
    printf("e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n");
}

int IngresarEntero(char mensaje[])
{
    int numero;
    printf(mensaje);
    scanf("%d",&numero);
    return numero;
}
