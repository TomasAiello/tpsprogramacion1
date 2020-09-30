/*
 ============================================================================
 Name        : asdadasd.c
 Author      : Tomas Aiello
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//PREGUNTAS
// DONDE SE DEFINE EL STRUCT? SI LO DEFINO en .h funciona
// COMO VALIDAR UN STRING ?
// COMO VACIAR/INICIALIZAR UN STRING?
// COMO ORDENAR POR APELLIDO YYYY POR SECTOR ?
//PROBLEMAS PARA USAR ISDIGIT, ISALPHA


#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaUTN.h"
#include "string.h"
#include <ctype.h>

#define CANT 1000


int main(void) {

	setbuf(stdout, NULL);

	int flagAlta = 0;
	int opcion, order;
	int i =0;
	char resp = 's';

	employee list[CANT];

	initEmployees(list, CANT);

	opcion = utn_menu(&flagAlta);

	do{

		switch(opcion){ // switch(utn_menu());
			case 1:
				do {

					addEmployee(list, CANT, i, list[i].name, list[i].lastName, list[i].salary, list[i].sector);

					list[i].isEmpty = 1;

					printf("\nQuiere ingresar otro empleado? s/n");
					fpurge(stdin);
					scanf("%c", &resp);

					i++;

					//flagAlta = 1;

				}while (resp == 's');

				opcion = utn_menu(&flagAlta);

			break;

			case 2:

					printf("\ningrese el numero de ID");
					scanf("%d", &i);

					if(list[i-1].isEmpty == 0){
						printf("Este ID esta vacio");
					}
					else{
						findEmployeeById(list, CANT, i-1);
					}
					opcion = utn_menu(&flagAlta);
			break;
			case 3:
				printf("\ningrese el numero de ID que desea dar de BAJA");
				scanf("%d", &i);

				if(list[i-1].isEmpty == 0){
					printf("Este ID esta vacio");
				}
				else{
					removeEmployee(list, CANT, i-1);
				}

				opcion = utn_menu(&flagAlta);

			break;
			case 4:
				printf("\n Desea MOSTRAR por orden alfabetico - ascendente o descendente (0-1, respectivamente) - \n, o bien por sector - ascendente o descendente (2-3, respectivamente) ? ");
				scanf("%d", &order);
				sortEmployees(list, CANT, order);
				printEmployees(list, CANT);

				opcion = utn_menu(&flagAlta);
			break;

		}
	}while(opcion == 1 || opcion == 2 || opcion == 3 || opcion == 4);


	return 0;
}

