#include <iostream>
#include <cstdlib>
#include <cstdio>
/*
 * Nombre: David Betancourt Montellano.
 * NL: 3.
 * Fecha: 16/05/2017.
 * UA: Estructuras de datos.
 * Programa académico: I.S.C.
 * Evidencia: Práctica #6 Lista doblemente enlazada (Conjuntos)
 * Maestra: M. en Ed. Karina Rodríguez Mejía.
 * Grupo: 2CM1.
 * Modificado para Windows
 * Compilado con: g++ 14_listaDoblementeEnlazada.cxx -o 14_listaDoblementeEnlazada
*/
using namespace std;
void menu();
void submenu(int);

struct Nodo {
    int dat;
    Nodo *sig;
    Nodo *ant;
};
//OPERACIONES BÁSICAS
class CLista {
    private:
        Nodo *Lista;
        Nodo *Inicio;
    public:
        CLista();
        int obtenerDato();
        void insertarDato(int);
        void mostrarDatos(int);
        void buscarDato(int);
        void sacarDato(int);
        bool vacia();
        Nodo* getDir(int);
        ~CLista();
};


CLista::CLista() {
    Lista = new Nodo;
    Lista -> ant = NULL;
    Lista -> sig = NULL;
    Inicio = Lista;
}


int CLista::obtenerDato() {
    int dato;
    cout << "Escribe el numero: ";
    cin >> dato;
    return dato;
}


void CLista::insertarDato(int dato) {
    Nodo *Temp;
    if(vacia()) {
        Inicio -> dat = dato;
        cout << "Correcto, se ha agregado el primer elemento" << endl;
        Lista = new Nodo;
        if(Lista == NULL) cout << "Error al guardar" << endl; //Buenas prácticas de programación
        else {
            Inicio -> sig = Lista;
            Lista -> ant = Inicio;
            Lista -> sig = NULL;
        }
    }
    else {
        if(Lista == NULL) cout << "Error al guardar" << endl;
        else {
            Temp  = Lista;
            Temp -> dat = dato;
            Lista = new Nodo;
            Temp -> sig = Lista;
            Lista -> ant = Temp;
            Lista -> sig = NULL;
            cout << "Correcto" << endl;
        }
    }
}


void CLista::mostrarDatos(int opcion) {
    Nodo *Temp;
    if(!vacia()) {
        Temp = Inicio; //de esta forma se recorre de inicio a fin, aunque se puede al revés si se iguala a Final
        if(opcion == 1) cout << "\nA = {";
        else cout << "\nB = {";
        while(Temp != Lista) {
            if(Temp -> sig != Lista) cout << Temp -> dat << ", ";
			else cout << Temp -> dat;
			Temp = Temp -> sig;
		}
		cout << "}\n" << endl;
    }
    else cout << "El conjunto esta vacío\n" << endl;
}


void CLista::buscarDato(int dato) {
    Nodo *Temp;
    int cont = 0;
	if(vacia()) cout << "El conjunto esta vacío" << endl;
	else {
		Temp = Inicio;
		while(Temp != Lista) {
            if(Temp -> dat == dato) {
                cont++;
                cout << "[" << Temp -> dat << "] ";
            }
            else cout << Temp -> dat << " ";
			Temp = Temp -> sig;
		}
    if(cont != 0){
        if(cont == 1) cout << "\nEncontrado 1 vez." << endl;
        else cout << "\nEncontrado " << cont << " veces." << endl;
    }
    else cout << "\nNo encontrado" << endl;
	cout << endl;
	}

}


void CLista::sacarDato(int dato) {
    Nodo *Temp, *Aux, *Aux2, *Aux3;
    bool flag = false;
    int cont = 0;
    if(vacia()) cout << "El conjunto esta vacío" << endl;
    else {
        Temp = Inicio;
        while(Temp != Lista) {
            if(Temp -> dat == dato) {
                flag = true;
                if(Temp == Inicio) { //cuando el elemento se encontró al inicio simbólico.
                    Aux = Inicio;
                    Inicio = Inicio -> sig;
                    Inicio -> ant = NULL;
                    delete Aux;
                    cont++;
                }
                else if(Temp == Lista -> ant) { //cuando se encontró en el final simbólico.
                    Aux = Temp;
                    Aux2 = Temp -> ant;
                    Aux2 -> sig = Lista;
                    Lista -> ant = Aux2;
                    delete Aux;
                    cont++;
                }
                else { //cuando se encontró en "medio".
                    Aux = Temp;
                    Aux2 = Temp -> ant;
                    Aux3 = Temp -> sig;
                    Aux2 -> sig = Aux3;
                    Aux3 -> ant = Aux2;
                    delete Aux;
                    cont++;
                }
            }
            Temp = Temp -> sig;
        }
        if(!flag) cout << "\nEl elemento no fue encontrado" << endl;
        else cout << "\nSe quita: " << dato << "\nCoincidencias encontradas: " << cont << endl;
    }
}


