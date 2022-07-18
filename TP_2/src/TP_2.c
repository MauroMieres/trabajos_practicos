/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "passenger.h"
#include "menus.h"
#include "typePassenger.h"
#include "utn.h"

#define LEN 2000
#define LEN_TYPE_PASSENGERS 3
#define LEN_FLIGHT_STATUS 2

int main(void) {
	setbuf(stdout, NULL);
	int nextId=1000;
	char exit;
	int opcion;
	Passenger pList[LEN];

	  eTypePassenger typePassengers[LEN_TYPE_PASSENGERS]=
	    {
	        { -1, "Menor"},
	        { 0, "Adulto"},
	        { 1, "Discapacitado"}
	    };

	  eStatusFlight statusFlights[LEN_FLIGHT_STATUS]=
	  {
			  { 0, "Cancelado"},
			  { 1, "Activo"}
	  };


	if(!initPassengers(pList,LEN))
	{
		printf("Error en la funcion initPassengers\n");
	}

	hardcodePassengers(pList, LEN, 5,&nextId);

	do
	{
		switch(menu())
		{
		case 1:
			if(!addPassenger(pList, LEN, &nextId))
			{
				printf("Error en la funcion addPassenger\n");
			}
			break;
		case 2:
			if(!modifyPassenger(pList,LEN,typePassengers,LEN_TYPE_PASSENGERS,statusFlights,LEN_FLIGHT_STATUS))
			{
				printf("Error en la funcion modifyPaassenger\n");
			}
			break;

		case 3:
			if(!removePassenger(pList, LEN, typePassengers, LEN_TYPE_PASSENGERS, statusFlights, LEN_FLIGHT_STATUS))
			{
				printf("Error en la funcion removePassenger\n");
			}
			break;
		case 4:
			switch(informMenu())
			{
				case 1:
					do
					{
						getInt(&opcion,"0: Mayor a menor\n1: Menor a Mayor", "Se ingreso un numero invalido\n");
					}while(opcion!=0&&opcion!=1);

					if(!sortPassengers(pList,LEN,opcion,typePassengers,LEN_TYPE_PASSENGERS,statusFlights,LEN_FLIGHT_STATUS))
					{
						printf("Error en la funcion sortPassengers\n");
					}
					if(!printPassengers(pList, LEN, typePassengers, LEN_TYPE_PASSENGERS, statusFlights, LEN_FLIGHT_STATUS))
					{
						printf("Error en la funcion printPassengers\n");
					}
					break;
				case 2:
					if(!printPassengers(pList, LEN, typePassengers, LEN_TYPE_PASSENGERS, statusFlights, LEN_FLIGHT_STATUS))
					{
						printf("Error en la funcion printPassengers\n");
					}
					if(!calculateAverageFlightPrice(pList,LEN))
					{
						printf("Error en la funcion calculateAverageFlightPrice\n");
					}
					break;
				case 3:
					do
					{
						getInt(&opcion,"0: Mayor a menor\n1: Menor a Mayor", "Se ingreso un numero invalido\n");
					}while(opcion!=0&&opcion!=1);

					if(!sortPassengersByCode(pList,LEN,opcion,typePassengers,LEN_TYPE_PASSENGERS,statusFlights,LEN_FLIGHT_STATUS))
					{
						printf("Error en la funcion sortPassengers\n");
					}
					if(!printActiveFlights(pList, LEN, typePassengers, LEN_TYPE_PASSENGERS, statusFlights, LEN_FLIGHT_STATUS))
					{
						printf("Error en la funcion printActiveFlights\n");
					}
					break;

				default:
					printf("Error, opcion invalida\n");
					break;
			}
			break;
		case 5:
			exit='S';
			break;
		default:
			printf("Introduzca una opcion valida!\n");
		}
	}while(exit!='S');

	return EXIT_SUCCESS;
}
