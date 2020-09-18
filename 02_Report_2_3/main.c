#include <stdio.h>

int main(void)
{
  // initializing variables
  int nA, nB = 0;
  int nAdd, nSub, nMul, nRemain = 0;
  float fDiv = 0.0f;

  // interaction: getting some information related to the given problem
  printf("Need to enter data(integer: a and b)\n");
  scanf("%d%d", &nA, &nB);

  // performaing the four fundamental arithmetic operations
  nAdd = nA + nB;
  nSub = nA - nB;
  nMul = nA * nB;
  fDiv = (float)(nA) / (float)(nB);
  nRemain = nA % nB;

  // displaying outputs related to the given problem
  printf("\nYour input:(nA,nB)=(%d,%d)\n", nA, nB);
  printf("Result:\n");
  printf("Addition:       %d + %d = %d\n", nA, nB, nAdd);
  printf("Subtraction:    %d - %d = %d\n", nA, nB, nSub);
  printf("Multiplication: %d * %d = %d\n", nA, nB, nMul);
  printf("Division:       %d / %d = %.4f\n", nA, nB, fDiv);
  printf("Reminder:       %d %% %d = %d\n", nA, nB, nRemain);

  // end of program..
  printf("End of the program..\n");
  return 0;
}