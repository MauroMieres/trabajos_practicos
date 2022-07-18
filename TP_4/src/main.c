/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "controller.h"
#include "jugador.h"
#include "input.h"

int main(void)
{

    int option = 0;
    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaJugadoresCopia = NULL;
    do
    {
        option =  menuOpcion();
        switch(option)
        {
        case 1:
            if(!controller_loadFromText("data.csv",listaJugadores))
            {
                printf("Error \n");
            }
            break;
        case 2:
            if(!controller_loadFromBinary("data.bin",listaJugadores))
            {
                printf("Error \n");
            }
            break;
        case 3:
            if(!controller_addJugador(listaJugadores))
            {
                printf("Error \n");
            }
            else
            {
                printf("Jugador agregado con exito! \n");
            }

            break;
        case 4:
            if(!controller_editJugador(listaJugadores))
            {
                printf("Error \n");
            }
            else
            {
                printf("Edicion con exito! \n");
            }

            break;
        case 5:
            if(!controller_removeJugador(listaJugadores))
            {
                printf("Error \n");
            }
            else
            {
                printf("Operacion con exito! \n");
            }

            break;
        case 6:
            if(!controller_ListJugadores(listaJugadores))
            {
                printf("Error \n");
            }
            else
            {
                printf("Listado de Jugadores con exitos! \n");
            }
            break;
        case 7:
            if(!controller_sortJugador(listaJugadores))
            {
                printf("Error \n");
            }
            else
            {
                controller_ListJugadores(listaJugadores);
                printf("Ordenado con exitos! \n");
            }
            break;
        case 8:
            if(!controller_saveAsText("data.csv", listaJugadores))
            {
                printf("Error \n");
            }
            else
            {
                printf("Datos cargados en Texto correctamente! \n");
            }
            break;
        case 9:
            if(!controller_saveAsBinary("data.bin", listaJugadores))
            {
                printf("Error \n");
            }
            else
            {
                printf("Datos cargados en bin correctamente! \n");
            }
            break;
        case 10:
            if(!controller_PushJugador(listaJugadores))
            {
                printf("Error \n");
            }
            else
            {
                printf("Pusheado el jugador en el indice correcto \n");
            }
            break;
        case 11:
            if(!controller_PopJugador(listaJugadores))
            {
                printf("Error \n");
            }
            else
            {
                printf("Pop al jugador en el indice correcto \n");
            }
            break;
        case 12:
            if(!controller_ContieneJugador(listaJugadores))
            {
                printf("Error \n");
            }
            break;
        case 13:
            listaJugadoresCopia = ll_clone(listaJugadores);

            if(listaJugadoresCopia == NULL)
            {
                printf("Error\n");
            }
            else
            {
                printf("..........................CARGANDO.....................................\n");
                printf("************************LISTA COPIADA******************\n");
                system("pause");
                controller_ListJugadores(listaJugadoresCopia);
            }
            break;
        case 14:
            if(!ll_isEmpty(listaJugadores))
            {
                ll_clear(listaJugadores);
                printf("***********************LISTA LIMPIA******************************************* \n");
                controller_ListJugadores(listaJugadoresCopia);
            }
            else
            {
                printf("LA LISTA ESTA VACIA \n");
            }
            break;
        case 15:
            printf("Gracias por usar el programa!! \n");
            break;
        default:
            printf("Opcion invalida \n");
            break;
        }
        system("pause");
    }
    while(option != 15);
    ll_deleteLinkedList(listaJugadores);

    /* startTesting(1);  // ll_newLinkedList
     startTesting(2);  // ll_len
     startTesting(3);  // getNode - test_getNode
     startTesting(4);  // addNode - test_addNode
     startTesting(5);  // ll_add
     startTesting(6);  // ll_get
     startTesting(7);  // ll_set
     startTesting(8);  // ll_remove
     startTesting(9);  // ll_clear
     startTesting(10); // ll_deleteLinkedList
     startTesting(11); // ll_indexOf
     startTesting(12); // ll_isEmpty
     startTesting(13); // ll_push
     startTesting(14); // ll_pop
     startTesting(15); // ll_contains
     startTesting(16); // ll_containsAll
     startTesting(17); // ll_subList
     startTesting(18); // ll_clone
     startTesting(19); // ll_sort */

    return 0;
}

































