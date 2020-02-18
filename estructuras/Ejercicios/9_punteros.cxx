#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv) {
	
	int n1;
	int n2;
	int *dirN1;
	char X;
	char *dirX;
	
	cout << "Dame un número: ";
	cin >> n1;
	dirN1 = &n1;
	cout << "Tú número es: "<< n1 << endl;
	cout << "Tú número se guardó en la dirección: "<< dirN1 << endl;
	
	cout << "Dame un número: ";
	cin >> n2;
	dirN1 = &n2;
	cout << "Tú número es: "<< n2 << endl;
	cout << "Tú número se guardó en la dirección: "<< dirN1 << endl;
	
	cout << "Dame un carácter: ";
	cin >> X;
	dirX = &X;
	cout << "Se guardó en la dirección: "<< dirX << endl;
	
	return 0;
}

