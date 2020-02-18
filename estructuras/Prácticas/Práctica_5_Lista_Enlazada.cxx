#include <iostream>
#include <cstdlib>
#include <cstdio>

/* Nombre: David Betancourt Montellano.
 * NL: 3.
 * Fecha: 24/04/2017.
 * UA: Estructuras de datos.
 * Programa académico: I.S.C.
 * Evidencia: Práctica #5 Lista.
 * Maestra: M. en Ed. Karina Rodríguez Mejía.
 * Grupo: 2CM1.
*/
void menu();
using namespace std;

struct Node {
    int dat;
    Node *inc; //pointer for dir next Node
};

class CLista {
    private:
        Node* Final;
        Node* Front;
        int num;
    public:
        CLista();
        int getNum();
        void message(int, int);
        void first(int); //for the first num
        void firstAdd(int);
        void interAdd(int);
        void finalAdd(int);
        void firstDel(); //delete the first num
        void firstDis(); //show the first num
        void finalDis(); //show the final num
        void interDel(int); //delete an specified number by user
        void finalDel();
        void search(int);
        void display();
        bool empty();
        ~CLista();
};

CLista::CLista() {
  Front = new Node;
  Final = Front;
  num = 0;
}

int CLista::getNum() {
	cout << "Ingresa el número: ";
    cin >> num;
	return num;
}

void CLista::first(int dat) {
  Final = new Node;
  Front -> dat = dat;
  Front -> inc = Final;
  message(0, 2);
}

void CLista::firstAdd(int dat) {
  Node *Temp, *Aux;
  if(empty()) first(dat);
  else {
    Aux = Front;
    Temp = new Node;
    Temp -> dat = dat;
    Temp -> inc = Aux;
    Front = Temp;
    message(0, 4);
  }
}

void CLista::interAdd(int dat) {
  Node *Temp, *Aux;
  if(empty()) first(dat);
  else {
    if(Front -> inc == Final) {
      Temp = new Node;
      Temp -> dat = dat;
      Temp -> inc = Final;
      Front -> inc = Temp;
      message(0, 3);
    }
    else {
      Aux = Front -> inc;
      Temp = new Node;
      Temp -> dat = dat;
      Temp -> inc = Aux;
      Front -> inc = Temp;
      message(0, 3);
    }
  }
}

void CLista::finalAdd(int dat) {
  Node *Temp, *Aux;
  if(empty()) first(dat);
  else {
    if(Front -> inc == Final) {
      Temp = new Node;
      Temp -> dat = dat;
      Temp -> inc = Final;
      Front -> inc = Temp;
      message(0, 5);
    }
    else {
      Aux = Front;
      while(Aux != Final) {
        if(Aux -> inc == Final) break;
        Aux = Aux -> inc;
      }
      Temp = new Node;
      Aux -> inc = Temp;
      Temp -> dat = dat;
      Temp -> inc = Final;
      message(0, 5);
    }
  }
}

void CLista::firstDel() {
  Node *Temp;
  if(empty()) message(0, 11);
  else {
    if(Front -> inc == Final) {
      message(Front -> dat, 1);
      delete Front;
      delete Final;
      Front = new Node;
      Final = Front;
    }
    else {
      message(Front -> dat, 1);
      Temp = Front;
      Front = Front -> inc;
      delete Temp;
    }
  }
}

void CLista::interDel(int dat) {
    Node *Temp, *Aux, *Aux2;
    bool flag = false;
    if(empty()) message(0, 11);
    else {
		Temp = Front;
		while(Temp != Final) {
            if(Temp -> dat == dat) {
                flag = true;
                break;
            }
            Aux = Temp;
			Temp = Temp -> inc;
	   }
       if(!flag) message(dat, 8);
       else {
            if(Temp == Front) {
               firstDel();
            }
            else if(Temp -> inc == Final) {
               message(Temp -> dat, 1);
               Aux2 = Temp;
               Aux -> inc = Final;
               delete Aux2;
            }
            else {
               message(Temp -> dat, 1);
               Aux2 = Temp -> inc;
               Aux -> inc = Aux2;
               delete Temp;
            }
        }
	}
}

void CLista::finalDel() {
  Node *Temp, *Aux;
  if(empty()) message(0, 11);
  else {
    Temp = Front;
    while(Temp != Final) {
      if(Temp -> inc == Final) break;
      Aux = Temp;
      Temp = Temp -> inc;
    }
    if(Temp == Front) firstDel();
    else {
      message(Temp -> dat, 1);
      Aux -> inc = Final;
      delete Temp;
    }
  }
}

