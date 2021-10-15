#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <windows.h>



void shell(int* items, int count)
{

    int i, j, gap, k;
    int x, a[5];

    a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

    for (k = 0; k < 5; k++) {
        gap = a[k];
        for (i = gap; i < count; ++i) {
            x = items[i];
            for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
                items[j + gap] = items[j];
            items[j + gap] = x;
        }
    }
}

void qs(int* items, int left, int right) //����� �������: qs(items, 0, count-1);
{
    int i, j;
    int x, y;



    i = left; j = right;

    /* ����� ���������� */
    x = items[(left + right) / 2];

    do {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j);
    if (i < right) qs(items, i, right);
}


int compare(const void* x1, const void* x2)   // ������� ��������� ��������� �������
{
    return (*(int*)x1 - *(int*)x2);              // ���� ��������� ��������� ����� 0, �� ����� �����, < 0: x1 < x2; > 0: x1 > x2
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));


    int* mass;
    int i, n = 100000;
    mass = (int*)malloc(n * sizeof(int));

    clock_t start, end;

    printf("\n���������� �� ��������� ������ �������� �������.\n\n");

    printf("�������� �����:");
    for (i = 0; i < n; i++)
    {
        mass[i] = rand() % 100;
    }
    start = clock();
    shell(mass, n);
    end = clock();
    printf("%f second(s)", ((double)end - start) / ((double)CLOCKS_PER_SEC));

    printf("\n�������� ������� ����������: ");
    for (i = 0; i < n; i++)
    {
        mass[i] = rand() % 10;
    }
    start = clock();
    qs(mass, 0, n - 1);
    end = clock();
    printf("%f second(s)", ((double)end - start) / ((double)CLOCKS_PER_SEC));

    printf("\n����������� ������� ���������� qsort: ");
    for (i = 0; i < n; i++)
    {
        mass[i] = rand() % 10;
    }
    start = clock();
    qsort(mass, n, sizeof(int), compare);
    end = clock();
    printf("%f second(s)", ((double)end - start) / ((double)CLOCKS_PER_SEC));
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("\n\n���������� ������a, ��������������� ����� ������������ ������������������ �����.\n\n");

    printf("�������� �����:");
    mass[0] = rand() % 10;
    for (i = 1; i < n; i++)
    {
        mass[0]++;
        mass[i] = mass[0];
    }
    start = clock();
    shell(mass, n);
    end = clock();
    printf("%f second(s)", ((double)end - start) / ((double)CLOCKS_PER_SEC));

    printf("\n�������� ������� ����������: ");
    mass[0] = rand() % 10;
    for (i = 1; i < n; i++)
    {
        mass[0]++;
        mass[i] = mass[0];
    }
    start = clock();
    qs(mass, 0, n - 1);
    end = clock();
    printf("%f second(s)", ((double)end - start) / ((double)CLOCKS_PER_SEC));

    printf("\n����������� ������� ���������� qsort: ");
    mass[0] = rand() % 10;
    for (i = 1; i < n; i++)
    {
        mass[0]++;
        mass[i] = mass[0];
    }
    start = clock();
    qsort(mass, n, sizeof(int), compare);
    end = clock();
    printf("%f second(s)", ((double)end - start) / ((double)CLOCKS_PER_SEC));
    
    ////////////////////////////////////////////////////////////////////////////////////////////////

    printf("\n\n���������� ������a, ��������������� ����� ��������� ������������������ �����.\n\n");

    printf("�������� �����:");
    mass[0] = rand() % 100;
    for (i = 1; i < n; i++)
    {
        mass[0]--;
        mass[i] = mass[0];
    }
    start = clock();
    shell(mass, n);
    end = clock();
    printf("%f second(s)", ((double)end - start) / ((double)CLOCKS_PER_SEC));

    printf("\n�������� ������� ����������: ");
    mass[0] = rand() % 100;
    for (i = 1; i < n; i++)
    {
        mass[0]--;
        mass[i] = mass[0];
    }
    start = clock();
    qs(mass, 0, n - 1);
    end = clock();
    printf("%f second(s)", ((double)end - start) / ((double)CLOCKS_PER_SEC));

    printf("\n����������� ������� ���������� qsort: ");
    mass[0] = rand() % 100;
    for (i = 1; i < n; i++)
    {
        mass[0]--;
        mass[i] = mass[0];
    }
    start = clock();
    qsort(mass, n, sizeof(int), compare);
    end = clock();
    printf("%f second(s)", ((double)end - start) / ((double)CLOCKS_PER_SEC));


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////

    printf("\n\n���������� ������a, ���� �������� �������� ������������\n ����� ������������ ������������������ �����, � ������, � ���������.\n\n");

    printf("�������� �����:");
    mass[0] = rand() % 10;
    for (i = 1; i < n / 2; i++)
    {
        mass[0]++;
        mass[i] = mass[0];
    }
    for (i = n / 2; i < n; i++)
    {
        mass[0]--;
        mass[i] = mass[0];
    }
    start = clock();
    shell(mass, n);
    end = clock();
    printf("%f second(s)", ((double)end - start) / ((double)CLOCKS_PER_SEC));

    
    printf("\n����������� ������� ���������� qsort: ");
    mass[0] = rand() % 100;
    for (i = 1; i < n; i++)
    {
        mass[0]--;
        mass[i] = mass[0];
    }
    start = clock();
    qsort(mass, n, sizeof(int), compare);
    end = clock();
    printf("%f second(s)", ((double)end - start) / ((double)CLOCKS_PER_SEC));

    printf("\n�������� ������� ����������: ");
    mass[0] = rand() % 100;
    for (i = 1; i < n / 2; i++)
    {
        mass[0]++;
        mass[i] = mass[0];
    }
    for (i = n / 2; i < n; i++)
    {
        mass[0]--;
        mass[i] = mass[0];
    }
    start = clock();
    qs(mass, 0, n-1);
    end = clock();
    printf("%f second(s)", ((double)end - start) / ((double)CLOCKS_PER_SEC));

    printf("\n");
    _getch();
}