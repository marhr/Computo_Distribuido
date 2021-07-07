
// Mariana Hernández
// Para ejecutar este programa:
// g++ -std=c++11 diffie_hellman_Mariana.cpp -o diffie_hellman

// Diffie-Hellman Key Exchange
// Fuerza bruta
#include <iostream>
#include <math.h>
using namespace std;

int n = 47; // num primo
int g = 3; // base
int A_B = 28;
int B_A = 17;
int x = 0;
int y = 0;
int limite = 20;

int main(int argc, char const *argv[]){

	// Encontrar x
	float temp = 0;
	int i = 0;
	do{

		temp = pow((float)g,(float)i);
		// printf("Prueba modulo: %f\n",temp );
		if ((fmod((float)temp, (float) n)) == A_B){
			x = i;
			printf("x: %d\n",x);
		}

		i++;
	} while( i<=limite && ((fmod((float)temp, (float) n)) != A_B) );

	// Encontrar y
	temp = 0;
	i = 0;
	do{

		temp = pow((float)g,(float)i);
		// printf("Prueba modulo: %f\n",temp );
		if ((fmod((float)temp, (float) n)) == B_A){
			y = i;
			printf("y: %d\n",y);
		}

		i++;
	} while( i<=limite && ((fmod((float)temp, (float) n)) != B_A) );

	// Validacion
	printf("g^{xy} mod n = %d\n", (int)fmod((pow((float)g,(float)(x*y))),(float)n));
	return 0;
}