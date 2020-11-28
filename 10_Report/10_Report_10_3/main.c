#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

int main()
{
  // initializing variables
  int nDefaultSize = 3;
  int ncurrIdx = 0;
  int nDeltaSize = 3;
  int nFinalSize = 0;

  // initializing the double-type array
  double* dDynamicArray = (double*)calloc(nDefaultSize, sizeof(double));

  // gathering the data with the arbitrary size array
  while (1)
  {
    double dNum = 0.0;
    printf("Input your floating number(defaultSize:%d, currIdx:%d):\n", nDefaultSize, ncurrIdx);
    scanf("%lf", &dNum);

    // increasing size with the continue flag
    if ((ncurrIdx + 1) == nDefaultSize)
    {
      char chrDecision;
      getchar();
      printf("Continue(y or n): ");
      scanf("%c", &chrDecision);
      if (chrDecision == 'y')
      {
        nDefaultSize += nDeltaSize;
        dDynamicArray = (double*)realloc(dDynamicArray, (nDefaultSize * sizeof(double)));
      }
      else
      {
        nFinalSize = ncurrIdx + 1;
        break;
      }
    }

    // saving data
    dDynamicArray[ncurrIdx] = dNum;

    // for debugging
    printf("\nCurrent status:\n");
    for (unsigned int i = 0; i < (ncurrIdx + 1); i++)
      printf("[%d] %.4lf\n", i, dDynamicArray[i]);

    // increasing the index
    ncurrIdx++;  
  }

  // calculating the summation result
  double dSum = 0;
  for (unsigned int i = 0; i < nFinalSize; i++)
    dSum += dDynamicArray[i];
  printf("Result(total summation): %.4lf\n", dSum);

  // releasing the heap memory
  free(dDynamicArray);

  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}