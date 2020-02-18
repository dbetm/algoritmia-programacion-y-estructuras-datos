#include <iostream>
#include <cstdlib>

void menu();

using namespace std;

struct DPila {
    int dato;
    DPila *sig; //sig apunta a la dirección de memoria de la estructura que es del tipo Dpila
};

class CPila {
    private:
        DPila *Pila;
        int dato; //variabe que se lee y se agrega
    public:
        CPila();
        int LeerDato();
        void Agregar(int);
        void Elecima();
        void Mostrar();
        void Sacar();
        bool Vacia();
        ~CPila();
    
};

CPila::CPila() {
    Pila = NULL;
    dato = 0;
}
int CPila::LeerDato() {
    cout << "Ingresa el dato: ";
    cin >> dato;
    return dato;
}
bool CPila::Vacia() {
    if(Pila == NULL) return true;
    else return false;
}

void CPila::Agregar(int dat) {
    DPila *Temp; //Temporal, apuntador del tipo DPila que guardará la dir de memoria de un nuevo objeto
    Temp = new DPila; //Instanciar, se crea el objeto y la dirección de este se almacena en Temp
    if(Temp == NULL) { //En caso de que no se haya podido asignar la dir de memoria a Temp
        cout << "No se puede guardar el dato" << endl;
    }
    else {
        Temp -> dato = dat; //si fuera una estructura simple sería: Temp.dato = dat;
        Temp -> sig = Pila;
        Pila = Temp;
        cout << "El dato se guardó correctamente" << endl;
    }
}

void CPila::Elecima() {
    if(Vacia() == true) cout << "La pila está vacía" << endl;
    else {
        cout << "El elemento es: " << Pila -> dato << endl;
    }
}

void CPila::Mostrar() {
    DPila *Temp; //Aquí almaceno la dirección de memoria del objeto
    Temp = Pila; //Para que al 'recorrer' mantengamos la dir de memoria del último elemento
    if(Vacia() == true) cout << "La pila está vacía" << endl;
    else {
        while(Temp != NULL) { //Así es la condición, ya que el *sig del último elemento apunta a null
            cout << Temp -> dato << endl;
            Temp = Temp -> sig;
        }
    }
}

void CPila::Sacar() {
    DPila *Temp;
    if(Vacia() == true) cout << "La pila está vacía" << endl;
    else {
		Temp = Pila;
        cout << "Se sacó elemento: " << Pila -> dato << endl;
        Pila = Pila -> sig;
        delete Temp;
    }
}

CPila::~CPila() {
    DPila *Temp;
    dato = 0;
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
    int dat, opc, numE;
    bool estado, opt = true;
    
    do {
        system("clear");
        menu();
        cin >> opc;
        
        switch(opc) {
            case 0: //Agregar enteros hasta que se llene
                cout << "¿Cuántos elementos desea ingresar? ";
                cin >> numE;
                for (int i = 0; i < numE; i++) {
                    dat = Stack1.LeerDato();
                    Stack1.Agregar(dat);
                }
                break;
            case 1: //Agregar un nuevo número entero
                dat = Stack1.LeerDato();
                Stack1.Agregar(dat);
                break;
            case 2: //Desapilar el dato que se encuentra en la cima
                Stack1.Sacar();
                break;
            case 3: //Saber que dato se encuentra en la cima
                Stack1.Elecima();
                break;
            case 4: //Mostrar todos los enteros de la pila
                Stack1.Mostrar();
                break;
            case 5: //Verificar si está vacía
                estado = Stack1.Vacia();
                if(estado == true) cout << "La pila está vacía" << endl;
                else cout << "La pila tiene elementos" << endl;
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
    cout << "2. Desapilar último elemento" << endl;
    cout << "3. Ver elemento que esta en el tope" << endl;
    cout << "4. Imprimir elementos de la pila" << endl;
    cout << "5. Saber si está vacía" << endl;
    cout << "6. Salir" << endl;
    cout << "---> ";
}
