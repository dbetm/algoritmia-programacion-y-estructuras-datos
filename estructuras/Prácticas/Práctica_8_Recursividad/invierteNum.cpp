#include <iostream>
#include <cstdlib>

using namespace std;

class Inversor {
    public:
        Inversor();
        int invertir(int, int);
        ~Inversor();
}Inv;

Inversor::Inversor() {}

int Inversor::invertir(int n, int num) {
    num = num * 10;
    num += (n % 10);
    n /= 10;
    if(n == 0) return num;
    return invertir(n, num);

}

Inversor::~Inversor() {}

int main(int argc, char const *argv[]) {
    int numero = 0;
    do {
        system("clear");
        cout << "Escribe el número: ";
        cin >> numero;
        cout << "--> " << Inv.invertir(numero, 0) << endl;

        cout << endl;
        cout << "Presione ENTER para continuar... o CTRL+C para salir --> ";
        cin.ignore().get();
    } while(1);

    return 0;
}
