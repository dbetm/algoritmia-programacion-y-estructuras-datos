#include <iostream>
#include <cstdlib>
//Recursividad
using namespace std;

class Primo {
    private:
    public:
        Primo();
        bool esPrimo(int, int);
        ~Primo();
};

Primo::Primo() {}

bool Primo::esPrimo(int num, int divisor) {
    if(num == 1) return false;
    if(num == 2) return true;
    if(divisor == 1) return true;
    if(divisor < num and divisor > 1) {
        if(num % divisor == 0) return false;
    }
    return esPrimo(num, divisor - 1);
}

Primo::~Primo() {}

int main(int argc, char const *argv[]) {
    int num;
    Primo Px;
    system("clear");
    cout << "Dame un número: ";
    cin >> num;
    if(Px.esPrimo(num, num)) cout << "Es primo" << endl;
    else cout << "No es primo" << endl;

    return 0;
}
