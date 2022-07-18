#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

typedef struct{
    int id;
    char nombre[20];
    char apellido[20];
    int edad;
    char genero;
}eJugador;

eJugador* newJugador();
eJugador* jugador_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* edadStr,char* generoStr);

void jugador_delete();

int jugador_setId(eJugador* this,int id);
int jugador_getId(eJugador* this,int* id);

int jugador_setNombre(eJugador* this,char* nombre);
int jugador_getNombre(eJugador* this,char* nombre);

int jugador_setApellido(eJugador* this,char* apellido);
int jugador_getApellido(eJugador* this,char* apellido);


int jugador_setEdad(eJugador* this,int edad);
int jugador_getEdad(eJugador* this,int* edad);

int jugador_setGenero(eJugador* this,char genero);
int jugador_getGenero(eJugador* this,char* genero);
#endif // JUGADOR_H_INCLUDED
