#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include<windows.h>




int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);	

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	clock_t start, end; // объявляем переменные для определения времени выполнения

	int i = 0, j = 0, r, n, m, elem_c,  g_mass=0;
	double mass[6];

	for (m = 0; m < 6; m++) {

		printf("Size n*n, n = ");
		scanf_s("%d", &n);

		start = clock();

		printf("Col = %d\n", n);
		printf("Row = %d\n", n);

		int* a = (int*)malloc(n * n * sizeof(int));
		int* b = (int*)malloc(n * n * sizeof(int));
		int* c = (int*)malloc(n * n * sizeof(int));

		srand(time(NULL)); // инициализируем параметры генератора случайных чисел

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				*(a + i * n + j) = rand() % 10;
			}
		}

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				*(b + i * n + j) = rand() % 10;
			}
		}

		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				elem_c = 0;
				for (r = 0; r < n; r++)
				{
					elem_c = elem_c + *(a + i * n + r) * *(b + r * n + j);
					*(c + i * n + j) = elem_c;
				}
			}
		}

		free(a);
		free(b);
		free(c);

		

		end = clock();

		mass[g_mass] = ((double)end - start) / ((double)CLOCKS_PER_SEC);

		printf("\n %f second(s)\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
		g_mass++;
	}
	FILE* file;
	file = fopen("data.txt", "w");
	for (i = 0; i < 6; i++)
	{
		fprintf(file, "%f", mass[i]);
		fprintf(file, "\n");
	}
	return(0);
}
