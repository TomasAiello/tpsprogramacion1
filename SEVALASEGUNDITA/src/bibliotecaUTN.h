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


int getInt(int* pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);
int getFloat(float* pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);
int employeeIsEmpty(employee* list, int len, int* posicion);
int utn_menu(int* flagAlta);
int initEmployees(employee* list, int len);
int addEmployee(employee* list, int len, int id, char name[],char lastName[],float salary, int sector);// contador de Alta
int findEmployeeById(employee* list, int len,int id, int* posicion);
int removeEmployee(employee* list, int len, int id, int* posicion);
int sortEmployees(employee* list, int len, int order);


int printEmployees(employee* list, int length);
