#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

void menu();

using namespace std;

struct DCola {
	int dat;
	DCola *sig;
};

class CCola {
	private:
		DCola *Finl;
		DCola *Ftr;
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
	Ftr = Finl;
	dato = 0;
}
int CCola::Leer() {
	cout << "Ingresa el dato: ";
    cin >> dato;
	return dato;
}
void CCola::Insertar(int dat) {
	DCola *Temp;
	if(Vacia() != true) {
		Temp = Finl;
		Finl = new DCola;
		Temp -> dat = dat;
		Temp -> sig = Finl;
		cout << "Se insertó correctamente" << endl;
	} 
	else {
		Finl = new DCola;
		Ftr -> dat = dat;
		Ftr -> sig = Finl;
		cout << "Se insertó correctamente" << endl;
	}
}

void CCola::Sacar() {
	DCola *Temp;
	if(Vacia() == true) cout << "La cola está vacía" << endl;
	else {
		Temp = Ftr;
		Ftr = Ftr -> sig;
		cout << "Se sacó: " << Temp -> dat << endl;
		delete Temp;
	}
}
void CCola::Frente() {
	if(Vacia() == true) cout << "La cola está vacía" << endl;
	else {
		cout << "El elemento del frente es: " << Ftr -> dat << endl;
	}
}
void CCola::Imprimir() {
	DCola *Temp;
	if(Vacia() == true) cout << "La cola está vacía" << endl;
	else {
		Temp = Ftr;
		while(Temp != Finl) {
			cout << Temp -> dat << " ";
			Temp = Temp -> sig;
		}
		cout << endl;
	}
}
bool CCola::Vacia() {
	if(Ftr == Finl) return true;
	else return false;
}

CCola::~CCola() {
	DCola *Temp;
	if(Vacia() == true) cout << "La cola está vacía" << endl;
	else {
		while(Ftr != Finl) {
			Temp = Ftr;
			Ftr = Ftr -> sig;
			delete Temp;
		}
		if(Ftr == Finl) delete Finl;
	}
}

int main(int argc, char **argv) {
    CCola Clx;
    int dat, opc, numE;
    bool estado, opt = true;
    
    do {
        system("clear");
        menu();
        cin >> opc;
        
        switch(opc) {
            case 0: //Agregar n enteros
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
            case 2: //Sacar dato del frente
                Clx.Sacar();
                break;
            case 3: //Saber que dato se encuentra al frente
                Clx.Frente();
                break;
            case 4: //Mostrar todos los enteros de la cola
                Clx.Imprimir();
                break;
            case 5: //Verificar si está vacía
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
