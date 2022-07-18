/*
 * funciones.h
 *
 *  Created on: 8 abr. 2022
 *      Author: knofl
 */
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#endif /* FUNCIONES_H_ */

/**
 * brief printea el menu
 * param ---
 * return ---
 */
void Menu(void);

/** printea el menu 3
 * brief ---
 * param ---
 * return
 */
void Menu3(void);

/**
 * brief solicita al usuario ingresar un numero entero
 * param char recibe un mensaje para printear
 * return int devuelve el entero
 */
int IngresarEntero(char mensaje[]);

/**
 * brief descuenta un porcentaje al valor de un numero
 * param float* numero por puntero
 * param float porcentaje de descuento
 * param char mensaje a printear
 * return
 */
void Descontar(float*numero,float descuento,char mensaje[]);

/**
 * brief aumenta porcentualmente el valor de un numero
 * param float* numero por puntero
 * param float porcentaje de aumento
 * param char mensaje a printear
 * return
 */
void Aumentar(float*numero,float aumento,char mensaje[]);

/**
 * brief calcula el equivalente de un precio, usa un define
 * param float* es el precio a calcular
 * param char es el mensaje a printear
 * return
 */
void CalcularPrecioBitcoin(float*precio,char mensaje[]);

/**
 * brief calcula el precio por kilometro
 * param float* recibe el precio
 * param int* recibe los kilometros
 * param char mensaje a printear
 * return
 */
void CalcularPrecioKilometro(float*precio,int*kilometros,char mensaje[]);

/**
 * brief hardcodea los viajes
 * param int* kilometros del viaje
 * param float* precio1 del viaje
 * param float* precio2 del viaje
 * param int* bandera de los kilometros ingresados
 * param int* bandera de los precios ingresados
 * param int* bandera de los calculos realizados
 * return
 */
void HardcodearViajes(int*kilometros,float*precio1,float*precio2,int*flagKm,int*flagPrecios,int*flagCalculos);
