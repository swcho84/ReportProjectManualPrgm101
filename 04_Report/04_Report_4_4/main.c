#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  // initializing variables  
  int nA = 0;
  int nB = 0;

  // interaction: getting some information related to the problem
  printf("Need to enter data(two numbers): ");
  scanf("%d%d", &nA, &nB);
  printf("Your raw input:(%d, %d)\n", nA, nB);

  // calculating the start and end number
  int nNumStart = 0;
  int nNumEnd = 0;
  if (nA <= nB)
  {
    nNumStart = nA;
    nNumEnd = nB;
  }
  else
  {
    nNumStart = nB;
    nNumEnd = nA;      
  }

  // calculating the summation between the start and end number
  int nSum = 0;
  printf("Parameter(start, end):(%d, %d)\n", nNumStart, nNumEnd);
  for (int i = nNumStart; i <= nNumEnd; ++i)
  {
    if (i < nNumEnd)
      printf("%d + ", i);
    else
      printf("%d = ", i);
    nSum += i;
  }

  // success: output and exit loop
  printf("\nnSum:%d\n", nSum);

  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}