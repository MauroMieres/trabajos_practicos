/*
 * menus.h
 *
 *  Created on: 22 abr. 2022
 *      Author: knofl
 */

#include <stdio.h>
#include <stdlib.h>
#include "passenger.h"

#ifndef MENUS_H_
#define MENUS_H_

#endif /* MENUS_H_ */

/** \brief menu principal
 *
 * \return int devuelve un integer que es usado como opcion para un switch
 *
 */
int menu();

/** \brief menu de modificacion de pasajero, recibe todos los arrays necesarios para hacer la modificacion
 *
 * \param passenger Passenger
 * \param eTypePassenger*typePassengers
 * \param lengthTypePassengers int
 * \param eStatusFlight*statusFlightList
 * \param lenghtStatusFlight int
 * \return int devuelve 1 si no hubo error
 *
 */
int modifyMenu(Passenger passenger,eTypePassenger*typePassengers,int lengthTypePassengers,eStatusFlight*statusFlightList,int lenghtStatusFlight);

/** \brief menu de informes
 *
 * \return int devuelve 1 si no hubo error
 *
 */
int informMenu();
