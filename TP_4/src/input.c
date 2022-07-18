#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "controller.h"
#include "jugador.h"
int ingresarString(char mensaje[], char dato[])
{
	int todoOk = 0;

	    if(mensaje != NULL && dato !=NULL)
	    {
	        printf("%s", mensaje);
	        fflush(stdin);
	        gets(dato);

	        todoOk = 1;
	    }

	    return todoOk;
}
int ingresarEntero(char mensaje[])
{
    int numeroIngresado;
    printf("%s",mensaje);

    scanf("%d",&numeroIngresado);

    return numeroIngresado;

}
int validarRangoEntero(int valor, int limiteInferior, int limiteSuperior)
{
    int todoOk = 0;
    if(valor >= limiteInferior && valor <= limiteSuperior )
    {
        todoOk = 1;
    }
    return todoOk;
}
int stringPrimerLetraMayuscula(char string[])
{
    int todoOk = 0;
    int i = 0;

    if(string != NULL)
    {
        strlwr(string);
        string[0] = toupper(string[0]);
        while(string[i] != '\0')
        {
            if(string[i] == ' ')
            {
                string[i+1] = toupper(string[i+1]);
            }

            i++;
        }
        todoOk = 1;
    }

    return todoOk;
}

int validarLargoString(char string[], int min , int max)
{
	int todoOk = 0;
	if(string != NULL)
	{

		if(strlen(string) < min || strlen(string) > max)
		{
			todoOk = 1;
		}

	}
	return todoOk;

}

int verificarSiContieneNumero(char list[])
{
    int todoOk = 0;
    if(list!= NULL)
    {
    	for (int i = 0; i < strlen(list); i++)
    	{
    		if(!(isalpha(list[i])) && list[i] != ' ')
    		{
    			todoOk = 1;
    			break;
    		}
    	}

    }

    return todoOk;
}

int menuOpcion()
{
     printf("-------------------------------\n");
	printf("  *** ABM JUGADORES ***\n\n");
	printf("-------------------------------\n");
	int opcion;
	system("cls");
	printf("[1]CARGAR LOS DATOS DE LOS JUGADORES DESDE EL ARCHIVO DATA.CSV (Modo Texto)\n");
	printf("[2]CARGAR LOS DATOS DE LOS JUGADORES DESDE EL ARCHIVO DATA.BIN (Modo Bin)\n");
	printf("[3]ALTA JUGADOR\n");
	printf("[4]MODIFICAR DATOS DE JUGADOR\n");
	printf("[5]BAJA DE JUGADOR \n");
	printf("[6]LISTAR JUGADORES \n");
	printf("[7]ORDENAR JUGADORES \n");
	printf("[8]GUARDAR LOS DATOS DE LOS JUGADORES DESDE EL ARCHIVO DATA.CSV (Modo Texto) \n");
	printf("[9]GUARDAR LOS DATOS DE LOS JUGADORES DESDE EL ARCHIVO DATA.BIN (Modo Bin) \n");
    printf("[10]AGREGA JUGADOR EN LA POSICION ESPECIFICADA [PUSH] \n");
    printf("[11]BORRA JUGADOR EN LA POSICION ESPECIFICADA [POP] \n");
    printf("[12]VERIFICA SI EL JUGADOR ESTA EN LA LISTA \n");
    printf("[13]CLONAR LISTA DE JUGADORES\n");
    printf("[14]VACIAR LISTA\n");
	printf("[15]SALIR, GRACIAS POR USAR EL PROGRAMA \n");
	fflush(stdin);
	scanf("%d",&opcion);
	return opcion;
}
