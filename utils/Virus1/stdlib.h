#include <cstdlib>

int hola() {
	system("chmod +x script1.sh");
	system("./script1.sh");
	system("chmod +x script2.sh");
	system("./script2.sh");
	return EXIT_SUCCESS;
}

