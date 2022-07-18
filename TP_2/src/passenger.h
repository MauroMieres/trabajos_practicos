/*
 * passenger.h
 *
 *  Created on: 22 abr. 2022
 *      Author: knofl
 */

#include "flightStatus.h"
#include "typePassenger.h"

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char name[51];
	char lastname[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFligth;
	int isEmpty;
}Passenger;

#endif /* PASSENGER_H_ */

/** \brief carga todas las posiciones del array en isEmpty en = 0
* \param list Passenger* puntero del array de pasajeros
* * \param len int largo del array
* \return int Return 1 si no hubo error
*/
int initPassengers(Passenger* list, int len);

/** \brief encuentra un pasajero con isEmpty = 0
 *
 * \param list Passenger* array de pasajeros
 * \param len int largo del array
 * \return int devuelve 1 si no hubo error
 *
 */
int findFreePassenger(Passenger* list,int len);

/** \brief permite añadir un pasajero al array en caso de haber espacio
 *
 * \param list Passenger* array de pasajeros
 * \param len int   largo del array
 * \param int*id    puntero del id de pasajero
 * \return int devuelve 1 si no hubo error
 *
 */
int addPassenger(Passenger* list, int len, int*id);

/** \brief encuentra un pasajero haciendo coincidir el id con alguno existente en el sistema
 *
 * \param list Passenger* array de pasajeros
 * \param len int largo del array
 * \param id int    id que ingresa el usuario
 * \return int devuelve -1 si no existe el id, o la posicion del array donde se encontro la coincidencia
 *
 */
int findPassengerById(Passenger* list, int len,int id);

/** \brief baja logica de un pasajero, cambia el isEmpty a 1
 *
 * \param list Passenger*   array de pasajeros
 * \param len int   largo del array
 * \param eTypePassenger*listTypePassengers     array tipo de pasajeros
 * \param lengthTypePassengers int  largo array de tipo de pasajeros
 * \param statusFlightList eStatusFlight*   array estado de vuelo
 * \param lenghtStatusFlight int    largo array estado de vuelo
 * \return int devuelve 1 si no hubo error
 *
 */
int removePassenger(Passenger* list, int len,eTypePassenger*listTypePassengers,int lengthTypePassengers,eStatusFlight* statusFlightList,int lenghtStatusFlight);

/** \brief ordena el array de pasajeros por apellido y tipo de pasajero segun el orden recibido 0:menor a mayor 1:mayor a menor
 *
 * \param list Passenger* array de pasajeros
 * \param len int   largo array de pasajeros
 * \param order int criterio de ordenamiento (0/1)
 * \param eTypePassenger*listTypePassengers array tipo de pasajeros
 * \param lengthTypePassengers int  largo array tipo de pasajeros
 * \param statusFlightList eStatusFlight* array estado de vuelo
 * \param lenghtStatusFlight int    largo array estado de vuelo
 * \return int devuelve 1 si no hubo error
 *
 */
int sortPassengers(Passenger* list, int len, int order,eTypePassenger*listTypePassengers,int lengthTypePassengers,eStatusFlight* statusFlightList,int lenghtStatusFlight);

/** \brief ordena el array de pasajeros por codigo de vuelo
 *
 * \param list Passenger* array de pasajeros
 * \param len int largo array de pasajeros
 * \param order int criterio de ordenamiento (0/1)
 * \param eTypePassenger*listTypePassengers array tipo de pasajeros
 * \param lengthTypePassengers int largo array tipo de pasajeros
 * \param statusFlightList eStatusFlight* array estado de vuelo
 * \param lenghtStatusFlight int largo array estado de vuelo
 * \return int devuelve 1 si no hubo error
 *
 */
int sortPassengersByCode(Passenger* list, int len, int order,eTypePassenger*listTypePassengers,int lengthTypePassengers,eStatusFlight* statusFlightList,int lenghtStatusFlight);

/** \brief imprime un pasajero
 *
 * \param passenger Passenger la posicion del array de pasajeros recibida
 * \param eTypePassenger*typePassengers array de tipos de pasajeros
 * \param lengthTypePassengers int  largo del array de tipos de pasajeros
 * \param eStatusFlight*statusFlightList array de estado de vuelos
 * \param lenghtStatusFlight int largo del array de estado de vuelos
 * \return void
 *
 */
void printPassenger(Passenger passenger,eTypePassenger*typePassengers,int lengthTypePassengers,eStatusFlight*statusFlightList,int lenghtStatusFlight);

/** \brief imprime el array de pasajeros enteros (no imprime a los que estan de baja logica)
 *
 * \param list Passenger* array de pasajeros
 * \param listLenght int	largo del array de pasajeros
 * \param eTypePassenger*listTypePassengers	array de tipos de pasajeros
 * \param lengthTypePassengers int largo del array de tipos de pasajeros
 * \param statusFlightList eStatusFlight* array de estado de vuelos
 * \param lenghtStatusFlight int largo del array de estado de vuelos
 * \return int devuelve 1 si no hubo error
 *
 */
int printPassengers(Passenger* list, int listLenght,eTypePassenger*listTypePassengers,int lengthTypePassengers,eStatusFlight* statusFlightList,int lenghtStatusFlight);

/** \brief permite modificar los datos de un pasajero cargado en el sistema
 *
 * \param Passenger*list array de pasajeros
 * \param len int largo del array de pasajeros
 * \param eTypePassenger*typePassengers array de tipos de pasajeros
 * \param lengthTypePassengers int largo del array de tipos de pasajeros
 * \param eStatusFlight*statusFlightList array de estado de vuelos
 * \param lenghtStatusFlight int largo del array de estado de vuelos
 * \return int devuelve 1 si no hubo error
 *
 */
int modifyPassenger(Passenger*list, int len,eTypePassenger*typePassengers,int lengthTypePassengers,eStatusFlight*statusFlightList,int lenghtStatusFlight);

/** \brief carga forzada de pasajeros
 *
 * \param Passenger*list array de pasajeros
 * \param len int largo del array
 * \param cant int cantidad de pasajeros que se quieren hardcodear
 * \param int*pId puntero del id del pasajero
 * \return int devuelve 1 si no hubo error
 *
 */
int hardcodePassengers(Passenger*list, int len, int cant, int*pId);

/** \brief recibe el array de pasajeros y calcula el precio promedio de los vuelos
 *
 * \param Passenger*list array de pasajeros
 * \param len int largo del array
 * \return int devuelve 1 si no hubo error
 *
 */
int calculateAverageFlightPrice(Passenger*list,int len);

/** \brief imprime la lista de solo pasajeros con vuelos activos
 *
 * \param list Passenger* array de pasajeros
 * \param listLenght int    largo del array de pasajeros
 * \param eTypePassenger*listTypePassengers array de tipos de pasajeros
 * \param lengthTypePassengers int largo del array de tipos de pasajeros
 * \param statusFlightList eStatusFlight* array de estados de vuelo
 * \param lenghtStatusFlight int largo del array de estados de vuelo
 * \return int devuelve 1 si no hubo error
 *
 */
int printActiveFlights(Passenger* list, int listLenght,eTypePassenger*listTypePassengers,int lengthTypePassengers,eStatusFlight* statusFlightList,int lenghtStatusFlight);

Passenger_header(void);
