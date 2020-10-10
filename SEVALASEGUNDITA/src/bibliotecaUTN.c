/*
 ============================================================================
 Name        : bibliotecaUTN.c
 Author      : Tomas Aiello
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"
#include "bibliotecaUTN.h"
#include <ctype.h>

#define RETRY 5

int getInt(int* pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos)
{
	int retorno=-1;
	int bufferInt;
	if(pResultado !=NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
	{
		do{
			printf("%s", mensaje);
			fpurge(stdin);
			scanf("%d",&bufferInt);

				if(bufferInt >= minimo && bufferInt <= maximo){
					*pResultado=bufferInt;
					retorno=0;
				break;
				}
				else{
					printf("%s", mensajeError);
					reintentos--;
				}
		}while(reintentos >=0);

	}
	return retorno;
}
int getFloat(float* pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos)
{
	int retorno=-1;
	float bufferInt;
	if(pResultado !=NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
	{
		do{
			printf("%s", mensaje);
			fpurge(stdin);
			scanf("%f",&bufferInt);

				if(bufferInt >= minimo && bufferInt <= maximo){
					*pResultado=bufferInt;
					retorno=0;
				break;
				}
				else{
					printf("%s", mensajeError);
					reintentos--;
				}
		}while(reintentos >=0);

	}
	return retorno;
}

int utn_menu(int* flagAlta){

	int opcion;
	char msgError[50];
	char msg[50];
	int min, max;

    printf("\nMenu de Opciones\n");
    printf("1- ALTAS\n");
    printf("2- MODIFICAR \n");
    printf("3- BAJA \n");
    printf("4- INFORMAR \n");
    printf("5 - SALIR \n");
    strcpy(msg, "Ingrese opcion\n");
    strcpy(msgError, "opcion no contemplada\n");
    min =1;
    max =5;
    fpurge(stdin);
    getInt(&opcion, msg, msgError, min, max, RETRY);

    do{
    	   switch(opcion){ // switch no evalua punteros ?
    	   case 1:
    		   *flagAlta = 1;
    		   break;
    	   case 2:
    		   if(*flagAlta == 0){
    			   printf("Para MODIFICAR primero debe dar de ALTA \n");
    			   fpurge(stdin);
    			   getInt(&opcion, msg, msgError, min, max, RETRY);
    		   }
    		   break;
    	   case 3:
    		   if(*flagAlta == 0){
    			   printf("Para dar de BAJA primero debe dar de ALTA \n");
    			   fpurge(stdin);
    			   getInt(&opcion, msg, msgError, min, max, RETRY);
    		   }
    		   break;
    	   case 4:
    		   if(*flagAlta == 0){
    		  	   printf("Para INFORMAR primero debe dar de ALTA \n");
    		  	   fpurge(stdin);
    		  	   getInt(&opcion, msg, msgError, min, max, RETRY);
    		   }
    		   break;
    	   case 5:
    		   printf("vuelvan prontos!");
    		   *flagAlta = 1;
    		   break;
    	   }

    	}while(*flagAlta == 0);

   return opcion;
}


int employeeIsEmpty(employee* list, int len, int* posicion){

	int retorno = -1;
	int i;
	if(list != NULL && len >= 0 && posicion != NULL){
		for(i=0; i<len; i++){
			if(list[i].isEmpty == 1){ // 1 para esta vacia
				retorno =0;
				*posicion = i;
				break;
			}
		}
	}
	return retorno;
}

int initEmployees(employee* list, int len){

	int i;

	if(list != NULL && len > 0){
		for(i = 0; i<len; i++){
			strcpy(list[i].name, "");
			strcpy(list[i].lastName, "");
			list[i].id = 0;
			list[i].salary = 0;
			list[i].sector = 0;
			list[i].isEmpty = 1; // SI isEmpty = 0 ESTA SIENDO USADA
		}
	}
	else{
		printf("Array NULL");
	}
 return 0;
}


int addEmployee(employee* list, int len, int id, char name[],char lastName[],float salary, int sector)
{
	char msgError[50];
	char msg[50];
	int min, max;

	if(list != NULL && len > 0){

			printf("\nIngrese nombre del ID %d", id);
			fpurge(stdin);
			fgets(name, 51, stdin);

			printf("\nIngrese apellido del ID %d ", id);
			fpurge(stdin);
			fgets(lastName, 51, stdin);

			printf("\nIngrese salario del ID %d ", id);
			strcpy(msg, "");
			strcpy(msgError, "Salario invalido \n");
			min = 0;
			max = 200000;
			getFloat(&salary, msg, msgError, min, max, RETRY);

			printf("\nIngrese sector del ID %d ", id);
			strcpy(msgError, "Sector invalido \n");
			min = 1;
			max = 50; // 50 sectores
			getInt(&sector, msg, msgError, min, max, RETRY);

	}

	return 0;

}

int findEmployeeById(employee* list, int len, int id, int* posicion){

	char resp = 's';
	int opcion;
	char msg[50];
	char msgError[50];
	int min, max;

	if(list != NULL && len > 0 && id >= 1 && posicion != NULL){

		if(list[*posicion].isEmpty == 0){

			printf("\n ID %d", list[*posicion].id);
			printf("\n Nombre: %s", list[*posicion].name);
			printf("\n Apellido: %s", list[*posicion].lastName);
			printf("\n Salario: %f", list[*posicion].salary);
			printf("\n Sector: %d", list[*posicion].sector);
			printf("\n");


			 do{

				printf("\n Que parametro desea modificar?");
				printf("\n 1 - Nombre");
				printf("\n 2 - Apellido");
				printf("\n 3 - Salario");
				printf("\n 4 - Sector");
				strcpy(msg, "Ingrese opcion\n");
				strcpy(msgError, "opcion no contemplada\n");
				min =1;
			    max =4;
			    fpurge(stdin);
			    getInt(&opcion, msg, msgError, min, max, RETRY);

		    	switch(opcion){

	    			case 1:
	    				printf("\nIngrese nombre del ID %d", id);
	    				fpurge(stdin);
	    				fgets(list[*posicion].name, 51, stdin);
	    			break;

				    case 2:
				    	printf("\nIngrese apellido del ID %d ", id);
					   	fpurge(stdin);
				    	fgets(list[*posicion].lastName, 51, stdin);
				    break;

				    case 3:
				    	printf("\nIngrese salario del ID %d ", id);
						strcpy(msg, "");
						strcpy(msgError, "Salario invalido \n");
						min = 0;
						max = 200000;
						getFloat(&list[*posicion].salary, msg, msgError, min, max, RETRY);
					break;

					case 4:
				    	strcpy(msgError, "Sector invalido \n");
						min = 1;
				   		max = 50; // 50 sectores
				   		getInt(&list[*posicion].sector, msg, msgError, min, max, RETRY);
					break;
		    	}

				printf("\n Desea modificar otro parametro? s/n" );
				fpurge(stdin);
				scanf("%c", &resp);

			}while(resp == 's');
		}
		else{
			printf("\n El ID %d ha sido dado de BAJA", id);
		}
	}

	return 0;
}

int removeEmployee(employee* list, int len, int id, int* posicion){

	char resp;
	int retorno = -1;

	if(list != NULL && len > 0 && posicion != NULL){

		printf("\n ID: %d", id);
		printf("\n Nombre: %s", list[*posicion].name);
		printf("\n Apellido: %s", list[*posicion].lastName);
		printf("\n Salario: %f", list[*posicion].salary);
		printf("\n Sector: %d", list[*posicion].sector);

		printf("\n Seguro desea dar de BAJA este empleado? s/n");
		fpurge(stdin);
		scanf("%c", &resp);

		if (resp == 's'){

			strcpy(list[*posicion].name, "");
			strcpy(list[*posicion].lastName, "");
			list[*posicion].salary = 0;
			list[*posicion].sector = 0;
			list[*posicion].isEmpty = 1;

			printf("\n El empleado de ID %d a sido eliminado exitosamente", id);

			retorno = 0;
		}
		else{
			retorno = 0;
		}
	}

	return retorno;
}
int sortEmployees(employee* list, int len, int order){

	// order == 0 ascendente  , order == 1 descendente por apellido

	int aux, i, j;
	float auxSal = 0;
	char auxName[51];

	if(list != NULL && len > 0 && (order == 1 || order == 0 )){

		for(i = 0; i<len-1; i++){

			for(j = i+1; j<len; j++){


				if(strcmp(list[i].lastName, list[j].lastName) > 0 && order == 0 && list[i].isEmpty == 0 && list[j].isEmpty == 0){ // de menor a mayor

					strcpy(auxName, list[i].name);
					strcpy(list[i].name, list[j].name);
					strcpy(list[j].name, auxName);

					strcpy(auxName, list[i].lastName);
					strcpy(list[i].lastName, list[j].lastName);
					strcpy(list[j].lastName, auxName);

					auxSal = list[i].salary;
					list[i].salary = list[j].salary;
					list[j].salary = auxSal;

					aux = list[i].sector;
					list[i].sector = list[j].sector;
					list[j].sector = aux;


				}
				else if(strcmp(list[i].lastName, list[j].lastName) < 0 && order == 1 && list[i].isEmpty == 0 && list[j].isEmpty == 0){ // de mayor a menor

					strcpy(auxName, list[j].name);
					strcpy(list[j].name, list[i].name);
					strcpy(list[i].name, auxName);

					strcpy(auxName, list[j].lastName);
					strcpy(list[j].lastName, list[i].lastName);
					strcpy(list[i].lastName, auxName);

					auxSal = list[j].salary;
					list[j].salary = list[i].salary;
					list[i].salary = auxSal;

					aux = list[j].sector;
					list[j].sector = list[i].sector;
					list[i].sector = aux;

				}
				else if(strcmp(list[i].lastName, list[j].lastName) ==  0 && list[i].sector > list[j].sector && list[i].isEmpty == 0 && list[j].isEmpty == 0  ){ // por sector (como segundo criterio)

					strcpy(auxName, list[i].name);
					strcpy(list[i].name, list[j].name);
					strcpy(list[j].name, auxName);

					strcpy(auxName, list[i].lastName);
					strcpy(list[i].lastName, list[j].lastName);
					strcpy(list[j].lastName, auxName);

					auxSal = list[i].salary;
					list[i].salary = list[j].salary;
					list[j].salary = auxSal;

					aux = list[i].sector;
					list[i].sector = list[j].sector;
					list[j].sector = aux;

				}
			}
		}
	}


	return 0;
}
int printEmployees(employee* list, int length)
{
	//printf("TXT1: %9s TXT2 %9s TXT3 %9s\n", txt1, txt2, txt3)

	int i;

	if(list != NULL && length > 0){

		printf("\n  ID    NOMBRE   APELLIDO   SALARIO   SECTOR");

		for (i = 0; i < length; i++){

			if(list[i].isEmpty == 0){

				printf("\n %4d%8s%8s%6.2f%5d", list[i].id, list[i].name,list[i].lastName,list[i].salary,list[i].sector);
			}
		}
	}

 return 0;
}
