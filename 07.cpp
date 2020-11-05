#include "stdio.h"

int main()
{
  int max = 10, a;
  int data[10];
  data[0] = 20;

  printf("data ke 0 adalah %d \n", data[0]);

  for (a = 9; a >= 0; a--)
  {
    printf("Masukan data ke %d ", a);
    scanf("%d\n", &data[a]);
  }

  printf("\n================\n");
  for (a = 0; a <= 9; a++)
  {
    printf("Data ke %d adalah %d \n", a, data[a]);
  }

  return 0;
}