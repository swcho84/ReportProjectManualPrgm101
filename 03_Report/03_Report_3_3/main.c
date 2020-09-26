#include <stdio.h>
#include <stdlib.h>

#define REFEVENUM  2
#define ZERONUM    0

int main(void)
{
  // initializing variables
  int nA = 0;
  int nB = 0;

  // entering with respect to (w.r.t) the given problem
	printf("Number Status(Even/Odd): Please input two integer numbers..\n");
  scanf("%d%d", &nA, &nB);

  // calculating for solving the given problem
  int nResA = (nA) % (REFEVENUM);
  int nResB = (nB) % (REFEVENUM);
  int nResTotal = nResA + nResB;

  switch (nResTotal)
  {
    case ZERONUM:
    {
      printf("A = %d, B = %d, All numbers are even..\n", nA, nB);  
      break;
    }
    default:
    {
      if ((nResA != 0) && (nResB == 0))
      {
        printf("A = %d, B = %d, A is odd number and B is even number..\n", nA, nB);  
      }
      else
      {
        printf("A = %d, B = %d, A is even number and B is odd number..\n", nA, nB);  
      }
      break;
    }

  }
  
  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}