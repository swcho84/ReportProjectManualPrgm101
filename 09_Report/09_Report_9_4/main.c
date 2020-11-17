#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAXLENGTH   100

typedef struct
{
  char chInfo;
  int nCount;
} CharUsage;

// assigning the string input from the user
char* GetString()
{
  char* strRes = (char*)(malloc(sizeof(char) * (MAXLENGTH)));
  scanf("%s", strRes);
  printf("Raw Input: %s\n\n", strRes);
  return strRes;
}

// calculating the character usage
int* CalcNumChar(char* strInput)
{
  int nStrLength = strlen(strInput);
  int* pnRes = (int*)(malloc(sizeof(int) * (nStrLength)));
  for (int i = 0; i < nStrLength; i++)
  {
    // for debugging
    // printf("strInput[%d]:%c\n", i, strInput[i]);

    // counting the result w.r.t the character
    pnRes[strInput[i]]++;
  }
  return pnRes;
}

// showing the output, small case
int PrintResultSmallCase(int* nInput)
{
  int nRes = 0;  
  printf("count result, small case:\n");
  for (int i = 'a'; i < 'z'; i++)
  {
    if (nInput[i] > 0)
    {
      printf("(character, num.):(%c,%d)\n", i, nInput[i]);
      nRes++;
    }
  }
  printf("\n");
  return nRes;
}

// showing the output, large case
int PrintResultLargeCase(int* nInput)
{
  int nRes = 0;
  printf("count result, large case:\n");
  for (int i = 'A'; i < 'Z'; i++)
  {
    if (nInput[i] > 0)
    {
      printf("(character, num.):(%c,%d)\n", i, nInput[i]);
      nRes++;
    }
  }
  printf("\n");
  return nRes;
}

// refining the result
CharUsage* RefineNumCharResult(int* nInput, int nTotalSize)
{
  CharUsage* resStruct = (CharUsage*)(malloc(sizeof(CharUsage) * nTotalSize));
  int nSize = 0;

  // for small case, only nonzero input
  for (int i = 'a'; i < 'z'; i++)
  {
    if (nInput[i] > 0)
    {
      resStruct[nSize].chInfo = (i);
      resStruct[nSize].nCount = nInput[i];
      nSize++;
    }
  }

  // for large case, only nonzero input
  for (int i = 'A'; i < 'Z'; i++)
  {
    if (nInput[i] > 0)
    {
      resStruct[nSize].chInfo = (i);
      resStruct[nSize].nCount = nInput[i];
      nSize++;
    }
  }

  // sorting the result, w.r.t the descending order
  CharUsage temp;
  for (int i = 0; i < nTotalSize; i++)
  {
    for (int j = 0; j < (nTotalSize - 1); j++)
    {
      if (resStruct[j].nCount < resStruct[j + 1].nCount)
      {
        temp = resStruct[j];
        resStruct[j] = resStruct[j + 1];
        resStruct[j + 1] = temp;
      }
    }
  }

  return resStruct;
}

int main()
{
  // interaction: getting some information related to the problem
  printf("Need to enter data(string): ");
  char* strRawData = (char*)(malloc(sizeof(char) * (MAXLENGTH)));
  strRawData = GetString();
  
  // calculating the character usage
  int* nCharInfo = (int*)(calloc(strlen(strRawData), sizeof(int)));
  nCharInfo = CalcNumChar(strRawData);

  // showing the output, small case
  int nTotalSize = 0;
  nTotalSize += PrintResultSmallCase(nCharInfo);
  nTotalSize += PrintResultLargeCase(nCharInfo);

  // rearranging the result into the structure
  CharUsage* structCharInfo = (CharUsage*)(malloc(sizeof(CharUsage) * nTotalSize));
  structCharInfo = RefineNumCharResult(nCharInfo, nTotalSize);

  // for debugging
  printf("refined result:\n");
  for (int i = 0; i < nTotalSize; i++)
    printf("structCharInfo[%d](char,count):(%c,%d)\n", i, structCharInfo[i].chInfo, structCharInfo[i].nCount);

  // deleting the heap memory
  free(strRawData);
  free(nCharInfo);
  free(structCharInfo);

  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}