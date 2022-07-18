#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "jugador.h"
#include "../inc/LinkedList.h"
int controller_loadFromText(char* path , LinkedList* pArrayListJugador);
int controller_loadFromBinary(char* path , LinkedList* pArrayListJugador);
int controller_addJugador(LinkedList* pArrayListJugador);
int controller_editJugador(LinkedList* pArrayListJugador);
int controller_removeJugador(LinkedList* pArrayListJugador);
int controller_ListJugadores(LinkedList* pArrayListJugador);
int controller_sortJugador(LinkedList* pArrayListJugador);
int controller_saveAsText(char* path , LinkedList* pArrayListJugador);
int controller_saveAsBinary(char* path , LinkedList* pArrayListJugador);
eJugador* controller_searchJugadorID(LinkedList* pArrayListJugador,int id, int* index);
int controller_showJugador(eJugador* pJugador);
int controller_CompararGenero(void* a, void* b);
int controller_CompararApellido(void* a, void* b);
int controller_CompararId(void* a, void* b);
int controller_CompararNombre(void* a, void* b);
int controller_IdSiguiente(LinkedList* pArrayListJugador);
int controller_CompararEdad(void* a, void* b);
int controller_PushJugador(LinkedList* pArrayListJugador);
int controller_PopJugador(LinkedList* pArrayListJugador);
int controller_ContieneJugador(LinkedList* pArrayListJugador);
#endif // CONTROLLER_H_INCLUDED
