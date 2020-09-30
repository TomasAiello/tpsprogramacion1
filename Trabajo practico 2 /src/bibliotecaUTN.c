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

#define TAM 20 // largo de matriz


int utn_menu(int* flagAlta){

	int opcion;


    printf("\nMenu de Opciones\n");
    printf("1- ALTAS\n");
    printf("2- MODIFICAR \n");
    printf("3- BAJA \n");
    printf("4- INFORMAR \n");
    printf("5 - SALIR \n");
    printf("Ingrese Opcion: \n");
    fpurge(stdin);
    scanf("%d", &opcion);

    /*
    while(isdigit(opcion) == 0){// This function returns non-zero value if "opcion" is a digit, else it returns 0
    	printf("\nElija un NUMERO del menu");
    	printf("\nIngrese Opcion: \n");
    	fpurge(stdin);
    	scanf("%d", &opcion);
    }
	*/

    do{

    	   switch(opcion){ // switch no evalua punteros ?
    	   case 1:
    		   *flagAlta = 1;
    		   break;
    	   case 2:
    		   if(*flagAlta == 0){
    			   printf("Para MODIFICAR primero debe dar de ALTA \n");
    			   printf("Ingrese Opcion: \n");
    			   fpurge(stdin);
    			   scanf("%d", &opcion);
    		   }
    		   break;
    	   case 3:
    		   if(*flagAlta == 0){
    			   printf("Para dar de BAJA primero debe dar de ALTA \n");
    			   printf("Ingrese Opcion: \n");
    			   fpurge(stdin);
    			   scanf("%d", &opcion);
    		   }
    		   break;
    	   case 4:
    		   if(*flagAlta == 0){
    		  	   printf("Para INFORMAR primero debe dar de ALTA \n");
    		  	   printf("Ingrese Opcion: \n");
    		  	   fpurge(stdin);
    		  	   scanf("%d", &opcion);
    		   }
    		   break;
    	   case 5:
    		   printf("vuelvan prontos!");
    		   *flagAlta = 1;
    		   break;
    	   default:
    		   	   printf("\nOpcion no contemplada");
    		   	   printf("\nIngrese Opcion: ");
    		   	   fpurge(stdin);
    		   	   scanf("%d", &opcion);
    		   break;

    	   }
    	}while(*flagAlta == 0); // isdigit(opcion) &&


   return opcion;
}

int initEmployees(employee* list, int len){

	int i;

		for(i = 0; i<len; i++){
			list[i].id = 0;
			list[i].salary = 0;
			list[i].sector = 0;
			list[i].isEmpty = 0; // SI isEmpty = 1 ESTA SIENDO USADA
			//list[i].name = 0;
			//list[i].lastName =0;
		}

 return 0;
}
/*
int getNumero(float* pResultado, char* mensaje[], char* mensajeError[], int minimo, int maximo, int reintentos)
{
	int retorno=-1;
	int bufferInt;
	if(pResultado !=NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
	{
		do{
			printf("%s",mensaje);
						scanf("%d",&bufferInt);
						if(bufferInt >=minimo&& bufferInt<= maximo)
						{
							*pResultado=bufferInt;
							retorno=0;
							break;
						}
						else
						{
							printf("%s",mensajeError);
							reintentos--;
						}
					}while(reintentos >=0);

				}
				return retorno;
}
*/
int addEmployee(employee* list, int len, int id, char name[],char lastName[],float salary, int sector) //  carga secuencial
{
	int cargaok = -1;

	/*
	char msgError[20];
	char msg[20];
	int salMin =0;
	int salMax = 200000;
	int reint  = 3;

*/

				printf("\nIngrese nombre del ID %d", id+1);
				fpurge(stdin);
				gets(list[id].name);

				/*
				 *
				if (isalpha(list[id].name) == 0){ // incompatible pointer to integer conversion passing 'char *' to parameter of type 'int' ?
					printf("\n Nombre invalido");
					printf("\nIngrese nombre del ID %d", id+1);
					fpurge(stdin);
					gets(list[id].name);
				}

				  comparison of array 'list[i].name' equal to a null pointer is always false ?

				while (list[i].name == NULL){
					printf("nombre invalido");
					printf("\nIngrese nombre del ID %d", i+1);
					fpurge(stdin);
					gets(list[i].name);
				}
				*/

				printf("\nIngrese apellido del ID %d ", id+1);
				fpurge(stdin);
				gets(list[id].lastName);

				/*  comparison of array 'list[i].name' equal to a null pointer is always false ?

				while (list[i].lastName == NULL){
					printf("apellido invalido");
					printf("\nIngrese apellido del ID %d", i+1);
					fpurge(stdin);
					gets(list[i].name);
				}
				 */

				printf("\nIngrese salario del ID %d ", id+1);
				scanf("%f", &list[id].salary);
				while (!isdigit(list[id].salary) && (list[id].salary < 0 || list[id].salary > 200000) ){
					printf("salario invalido");
					printf("\nIngrese salario del ID %d ", id+1);
					scanf("%f", &list[id].salary);
				}

				printf("\nIngrese sector del ID %d ", id+1);
				scanf("%d", &list[id].sector);
				while(!isdigit(list[id].sector) && (list[id].sector <= 0 || list[id].sector > 100) ){ // 100 sectores ?
					printf("sector invalido");
					printf("\nIngrese sector del ID %d ",id+1);
					scanf("%d", &list[id].sector);

				}

				cargaok =0 ;



		/*
		strcpy(msg, "ingrese salario");
		strcpy(msgError, "salario no valido");
		getNumero(&list[i].salary, msg, msgError, salMin, salMax, reint);
		*/


	return cargaok;

}

