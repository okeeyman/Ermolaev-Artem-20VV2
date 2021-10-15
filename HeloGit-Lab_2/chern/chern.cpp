#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main() {
	
	int n = 10, m = 10, i, j;
	int* a = (int*)malloc(n * m * sizeof(int));

	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < m; j++)
		{
			*(a + i * m + j) = rand() % 10;
			printf("%d ", *(a + i * m + j));
		}
		printf("\n");
	}
}