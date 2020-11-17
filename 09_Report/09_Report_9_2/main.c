#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int main()
{
  char strWord;   
  int nLength = 0; 
  int nMaxLength = 0;

  while (1)
  {
    nLength = 0;
    scanf("%c", &strWord);

    while ((strWord != '\n') && (strWord != EOF))
    {
      nLength++;
      strWord = getchar();
    }

    if (strWord == EOF) 
      break;

    if (nLength > nMaxLength)
      nMaxLength = nLength;

    printf("(Word Length, Max Length):(%d, %d)\n", nLength, nMaxLength);
  }
  printf("Length of longest word : %d\n", nMaxLength);
  
  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}