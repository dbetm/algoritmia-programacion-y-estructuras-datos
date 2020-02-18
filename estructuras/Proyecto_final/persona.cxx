#include "header.h"

bool controlActualizacion(string);
string generaNumTarjeta(int);
void mostrarNumTarjeta(string); //formateado

int numerador;

struct Nodo {
    string nombre;
    string apellido;
    string numTarjeta;
    double saldo;
    int clabe;
    int edad;
    Nodo *sig;
    Nodo *ant;
};

class Cliente {
    private:
        Nodo *Inicio;
        Nodo *Final;
    public:
        Cliente();
        //CONSULTAS BÁSICAS
        void insertarDatos(string, int, string, int);
        void mostrarRegistros();
        Nodo* buscarCliente(int); //se busca a partir de la clabe interbancaria
        void eliminarCliente(int);
        void actualizarDatos(int);
        //ClienteACCIONES CUENTA
		void depositar(double, Nodo*);
		void retirar(double, Nodo*);
		double consultaSaldo(Nodo*);
        //MÉTODOS GENÉRICOS
        bool vacia();
        ~Cliente();
};

Cliente::Cliente() {
    Final = new Nodo;
    Final -> sig = NULL;
    Final -> sig = NULL;
    Inicio = Final;
}

void Cliente::insertarDatos(string nombre, int clabe, string apellido, int edad) {
    Nodo *Temp;
    if(vacia()) {
        Inicio -> clabe = clabe;
        Inicio -> nombre = nombre;
        Inicio -> apellido = apellido;
        Inicio -> edad = edad;
        Inicio -> numTarjeta = generaNumTarjeta(clabe);
        cout << "Número de tarjeta: ";
        mostrarNumTarjeta(Inicio -> numTarjeta);
        if(edad >= 18)
            Inicio -> saldo = 100;
        else
            Inicio -> saldo = 0;
        Final = new Nodo;
        if(Final == NULL) cout << "Ups! Parece que hay un error." << endl; //Buenas prácticas de programación
        else {
            cout << "\nDATOS GUARDADOS DE FORMA CORRECTA.\n" << endl;
            Inicio -> sig = Final;
            Final -> ant = Inicio;
            Final -> sig = NULL;
        }
    }
    else {
        if(Final == NULL) cout << "Error al guardar" << endl;
        else {
            Temp = Final;
            Temp -> clabe = clabe;
            Temp -> nombre = nombre;
            Temp -> apellido = apellido;
            Temp -> edad = edad;
            Temp -> numTarjeta = generaNumTarjeta(clabe);
            cout << "Número de tarjeta: ";
            mostrarNumTarjeta(Temp -> numTarjeta);
            if(edad >= 18)
                Temp -> saldo = 100;
            else
                Temp -> saldo = 0;
            Final = new Nodo;
            if(Final == NULL) cout << "Ups! Parece que hay un error." << endl;
            else {
                cout << "\nDATOS GUARDADOS DE FORMA CORRECTA." << endl;
                Temp -> sig = Final;
                Final -> ant = Temp;
                Final -> sig = NULL;
            }
        }
    }
    cout << endl;
}

void Cliente::mostrarRegistros() {
    Nodo *Temp;
    if(!vacia()) {
        Temp = Inicio;
        while(Temp != Final) {
            cout << "[" << numerador << "]" << endl;
            cout << "\tClabe bancaria: " << Temp -> clabe << endl;
            cout << "\tNombre: " << Temp -> nombre << endl;
            cout << "\tApellido: " << Temp -> apellido << endl;
            cout << "\tEdad: " << Temp -> edad << endl;
            cout << "\tNúmero de tarjeta: ";
            mostrarNumTarjeta(Temp -> numTarjeta);
            cout << endl << endl;
			Temp = Temp -> sig;
            numerador++;
		}
    }
}
// arg2 es opción, 0 sólo devuelve la dirección
Nodo* Cliente::buscarCliente(int clabe) {
    Nodo *Temp;
	if(vacia()) {
        cout << "\nNo hay registros del cliente que busca." << endl;
        return NULL;
    }
	else {
		Temp = Inicio;
		while(Temp != Final) {
            if(Temp -> clabe == clabe) {
                    cout << "¡Cliente encontrado!" << endl;
                    cout << "\tClabe: " << Temp -> clabe << endl;
                    cout << "\tNombre: " << Temp -> nombre << endl;
                    cout << "\tApellido: " << Temp -> apellido << endl;
                    cout << "\tEdad: " << Temp -> edad << endl;
                    cout << "\tNúmero de tarjeta: ";
                    mostrarNumTarjeta(Temp -> numTarjeta);
                    cout << endl;
                    return Temp;
            }
            Temp = Temp -> sig;
		}
        cout << "Cliente no encontrado." << endl;
        return NULL;
	}
}

