/*
 * tp1funciones.c
 *
 *  Created on: 9 sep. 2020
 *      Author: tomasaiello
 */

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


