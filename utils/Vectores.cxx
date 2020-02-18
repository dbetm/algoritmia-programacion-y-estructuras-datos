#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char **argv) {
	int max;
	vector <int> altura(4); // declaramos un mensaje de tamaño 4
	
	for (int i = 0; i < 4; i++) {
		cin >> altura[i];
	}
	
	// max_element es método de algorithm
	cout << max_element(altura.begin(), altura.end()) << endl;
	
	return 0;
}

