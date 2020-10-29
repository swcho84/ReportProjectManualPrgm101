#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define SIZE    4
#define RANGE   9
#define COM     99
#define PLAYER  100

// generating the seed number using the time clock information
void GenRandSeed()
{
  // generating the random number using the time seed
  srand((unsigned int)(time(NULL)));

  return;
}

// generating the random number, integer type
int GenRandNum(int nRange)
{
  int nRes = 0;
  int nNum = rand();
  nRes = ((int)(nNum) % (nRange));
  return nRes;
}

// generating the random number array, double type
int* GenBballRandNumArr(int *nPtArray, int nSize, int nRange, int nCase)
{
  for (int i = 0; i < nSize; i++)
  {
    switch (nCase)
    {
      case COM:
      {
        *(nPtArray + i) = GenRandNum(nRange);
        break;
      }
      case PLAYER:
      {
        printf("[%d]: ", i);
        scanf("%d", (nPtArray + i));    
        break;
      }
    }

    for (int j = 0; j < i; j++)
    {
      if (*(nPtArray + i) == *(nPtArray + j))
      {
        i--;
      }     
    }      
  }

  return nPtArray;
}

// calculating the strike or ball
int* CalcStrikeBallInfo(int *ptCom, int *ptPlayer)
{
  int nArrayRes[2] = {};
  int *ptRes = nArrayRes;
  int nCountBall = 0;
  int nCountStrike = 0;
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      if (*(ptPlayer + i) == *(ptCom + j))
      {
        if (i == j)
          nCountStrike++;
        else
          nCountBall++;    
      }
    }
  }
  ptRes[0] = nCountStrike;
  ptRes[1] = nCountBall;
  return ptRes;
}

// printing array
void PrintBballNumArr(int *nInput, int nSize)
{
  for (int i = 0; i < nSize; i++)
  {
    printf("BballNumArr[%d]:%d\n", i, nInput[i]);
  }

  printf("\n");
}

int main(void)
{
  // assigning seed
  GenRandSeed(); 

  // for debugging
  printf("Bulls and Cows Game: Start..\n");   

  // assigning random number array for the computer(rejecting the same number)
  int nComBballRandNumArr[SIZE] = {};
  int *nPtComBballRandNumArr = nComBballRandNumArr;
  nPtComBballRandNumArr = GenBballRandNumArr(nPtComBballRandNumArr, SIZE, RANGE, COM);

  // for debugging
  printf("Computer`s number:\n");
  PrintBballNumArr(nPtComBballRandNumArr, (int)(sizeof(nComBballRandNumArr)/sizeof(int)));

  // assigning trial information
  int nTrial = 0;
  printf("How many trial do yo need?: ");
  scanf("%d", &nTrial);

  // main loop
  int nCounter = 0;
  while (1)
  {
    // for showing the game information
    printf("Remain:%d...\n", (nTrial - nCounter));

    // generating random number array for the player
    int nPlayerBballRandNumArr[SIZE] = {};
    int *nPtPlayerBballRandNumArr = nPlayerBballRandNumArr;
    printf("Your Baseball Number, size:%d..\n", SIZE);
    nPtPlayerBballRandNumArr = GenBballRandNumArr(nPtPlayerBballRandNumArr, SIZE, RANGE, PLAYER);

    // for debugging
    printf("Player`s number:\n");
    PrintBballNumArr(nPtPlayerBballRandNumArr, (int)(sizeof(nPlayerBballRandNumArr)/sizeof(int)));

    // calculating the strike or ball
    // ball: is there a same number in the computer`s array?
    // strike: is there a same number in the same index in the computer`s array?
    int nCountStrike, nCountBall = 0;
    int *ptRes = CalcStrikeBallInfo(nPtComBballRandNumArr, nPtPlayerBballRandNumArr);

    // ----------------------------------------------------------------------------------//
    // same rule between array and pointer
    // nCountStrike = *(ptRes + 0);
    // nCountBall = *(ptRes + 1);
    // nCountStrike = ptRes[0];
    // nCountBall = ptRes[1];

    // printing pointer`s memory address w.r.t index, %x: hexadecimal number
    // printf("%x, %x\n", ptRes + 0, ptRes + 1);
    // printf("%x, %x\n", &(ptRes[0]), &(ptRes[1]));

    // printing pointer`s value w.r.t index
    // printf("%d, %d\n", *(ptRes + 0), *(ptRes + 1));
    // printf("%d, %d\n", ptRes[0], ptRes[1]);
    // ----------------------------------------------------------------------------------//

    // printing the game status
    printf("Your Game Status(Strike, Ball):(%d, %d)\n", nCountStrike, nCountBall);

    // game end condition
    if (nCountStrike == SIZE)
    {
      printf("Game end, Player Win...\n");
      break;      
    }
    else
    {
      // calculating the counter
      if (nCounter == nTrial)
      {
        printf("Game end, Computer Win...\n");
        break;
      }
      else
      {
        nCounter++;
      }
    }
  }

  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}