#include <iostream>
#include <cstdlib>
#include <cstdio>
/* Nombre: David Betancourt Montellano
 * NL: 3
 * Fecha: 18/02/2017
 * UA: Estructuras de datos
 * Programa académico: ISC
 * Evidencia: Práctica TAD (formales)
 * Maestra: M. en Ed. Karina Rodríguez Mejía
 * Grupo: 2CM1.
*/
using namespace std;
	//Specification
class Salary {
	private:
		float s_monthly, v_monthly;
	public:
		Salary();
		float getSMon();
		float getVMon();
		float decIVA(float);
		void showNSalary(float);
		~Salary();
} Salary;

	//Implementation
//Constructor
Salary::Salary() { 
	s_monthly = 0;
	v_monthly = 0;
}

float Salary::getSMon() {
	cout << "Give me the monthly salary: ";
	cin >> s_monthly;
	return s_monthly;
}

float Salary::getVMon() {
	cout << "Give me the monthly sales: ";
	cin >> v_monthly;
	v_monthly = (v_monthly * 4) / 100;
	return v_monthly;
}

float Salary::decIVA(float sal) {
	sal -= (sal * 16) / 100;
	return sal; 
}

void Salary::showNSalary(float sal) {
	cout << "Neto salary: " << sal << endl;
}

//Destructor
Salary::~Salary() {
	s_monthly = 0;
	v_monthly = 0;
}

int main(int argc, char **argv) {
	float netoSal;
	netoSal = Salary.getSMon();
	netoSal += Salary.getVMon();
	netoSal = Salary.decIVA(netoSal);
	Salary.showNSalary(netoSal);
	return 0;
}