void Cliente::eliminarCliente(int clabe) {
    Nodo *Temp, *Aux, *Aux2, *Aux3;
    bool flag = false;
    if(vacia()) cout << "No se ha encontrado." << endl;
    else {
        Temp = Inicio;
        while(Temp != Final) {
            if(Temp -> clabe == clabe) {
                flag = true;
                if(Temp == Inicio) { //cuando el elemento se encontró al inicio simbólico.
                    Aux = Inicio;
                    Inicio = Inicio -> sig;
                    Inicio -> ant = NULL;
                    delete Aux;
                    break;
                }
                else if(Temp == Final -> ant) { //cuando se encontró en el final simbólico.
                    Aux = Temp;
                    Aux2 = Temp -> ant;
                    Aux2 -> sig = Final;
                    Final -> ant = Aux2;
                    delete Aux;
                    break;
                }
                else { //cuando se encontró en "medio".
                    Aux = Temp;
                    Aux2 = Temp -> ant;
                    Aux3 = Temp -> sig;
                    Aux2 -> sig = Aux3;
                    Aux3 -> ant = Aux2;
                    delete Aux;
                    break;
                }
            }
            Temp = Temp -> sig;
        }
        if(!flag) cout << "\nCliente no encontrado" << endl;
        else cout << "\nSe han eliminado los datos del cliente con clabe: " << clabe << ".\n" << endl;
    }
}

void Cliente::actualizarDatos(int clabe) {
    Nodo *Temp;
    bool ctrl;
    if(buscarCliente(clabe) != NULL) {
        Temp = buscarCliente(clabe);
        system("clear");
        cout << "\tEDITANDO DATOS DEL CLIENTE." << endl << endl;
        cout << "--- Datos actuales del cliente ---" << endl;
        cout << "Clabe bancaria: " << Temp -> clabe << endl; //La clabe no se edita
        cout << "Nombre: " << Temp -> nombre << endl;
        cout << "Apellido: " << Temp -> apellido << endl;
        cout << "Edad: " << Temp -> edad << endl;
        cout << "Número de tarjeta: ";
        mostrarNumTarjeta(Temp -> numTarjeta);
        cout << endl << endl;

        ctrl = controlActualizacion("nombre");
        if(ctrl) {
            cout << "Nuevo nombre: ";
            cin >> Temp -> nombre;
            cout << "OK" << endl;
        }
        ctrl = controlActualizacion("apellido");
        if(ctrl) {
            cout << "Nuevo apellido: ";
            cin >> Temp -> apellido;
            cout << "OK" << endl;
        }
        ctrl = controlActualizacion("edad");
        if(ctrl) {
            cout << "Edad: ";
            cin >> Temp -> edad;
            cout << "\nACTUALIZACIÓN FINALIZADA.\n" << endl;
            cin.get();
        }
    }
}

/* MÉTODOS PARA LAS TRANSACCIONES BANCARIAS */

void Cliente::depositar(double monto, Nodo *Dir) {
    Dir -> saldo += monto;
    cout << "\n" << Dir -> nombre << ", se han depositado de forma correcta $"<< monto << endl << endl;
}

void Cliente::retirar(double monto, Nodo *Dir) {
	if(monto > Dir -> saldo) {
		cout << "\n¡Saldo insuficiente!" << endl << endl;
	}
	else {
		Dir -> saldo = Dir -> saldo - monto;
        cout << "Operación realizada con éxito." << endl << endl;
	}
}

double Cliente::consultaSaldo(Nodo *Dir) {
	return Dir -> saldo;
}

bool Cliente::vacia() {
    if(Final -> ant == NULL) return true;
    else return false;
}

Cliente::~Cliente() {
    Nodo *Temp;
	if(!vacia()) {
		while(Inicio != Final) {
			Temp = Inicio;
			Inicio = Inicio -> sig;
			delete Temp;
		}
		if(Inicio == Final) delete Final;
	}
    else {
        delete Inicio;
    }
}

//EXTRAWARE

bool controlActualizacion(string atrib) {
    char opc;
    cout << "Modificar " << atrib << " [S/N] ->> ";
    cin >> opc;
    opc = toupper(opc);
    if(opc == 'S') return true;
    return false;
}

string generaNumTarjeta(int clabe) {
    int num, ctr = 0;
    string cadena;
    stringstream ss;

    srand(time(NULL));
    for (int i = 0; i < 4; i++) {
        num = 1000+rand()%(10000-1000); //genera aleatorios entre 1000 y 9999
        if(i == 0) num = clabe;
        ss << num;
        cadena = ss.str();
    }

    return cadena;
}

void mostrarNumTarjeta(string cadena) {
    for (int i = 0; i < cadena.size(); i++) {
        if(i%4 == 0) {
            if(i == 0) cout << cadena[i];
            else cout << " " << cadena[i];
        }
        else cout << cadena[i];
    }

    cout << endl;
}
