/*
 * menus.c
 *
 *  Created on: 22 abr. 2022
 *      Author: knofl
 */

#include "menus.h"
#include "utn.h"
#include "passenger.h"

int menu()
{
	int option;

	printf("MENU ABM PASAJEROS-VUELOS\n\n");
	printf("1. Altas\n");
	printf("2. Modificar\n");
	printf("3. Baja\n");
	printf("4. Informar\n");
	printf("5. Salir\n");
	printf("Ingrese una opcion: ");
	fflush(stdin);
	scanf("%d",&option);

	return option;
}

int modifyMenu(Passenger passenger,eTypePassenger*typePassengers,int lengthTypePassengers,eStatusFlight*statusFlightList,int lenghtStatusFlight)
{
	int option;

		printf("MENU MODIFICACION DE PASAJERO\n");
		printf("-----------------------------------------------------------------------------------------------------------\n");
		printf(" ID   Nombre     Apellido     Precio      Flycode    Type passenger   Status Flight\n");
		printf("-----------------------------------------------------------------------------------------------------------\n");
		printPassenger(passenger,typePassengers,lengthTypePassengers,statusFlightList,lenghtStatusFlight);
		printf("1. Modificar nombre\n");
		printf("2. Modificar apellido \n");
		printf("3. Modificar precio\n");
		printf("4. Modificar tipo de pasajero\n");
		printf("5. Modificar codigo de vuelo\n");
		printf("6. Salir\n");
		printf("Ingrese una opcion: ");
		scanf("%d",&option);

		return option;
}

int informMenu()
{
	int opcion;

	getInt(&opcion, "1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.\n"
	"2. Total y	promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.\n"
	"3. Listado de los pasajeros por Codigo de vuelo y estados de vuelos ‘ACTIVO'","Error, ingrese un numero valido");

	return opcion;
}
