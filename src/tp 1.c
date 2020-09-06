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
#include <ctype.h>

int suma (int valor1, int valor2);
int resta (int valor1, int valor2);
float division (int valor1, int valor2);
int multiplicacion(int valor1, int valor2);
int factorial(int valor1);

int main(void) {
	setbuf(stdout, NULL);
	int num1;
	int num2;
	int sumar;
	int restar;
	float dividir;
	int multiplicar;
	int fact;
	char operacion;
	char resp = 's';

	printf("ingrese 1er operando (A)");
	fpurge(stdin);
	scanf("%d", &num1);
	printf("\ningrese 2do operando (B)");
	fpurge(stdin);
	scanf("%d",&num2);
	printf("\na) Calcular la suma (A+B)");
		printf("\nb) Calcular la resta (A-B)");
		printf("\nc) Calcular la division (A/B)");
		printf("\nd) Calcular la multiplicacion (A*B)");
		printf("\ne) Calcular el factorial (A!)");
		printf("\n ingrese la operacion que desea realizar");
		fpurge(stdin);
		scanf("%c",&operacion);

	//do{

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

	}

	//printf("\nquiere realizar otra operacion con los mismo numeros? s/n");
	//resp = getchar();

	//}while(resp == 's');
	return 0;
}

int suma (int valor1, int valor2){
	int suma;
	suma = valor1 + valor2;
	return suma;
}
int resta (int valor1, int valor2){
	int resta;
	resta = valor1 - valor2;
	return resta;
}
float division (int valor1, int valor2){
	float division;
	division = valor1/(float)valor2;
	return division;
}
int multiplicacion(int valor1, int valor2){
	int multiplicacion;
	multiplicacion = valor1 * valor2;
	return multiplicacion;
}
int factorial(int valor1){
	int factorial =1;
	int i;

	for(i=1;i<=valor1;i++){
			factorial *= i;
	}
	return factorial;
}
