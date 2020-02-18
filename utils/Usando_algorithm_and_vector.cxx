#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char **argv)
{
	int cont;
	std::vector<int> lista ();
	cont = std::count(lista.begin(), lista.end(), 2);
	std::cout << "El 2 aparece: " << cont << endl;
	
	return 0;
}

