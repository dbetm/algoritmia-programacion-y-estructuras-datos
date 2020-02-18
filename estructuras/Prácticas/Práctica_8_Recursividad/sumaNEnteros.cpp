#include <iostream>
#include <cstdlib>

using namespace std;

class Suma {
    private:
        long int sumaTotal;
    public:
        Suma();
        long int Sumar(int); //arg = n (n primeros enteros)
        ~Suma();
}Suma;

Suma::Suma() {
    sumaTotal = 0;
}

long int Suma::Sumar(int n) { //formula no recursiva: (n^2 + n) / 2 o [(n + 1) / 2] * n
    if(n == 0) return sumaTotal;
    sumaTotal += n;
    return Sumar(n-1);
}

Suma::~Suma() {
    sumaTotal = 0;
}

int main(int argc, char const *argv[]) {
    int n;
    system("clear");
    cout << "¿Hasta que entero desea sumar? ";
    cin >> n;
    cout << Suma.Sumar(n) << endl;

    return 0;
}
