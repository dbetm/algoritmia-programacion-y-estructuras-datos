#include <iostream>
#include <cstdlib>

//Programa para sumar los dígitos de un número

using namespace std;

class Suma {
    protected:
        int suma;
    public:
        Suma();
        int sumDig(int);
        ~Suma();
};

Suma::Suma() {
    suma = 0;
}

int Suma::sumDig(int n) {
    if(n == 0) return suma;
    else {
        suma += n % 10;
        n = n / 10;
        sumDig(n);
    }
}

Suma::~Suma() {
    suma = 0;
}


int main(int argc, char const *argv[]) {
    int n;
    Suma Obj;
    cout << "Escribe el número: ";
    cin >> n;
    cout << "La suma de los dígitos es: " << Obj.sumDig(n) << endl;
    return 0;
}
