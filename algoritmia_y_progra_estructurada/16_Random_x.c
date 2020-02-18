#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{ 
	int num[5];
	int lim = 0;
	
	do {
	num[lim] = rand();
	lim++;
	}while(lim < 5);
	                                                                                                                                                                                                                                                                                                                                                                                                                                              
	lim = 0;
	
	for (lim = 0; lim < 5; lim++) {
		printf("%i\n",num[lim]);
	}
	
	return 0;
}

