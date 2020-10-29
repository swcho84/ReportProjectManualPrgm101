#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define SIZE      10
#define DESCEND   11
#define ASCEND    22

// swapping number using pointer
void swap(double *ap, double *bp)
{
  double temp;
  temp = *ap;
  *ap = *bp;
  *bp = temp;
}

// sorting function
void line_up(double *maxp, double *midp, double *minp)
{
  if (*maxp < *midp) 
    swap(maxp, midp);
  if (*maxp < *minp) 
    swap(maxp, minp);
  if (*midp < *minp) 
    swap(midp, minp);
}

// challenge problem
void ProbBook()
{
  double max, mid, min;
  printf("실수 세 개 입력 : ");
  scanf("%lf%lf%lf", &max, &mid, &min);
  line_up(&max, &mid, &min);
  printf("정렬: %.1lf, %.1lf, %.1lf\n", max, mid, min);
}

// generating the seed number using the time clock information
void GenRandSeed()
{
  // generating the random number using the time seed
  srand((unsigned int)(time(NULL)));
  return;
}

// generating the random number, integer type
int GenRandIntNum(int nRange)
{
  int nRes = 0;
  int nNum = rand();
  nRes = ((int)(nNum) % (nRange));
  return nRes;
}

// generating the random number, double type
double GenRandDoubleNum()
{
  int nRes = GenRandIntNum(9);
  double dRes = ((double)(nRes)) + (((double)(GenRandIntNum(RAND_MAX)))/RAND_MAX);
  return dRes;
}

// generating the random number array, double type
void GenRandNumArray(double *dPtArrayInput, int nSize)
{
  for (int i = 0; i < nSize; i++)
    dPtArrayInput[i] = GenRandDoubleNum();
}

// generating the size 
int GetSizeInfo()
{
  int nRes = 0;
  while(1)
  {
    printf("Need to enter data(array size): ");
    scanf("%d", &nRes);
    if (nRes > 0)
    {
      printf("Your raw input: %d\n", nRes);
      break;
    }
    else
    {
      printf("Please check your input..\n");
    }    
  }
  return nRes;
}

// sort function: bubble sort (a.k.a. basic sort)
double* CalcBubbleSort(double *dPtArrayInput, int nSize, int nCase)
{
  double *dPtArrayRes;
  double dTemp = 0.0;
  for (int i = 0; i < nSize; i++)
  {
    for (int j = 0; j < (nSize - 1); j++)
    {
      switch (nCase)
      {
        default:
        case DESCEND:
        {
          if (dPtArrayInput[j] < dPtArrayInput[j + 1])
          {
            dTemp = dPtArrayInput[j];
            dPtArrayInput[j] = dPtArrayInput[j + 1];
            dPtArrayInput[j + 1] = dTemp; 
          }
          break;
        }
        case ASCEND:
        {
          if (dPtArrayInput[j] > dPtArrayInput[j + 1])
          {
            dTemp = dPtArrayInput[j];          if (dPtArrayInput[i] < dPtArrayInput[j])
            dPtArrayInput[j] = dPtArrayInput[j + 1];
            dPtArrayInput[j + 1] = dTemp; 
          }
          break;
        }        
      }
    }
  }

  dPtArrayRes = dPtArrayInput;
  return dPtArrayRes;
}

void SortingArray()
{
  double dArray[SIZE] = {};
  double *dPtArray = dArray;
  GenRandNumArray(dPtArray, SIZE); 

  // for debugging
  for (int i = 0; i < SIZE; i++)
    printf("before sorting[%d]:%.4lf\n", i, dPtArray[i]);
  
  // calculating the bubble sort with the option (DESCEND, ASCEND)
  dPtArray = CalcBubbleSort(dPtArray, SIZE, ASCEND);
  printf("\n");

  // for debugging
  for (int i = 0; i < SIZE; i++)
    printf("after sorting[%d]:%.4lf\n", i, dPtArray[i]);   
}

int main(void)
{
  // generating the seed number using the time clock information
  GenRandSeed();

  // challenge problem given by the main book
  // ProbBook();

  // additional problem: sorting array
  // sort problem, random number array, using the defined size data
  SortingArray();

  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}