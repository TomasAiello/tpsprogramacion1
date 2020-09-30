/*
 * bibliotecaUTN.h
 *
 *  Created on: 23 sep. 2020
 *      Author: tomasaiello
 */

#ifndef BIBLIOTECAUTN_H_
#define BIBLIOTECAUTN_H_
#define TAM 20 //largo de la matriz
typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}employee;

#endif /* BIBLIOTECAUTN_H_ */


int utn_inicialArray(int array1[], float array2[], int tam);
int utn_continuar(char* resp);
int utn_cargaSec(int array1[], float array2[], int tam);
int burbuja(int vec[], int tam, int criterio);

int utn_mostrar(int edades[], float sueldos[], int tam);
void getString(char mensaje[], char input[]);
int printArrayStr(char pArray[][TAM], int limite);
int ordenar2ArrayStr(char pArrayNom[][TAM], char pArrayApe[][TAM], int limite);

int getNumero(float* pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);


int utn_menu(int* flagAlta);
int initEmployees(employee* list, int len);
int addEmployee(employee* list, int len, int id, char name[],char lastName[],float salary, int sector);
int findEmployeeById(employee* list, int len,int id);
int removeEmployee(employee* list, int len, int id);
int sortEmployees(employee* list, int len, int order);
int printEmployees(employee* list, int length);
