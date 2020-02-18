#define sumar(a,b) a + b

#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	int suma;
	cout << "Estoy usando una macro para sumar dos números" << endl;
	suma = sumar(5,6);
	cout << "El resultado es: " << suma << endl;
	cout << "pulse una tecla para continuar";
	cin.get();
	
	return 0;
}

