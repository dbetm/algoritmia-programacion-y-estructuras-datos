#include <iostream>

using namespace std;

class Metodo {
    private:
        int cociente;
    public:
        Metodo();
        int resta(int, int);
        ~Metodo();
};

Metodo::Metodo() {
    cociente = 0;
}

int Metodo::resta(int divisor, int dividendo) {
    if(dividendo > divisor and cociente == 0) return 0;
    if(divisor <= 0) return cociente;
    cociente++;
    return resta(divisor - dividendo, dividendo);

    //sin usar contador -> return resta(divisor - dividendo, dividendo) + 1;
}

Metodo::~Metodo() {
    cociente = 0;
}

int main(int argc, char const *argv[]) {
    int divisor, dividendo;
    Metodo Obj;
    cout << "Dame el divisor: ";
    cin >> divisor;
    cout << "Dame el dividendo: ";
    cin >> dividendo;
    cout << "El cociente es: " << Obj.resta(divisor, dividendo) << endl;

    return 0;
}
