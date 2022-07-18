/*
 * typePassenger.h
 *
 *  Created on: 13 may. 2022
 *      Author: knofl
 */

#ifndef TYPEPASSENGER_H_
#define TYPEPASSENGER_H_

typedef struct
{
	int idTypePassenger;
	char descTypePassenger[15];
}eTypePassenger;

#endif /* TYPEPASSENGER_H_ */

/** \brief permite cargar la descripcion segun el tipo de pasajero para luego poder mostrarla (menor,adulto,discapacitado)
 *
 * \param eTypePassenger*listTypePassengers array de tipo de pasajeros
 * \param lenghtList int largo del array
 * \param idTypePassenger int el id que se busca hacer coincidir con el idTypePassenger
 * \param descripcion[] char la descripcion que sera cargada por referencia
 * \return int devuelve 1 si no hubo error
 *
 */
int loadTypePassengerDescription(eTypePassenger*listTypePassengers, int lenghtList,int idTypePassenger, char descripcion[]);