int findEmployeeById(employee* list, int len,int id){

	char resp = 's';
	int opcion;

	printf("\n Nombre: %s", list[id].name);
	printf("\n Apellido: %s", list[id].lastName);
	printf("\n Salario: %f", list[id].salary);
	printf("\n Sector: %d", list[id].sector);

	printf("\n Quiere modificar algun parametro? s/n");
	fpurge(stdin);
	scanf("%c", &resp);

	while(resp == 's'){

		printf("\n Que parametro desea modificar?");
		printf("\n 1 - Nombre");
		printf("\n 2 - Apellido");
		printf("\n 3 - Salario");
		printf("\n 4 - Sector");
		scanf("%d", &opcion);

		switch(opcion){
		case 1:
			printf("\nIngrese nombre del ID %d", id+1);
			fpurge(stdin);
			gets(list[id].name);
		break;
		case 2:
			printf("\nIngrese apellido del ID %d ", id+1);
			fpurge(stdin);
			gets(list[id].lastName);
		break;
		case 3:
			printf("\nIngrese salario del ID %d ", id+1);
			scanf("%f", &list[id].salary);
		break;
		case 4:
			printf("\nIngrese sector del ID %d ", id+1);
			scanf("%d", &list[id].sector);
		break;
		default:
			printf("\n Opcion no contemplada");
		break;

		}

		printf("\n Desea modificar otro parametro? s/n" );
		fpurge(stdin);
		scanf("%c", &resp);

	}

	return 0;
}
int removeEmployee(employee* list, int len, int id){

	char resp = 's';

	printf("\n Nombre: %s", list[id].name);
	printf("\n Apellido: %s", list[id].lastName);
	printf("\n Salario: %f", list[id].salary);
	printf("\n Sector: %d", list[id].sector);
	printf("\n Seguro desea dar de BAJA este empleado? s/n");
	fpurge(stdin);
	scanf("%c", &resp);

	if (resp == 's'){
		// como pongo en "cero" los string?
		list[id].salary = 0;
		list[id].sector = 0;
		list[id].isEmpty = 0;
		printf("\n El empleado de ID %d a sido eliminado exitosamente", id+1);
	}

	return 0;
}
int sortEmployees(employee* list, int len, int order){

	// order == 0 ascendente  , order == 1 descendente por apellido
	// order == 2 ascendente , order == 3 descendente por sector

	int aux, i, j;
	float auxSal = 0;
	char auxName[51];

		for(i = 0; i<len-1; i++){

		for(j = i+1; j<len; j++){


			if(strcmp(list[i].lastName, list[j].lastName) > 0 && order == 0 && list[i].isEmpty == 1 && list[j].isEmpty == 1){ // de menor a mayor

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
			else if(strcmp(list[i].lastName, list[j].lastName) < 0 && order == 1 && list[i].isEmpty == 1 && list[j].isEmpty == 1){ // de mayor a menor

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
			else if(list[i].sector > list[j].sector && order == 2 && list[i].isEmpty == 1 && list[j].isEmpty == 1  ){ // ascendente

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
			else if(list[i].sector < list[j].sector && order == 2 && list[i].isEmpty == 1 && list[j].isEmpty == 1  ){ // descendente

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
		}
	}
	return 0;
}
int printEmployees(employee* list, int length)
{
	//printf("TXT1: %9s TXT2 %9s TXT3 %9s\n", txt1, txt2, txt3)

	int i;

	printf("\n  ID    NOMBRE   APELLIDO   SALARIO   SECTOR");

	for (i = 0; i < length; i++){

		if(list[i].isEmpty == 1){

			printf("\n %4d%8s%8s%6.2f%5d", i+1, list[i].name,list[i].lastName,list[i].salary,list[i].sector);
		}
	}


 return 0;
}


/*
int utn_mostrar(int edades[], float sueldos[], int tam){

	int i;

	for(i = 0; i<tam; i++){
	printf("la persona de edad : %d, tiene un sueldo de: %.2f \n", edades[i], sueldos[i]);
	}

	return 0;
}

void getString(char mensaje[], char input[]){
	printf("%s", mensaje);
	fgets(input, 20, stdin);
}

int printArrayStr(char pArray[][TAM], int limite){

	int retorno = -1;
	int i;

	if (pArray != NULL && limite > 0){

		for (i =0; i <limite; i++){

			printf("%s", pArray[i]);
			printf("\n");
		}
		retorno = 0;
	}
	return retorno;
}


 int ordenar2ArrayStr(char pArrayNom[][TAM], char pArrayApe[][TAM], int limite){

	int flagDesordenado = -1;
	int i;
	char auxNom[TAM];
	char auxApe[TAM];

	while(flagDesordenado == -1)
	{
		flagDesordenado = 0;

		for (i =0; i <limite; i++)
		{
			if(strcmp(pArrayApe[i], pArrayApe[i+1])>0)
			{
				strcpy(auxNom, pArrayNom[i]);
				strcpy(pArrayNom [i], pArrayNom[i+1]);
				strcpy(pArrayNom[i+1],pArrayNom);

				strcpy(auxApe, pArrayApe[i]);
				strcpy(pArrayApe [i], pArrayApe[i+1]);
				strcpy(pArrayApe[i+1],pArrayApe);

				flagDesordenado = -1;
			}
		}
	}

	return flagDesordenado;
}

int swapInt(int vec[]){
	int i, j, aux;
	aux = vec[i];
	vec[i]= vec[j];
	vec[j] = aux;
	return 0;
}


int utn_initArray(int array1[], int tam){ // un solo array

	int i;

	for(i = 0; i<tam; i++){
		array1[i] = 0;
	}

	return 0;
}

int utn_continuar(char* resp){

	char respuesta;
	printf("desea continuar? s/n");
	fpurge(stdin);
	scanf("%c", &respuesta);
	*resp = respuesta;

	return 0;

}
int utn_cargaSec(int array1[], float array2[], int tam){

	int i;

	for (i = 0; i<tam; i++){

	printf("ingrese dato en la posicion del array1 n %d : \n", i);
	fpurge(stdin);
	scanf("%d", &array1[i]);

	printf("ingrese dato en la posicion del array2 n  %d : \n", i);
	fpurge(stdin);
	scanf("%f", &array2[i]);

	}
	return 0;
}

int getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{

	int retorno = -1;
	char buffer;
	if (pResultado !=NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
	{
		do{
			printf("%s",mensaje);
			scanf("%c",&buffer);
			if(buffer >=minimo&& buffer<= maximo)
			{
				*pResultado=buffer;
				retorno=0;
				break;

			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos >=0);

	}
	return retorno;
}



int burbuja(int vec[], int tam, int criterio){ // criterio es como quiero ordenar los datos del array

int aux, i, j;

	for(i = 0; i<tam-1; i++){
	for(j = i+1; j<tam; j++){

		if(vec[i]>vec[j] && criterio == 1){ // de menor a mayor
			aux =vec[i]; // swap
			vec[i]= vec[j];
			vec[j] = aux;
		}
		else if(vec[i]<vec[j] && criterio == 0){ // de mayor a menor
			aux = vec[i]; // swap
			vec[j] = vec[i];
			vec[i] = aux;
		}
	}
}
return 0;
}
*/
