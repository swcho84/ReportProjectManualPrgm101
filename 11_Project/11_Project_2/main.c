#include <stdio.h>
#include <stdlib.h>

#define JAN   1
#define FEB   2
#define MAR   3
#define APR   4
#define MAY   5
#define JUN   6
#define JUL   7
#define AUG   8
#define SEP   9
#define OCT   10
#define NOV   11
#define DEC   12

int main(void)
{
  // initializing variables
  int nMonth = 0;

  // interaction: getting some information related to the problem
  printf("Need to enter data(Month, 1~12):\n");
  scanf("%d", &nMonth);

  // calculating the season w.r.t the month
  printf("Your raw input: %d\n", nMonth);
  switch (nMonth)
  {
    case MAR:
    case APR:
    case MAY:
    {
      printf("Output: Spring..\n");
      break;
    }
    case JUN:
    case JUL:
    case AUG:
    {
      printf("Output: Summer..\n");
      break;
    }
    case SEP:
    case OCT:
    case NOV:
    {
      printf("Output: Autumn..\n");
      break;
    }
    case DEC:
    case JAN:
    case FEB:
    {
      printf("Output: Winter..\n");
      break;
    }
    default:
    {
      printf("Please check your input..\n");
      break;
    }
  }
  
  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}