#include <stdio.h>

int main(int argc, char **argv) {
	int f, c, i, j;
	int A[50][50] = {{0}};
	scanf("%d %d", &f, &c);

	for (i = 0; i < f; i++) {
		for (j = 0; j < c; j++) {
			scanf("%d", &A[j][i]);
			fflush(stdin);
		}
		
	}
	for (i = 0; i < c; i++) {
		for (j = 0; j < f; j++) {
			if(i == c-1 && j == f-1) {
				printf("%d", A[i][j]);
				return 0;
			}
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	return 0;
}

