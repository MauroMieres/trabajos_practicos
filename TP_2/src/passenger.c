/*
 * passenger.c
 *
 *  Created on: 22 abr. 2022
 *      Author: knofl
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "menus.h"
#include "utn.h"
#include "passenger.h"

int initPassengers(Passenger* list, int len)
{
	int todoOk = 0;
	    if (list != NULL && len > 0)
	    {
	        todoOk = 1;
	        for (int i = 0; i < len; i++)
	        {
	        	list[i].isEmpty = 1;
	        }
	    }
	    return todoOk;
}

int findFreePassenger(Passenger* list,int len)
{
	int indice = -1;
	for (int i = 0; i < len; i++)
	{
		if (list[i].isEmpty)
		{
			indice = i;
			break;
		}
	}
	return indice;
}

int addPassenger(Passenger* list, int len, int*id)
{
	int todoOk = 0;
	int indice;
	Passenger auxPassenger;
	if (list != NULL && len > 0)
	{
		printf("  ***Agregar Pasajero*** \n\n");
		indice = findFreePassenger(list,len);
		if (indice == -1)
		{
			printf("No hay lugar\n");
		}
		else
		{
			auxPassenger.id = *id;
			(*id)++;


		   getAlphabetic_Characters_String(auxPassenger.name,"Ingresar nombre: ","Nombre muy largo, reingrese: ",51);

		   changeStringFormat(auxPassenger.name);

		   getAlphabetic_Characters_String(auxPassenger.lastname,"Ingresar apellido: ","Apellido muy largo, reingrese: ",51);
		   changeStringFormat(auxPassenger.lastname);

		   getFloat(&auxPassenger.price, "Ingrese precio del vuelo: ","Error, precio ingresado invalido\n");

		   getString(auxPassenger.flycode, "Ingrese codigo de vuelo: ", "Error, maximo 10 caracteres por codigo",10);
		   toupperString(auxPassenger.flycode);

		   do
		   {
			   getInt(&auxPassenger.typePassenger,"Ingrese el tipo de pasajero: -1(menor)/0(adulto)/1(discapacitado)","Error, ingrese un tipo de pasajero valido");
		   }while(!validateTypePassenger(auxPassenger.typePassenger));

		   do
		   {
			   getInt(&auxPassenger.statusFligth,"Ingrese Estado del vuelo: -1(cancelado)/0(en horario)/1(activo): ","Error, ingrese un estado de vuelo valido");
		   }while(!validateFlightStatus(auxPassenger.statusFligth));

		auxPassenger.isEmpty = 0;

		list[indice] = auxPassenger;

		todoOk = 1;
		}
	}
	return todoOk;
}

int findPassengerById(Passenger* list, int len,int id)
{
	int indice = -1;
	for (int i = 0; i < len; i++)
	{
		if (list[i].id == id && list[i].isEmpty == 0)
		{
			indice = i;
			break;
		}
	}
	    return indice;
}

int removePassenger(Passenger* list, int len,eTypePassenger*listTypePassengers,int lengthTypePassengers,eStatusFlight* statusFlightList,int lenghtStatusFlight)
{
	int ok=0;
	int indice;
	int id;
	char confirmar;

	 if (list != NULL && len > 0 && listTypePassengers!=NULL&&lengthTypePassengers>0&&statusFlightList!=NULL&&lenghtStatusFlight>0)
			{
				printf("   ***Baja pasajero***    \n");
				printPassengers(list,len,listTypePassengers,lengthTypePassengers, statusFlightList, lenghtStatusFlight);
				printf("Ingrese ID: ");
				scanf("%d",&id);

				indice = findPassengerById(list, len, id);

				if(indice == -1)
				{
					 printf("El id: %d no esta registrado en el sistema\n", id);
				}
				else
				{
					printf(" ID   Nombre     Apellido     Precio      Flycode      Type passenger   Status Flight\n");
					printf("-----------------------------------------------------------------------------------------\n");
					printPassenger(list[indice],listTypePassengers, lengthTypePassengers,statusFlightList,lenghtStatusFlight);
					getCaracter(&confirmar, "Quiere darle de baja a este pasajero? S/N \n","Ingrese una opcion valida (S/N):",'S','N');

					 if (confirmar == 'S')
					{
						list[indice].isEmpty=1;
						printf("Baja exitosa.\n");
					}
					else
					{
						printf("Baja cancelada.\n");
					}
				}
				ok=1;
			}
			return ok;
}

int sortPassengers(Passenger* list, int len, int order,eTypePassenger*listTypePassengers,int lengthTypePassengers,eStatusFlight* statusFlightList,int lenghtStatusFlight)
{
	int todoOk = 0;
	    Passenger auxPassenger;
	    if (list != NULL && len > 0 && listTypePassengers!=NULL&&lengthTypePassengers>0&&statusFlightList!=NULL&&lenghtStatusFlight>0)
	    {
	            for (int i = 0; i < len -1; i++)
	            {
	                for (int j = i+1; j < len; j++)
	                {

	                	if(order==0)//decreciente apellido Y tipo de pasajero
	                	{
	                		if((strcmp(list[i].lastname,list[j].lastname)<0)||
	                		((strcmp(list[i].lastname,list[j].lastname)==0)&&(list[i].typePassenger<list[j].typePassenger)))
	                		{
								 auxPassenger = list[i];
								list[i] = list[j];
								list[j] = auxPassenger;
							}
	                	}
	                	else
	                	{
	                		if((strcmp(list[i].lastname,list[j].lastname)>0)||
							((strcmp(list[i].lastname,list[j].lastname)==0)&&(list[i].typePassenger>list[j].typePassenger)))
							{
								 auxPassenger = list[i];
								list[i] = list[j];
								list[j] = auxPassenger;
							}
	                	}
	                }
	            }
	            todoOk=1;
	    }
	    return todoOk;
}

void printPassenger(Passenger passenger,eTypePassenger*typePassengers,int lengthTypePassengers,eStatusFlight*statusFlightList,int lenghtStatusFlight)
{
	char descripcion[15];
	char descripcion2[10];
	loadTypePassengerDescription(typePassengers, lengthTypePassengers,passenger.typePassenger,descripcion);
	loadStatusFlightDescripction(statusFlightList, lenghtStatusFlight, passenger.statusFligth, descripcion2);
	printf(" %-4d %-10s %-12s %-10.2f  %-10s   %-15s     %10s \n",
	passenger.id,
	passenger.name,
	passenger.lastname,
	passenger.price,
	passenger.flycode,
	descripcion,
	descripcion2
	);
}

int printPassengers(Passenger* list, int listLenght,eTypePassenger*listTypePassengers,int lengthTypePassengers,eStatusFlight* statusFlightList,int lenghtStatusFlight)
{
	 int todoOk = 0;
	    int flag = 1;
	    if (list != NULL && listLenght > 0)
	    {
	        printf("                     ***Lista de Pasajeros ***\n");
	        printf("-----------------------------------------------------------------------------------------\n");
	        printf(" ID   Nombre     Apellido     Precio      Flycode      Type passenger   Status Flight\n");
	        printf("-----------------------------------------------------------------------------------------\n");
	        for (int i = 0; i < listLenght; i++)
	        {
	            if (!list[i].isEmpty)
	            {
	            	printPassenger(list[i], listTypePassengers, lengthTypePassengers,statusFlightList,lenghtStatusFlight);
	                flag = 0;
	            }
	        }
	        if (flag)
	        {
	            printf("No hay pasajeros para mostrar.\n");
	        }
	        todoOk = 1;
	    }
	    printf("\n");
	    return todoOk;
}

int sortPassengersByCode(Passenger* list, int len, int order,eTypePassenger*listTypePassengers,int lengthTypePassengers,eStatusFlight* statusFlightList,int lenghtStatusFlight)
{
	int todoOk = 0;
		    Passenger auxPassenger;
		    if (list != NULL && len > 0 && listTypePassengers!=NULL&&lengthTypePassengers>0&&statusFlightList!=NULL&&lenghtStatusFlight>0)
		    {
		            for (int i = 0; i < len -1; i++)
		            {
		                for (int j = i+1; j < len; j++)
		                {

		                	if(order==0)
		                	{
		                		if((strcmp(list[i].flycode,list[j].flycode)<0)||
		                		((strcmp(list[i].flycode,list[j].flycode)==0)&&(list[i].statusFligth<list[j].statusFligth)))
		                		{
									 auxPassenger = list[i];
									list[i] = list[j];
									list[j] = auxPassenger;
								}
		                	}
		                	else
		                	{
		                		if((strcmp(list[i].flycode,list[j].flycode)>0)||
								((strcmp(list[i].flycode,list[j].flycode)==0)&&(list[i].statusFligth>list[j].statusFligth)))
								{
									auxPassenger = list[i];
									list[i] = list[j];
									list[j] = auxPassenger;
								}
		                	}
		                }
		            }
		            todoOk=1;
		    }
		    return todoOk;
}

int modifyPassenger(Passenger*list, int len,eTypePassenger*typePassengers,int lengthTypePassengers,eStatusFlight*statusFlightList,int lenghtStatusFlight)
{
	int ok=0;
	int indice;
	int id;
	char respuesta;
	char confirmar;

	Passenger auxPassenger;

	if(list!=NULL && len>0)
	{
		printf("   ***Modificar Pasajero***    \n\n");
		printPassengers(list, len, typePassengers, lengthTypePassengers, statusFlightList, lenghtStatusFlight);
		printf("Ingrese ID: ");
		scanf("%d",&id);

		indice = findPassengerById(list, len, id);

		if(indice == -1)
		{
			 printf("El id: %d no esta registrado en el sistema\n", id);
		}
		else
		{
			do
			{
				switch(modifyMenu(list[indice],typePassengers,lengthTypePassengers,statusFlightList,lenghtStatusFlight))
				{
				case 1:
				getAlphabetic_Characters_String(auxPassenger.name,"Modificar nombre: ","Nombre muy largo, reingrese: ",51);
				getCaracter(&confirmar, "Confirma cambio de nombre? S/N:","Ingrese una opcion valida (S/N):",'S','N');

				 if (confirmar == 'S')
				{
					changeStringFormat(auxPassenger.name);
					strcpy(list[indice].name, auxPassenger.name);
					printf("Modificacion exitosa.\n");
				}
				else
				{
					printf("Modificacion cancelada.\n");
				}

				getCaracter(&respuesta, "Quiere hacer otra modificacion? S/N:", "Ingrese una opcion valida(S/N):",'S','N');
				break;

				case 2:
				getAlphabetic_Characters_String(auxPassenger.lastname,"Modificar apellido: ","Apellido muy largo, reingrese: ",51);
				getCaracter(&confirmar, "Confirma cambio de apellido? S/N:","Ingrese una opcion valida (S/N):",'S','N');

				 if (confirmar == 'S')
				{
					changeStringFormat(auxPassenger.lastname);
					strcpy(list[indice].lastname, auxPassenger.lastname);
					printf("Modificacion exitosa.\n");
				}
				else
				{
					printf("Modificacion cancelada.\n");
				}
				getCaracter(&respuesta, "Quiere hacer otra modificacion? S/N:", "Ingrese una opcion valida(S/N):",'S','N');
					break;
				case 3:
				 getFloat(&auxPassenger.price, "Modificar el precio del vuelo: ","Error, precio ingresado invalido\n");
				 getCaracter(&confirmar, "Confirma cambio de precio del vuelo? S/N:","Ingrese una opcion valida (S/N):",'S','N');

				 if (confirmar == 'S')
				{
					list[indice].price=auxPassenger.price;
					printf("Modificacion exitosa.\n");
				}
				else
				{
					printf("Modificacion cancelada.\n");
				}
				getCaracter(&respuesta, "Quiere hacer otra modificacion? S/N:", "Ingrese una opcion valida(S/N):",'S','N');
				break;

				case 4:
					do
				   {
					   getInt(&auxPassenger.typePassenger,"Modificar tipo de pasajero: -1(menor)/0(adulto)/1(discapacitado)","Error, ingrese un numero valido.");
				   }while(!validateTypePassenger(auxPassenger.typePassenger));

					getCaracter(&confirmar, "Confirma cambio de tipo de pasajero? S/N:","Ingrese una opcion valida (S/N):",'S','N');

					 if (confirmar == 'S')
					{
						 list[indice].typePassenger=auxPassenger.typePassenger;
						printf("Modificacion exitosa.\n");
					}
					else
					{
						printf("Modificacion cancelada.\n");
					}
					getCaracter(&respuesta, "Quiere hacer otra modificacion? S/N:", "Ingrese una opcion valida(S/N):",'S','N');
					break;
				case 5:
				 getString(auxPassenger.flycode, "Modificar codigo de vuelo: ", "Error, maximo 10 caracteres por codigo",10);
				 getCaracter(&confirmar, "Confirma cambio de codigo de vuelo? S/N:","Ingrese una opcion valida (S/N):",'S','N');

					 if (confirmar == 'S')
					{
						toupperString(auxPassenger.flycode);
						strcpy(list[indice].flycode, auxPassenger.flycode);
						printf("Modificacion exitosa.\n");
					}
					else
					{
						printf("Modificacion cancelada.\n");
					}
					getCaracter(&respuesta, "Quiere hacer otra modificacion? S/N:", "Ingrese una opcion valida(S/N):",'S','N');
				break;

				case 6:
					printf("Volver al menu principal? S/N");
					fflush(stdin);
					scanf("%c",&respuesta);

					break;
				default:
					printf("Ingrese una opcion valida.\n");
					break;
				}
			}while(respuesta=='S');
		}
		ok=1;
	}

	return ok;
}

char names[5][51]=
{
	"Juan",
	"Pedro",
	"Sofia",
	"Miguel",
	"Valentina"
};

char lastnames[5][51]=
{
	"Martinez",
	"Gimenez",
	"Fernandez",
	"Gimenez",
	"Musk"
};

float prices[5]={200000,150000,120000,180000,100000};

char flycodes[5][10]=
{
		"ZH27HR2DL",
		"933TKVQM8",
		"QE47KZXLZ",
		"RT6BNWJ79",
		"BJJ23UZ35"}
;

int typePassengers[5]={-1,0,1,1,0};

int statusFlights[5]={1,0,0,1,1};

int hardcodePassengers(Passenger*list, int len, int cant, int*pId)
{
	int contador = -1;
	if (list != NULL && len > 0 && cant >= 0 && cant <= len && pId != NULL)
	{
		contador = 0;
		for (int i = 0; i < cant;  i++)
		{
			list[i].id = *pId;
			(*pId)++;
			strcpy(list[i].name, names[i]);
			strcpy(list[i].lastname, lastnames[i]);
			list[i].price = prices[i];
			strcpy(list[i].flycode, flycodes[i]);
			list[i].typePassenger = typePassengers[i];
			list[i].statusFligth = statusFlights[i];
			list[i].isEmpty = 0;
			contador++;
		}
	}
	return contador;
}

int calculateAverageFlightPrice(Passenger*list,int len)
{
	int retorno=0;
	int contador=0;
	float precioTotal=0;
	float promedio;

	if(list!=NULL&&len>0)
	{
		for(int i=0;i<len;i++)
			{
				if(list[i].isEmpty==0)
				{
					precioTotal=precioTotal+list[i].price;
					contador++;
				}
			}
		retorno=1;
	}
	promedio=precioTotal/contador;
	printf("Cantidad de vuelos: %d, promedio precio vuelos: $%.2f\n",contador,promedio);

	return retorno;
}

int printActiveFlights(Passenger* list, int listLenght,eTypePassenger*listTypePassengers,int lengthTypePassengers,eStatusFlight* statusFlightList,int lenghtStatusFlight)
{
	int todoOk = 0;
		    int flag = 1;
		    if (list != NULL && listLenght > 0)
		    {
		        printf("                     ***Lista de Pasajeros ***\n");
		        printf("-----------------------------------------------------------------------------------------\n");
		        printf(" ID   Nombre     Apellido     Precio      Flycode      Type passenger   Status Flight\n");
		        printf("-----------------------------------------------------------------------------------------\n");
		        for (int i = 0; i < listLenght; i++)
		        {
		            if (!list[i].isEmpty && list[i].statusFligth==1)
		            {
		            	printPassenger(list[i], listTypePassengers, lengthTypePassengers,statusFlightList,lenghtStatusFlight);
		                flag = 0;
		            }
		        }
		        if (flag)
		        {
		            printf("No hay pasajeros para vuelos.\n");
		        }
		        todoOk = 1;
		    }
		    printf("\n");
		    return todoOk;
}