bool CLista::vacia() {
    if(Lista -> ant == NULL) return true;
    else return false;
}


Nodo* CLista::getDir(int opc) {
    switch (opc) {
        case 1:
            return Inicio;
        case 2:
            return Lista;
    }
    return EXIT_SUCCESS;
}


CLista::~CLista() {
	Nodo *Temp;
	if(!vacia()) {
		while(Inicio != Lista) {
			Temp = Inicio;
			Inicio = Inicio -> sig;
			delete Temp;
		}
		if(Inicio == Lista) delete Lista;
	}
    else {
        delete Inicio;
    }
}


//OPERACIONES DE CONJUNTOS
class Algebra {
    private:
        Nodo *AI, *AF, *BI, *BF;
    public:
        Algebra(Nodo *, Nodo *, Nodo *, Nodo *);
        void interseccion();
        void unionAB();
        int cardinalidad(int);
        void diferencia(int);
        bool repetido(Nodo*);
        bool espejo(int, int);
        ~Algebra();
};

//AI = A inicio, AF = A final.
Algebra::Algebra(Nodo *_AI, Nodo *_AF, Nodo *_BI, Nodo *_BF) : AI(_AI), AF(_AF), BI(_BI), BF(_BF) {}

void Algebra::interseccion() {
    Nodo *TempA;
    TempA = AI;
    cout << "\n{";
    while(TempA != AF) {
        if(espejo(TempA -> dat, 2)) {
            if(!repetido(TempA)) {
                if(TempA -> sig == AF) cout << TempA -> dat;
                else cout << TempA -> dat << ", ";
            }
        }
        TempA = TempA -> sig;
    }
    cout << "}\n" << endl;
}


void Algebra::unionAB() {
    Nodo *TempA, *TempB;
    TempA = AI;
    TempB = BI;

    cout << "\n{";
    while(TempA != AF) {
        if(!repetido(TempA)) cout << TempA -> dat << ", ";
        TempA = TempA -> sig;
    }
    while(TempB != BF) {
        if(!repetido(TempB) && !espejo(TempB -> dat, 1)) {
            if(TempB -> sig == BF) cout << TempB -> dat;
            else cout << TempB -> dat << ", ";
        }
        TempB = TempB -> sig;
    }
    cout << "}\n" << endl;
}


int Algebra::cardinalidad(int opcion) {
    Nodo *Temp, *Fin;
    int cont = 0;
    if(opcion == 1) { //el 1 para el conjunto A
        Temp = AI;
        Fin = AF;
    }
    else {
        Temp = BI;
        Fin = BF;
    }
    while (Temp != Fin) {
        cont++;
        Temp = Temp -> sig;
    }
    return cont;
}


void Algebra::diferencia(int opc) {
    Nodo *Temp, *Fin;
    int opcion;
    cout << "\n{";
    if(opc == 1) { //el 1 para el conjunto A
        Temp = AI;
        Fin = AF;
        opcion = 2; //Al ser opción igual a 2 quiere decir que va a comparar con B
    }
    else {
        Temp = BI;
        Fin = BF;
        opcion = 1; //Al ser opción igual a 2 quiere decir que va a comparar con A
    }
    while (Temp != Fin) {
        if(!espejo(Temp -> dat, opcion)) { // !espejo(dato, opcion) indica que si el dato no se encuentra en el otro conjunto entonces forma parte de la diferencia y por ende lo imprime
            if(Temp -> sig == Fin) cout << Temp -> dat;
            else cout << Temp -> dat << ", ";
        }
        Temp = Temp -> sig;
    }
    cout << "}\n" << endl;;
}


bool Algebra::repetido(Nodo *Aux) { //Buscar repeticiones en el conjunto
    int dato = Aux -> dat;
    Aux = Aux -> ant;
    while(Aux != NULL) { //va para atrás
        if(Aux -> dat == dato) return true;
        Aux = Aux -> ant;
    }
    return false;
}


