#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  // initializing variables
  int nA = 0;
  int nB = 0;

  // entering with respect to (w.r.t) the given problem
	printf("Number Status(divisor): Please input two integer numbers..\n");
  scanf("%d%d", &nA, &nB);

  // calculating for solving the given problem
  int nRes = 0;
  if (nB > nA)
  {
    printf("\nCheck: A is a divisor of B: ");
    nRes = (nB) % (nA);
    if (nRes == 0)
      printf("Yes..\n");
    else
      printf("No..\n");
  }
  else
  {
    printf("\nCheck: B is a divisor of A (reverse input): ");
    nRes = (nA) % (nB);
    if (nRes == 0)
      printf("Yes..\n");
    else
      printf("No..\n");    
  }  

  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}