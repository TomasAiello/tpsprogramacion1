/*
 ============================================================================
 Name        : tp.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tp1funciones.h"

char menu();
int suma (int valor1, int valor2);
int resta (int valor1, int valor2);
float division (int valor1, int valor2);
int multiplicacion(int valor1, int valor2);
int factorial(int valor1);


int main(void)
{
	setbuf(stdout, NULL);

	int num1;
	int num2;
	int sumar;
	int restar;
	float dividir;
	int multiplicar;
	int fact;
	char resp = 's';
	char operacion;

	do{

	operacion = menu();

	if(operacion == 'e'){
	printf("\n ingrese operando (A)");
	fpurge(stdin);
	scanf("%d", &num1);
	}
	else{
	printf("\n ingrese 1er operando (A)");
	fpurge(stdin);
	scanf("%d", &num1);
	printf("\n ingrese 2do operando (B)");
	fpurge(stdin);
	scanf("%d", &num2);
	}

	switch(operacion){

		case 'a':
		sumar = suma (num1,num2);
		printf("\nla suma es: %d",sumar);
		break;

		case 'b':
		restar = resta (num1,num2);
		printf("\nla resta es: %d",restar);
		break;

		case 'c':
		if(num2!=0){
			dividir = division (num1,num2);
			printf("\nla division es: %f",dividir);
		}
		else{
			printf("\nno se puede dividir por cero");
		}
		break;

		case 'd':
		multiplicar = multiplicacion(num1,num2);
		printf("\nla multiplicacion es: %d", multiplicar);
		break;

		case 'e':
			if (num1 <0){
				printf("\n no existe el factorial de un numero negativo");
			}
			else{
			fact = factorial(num1);
			printf("\n el factorial del 1er operando es: %d", fact);
				}
			break;

		default:
			printf("\nesa opcion no esta contemplada");
			break;
		}

		printf("\nquiere realizar otra operacion? s/n");
		fpurge(stdin);
		scanf("%c", &resp);

	}while(resp == 's');

return 0;
}
