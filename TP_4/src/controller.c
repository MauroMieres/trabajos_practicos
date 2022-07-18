#include <stdio.h>
#include <stdlib.h>
#include "jugador.h"
#include "parser.h"
#include "controller.h"
#include "../inc/LinkedList.h"
#include <ctype.h>
#include <string.h>
#include "input.h"



int controller_loadFromText(char* path, LinkedList* pArrayListJugador)
{
    int todoOk = 0;
    FILE* pFile;

    if (path != NULL && pArrayListJugador != NULL)
    {
        system("cls");
        printf("Cargar los datos de los jugadores desde el archivo data.csv (modo texto).\n");

        pFile = fopen( path, "r");
        if (pFile == NULL)
        {
            printf("No se pudo abrir el archivo\n");
        }
        else
        {
            if (parser_JugadorFromText(pFile, pArrayListJugador))
            {
                printf( "Carga de archivo de texto exitosa\n" );
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;
}
int controller_loadFromBinary(char* path, LinkedList* pArrayListJugador)
{
    int todoOk  = 0;
    FILE* p;

    if(path != NULL && pArrayListJugador != NULL)
    {
        system("cls");
        printf("Cargar los datos de los jugadores desde el archivo data.bin (modo bin).\n");
        p = fopen(path,"rb");
        if(p == NULL)
        {
            printf("No se pudo abrir el archivo\n");
        }
        else
        {
            if(parser_JugadorFromBinary(p,pArrayListJugador))
            {
                printf("Carga de archivo de texto exitosa\n");
                todoOk = 1;
            }
        }
    }
    fclose(p);
    return todoOk;
}
int controller_addJugador(LinkedList* pArrayListJugador)
{
    eJugador* nuevoJugador = NULL;
    char nombre[101];
    char apellido[101];
    int edad;
    char genero;
    int todoOk = 0;
    int id = 0;
    if(pArrayListJugador != NULL)
    {

        id = controller_IdSiguiente(pArrayListJugador);
        id++;
        ingresarString("Ingresa el nombre : ", nombre);
        while(validarLargoString(nombre,1, 19) || verificarSiContieneNumero(nombre))
        {
            printf("Error no se puede ingresar mas de 19 caracteres  o numeros\n");
            ingresarString("Ingresa el nombre : ", nombre);

        }
        stringPrimerLetraMayuscula(nombre);
        ingresarString("Ingresa el apellido : ", apellido);
        while(validarLargoString(apellido,1, 19) || verificarSiContieneNumero(apellido))
        {
            printf("Error no se puede ingresar mas de 19 caracteres  o numeros\n");
            ingresarString("Ingresa el apellido : ", apellido);

        }
        stringPrimerLetraMayuscula(apellido);
        edad = ingresarEntero("Ingresar edad: ");
        while(edad < 18 || edad > 40 )
        {
            edad = ingresarEntero("Error. Ingresar edad: ");
        }
        printf("Ingresar genero. F O M : ");
        fflush(stdin);
        scanf("%c",&genero);
        genero = toupper(genero);
        while(genero != 'F' && genero != 'M' )
        {
            printf("Ingresar genero. F O M : ");
            fflush(stdin);
            scanf("%c",&genero);
            genero = toupper(genero);
        }


        nuevoJugador = newJugador();
        if(nuevoJugador != NULL)
        {
            if(jugador_setId(nuevoJugador,id)
                    && jugador_setNombre(nuevoJugador,nombre)
                    && jugador_setApellido(nuevoJugador,apellido)
                    && jugador_setEdad(nuevoJugador,edad)
                    && jugador_setGenero(nuevoJugador,genero)
              )
            {
                printf("\n** Jugador agregado con exito!! **\n");
                ll_add(pArrayListJugador,nuevoJugador);
            }
            else
            {
                free(nuevoJugador);
                printf("\n** Error**\n");
            }
        }

        todoOk = 1;
    }
    else
    {
        printf("**\n No hay espacio**\n");

    }

    return todoOk;
}

int controller_editJugador(LinkedList* pArrayListJugador)
{
    int idIngresado;//Por el usuario
    int indice = -1;//
    eJugador* auxJugador = NULL;
    int opcion;
    int todoOk = 0;
    char nombre[60];
    char apellido[60];
    int edad;
    char genero;
    if(pArrayListJugador != NULL)
    {
        controller_ListJugadores(pArrayListJugador);
        idIngresado = ingresarEntero("Ingresa ID: ");
        while(idIngresado < 0 )
        {
            idIngresado = ingresarEntero("Error ID invalido. Ingresa ID: ");

        }

        auxJugador = controller_searchJugadorID(pArrayListJugador,idIngresado,&indice);
        if(indice != -1)
        {

            do
            {
                system("cls");
                printf("\n          **Editar**\n   ID     Nombre        Apellido     Edad    Genero   \n");
                controller_showJugador(auxJugador);
                printf("\n 1) Nombre  2) Apellido 3) Edad 4) Genero 5)Salir \n");
                opcion = ingresarEntero("Ingresa opcion :  ");
                while(opcion < 1 || opcion > 5 )
                {
                    printf("\n 1) Nombre  2) Apellido 3) Edad 4) Genero 5)Salir \n");
                    opcion = ingresarEntero("Error . Ingresa opcion :  ");

                }
                printf("\n          **Editar**\n   ID     Nombre        Apellido     Edad    Genero   \n");

                controller_showJugador(auxJugador);
                switch(opcion)
                {
                case 1:
                    ingresarString("Ingresa el nombre : ", nombre);
                    while(validarLargoString(nombre,1, 19) || verificarSiContieneNumero(nombre))
                    {
                        printf("Error no se puede ingresar mas de 19 caracteres  o numeros\n");
                        ingresarString("Ingresa el nombre : ", nombre);

                    }
                    stringPrimerLetraMayuscula(nombre);
                    jugador_setNombre(auxJugador,nombre);
                    break;
                case 2:
                    ingresarString("Ingresa el apellido : ", apellido);
                    while(validarLargoString(apellido,1, 19) || verificarSiContieneNumero(apellido))
                    {
                        printf("Error no se puede ingresar mas de 19 caracteres  o numeros\n");
                        ingresarString("Ingresa el apellido : ", apellido);

                    }
                    stringPrimerLetraMayuscula(apellido);
                    jugador_setApellido(auxJugador,apellido);
                    break;
                case 3:
                    edad = ingresarEntero("Ingresar edad: ");
                    while(edad < 18 || edad > 40 )
                    {
                        edad = ingresarEntero("Error. Ingresar edad: ");
                    }
                    jugador_setEdad(auxJugador,edad);
                    break;
                case 4:
                    printf("Ingresar genero. F O M");
                    fflush(stdin);
                    scanf("%c",&genero);
                    genero = toupper(genero);
                    while(genero != 'F' || genero != 'M' )
                    {
                        printf("Ingresar genero. F O M");
                        fflush(stdin);
                        scanf("%c",&genero);
                        genero = toupper(genero);
                    }
                    jugador_setGenero(auxJugador,genero);
                    break;
                case 5:
                    printf("Salida con exito!! \n");
                    break;
                default:
                    printf("Error \n");
                    break;
                }
            }
            while(opcion != 5);


            todoOk = 1;
        }
        else
        {

            printf("*** Jugador con el id %d no existe. ****\n",idIngresado);
            todoOk = -1;
        }
    }

    return todoOk;
}
int controller_removeJugador(LinkedList* pArrayListJugador)
{
    int idIngresado;//Por el usuario
    int indice = -1;//
    eJugador* auxJugador = NULL;
    char confirmacion;
    int todoOk = 0;
    if(pArrayListJugador != NULL)
    {
        controller_ListJugadores(pArrayListJugador);
        idIngresado = ingresarEntero("Ingresa ID: ");
        while(idIngresado < 0 )
        {
            idIngresado = ingresarEntero("Error ID invalido. Ingresa ID: ");

        }

        auxJugador = controller_searchJugadorID(pArrayListJugador,idIngresado,&indice);

        if(indice != -1)
        {
            printf("\n 						  Jugador a remover \n");
            printf("--------------------------------------------------------------------------\n");
            printf(" ID         NOMBRE            APELLIDO            EDAD          GENERO        \n");
            printf("---------------------------------------------------------------------------\n");
            controller_showJugador(auxJugador);
            printf("Queres remover a este jugador? s/n: ");
            fflush(stdin);
            scanf(" %c",&confirmacion);
            confirmacion = tolower(confirmacion);
            if(confirmacion == 's')
            {
                if(ll_remove(pArrayListJugador,indice) == 0)
                {
                    printf("-- Jugador removido --\n");
                }
                jugador_delete(auxJugador);
            }
            else
            {
                printf("-- No se borro el jugador--\n");
            }

            todoOk = 1;
        }
        else
        {

            printf("*** Jugador con el id %d no existe. ****\n",idIngresado);
            todoOk = -1;
        }
    }
    return todoOk;
}

int controller_ListJugadores(LinkedList* pArrayListJugador)
{
    eJugador* pJugador = NULL;
    int todoOk = 0;
    int tam;

    if(pArrayListJugador != NULL)
    {
        tam =  ll_len(pArrayListJugador);
        system("cls");
        printf("                     ***Lista de Jugador  ***\n");
        printf("--------------------------------------------------------------------------\n");
        printf(" ID         NOMBRE            APELLIDO            EDAD          GENERO        \n");
        printf("---------------------------------------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            pJugador = ll_get(pArrayListJugador,i);
            controller_showJugador(pJugador);

        }
        todoOk =1;
    }
    return todoOk;
}
int controller_sortJugador(LinkedList* pArrayListJugador)
{
    int todoOk = 0;
    int opcion;
    int orden;
    if (pArrayListJugador != NULL)
    {
        todoOk = 1;
        printf("Ordenar Jugadores\n");
        orden = ingresarEntero("Orden ascendente o descendente : 0 Descendente, 1 Ascendente ");
        while(orden < 0 || orden > 1)
        {
            orden = ingresarEntero("Error... Orden ascendente o descendente : 0 Descendente, 1 Ascendente ");
        }

        opcion = ingresarEntero("Ingresar opcion: 1-Ordenar por Id, 2-Ordenar por Nombre, 3-Ordenar Apellido 4-Ordenar por edad , 5-Ordenar por genero 6-Salir : ");
        while(opcion < 1 || opcion > 6)
        {
            opcion = ingresarEntero("Ingresar opcion: 1-Ordenar por Id, 2-Ordenar por Nombre, 3-Ordenar Apellido 4-Ordenar por edad , 5-Ordenar por genero 6-Salir : ");
        }
        system("cls");
        printf("***************************** CARGANDO*********************************************\n");
        switch (opcion)
        {
        case 1:
            printf("ORDENADO POR ID\n");
            ll_sort(pArrayListJugador, controller_CompararId, orden);
            break;
        case 2:
            printf("ORDENADO POR NOMBRE\n");
            ll_sort(pArrayListJugador, controller_CompararNombre, orden);
            break;
        case 3:
            printf("ORDENADO POR APELLIDO\n");
            ll_sort(pArrayListJugador,controller_CompararApellido,orden);
            break;
        case 4:
            printf("ORDENADO POR EDAD\n");
            ll_sort(pArrayListJugador, controller_CompararEdad,orden);
            break;
        case 5:
            printf("ORDENADO POR GENERO\n");
            ll_sort(pArrayListJugador, controller_CompararGenero,orden);
            break;
        case 6:
            printf("Salida correctamente !!! \n");
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }
    }
    return todoOk;
}
int controller_saveAsText(char* path, LinkedList* pArrayListJugador)
{
    int todoOk = 0;
    FILE* pFile;
    int id;
    char nombre[50];
    char apellido[50];
    int edad;
    char  genero;
    eJugador* auxJugador;

    if (path != NULL && pArrayListJugador != NULL)
    {
        pFile = fopen(path, "w");
        if (pFile == NULL)
        {
            printf("No se pudo abrir el archivo\n");
        }

        fprintf(pFile, "id,nombre,apellido,edad,genero\n");

        for (int i = 0; i < ll_len(pArrayListJugador); i++)
        {
            auxJugador = ll_get(pArrayListJugador, i);
            if ( jugador_getId(auxJugador, &id) &&
                    jugador_getNombre(auxJugador, nombre) &&
                    jugador_getApellido(auxJugador, apellido) &&
                    jugador_getEdad(auxJugador,&edad)&&
                    jugador_getGenero(auxJugador,&genero)
               )
            {
                fprintf(pFile, "%d,%s,%s,%d,%c\n", id, nombre, apellido, edad, genero);
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;
}
int controller_saveAsBinary(char* path, LinkedList* pArrayListJugador)
{
    int todoOk = 0;
    FILE* pFile;
    eJugador* auxJugador;

    if (path != NULL && pArrayListJugador != NULL)
    {
        pFile = fopen(path, "wb");
        if (pFile == NULL)
        {
            printf("No se pudo abrir el archivo\n");
        }

        for (int i = 0; i < ll_len(pArrayListJugador); i++)
        {
            auxJugador = ll_get(pArrayListJugador, i);
            if ((auxJugador) != NULL)
            {
                fwrite(auxJugador, sizeof(eJugador), 1, pFile);
                todoOk = 1;
            }
        }
    }
    fclose(pFile);
    return todoOk;
}
eJugador* controller_searchJugadorID(LinkedList* pArrayListJugador,int id, int* index)
{
    eJugador* auxJugador = NULL; //Jugador a analizar en cada iteracion de for
    int auxId;//Id del jugador que averiguo en cada iteracion de for
    *index = -1;
    for(int i = 0 ; i < ll_len(pArrayListJugador) ; i++ )
    {
        auxJugador  = (eJugador*) ll_get(pArrayListJugador,i);
        jugador_getId(auxJugador,&auxId);
        if(auxJugador  != NULL && auxId == id)
        {
            (*index) = i;
            break;
        }
    }

    return auxJugador;
}
int controller_showJugador(eJugador* pJugador)
{
    int id;
    char nombre[40];
    char apellido[40];
    int edad;
    char genero[20];
    int todoOk = 0;
    if(pJugador != NULL &&
            jugador_getId(pJugador, &id) &&
            jugador_getNombre(pJugador, nombre) &&
            jugador_getApellido(pJugador, apellido) &&
            jugador_getEdad(pJugador,&edad)&&
            jugador_getGenero(pJugador,genero) )
    {

        printf(" %d 	%-10s       %-10s  		%-4d   		   %-4s \n",id,nombre,apellido,edad,genero);
        todoOk = 1;
    }
    return todoOk;
}

int controller_CompararGenero(void* a, void* b)
{
    int todoOk;
    if(a != NULL && b != NULL)
    {
        if(((eJugador*)a)->genero > ((eJugador*)b)->genero)
        {
            todoOk = 1;
        }
        else
        {
            if(((eJugador*)a)->genero < ((eJugador*)b)->genero)
            {
                todoOk = -1;
            }
        }
    }

    return todoOk;
}
int controller_CompararApellido(void* a, void* b)
{
    int todoOk = 0;
    char auxApellidoeA[40];
    char auxApellidoB[40];
    if(a != NULL && b != NULL)
    {
        strcpy(auxApellidoeA,((eJugador*)a)->apellido);
        strcpy(auxApellidoB,((eJugador*)b)->apellido);
        todoOk = strcmp(auxApellidoeA,auxApellidoB);
    }
    return todoOk;
}
int controller_CompararId(void* a, void* b)
{
    int todoOk;
    if(a != NULL && b != NULL)
    {
        if(((eJugador*)a)->id > ((eJugador*)b)->id)
        {
            todoOk = 1;
        }
        else
        {
            if(((eJugador*)a)->id < ((eJugador*)b)->id)
            {
                todoOk = -1;
            }
        }
    }

    return todoOk;
}
int controller_CompararNombre(void* a, void* b)
{
    int todoOk = 0;
    char auxNombreA[40];
    char auxNombreB[40];
    if(a != NULL && b != NULL)
    {
        strcpy(auxNombreA,((eJugador*)a)->nombre);
        strcpy(auxNombreB,((eJugador*)b)->nombre);
        todoOk = strcmp(auxNombreA,auxNombreB);
    }
    return todoOk;
}
int controller_CompararEdad(void* a, void* b)
{
    int todoOk;
    if(a != NULL && b != NULL)
    {
        if(((eJugador*)a)->edad > ((eJugador*)b)->edad)
        {
            todoOk = 1;
        }
        else
        {
            if(((eJugador*)a)->edad < ((eJugador*)b)->edad)
            {
                todoOk = -1;
            }
        }
    }

    return todoOk;
}
int controller_IdSiguiente(LinkedList* pArrayListJugador)
{
    eJugador* auxJugador = NULL;
    int maximo;
    int id = 0;
    int tam;
    if(pArrayListJugador != NULL)
    {
        tam = ll_len(pArrayListJugador);
        for(int i = 0; i < tam ; i++)
        {
            auxJugador = ll_get(pArrayListJugador,i);
            jugador_getId(auxJugador, &id);
            if(id > maximo || i == 0)
            {
                maximo = id;
            }
        }
    }
    return maximo;
}

int controller_PushJugador(LinkedList* pArrayListJugador)
{
    eJugador* nuevoJugador = NULL;
    char nombre[101];
    char apellido[101];
    int edad;
    char genero;
    int todoOk = 0;
    int id = 0;
    int indice;
    if(pArrayListJugador != NULL)
    {

        id = controller_IdSiguiente(pArrayListJugador);
        id++;
        ingresarString("Ingresa el nombre : ", nombre);
        while(validarLargoString(nombre,1, 19) || verificarSiContieneNumero(nombre))
        {
            printf("Error no se puede ingresar mas de 19 caracteres  o numeros\n");
            ingresarString("Ingresa el nombre : ", nombre);

        }
        stringPrimerLetraMayuscula(nombre);
        ingresarString("Ingresa el apellido : ", apellido);
        while(validarLargoString(apellido,1, 19) || verificarSiContieneNumero(apellido))
        {
            printf("Error no se puede ingresar mas de 19 caracteres  o numeros\n");
            ingresarString("Ingresa el apellido : ", apellido);

        }
        stringPrimerLetraMayuscula(apellido);
        edad = ingresarEntero("Ingresar edad: ");
        while(edad < 18 || edad > 40 )
        {
            edad = ingresarEntero("Error. Ingresar edad: ");
        }
        printf("Ingresar genero. F O M : ");
        fflush(stdin);
        scanf("%c",&genero);
        genero = toupper(genero);
        while(genero != 'F' && genero != 'M' )
        {
            printf("Ingresar genero. F O M : ");
            fflush(stdin);
            scanf("%c",&genero);
            genero = toupper(genero);
        }
        indice = ingresarEntero("Indice en el que quieres agregar al jugador\n");
        nuevoJugador = newJugador();
        if(nuevoJugador != NULL)
        {
            if(jugador_setId(nuevoJugador,id)
                    && jugador_setNombre(nuevoJugador,nombre)
                    && jugador_setApellido(nuevoJugador,apellido)
                    && jugador_setEdad(nuevoJugador,edad)
                    && jugador_setGenero(nuevoJugador,genero)
              )
            {
                if(ll_push(pArrayListJugador,indice,nuevoJugador) == -1)
                {
                    printf("Error \n");
                }
                else
                {
                    printf("Agregado correctamente en el indice especificado \n");
                    todoOk = 1;
                }
            }
            else
            {
                free(nuevoJugador);
                printf("\n** Error**\n");
            }
        }
    }
    return todoOk;

}
int controller_PopJugador(LinkedList* pArrayListJugador)
{
    eJugador* auxJugador = NULL;
    int todoOk = 0;
    int indice;
    int idIngresado;//Por el usuario
    char confirmacion;
    if(pArrayListJugador != NULL)
    {
        controller_ListJugadores(pArrayListJugador);
        idIngresado = ingresarEntero("Ingresa ID: ");
        while(idIngresado < 0 )
        {
            idIngresado = ingresarEntero("Error ID invalido. Ingresa ID: ");

        }

        auxJugador = controller_searchJugadorID(pArrayListJugador,idIngresado,&indice);

        if(indice != -1)
        {
            printf("\n 						  Jugador a remover \n");
            printf("--------------------------------------------------------------------------\n");
            printf(" ID         NOMBRE            APELLIDO            EDAD          GENERO        \n");
            printf("---------------------------------------------------------------------------\n");
            auxJugador = ll_get(pArrayListJugador,indice);
            controller_showJugador(auxJugador);
            todoOk = 1;
            printf("Queres remover a este jugador? s/n: ");
            fflush(stdin);
            scanf(" %c",&confirmacion);
            confirmacion = tolower(confirmacion);
            if(confirmacion == 's')
            {
                auxJugador = (eJugador*) ll_pop(pArrayListJugador,indice);
                if(auxJugador == NULL)
                {

                    printf("Error \n");
                }
                else
                {
                    printf("-- Jugador popeado (Eliminado) --\n");
                    controller_showJugador(auxJugador);
                }
            }
            else
            {
                printf("-- No se borro el jugador--\n");
            }

        }
        else
        {

            printf("*** Jugador con el id %d no existe. ****\n",idIngresado);
        }
    }
    return todoOk;
}
int controller_ContieneJugador(LinkedList* pArrayListJugador)
{
    eJugador* auxJugador = NULL;
    int todoOk = 0;
    int indice;
    int idIngresado;//Por el usuario
    if(pArrayListJugador != NULL)
    {
        controller_ListJugadores(pArrayListJugador);
        idIngresado = ingresarEntero("Ingresa ID para ver si existe en la lista: ");
        while(idIngresado < 0 )
        {
            idIngresado = ingresarEntero("Error ID invalido. Ingresa ID: ");

        }

        auxJugador = controller_searchJugadorID(pArrayListJugador,idIngresado,&indice);
        auxJugador = ll_get(pArrayListJugador,indice);
        if(ll_contains(pArrayListJugador,auxJugador) == 1)
        {
            controller_showJugador(auxJugador);
            printf("El Jugador esta en la lista \n");
        }
        else
        {
            printf("No esta en la lista. \n");
        }
        todoOk = 1;
    }
    return todoOk;
}
