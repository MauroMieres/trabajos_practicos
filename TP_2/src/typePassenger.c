/*
 * typePassenger.c
 *
 *  Created on: 13 may. 2022
 *      Author: knofl
 */
#include "typePassenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

int loadTypePassengerDescription(eTypePassenger*listTypePassengers, int lenghtList,int idTypePassenger, char descripcion[])
{
    int todoOk = 0;
    int flag = 1;
    if (listTypePassengers != NULL && lenghtList > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < lenghtList; i++)
        {
            if (listTypePassengers[i].idTypePassenger == idTypePassenger)
            {
                strcpy(descripcion, listTypePassengers[i].descTypePassenger);
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
