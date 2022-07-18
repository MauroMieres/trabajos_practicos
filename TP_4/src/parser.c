#include <stdio.h>
#include <stdlib.h>
#include "../inc/LinkedList.h"
#include "jugador.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
		eJugador* pJugAux = NULL;
	    int cant;
	    char buffer[5][128];
	    int todoOk = 0;
	    if(pFile != NULL)
	    {
	    	 todoOk = 1;
	         cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);//Lectura fantasma
	         do
	         {
	            cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

	            if(cant < 5)
	            {
	                break;
	            }

	            pJugAux = jugador_newParametros(buffer[0],buffer[1],buffer[2],buffer[3],buffer[4]);

	            if(pJugAux != NULL)
	            {
	                    ll_add(pArrayListJugador,pJugAux);

	            }
	        }while(!feof(pFile));
	    }
	    else
	    {
	        printf("Error abriendo el archivo\n");
	    }
	    fclose(pFile);
	    return todoOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	int todoOk = 0;
	int cantidad; //Cantidad leida
	eJugador* pJugador;

	if(pFile != NULL)
	{
		do
		{
			pJugador = newJugador();
			cantidad = fread(pJugador,sizeof(eJugador),1,pFile);
			if(pJugador != NULL && cantidad == 1)
			{
				ll_add(pArrayListJugador,pJugador);
				todoOk = 1;
			}
		}
		while(!feof(pFile));

	}
	return todoOk;
}
