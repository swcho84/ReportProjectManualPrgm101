#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  // initializing variables  
  int nNumStar = 0;
  int nRow = 0;

  // main loop
  while (1)
  {
    // interaction: getting some information related to the problem
    printf("Need to enter data(number of the star and the row): ");
    scanf("%d%d", &nNumStar, &nRow);
    printf("Your raw input(nNumStar, nRow):(%d, %d)\n", nNumStar, nRow);

    // calculating the star-in-row
    if (nNumStar < nRow)
    {
      // asserting the wrong input and re-interaction
      printf("Please check your input..try again..\n");
      continue;      
    }
    else
    {
      // calculating the number of line
      int nNumStarLine = nNumStar / nRow;
      int nNumStarRem = nNumStar % nRow;

      // zero remainder: normal case
      if (nNumStarRem == 0)
      {
        for (int i = 0; i < nRow; i++)
        {
          for (int j = 0; j < nNumStarLine; j++)
          {
            printf("*");
          }
          printf("\n");
        }
      }
      else
      {
        // non-zero remainder: adding remainder in the last row
        for (int i = 0; i < nRow; i++)
        {
	        if (i != nRow - 1)
	        {           
            for (int j = 0; j < nNumStarLine; j++)
            {
              printf("*");
            }
            printf("\n");
          }
          else
          {
            for (int j = 0; j < (nNumStarLine + nNumStarRem); j++)
            {
              printf("*");
            }
            printf("\n");            
          }
        }
      }

      // success: ending program
      break;
    }
  }

  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}