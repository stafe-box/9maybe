#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void zapol(int n, int m, int a[][m])
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            a[i][j] = rand() % 100;
}

void printmassiv(int n, int m, int a[][m])
{
  for(int i = 0; i < n; i++)
  {
      for(int j = 0; j < m; j++)
          printf("%*u ", 3, a[i][j]);
      printf("\n");
  }
}

int norma(int n, int m, int a[][m])
{
    int sum = 0;
      for(int i = 0; i < n; i++)
      {
          for(int j = 0; j < m; j++)
              sum += a[i][j] * a[i][j];
      }
    return sum;
}

int main()
{
    srand(time(NULL));
    unsigned int n = 0, m = 0;
    printf("Введите количество строк: ");
    scanf("%u", &n);
    printf("Введите количество столбцов: ");
    scanf("%u", &m);
    int a[n][m];
    zapol(n, m, a);
    printmassiv(n, m, a);
    printf("Норма Фробениуса равна: %d\n", norma(n, m, a));
    return 0;
}
