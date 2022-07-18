/*
 * statusFlight.h
 *
 *  Created on: 13 may. 2022
 *      Author: knofl
 */

#ifndef STATUSFLIGHT_H_
#define STATUSFLIGHT_H_

typedef struct
{
	int idStatusFlight;
	char descStatusFlight[10];
}eStatusFlight;

#endif /* STATUSFLIGHT_H_ */

/** \brief recibe el array de estados de vuelo, y un id, cuando el id coincide, se carga en un descripcion[] el texto correspondiente
  *
 * \param eStatusFlight*listOfStatusFlight array de estados de vuelo
 * \param lenghtList int largo del array de estados de vuelo
 * \param idStatusFlight int el id que recibe
 * \param descripcion[] char
 * \return int devuelve 1 si no hubo error
 *
 */
int loadStatusFlightDescripction(eStatusFlight*listOfStatusFlight, int lenghtList,int idStatusFlight, char descripcion[]);
