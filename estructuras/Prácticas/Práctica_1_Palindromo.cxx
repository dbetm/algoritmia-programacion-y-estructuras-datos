#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

/* Nombre: David Betancourt Montellano
 * NL: 3
 * Fecha: 22/03/2017
 * UA: Estructuras de datos
 * Programa académico: ISC
 * Evidencia: Práctica_1 Palindromo
 * Maestra: M. en Ed. Karina Rodríguez Mejía
 * Grupo: 2CM1.
*/

void menu();
int validarEnteros();

using namespace std;

struct DPila {
    char letra;
    DPila *sig;
};

class CPila {
    private:
        DPila *Pila;
    public:
        CPila();
        void Agregar(char);
        //void Elecima();
        //void Mostrar();
        char Sacar();
        bool Vacia();
        ~CPila();
    
};

CPila::CPila() {
    Pila = NULL;
}
bool CPila::Vacia() {
    if(Pila == NULL) return true;
    else return false;
}

void CPila::Agregar(char crt) {
    DPila *Temp;
    Temp = new DPila;
    if(Temp == NULL) {
        cout << "No se ha podido guardar el carácter" << endl;
    }
    else {
        Temp -> letra = crt;
        Temp -> sig = Pila;
        Pila = Temp;
    }
}
/*
void CPila::Elecima() {
    if(Vacia() == true) cout << "La pila está vacía" << endl;
    else {
        cout << "El elemento es: " << Pila -> letra << endl;
    }
}

void CPila::Mostrar() {
    DPila *Temp;
    Temp = Pila;
    if(Vacia() == true) cout << "La pila está vacía" << endl;
    else {
        while(Temp != NULL) {
            cout << Temp -> letra << endl;
            Temp = Temp -> sig;
        }
    }
} 
*/
char CPila::Sacar() {
    DPila *Temp;
    char letra;
    
	Temp = Pila;
	letra = Pila -> letra;
	Pila = Pila -> sig;
	delete Temp;
	return letra;
}

CPila::~CPila() {
    DPila *Temp;
    if(Vacia() == false) {
        while(Pila != NULL) {
            Temp = Pila;
            Pila = Pila -> sig;
            delete Temp;
        }
    }
}

int main(int argc, char **argv) {
    CPila Stack1;
    char Cadena[30];
    int opc;
    int unsigned i;
    bool opt = true, flag = true;
    
    do {
        system("clear");
        menu();
		opc = validarEnteros();
        flag = true;
        switch(opc) {
            case 1:
				cout << "\nIngresa la palabra: ";
				cin >> Cadena;
				for (i = 0; i < strlen(Cadena); i++) {
					Stack1.Agregar(Cadena[i]);
				}
				for (i = 0; i < strlen(Cadena); i++) {
					if(Cadena[i] == Stack1.Sacar()) continue;
					else {
						flag = false;
						break;
					}
				}
				if(flag == true) cout << "Es palindromo" << endl;
				else cout << "No es palindromo" << endl;
				
                break;
            case 2: 
				opt = false;
				break;
            default:
                cout << "Opción no válida" << endl;
                break;
        }
        cout << "\nPresione una tecla para continuar...";
        cin.ignore().get();
    } while(opt);
    
    return 0;
}

void menu() {
    cout << "\tElija una opción" << endl;
    cout << "1. Validar palabra" << endl;
    cout << "2. Salir" << endl;
    cout << "---> ";
}

int validarEnteros() { //Para evitar el bucle infinito al escribir texto en lugar de una opción numérica 
	int valor = 0, ok = 0, ch = 0;
	do {
		if ((ok = scanf("%d", &valor)) == EOF)
		return EXIT_FAILURE;
			  
		if ((ch = getchar()) != '\n') {
		ok = 0;
		printf("Vuelva a intentarlo: ");
		while ((ch = getchar()) != EOF && ch != '\n');
		}
	} while (!ok);
	return valor;
}
