#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jugador.h"


eJugador* newJugador()
{

	eJugador* nuevoJugador =  (eJugador*)malloc(sizeof(eJugador));
    if(nuevoJugador != NULL )
    {
        nuevoJugador->id = 0;
        strcpy(nuevoJugador->nombre," ");
        strcpy(nuevoJugador->apellido," ");
        nuevoJugador->edad = 0;
        nuevoJugador->genero = ' ';
    }
    return nuevoJugador;
}
eJugador* jugador_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* edadStr,char* generoStr)
{
	eJugador* pJugador = newJugador();
	    if(pJugador != NULL)
	    {
	        if(!( jugador_setId(pJugador,atoi(idStr) )
	           && jugador_setNombre(pJugador,nombreStr)
               && jugador_setApellido(pJugador,apellidoStr)
	           && jugador_setEdad(pJugador,atoi(edadStr))
	           && jugador_setGenero(pJugador,*generoStr))){

	                free(pJugador);
	                pJugador = NULL;

	        }
	    }
	    return pJugador;
}
int jugador_setId(eJugador* this,int id)
{

	int todoOk = 0;
	if(this != NULL && id > 0)
	{
		this->id = id;
		todoOk = 1;
	}
	return todoOk;
}
int jugador_getId(eJugador* this,int* id)
{
	int todoOk = 0;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		todoOk = 1;
	}
	return todoOk;
}

int jugador_setNombre(eJugador* this,char* nombre)
{
	int todoOk = 0;
	if(this != NULL && nombre != NULL && strlen(nombre) < 19)
	{
		strcpy(this->nombre,nombre);
		todoOk = 1;
	}
	return todoOk;

}
int jugador_getNombre(eJugador* this,char* nombre)
{
	int todoOk = 0;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		todoOk = 1;
	}
	return todoOk;
}

int jugador_setApellido(eJugador* this,char* apellido)
{
	int todoOk = 0;
	if(this != NULL && apellido != NULL && strlen(apellido) < 19)
	{
		strcpy(this->apellido,apellido);
		todoOk = 1;
	}
	return todoOk;

}
int jugador_getApellido(eJugador*this,char* apellido)
{
	int todoOk = 0;
	if(this != NULL && apellido != NULL)
	{
		strcpy(apellido,this->apellido);
		todoOk = 1;
	}
	return todoOk;
}
int jugador_setEdad(eJugador* this,int edad)
{
	int todoOk = 0;
	if(this != NULL && edad > 17 && edad < 41)
	{
		this->edad = edad;
		todoOk = 1;
	}
	return todoOk;
}
int jugador_getEdad(eJugador* this,int* edad)
{
	int todoOk = 0;
	if(this != NULL && edad != NULL)
	{
		*edad = this->edad;
		todoOk = 1;
	}
	return todoOk;
}


int jugador_setGenero(eJugador* this,char genero)
{
    int todoOk = 0;
    genero = toupper(genero);
    if(this != NULL && (genero == 'F' || genero == 'M')  )
    {
        this->genero = genero;
        todoOk = 1;
    }
    return todoOk;
}
int jugador_getGenero(eJugador* this,char *genero)
{
    int todoOk = 0;
    if(this != NULL)
    {
        if(this->genero == 'F')
        {
            strcpy(genero,"Femenino");
        }
        else
        {
            strcpy(genero,"Masculino");
        }
        todoOk = 1;
    }
    return todoOk;
}
void jugador_delete(eJugador* this)
{
	if(this!= NULL)
	{
		free(this);
	}

}