void CLista::firstDis() {
  if(!empty()) message(Front -> dat, 6);
  else message(0, 11);
}

void CLista::finalDis() {
  Node *Temp;
  if(!empty()) {
    Temp = Front;
    while(Temp != Final) {
      if(Temp -> inc == Final) break;
      Temp = Temp -> inc;
    }
    message(Temp -> dat, 7);
  }
  else message(0, 11); //Para mandar mensaje que la lista está vacía
}

bool CLista::empty() {
  if(Final == Front) return true;
  else return false;
}

void CLista::search(int dat) {
	Node *Temp;
  bool flag = false;
	if(empty()) message(0, 11);
	else {
		Temp = Front;
		while(Temp != Final) {
      if(Temp -> dat == dat and flag == false) {
          flag = true;
          cout << "[" << Temp -> dat << "] ";
      }
      else cout << Temp -> dat << " ";
			Temp = Temp -> inc;
		}
    if(flag) message(0, 9);
    else message(dat, 8);
		cout << endl;
	}
}

void CLista::display() {
	Node *Temp;
	if(empty()) message(0, 11);
	else {
		Temp = Front;
		while(Temp != Final) {
			cout << Temp -> dat << " ";
			Temp = Temp -> inc;
		}
		cout << endl;
	}
}

void CLista::message(int dat, int opc) {
  switch (opc) {
    case 1:
      cout << "Se sacó: " << dat << endl;
      break;
    case 2:
      cout << "Se insertó por primera vez" << endl;
      break;
    case 3:
      cout << "Se insertó correctamente" << endl;
      break;
    case 4:
      cout << "Se insertó al inicio" << endl;
      break;
    case 5:
      cout << "Se insertó al final" << endl;
      break;
    case 6:
      cout << "El elemento al inicio es: " << dat << endl;
      break;
    case 7:
      cout << "El elemento del final es: " << dat << endl;
      break;
    case 8:
      cout << endl << dat <<  " no fue encontrado." << endl;
      break;
    case 9:
      cout << endl << "¡Encontrado!" << endl;
      break;
    case 10:
      cout << "La lista tiene elementos" << endl;
      break;
    default:
      cout << "La lista está vacía" << endl;
  }
}

CLista::~CLista() {
	Node *Temp;
	if(!empty()) {
		while(Front != Final) {
			Temp = Front;
			Front = Front -> inc;
			delete Temp;
		}
		if(Front == Final) delete Final;
	}
}

int main(int argc, char const *argv[]) {
  CLista Lx;
  int dat, opc;
  bool estado, opt = true;

  do {
      system("clear");
      menu();
      cin >> opc;

      switch(opc) {
          case 1:
              dat = Lx.getNum();
              Lx.firstAdd(dat);
              break;
          case 2: //delete the first number
              Lx.firstDel();
              break;
          case 3:
              Lx.firstDis();
              break;
          case 4:
              dat = Lx.getNum();
              Lx.interAdd(dat);
              break;
          case 5:
              dat = Lx.getNum();
              Lx.interDel(dat);
              break;
          case 6:
              dat = Lx.getNum();
              Lx.finalAdd(dat);
              break;
          case 7:
              Lx.finalDel();
              break;
          case 8:
              Lx.finalDis();
              break;
          case 9:
              Lx.display();
              break;
          case 10:
              estado = Lx.empty();
              if(estado) cout << "Sí" << endl;
              else cout << "No" << endl;
              break;
          case 11: //find a number
              dat = Lx.getNum();
              Lx.search(dat);
              break;
          case 12:
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
    cout << "\tElija una opción" << endl;
    cout << "1. Agregar al inicio" << endl; //ya
    cout << "2. Sacar del inicio" << endl; //ya
    cout << "3. Mostrar inicio" << endl;  //ya
    cout << "4. Agregar en medio" << endl; //ya
    cout << "5. Sacar un número en específico" << endl; //ya
    cout << "6. Agregar al final" << endl; //ya
    cout << "7. Sacar del final" << endl; //ya
    cout << "8. Mostrar final" << endl;
    cout << "9. Mostrar elementos" << endl; //ya
    cout << "10. ¿Está vacía?" << endl; //ya
    cout << "11. Buscar elemento" << endl; //ya
    cout << "12. Salir" << endl; //ya
    cout << "---> ";
}
