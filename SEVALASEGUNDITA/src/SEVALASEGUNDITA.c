/*
 ============================================================================
 Name        : SEVALASEGUNDITA.c
 Author      : Tomas Aiello
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
// como escribir la condicion del else

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"
#include "bibliotecaUTN.h"
#include <ctype.h>

#define CANT 1000
#define RETRY 5

int main(void) {

	setbuf(stdout, NULL);

	int opcion;
	int posicion =0;
	int flagAlta =0;
	char resp;
	char msg[50];
	char msgError[50];
	int acumId = 0;
	int auxId, i;
	int max, min;
	int order;

	employee list[CANT];

	initEmployees(list, CANT);

	opcion = utn_menu(&flagAlta);

	switch(opcion){

		case 1:

			do{
				employeeIsEmpty(list, CANT, &posicion);

				if(list[posicion].isEmpty == 1){

					acumId++;
					list[posicion].id = acumId;

					addEmployee(list, CANT, list[posicion].id, list[posicion].name, list[posicion].lastName, list[posicion].salary, list[posicion].sector);

					list[posicion].isEmpty = 0;

				}
				else{
					printf("\n No hay posiciones libres");
				}

				printf("\nQuiere ingresar otro empleado? s/n");
				fpurge(stdin);
				scanf("%c", &resp);

			}while(resp == 's');

			opcion = utn_menu(&flagAlta);

		break;

		case 2:

			strcpy(msg,"\nIngrese el numero de ID" );
			strcpy(msgError, "\nID inexistente"); // esto solo sirve si el empleado fue dado de alta pero no de baja, creo
			min = 1;
			max = acumId;
			getInt(&auxId, msg, msgError, min, max, RETRY);

				for(i = 1; i < acumId ; i++){
					if(list[i].id == auxId){
						posicion = i;
						findEmployeeById(list, CANT, list[posicion].id, &posicion);
						break;
					}
				}

		break;

		case 3:

			strcpy(msg,"\nIngrese el numero de ID" );
			strcpy(msgError, "\nID inexistente");
			min = 1;
			max = acumId;
			getInt(&auxId, msg, msgError, min, max, RETRY);

			for(i = 1; i < acumId ; i++){
				if(list[i].id == auxId){
					posicion = i;
					removeEmployee(list, CANT, list[posicion].id, &posicion);
				break;
				}
			}
		break;

		case 4:

			strcpy(msg,"\nDesea INFORMAR por orden alfabetico - ascendente o descendente (0-1, respectivamente) ? " );
			strcpy(msgError, "\nOpcion no contemplada");
			min = 0;
			max = 1;
			getInt(&order, msg, msgError, min, max, RETRY );

			sortEmployees(list, CANT, order);
			printEmployees(list, CANT);

		break;

		}

	return 0;
}
