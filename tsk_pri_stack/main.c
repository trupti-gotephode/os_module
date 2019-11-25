#include<stdio.h>
#include"stackheader.h"
#include<stdlib.h>
int MAX = 10;
int arr[10];
int top = -1;
int main()
{

  int input[8];
  int i, in, pri;
  printf("Enter 8 bit binary no.\n");
  scanf("%d", &in);

  for (i = 8; i >= 1; i--)
  {
    input[i] = in % 10;
    in = in / 10;
  }
  for (i = 1; i<9; i++)
  {
    if (input[i] == 1) {
      push(i);
      
    }

  }
  printf("Task to be schedule=%d\n", peek());

  return 0;
}