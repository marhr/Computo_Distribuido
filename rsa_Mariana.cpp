// Mariana Hernández
// Para ejecutar este programa:
// g++ -std=c++11 rsa_Mariana.cpp -o rsa

// RSA
// Exponenciacion modular
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

// int m = 12;
// int e = 5;
int n = 35;
int c = 17;
int d = 29;

vector<bool> dec2Bin(int d){ 
	vector<bool> v;
    // tamanio de int 32 bits 
    for (int i = 31; i >= 0; i--) { 
        int k = d >> i; 
        if (k & 1){ 
            v.push_back(1);
            // cout << "1";
        } 
        else{
        	v.push_back(0);
            // cout << "0"; 
        }
    }
    return v;
} 

int main(int argc, char const *argv[]){

	int mult_temp;
	int res = 1;

	// usando exponenciacion modular
	// obtener exponente en binario
	vector<bool> v = dec2Bin(d);
	reverse(v.begin(), v.end());
    // for(auto e : v) std::cout << e;
    // std::cout << '\n';
	
	// multiplicaciones intermedias
	for (int i = 0; i < v.size(); i++){
		if (v[i]){
			mult_temp = fmod(pow((float)c,pow((float)2,(float)i)),(float)n);
			res = res*mult_temp;
		}
	}
	printf(" mult: %d\n", res);

	printf("d = %d\n", res%n );
	// printf("Encrypt c = %d\n", (int)pow((float)m,(float)e) % n);
	printf("Decrypt m = %f\n", fmod(res,n));
	return 0;
}