/*
 * tp1funciones.c
 *
 *  Created on: 9 sep. 2020
 *      Author: tomasaiello
 */

#include <stdio.h>
#include <stdlib.h>

char menu(){

    char operacion;

    printf("\na) Calcular la suma (A+B)");
	printf("\nb) Calcular la resta (A-B)");
	printf("\nc) Calcular la division (A/B)");
	printf("\nd) Calcular la multiplicacion (A*B)");
	printf("\ne) Calcular el factorial (A!)");
	printf("\n ingrese la operacion que desea realizar");
	fpurge(stdin);
	scanf("%c",&operacion);

	switch(operacion){
		case 'a':
		case 'b':
		case 'c':
		case 'd':
		case 'e':
			break;
		default:
			do{
			printf("\n Esta opcion no esta contemplada");
			printf("\n ingrese la operacion que desea realizar: a/b/c/d/e");
			fpurge(stdin);
			scanf("%c",&operacion);
			}while(operacion != 'a' && operacion != 'b' && operacion !='c' && operacion != 'd' && operacion != 'e' );
			break;
		}

		return operacion;

        }



int suma (int valor1, int valor2)
{
	int suma;
	suma = valor1 + valor2;
	return suma;
}
int resta (int valor1, int valor2)
{
	int resta;
	resta = valor1 - valor2;
	return resta;
}
float division (int valor1, int valor2)
{
	float division;
	division = valor1/(float)valor2;
	return division;
}
int multiplicacion(int valor1, int valor2)
{
	int multiplicacion;
	multiplicacion = valor1 * valor2;
	return multiplicacion;
}
int factorial(int valor1)
{
	int factorial =1;
	int i;

	for(i=1;i<=valor1;i++)
	{
			factorial = factorial*i;
	}
	return factorial;
}



