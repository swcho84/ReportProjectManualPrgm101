#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  // initializing variables
  int nYear = 0;

  // interaction: getting some information related to the problem
  printf("Need to enter data(Year):\n");
  scanf("%d", &nYear);  

  // calculating to determine if the inpus is a leap year
  printf("Your raw input: %d\n", nYear);
  if (((nYear % 4 == 0) && (nYear % 100 != 0)) || 
      (nYear % 400 == 0))
	  printf("Output: leap year\n");
  else
  	printf("Output: not leap year\n");
  
  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}