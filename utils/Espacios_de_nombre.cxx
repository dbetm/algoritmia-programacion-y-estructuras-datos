#include <iostream>
#include <cstring>
namespace alumno {
	char nombre[] = "David";
}
namespace maestro {
	char nombre[20];
}

using namespace maestro;
using namespace std;

int main(int argc, char **argv) {
	strcpy(nombre, "Xavi");
	cout << alumno::nombre << endl;
	cout << nombre << endl;
	
	return 0;
}

