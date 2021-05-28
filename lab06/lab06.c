#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void zapol(int k, int a[])
{
    for(int i = 0; i < k; i++)
        a[i] = rand() % 100;
}

void printmassiv(int k, int a[])
{
    for (int i = 0; i < k; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int check(int n, int a[])
{
  int z = 0, p;
  for(int i = 0; i < n; i++)
  {
      p = 0;
      for(int k = 2; k < a[i]; k++)
      {
          if (a[i] % k == 0)
              p++;
      }
      if (!p)
          z++;
  }
  return z;
}
int check1(int a)
{
    int k = 0, o = 0;
    for(k = 2; k < a; k++)
    {
        if ((a % k) == 0)
            o++;
    }
    if (!o)
        return 1;
    else
        return 0;
}

void zadacha(int n, int l, int a[])
{
    int i = 0, p = 0, u = 0, h = 0;
    switch(l)
    {
      case 0:
          break;
      case 1:
          for(i = 0; i < n; i++)
          {
              if (check1(a[i]) == 1)
                  printf("Простое число: %d\n", a[i]);
          }
          break;
      case 2:
          for(i = 0; i < n; i++)
          {
              if ((check1(a[i]) == 1) && !p)
                  p = i;
              if ((check1(a[i]) == 1) && p)
                  h = i;
          }
          u = a[p];
          a[p] = a[h];
          a[h] = u;
          break;
      default:
          printf("Индексы простых элементов: ");
          for(i = 0; i < n; i++)
          {
              if (check1(a[i]))
                  printf("%d, ", i);
          }
          printf("\n");
          break;
    }
}

int main()
{
  srand(time(NULL));
  int n, l;
  printf("Введите количество элементов в массиве: \n");
  scanf("%d", &n);
  int a[n];
  zapol(n, a);
  printf("Исходный массив:\n");
  printmassiv(n, a);
  l = check(n, a);
  printf("В массиве %d простых чисел\n", l);
  zadacha(n, l, a);
  printmassiv(n, a);
  return 0;
}