bool Algebra::espejo(int n, int opc) { //Retorna true si B contiene el mismo elemento que A o true si A contiene el mismo elemento que B
    Nodo *Temp, *Fin;
    if(opc == 1) { //Para comparar con A
        Temp = AI;
        Fin = AF;
    }
    else {
        Temp = BI;
        Fin = BF;
    }
    while(Temp != Fin) { //se recorre de inicio a fin
        if(Temp -> dat == n) return true;
        Temp = Temp -> sig;
    }
    return false;
}


Algebra::~Algebra() {
    //  Los atributos (estructuras) para los cuales se reserva memoria son eliminados por el
    // constructor de la otra clase
}


int main(int argc, char **argv) {
    CLista A, B; //instancio mis dos objetos de la clase CLista que los describe
    int dat, opc, numE, subOpc, card;
    bool opt = true;
    Nodo *AI, *AF, *BI, *BF;

    do {
        system("cls");
        menu();
        cin >> opc;

        AI = A.getDir(1);
        AF = A.getDir(2);
        BI = B.getDir(1);
        BF = B.getDir(2);
        Algebra Obx(AI, AF, BI, BF);

        switch(opc) {
            case 1: //Para el conjunto A
                cout << "Cuantos elementos desea ingresar? ";
                cin >> numE;
                for (int i = 0; i < numE; i++) {
                    dat = A.obtenerDato();
                    A.insertarDato(dat);
                }
                break;
            case 2: //Para el conjunto B
                cout << "Cuantos elementos desea ingresar? ";
                cin >> numE;
                for (int i = 0; i < numE; i++) {
                    dat = B.obtenerDato();
                    B.insertarDato(dat);
                }
                break;
            case 3: //A
                dat = A.obtenerDato();
                A.sacarDato(dat);
                break;
            case 4: //B
                dat = B.obtenerDato();
                B.sacarDato(dat);
                break;
            case 5: //A
                A.mostrarDatos(1);
                break;
            case 6: //para mostrar del conjunto B
                B.mostrarDatos(2);
                break;
            case 7:
                dat = A.obtenerDato();
                A.buscarDato(dat);
                break;
            case 8:
                dat = B.obtenerDato();
                B.buscarDato(dat);
                break;
            case 9:
                Obx.interseccion();
                break;
            case 10:
                Obx.unionAB();
                break;
            case 11:
                submenu(1);
                cin >> subOpc;
                if(subOpc != 1 && subOpc != 2) cout << "Opcion no valida" << endl;
                else {
                    card = Obx.cardinalidad(subOpc);
                    if(card == 0) cout << "El conjunto esta vacio" << endl;
                    else {
                        if(subOpc == 1) cout << "La cardinalidad de A es: " << card << endl;
                        else cout << "La cardinalidad de B es: " << card << endl;
                    }
                }
                break;
            case 12:
                submenu(2);
                cin >> subOpc;
                if(subOpc != 1 && subOpc != 2) cout << "Opcion no valida" << endl;
                else Obx.diferencia(subOpc);
                break;
            case 13:
				opt = false;
				break;
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
        cout << "Presione una tecla para continuar...";
        cin.ignore().get();
    } while(opt);

    return 0;
}


void menu() {
    cout << "\nOPERACIONES BASICAS" << endl;
    cout << "1. Agregar a A" << endl;
    cout << "2. Agregar a B" << endl;
    cout << "3. Quitar de A" << endl;
    cout << "4. Quitar de B" << endl;
    cout << "5. Mostrar conjunto A" << endl;
    cout << "6. Mostrar conjunto B" << endl;
    cout << "7. Buscar en A" << endl;
    cout << "8. Buscar en B" << endl;
    cout << "\nOPERACIONES DE CONJUNTOS" << endl;
    cout << "9. Interseccion" << endl;
    cout << "10. Union" << endl;
    cout << "11. Cardinalidad" << endl;
    cout << "12. Diferencia" << endl;
    cout << "13. Salir" << endl;
    cout << "\n>>> ";
}


void submenu(int opc) {
    system("cls");
    cout << "\tElija una opcion: " << endl;
    if(opc == 1) {
        cout << "\n1. Cardinalidad de A" << endl;
        cout << "2. Cardinalidad de B" << endl;
    }
    else {
        cout << "1. Diferencia A - B" << endl;
        cout << "2. Diferencia de B - A" << endl;
    }
    cout << "\n>>> ";
}
