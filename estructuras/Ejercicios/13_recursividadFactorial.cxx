#include <iostream>
#include <cstdlib>

using namespace std;

class Factorial {
    private:
    public:
        Factorial();
        int getFactorial(int);
        ~Factorial();
};

Factorial::Factorial() {}

int Factorial::getFactorial(int n) {
    if(n == 0) return 1;
    else return n * getFactorial(n - 1);
}

Factorial::~Factorial() {}


int main(int argc, char const *argv[]) {
    int n;
    Factorial Obj;
    cout << "Type a number: ";
    cin >> n;
    cout << "El factorial es: " << Obj.getFactorial(n) << endl;
    return 0;
}
