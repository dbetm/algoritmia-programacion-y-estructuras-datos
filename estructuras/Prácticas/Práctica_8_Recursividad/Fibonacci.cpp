#include <iostream>
#include <cstdlib>

using namespace std;

class Fib {
    private:
    public:
        Fib();
        int getAn(int); //An, el parámetro
        ~Fib();
}Obj;

Fib::Fib() {}

int Fib::getAn(int An) {
    if(An < 2) return An;
    return getAn(An-1) + getAn(An-2);
}

Fib::~Fib() {}

int main(int argc, char const *argv[]) {
    int num;
    do {
        system("clear");
        cout << "Escriba n >> ";
        cin >> num;

        for (int i = 0; i < num; i++) {
            cout << Obj.getAn(i) << " ";
            if(i == 10) cout << endl;
        }
        cout << endl;
        cout << "Presione una tecla para continuar... o CTRL+C para salir --> ";
        cin.ignore().get();
    } while(1);
    return 0;
}
