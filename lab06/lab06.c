#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void zapol(int k, unsigned int a[])
{
    for(int i = 0; i < k; i++)
        a[i] = rand() % 100;
}

void printmassiv(int k, unsigned int a[])
{
    for (int i = 0; i < k; i++)
        printf("%u ", a[i]);
    printf("\n");
}

int check(int n, unsigned int a[])
{
    int sl = 0, k = 0;
    for (int i = 0; i < n; i++)
    {
        sl = 0;
        if (a[i] > 1)
        {
          for(int j = 2; j < a[i]; j++)
              if (a[i] % j == 0)
                  sl++;
        }
        else
            sl++;
        if (!sl)
            k++;
    }
    return k;
}

int check1(int n)
{
    if (n > 1)
    {
      for (int i = 2; i < n; i++)
          if (n % i == 0)
              return 0;
      return 1;
    }
    else
        return 0;
}

void zadacha(int n, int k, unsigned int a[], unsigned int b[])
{
    int l = 0;
    switch (k)
    {
      case 0:
          break;
      case 1:
          for(int i = 0; i < n; i++)
          {
              if (check1(a[i]) == 1)
                  printf("В массиве только один простой элемент: %d\n", a[i]);
          }
          break;
      case 2:
          for(int i = 0; i < n; i++)
          {
              if (check1(a[i]) == 1 && !k)
                  k = i;
              if (check1(a[i]) == 1 && !l)
              {
                  l = a[i];
                  a[i] = a[k];
                  a[k] = l;
                  l = 1;
              }
              printf("Элементы поменялись местами\n", );
          }
          break;
      default:
          printf("В массиве более 3-х простых элементов\n", );
          break;
    }
}

int main()
{
    int n = 0;
    srand(time(NULL));
    printf("Введите количество элементов в массиве: ");
    scanf("%d", &n);
    unsigned int a[n], b[n];
    unsigned int l = 0;
    zapol(n, a);
    printmassiv(n, a);
    l = check(n, a);
    zadacha(n, l, a, b);
    printmassiv(n, a);
    printf("\nКол-во символов: %d\n", l);
    return 0;
}
