/*
 * statusFlight.c
 *
 *  Created on: 13 may. 2022
 *      Author: knofl
 */

#include "flightStatus.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

int loadStatusFlightDescripction(eStatusFlight*listOfStatusFlight, int lenghtList,int idStatusFlight, char descripcion[])
{
    int todoOk = 0;
    int flag = 1;
    if (listOfStatusFlight != NULL && lenghtList > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < lenghtList; i++)
        {
            if (listOfStatusFlight[i].idStatusFlight == idStatusFlight)
            {
                strcpy(descripcion, listOfStatusFlight[i].descStatusFlight);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1;
        }
    }
    return todoOk;
}
