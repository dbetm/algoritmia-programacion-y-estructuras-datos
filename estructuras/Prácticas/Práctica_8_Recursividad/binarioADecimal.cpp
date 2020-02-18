#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;

int obtenerNum();

class Convertidor {
    public:
        Convertidor();
        int expansion(int, int);
        ~Convertidor();
}Conv;

Convertidor::Convertidor() {}

int Convertidor::expansion(int i, int num) {
    if(i == 0) return num;
    return expansion(i-1, num*2);
}

Convertidor::~Convertidor() {}

int main(int argc, char const *argv[]) {
    int numero;

    cout << "Escribe el número: ";
    numero = obtenerNum();
    cout << endl;

    return 0;
}

int obtenerNum() {
    string Bin;
    int numBaseDiez = 0, dig = 0, pos = 0; //pos = posición

    cout << "Escribe el número: ";
    cin >> Bin;
    pos = Bin.size() - 1;

    for (int i = 0; i < Bin.size(); i++) {
        dig = (int)Bin[i] - 48; //-48 por el uso del código ASCII
        numBaseDiez += Conv.expansion(pos, dig);
        pos--;
    }
    cout << endl;
    cout << numBaseDiez << endl;
    return 0;

}
