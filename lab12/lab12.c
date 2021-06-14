#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct rep
{
    int status;
    char name[40];
    char marka[60];
    char model[60];
    int price;
} repairs;

void init_repairs(int n, repairs *name)
{
  for (int i = 0; i < n; i++)
      name[i].status = 0;
}

void fill(int n, repairs *name)
{
    char v4[2];
    char v1[40];
    char v2[60];
    char v3[60];
    int k = 0, t = 0;
    for (int i = 0; i < n; i++)
    {
        if (!name[i].status)
            t = i;
        else
            k++;
    }
    if (k != n)
    {
        if (!name[t].status)
        {
            memset(v1, 0, sizeof(v1));
            memset(v2, 0, sizeof(v2));
            memset(v3, 0, sizeof(v3));
            name[t].status = 1;
            fgets(v4, 2, stdin);
            printf("\nВведите наименование запчасти -> ");
            fgets(v1, 40, stdin);
            for (int t = 0; t < 40; t++)
            {
                if (v1[t] == 0x20)
                    v1[t] = 0x5f;
                v1[t] = tolower(v1[t]);
            }
            strcpy(name[t].name, v1);
            printf("Введите наименование марки -> ");
            fgets(v2, 60, stdin);
            for (int t = 0; t < 60; t++)
            {
                if (v2[t] == 0x20)
                    v2[t] = 0x5f;
                v2[t] = tolower(v2[t]);
            }
            strcpy(name[t].marka, v2);
            printf("Введите наименование модели-> ");
            fgets(v3, 60, stdin);
            for (int t = 0; t < 60; t++)
            {
                if (v3[t] == 0x20)
                    v3[t] = 0x5f;
                v3[t] = tolower(v3[t]);
            }
            strcpy(name[t].model, v3);
            printf("Введите стоимость запчасти -> ");
            scanf("%d", &name[t].price);
        }
        else
            printf("Нет свободного места! Удалите одну из существующих записей\n");
  }
}

void remove_repairs(int n, repairs *name)
{
    name[n].status = 0;
}

void printstr(int n, repairs *name)
{
    for (int i = 0; i < n; i++)
    {
        if (name[i].status)
        {
            printf("--------------------------------------------------\n");
            printf("Название запчасти №%d = %s\n", i, name[i].name);
            printf("Название марки №%d = %s\n", i, name[i].marka);
            printf("Название модели №%d = %s\n", i, name[i].model);
            printf("Цена запчасти: %d\n", name[i].price);
        }
    }
}

void print1str(int i, repairs *name)
{
    printf("--------------------------------------------------\n");
    printf("Название запчасти №%d = %s\n", i, name[i].name);
    printf("Название марки №%d = %s\n", i, name[i].marka);
    printf("Название модели №%d = %s\n", i, name[i].model);
    printf("Цена запчасти: %d\n", name[i].price);
}

int check(int i, repairs *name)
{
    char v1[] = "lada";
    char v2[] = "vesta_cross_sw";
    if (!strcmp(name[i].marka, v1) && !strcmp(name[i].model, v2))
        return 1;
    else
        return 0;
}

void read_repairs(int n, repairs *name)
{
    FILE* repairs_list = fopen("repairs_list.txt", "r");
    if (repairs_list == NULL)
        printf("Файла со списком магазинов не существует\n");
    else
    {
        for(int i = 0; i < n; i++)
            fscanf(repairs_list, "%d %s %s %s %d \n", &name[i].status, name[i].name, name[i].marka, name[i].model, &name[i].price);
        fclose(repairs_list);
    }
}

void write_repairs(int n, repairs *name)
{
    FILE* repairs_list = fopen("repairs_list.txt", "w");
    for (int i = 0; i < n; i++)
    {
        if (name[i].status)
        fprintf(repairs_list, "%d %s %s %s %d \n", name[i].status, name[i].name, name[i].marka, name[i].model, name[i].price);
    }
    fclose(repairs_list);
}

int main()
{
  int n = 10, l = 0;
  unsigned int k = 5;
  repairs test[n];
  init_repairs(n, test);
  read_repairs(n, test);
  //repairs test1 = {1, "колесо", "lada", "vesta_sw_cross", 1000};
  //test[0] = test1;
  //repairs test2 = {1, "стекло", "lada", "vesta_sw_cross", 2000};
  //test[1] = test2;
  //repairs test3 = {1, "колесо", "ford", "model_t", 1000};
  //test[2] = test3;
  while(k != 255)
  {
      printf("----------------------\n  Выберите операцию:\n1:Просмотр всего списка запчастей\n2:Добавление запчасти\n3:Удаление запчасти\n4:Просмотр запчастей lada vesta cross sw\n5:Закрыть программу\n----------------------\n");
      scanf("%d", &k);
      if (k > 5)
          printf("Введена неверная операция!\n");
      else
      {
          switch(k)
          {
              case 1:
                  printstr(n,test);
                  break;
              case 2:
                  fill(n,test);
                  break;
              case 3:
                  printf("Впишите номер удаляемой запчасти: \n");
                  scanf("%d", &l);
                  remove_repairs(l,test);
                  break;
              case 4:
                  for(int i = 0; i < n; i++)
                      if(check(i, test))
                          print1str(i, test);
                  break;
              case 5:
                  k = 255;
                  break;
          }
      }
      if (k != 255)
          k = 0;
  }
  write_repairs(n, test);
  return 0;
}
