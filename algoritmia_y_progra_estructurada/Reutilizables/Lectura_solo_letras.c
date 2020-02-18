#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)

{
	char dabetm[23] = "";
	int a = 5, b = 4, c = 6;
	
	scanf("%[a-z]",dabetm);
	printf("%s\n",dabetm);
	fflush(stdin);
	return 0;
}


