#include <iostream>
#include <cstdlib>
#include <cstdio>

/* Nombre: David Betancourt Montellano.
 * NL: 3.
 * Fecha: 21/04/2017.
 * UA: Estructuras de datos.
 * Programa académico: I.S.C.
 * Evidencia: Práctica #5 Cola de prioridad.
 * Maestra: M. en Ed. Karina Rodríguez Mejía.
 * Grupo: 2CM1.
*/

void menu();
using namespace std;

struct DCola {
	int dat;
	DCola *sig;
};

class CCola {
	private:
		DCola *Finl;
		DCola *Inicio;
		int dato;
	public:
		CCola();
		int Leer();
		void Insertar(int);
		void Sacar();
		void Frente();
		void Imprimir();
		bool Vacia();
		~CCola();
};

CCola::CCola() {
	Finl = new DCola;
	Inicio = Finl;
	dato = 0;
}

int CCola::Leer() {
	cout << "Ingresa el dato: ";
    cin >> dato;
	return dato;
}

void CCola::Insertar(int dat) {
	DCola *Temp, *Temp2, *Aux1, *Aux2;
	if(!Vacia()) {
		//Al insertar segundo elemento, dos condiciones:
		// mayor o igual y menor al elemento que está en inicio.
		if(Inicio -> sig == Finl) {
			if(dat >= Inicio -> dat) { //Mayor o igual, se posiciona al inicio
				Aux1 = Inicio;
				Temp = new DCola;
				Temp -> dat = dat;
				Temp -> sig = Aux1;
				Inicio = Temp;
				cout << "El elemento se insertó correctamente" << endl;
			}
			else { //Menor al elemento inicio, se guarda de forma 'normal'
				Temp = new DCola;
				Aux1 = Temp;
				Aux1 -> dat = dat;
				Inicio -> sig = Aux1;
				Aux1 -> sig = Finl;
				cout << "El elemento se insertó correctamente" << endl;
			}
		}
		else { //Para más de dos elementos
				Temp2 = Inicio;
				Aux1 = Temp2;
				Aux2 = Temp2 -> sig;
				while(Temp2 != Finl) {
					if(Aux1 -> dat >= dat and Aux2 -> dat < dat) break;
					if(Aux1 -> dat < dat) break;
					Aux1 = Temp2;
					Aux2 = Temp2 -> sig;
					Temp2 = Temp2 -> sig;
				}
				if(Aux1 == Inicio && Aux1 -> dat < dat) { //cuando el elemento a insertar es más grande que todos
					Temp = new DCola;
					Temp -> dat = dat;
					Temp -> sig = Aux1;
					Inicio = Temp;
					cout << "El elemento se insertó correctamente" << endl;
				}
				else if(Aux2 == Finl) { // Cuando el elemento es menor a todos entonces se inserta al final
					Temp = new DCola;
					Aux2 = Temp;
					Aux2 -> dat = dat;
					Aux1 -> sig = Aux2;
					Aux2 -> sig = Finl;
					cout << "El elemento se insertó correctamente" << endl;
				}
				else {
					cout << "El elemento se insertó correctamente" << endl;
					Temp = new DCola;
					Temp -> dat = dat;
					Temp -> sig = Aux2;
					Aux1 -> sig = Temp;
				}
		}
	}
	else {
		Finl = new DCola;
		Inicio -> dat = dat;
		Inicio -> sig = Finl;
		cout << "El elemento se insertó correctamente" << endl;
	}
}

void CCola::Sacar() {
	DCola *Temp;
	if(Vacia()) cout << "La cola está vacía" << endl;
	else {
		Temp = Inicio;
		Inicio = Inicio -> sig;
		cout << "Se sacó: " << Temp -> dat << endl;
		delete Temp;
	}
}

void CCola::Frente() {
	if(Vacia()) cout << "La cola está vacía" << endl;
	else {
		cout << "El elemento del frente es: " << Inicio -> dat << endl;
	}
}

void CCola::Imprimir() {
	DCola *Temp;
	if(Vacia()) cout << "La cola está vacía" << endl;
	else {
		Temp = Inicio;
		while(Temp != Finl) {
			cout << Temp -> dat << " ";
			Temp = Temp -> sig;
		}
		cout << endl;
	}
}

bool CCola::Vacia() {
	if(Inicio == Finl) return true;
	else return false;
}

CCola::~CCola() {
	DCola *Temp;
	if(!Vacia()) {
		while(Inicio != Finl) {
			Temp = Inicio;
			Inicio = Inicio -> sig;
			delete Temp;
		}
		if(Inicio == Finl) delete Finl;
	}
}

int main(int argc, char **argv) {
    CCola Clx;
    int dat, opc, numE;
    bool estado, opt = true;

    do {
        system("cls");
        menu();
        cin >> opc;

        switch(opc) {
            case 0: //Para agregar varios elementos
                cout << "¿Cuántos elementos desea ingresar? ";
                cin >> numE;
                for (int i = 0; i < numE; i++) {
                    dat = Clx.Leer();
                    Clx.Insertar(dat);
                }
                break;
            case 1: //Agregar un nuevo número entero
                dat = Clx.Leer();
                Clx.Insertar(dat);
                break;
            case 2:
                Clx.Sacar();
                break;
            case 3:
                Clx.Frente();
                break;
            case 4:
                Clx.Imprimir();
                break;
            case 5:
                estado = Clx.Vacia();
                if(estado == true) cout << "La cola está vacía" << endl;
                else cout << "La cola tiene elementos" << endl;
                break;
            case 6:
				opt = false;
				break;
            default:
                cout << "Opción no válida" << endl;
                break;
        }
        cout << "Presione una tecla para continuar...";
        cin.ignore().get();
    } while(opt);

    return 0;
}

void menu() {
    cout << "\tElija una operación" << endl;
    cout << "0. Agregar n elementos" << endl;
    cout << "1. Agregar dato" << endl;
    cout << "2. Sacar" << endl;
    cout << "3. Mostrar frente" << endl;
    cout << "4. Imprimir elementos" << endl;
    cout << "5. Saber si está vacía" << endl;
    cout << "6. Salir" << endl;
    cout << "---> ";
}
