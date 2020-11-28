#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define MAXSIZE   10

typedef struct 
{
  char *strFp[MAXSIZE];
  int nSizeFp;  
} FileWordStatus;

// checking the file status
int CheckFileStatus(FILE* file)
{
  int nStatus = 1;
  if (file == NULL)
    nStatus = 0;
  return nStatus;
}

// reading data using getline from the txt file
int ParsingLine(FILE* fpIn, char **strRes)
{
  // reading the data
  char *line = NULL;
  size_t len = 0;
  size_t read;

  int nCounter = 0;
  while ((read = getline(&line, &len, fpIn)) != -1) 
  {
    // assigning the string label to the variable
    // using dynamic memory
    char* newstrptr = (char*)(malloc(sizeof(char) * (strlen(line) + 1)));
    char *ptr = strtok(line, "\n");
    while (ptr != NULL)
    {
      strcpy(newstrptr, ptr);
      strRes[nCounter] = newstrptr;
      nCounter++;
      ptr = strtok(NULL, "\n");
    }
  }

  // free heap memory
  free(line);
  return nCounter;
}

// comparing the data (picking the same data)
FileWordStatus ComparingSameData(FileWordStatus fpIn1, FileWordStatus fpIn2)
{
  FileWordStatus fpRes;
  fpRes.nSizeFp = fpIn2.nSizeFp;
  for (unsigned int i = 0; i < fpRes.nSizeFp; i++)
    fpRes.strFp[i] = fpIn2.strFp[i];

  int nCounter = 0;
  while (nCounter < fpIn1.nSizeFp)
  {
    for (unsigned int i = 0; i < fpIn2.nSizeFp; i++)
    {
      if (!strcmp(fpIn1.strFp[nCounter], fpIn2.strFp[i])) 
        fpRes.strFp[i] = "same";
    }
    nCounter++;
  }
  return fpRes;
}

// main loop
int main()
{
  // assigning the file pointer
  FILE* fpIn1; 
  FILE* fpIn2; 
  FILE* fpOut;

  // opening files
  char *strFileIn1 = "a.txt";
  char *strFileIn2 = "b.txt";
  char *strFileOut = "c.txt";
  fpIn1 = fopen(strFileIn1, "r");
  fpIn2 = fopen(strFileIn2, "r");
  fpOut = fopen(strFileOut, "r+");
  
  // checking the file pointer status  
  int nFileStatus = CheckFileStatus(fpIn1) + CheckFileStatus(fpIn2) + CheckFileStatus(fpOut);
  if (nFileStatus != 3)
  {
    printf("Please check file status..\n");
    return -1;
  }
  else
    printf("Success: reading files..\n");  

  // parsing the data, fpIn1
  FileWordStatus fpIn1Status;
  fpIn1Status.nSizeFp = ParsingLine(fpIn1, fpIn1Status.strFp);

  // for debugging
  printf("\nResult: reading the file pointer info(fpIn1):\n");
  for(unsigned int i = 0; i < fpIn1Status.nSizeFp; i++)
    printf("[%d]%s\n", i, fpIn1Status.strFp[i]);

  // parsing the data, fpIn2
  FileWordStatus fpIn2Status;
  fpIn2Status.nSizeFp = ParsingLine(fpIn2, fpIn2Status.strFp);

  // for debugging
  printf("\nResult: reading the file pointer info(fpIn2):\n");
  for(unsigned int i = 0; i < fpIn2Status.nSizeFp; i++)
    printf("[%d]%s\n", i, fpIn2Status.strFp[i]);

  // comparing the data (picking the same data)
  FileWordStatus fpOutStatus;
  fpOutStatus = ComparingSameData(fpIn1Status, fpIn2Status);

  // for debugging
  printf("\nResult: comparing the file pointer info(fpIn1 and fpIn2):\n");
  for(unsigned int i = 0; i < fpOutStatus.nSizeFp; i++)
    printf("[%d]%s\n", i, fpOutStatus.strFp[i]);

  // writing the data (others)
  printf("\nResult: printout (fpOut):\n");  
  for (unsigned i = 0; i < fpOutStatus.nSizeFp; i++)
  {
    if (abs(strcmp(fpOutStatus.strFp[i], "same")) > 0)
    {
      printf("[%d]%s\n", i, fpOutStatus.strFp[i]);
      fprintf(fpOut, "%s\n", fpOutStatus.strFp[i]);
    }
  }  

  // closing files
  fclose(fpIn1);
  fclose(fpIn2);
  fclose(fpOut);    

  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}
