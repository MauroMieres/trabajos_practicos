#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED
#include "../inc/LinkedList.h"
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador);

#endif // PARSER_H_INCLUDED
