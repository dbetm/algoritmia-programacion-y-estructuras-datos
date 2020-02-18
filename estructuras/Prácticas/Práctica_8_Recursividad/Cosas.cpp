#include <iostream>
#include <cstdlib>

using namespace std;

class Combinatoria {
    private:
    public:
        Combinatoria();
        long int posibilidades(int, int); //C(n,r) = n!(r! * (n-r)!)
        long int factorial(int);
        ~Combinatoria();
}Comb;

Combinatoria::Combinatoria() {}

long int Combinatoria::posibilidades(int n, int r) {
    return factorial(n) * (factorial(r) * factorial(n - r));
}

long int Combinatoria::factorial(int n) {
    if(n == 0) return 1;
    else return n * factorial(n - 1);
}

Combinatoria::~Combinatoria() {}

int main(int argc, char const *argv[]) {
    int n, r; //r = cosa distinta, n = conjunto de cosas
    do {
        system("clear");
        cout << "Número de cosas distintas: ";
        cin >> r;
        cout << "Cardinalidad del conjunto: ";
        cin >> n;
        if(r > n) cout << "No es posible realizar el cálculo" << endl;
        else
            cout <<  "Usted tiene " << Comb.posibilidades(n,r) << " formas distintas para elegir" << endl;
        cout << endl;
        cout << "Presione ENTER para continuar... o CTRL+C para salir --> ";
        cin.ignore().get();
    } while(1);
    return 0;
}
