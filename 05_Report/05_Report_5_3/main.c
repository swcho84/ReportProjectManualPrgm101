#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define COINSIDE        2
#define COINFRONTSIDE   1
#define COINBACKSIDE    0

// generating the seed number using the time clock information
void GenRandSeed()
{
  // generating the random number using the time seed
  srand((unsigned int)(time(NULL)));
  return;
}

// generating the random number
int GenRandNum(int nRange)
{
  int nRes = 0;
  int nNum = rand();
  nRes = ((int)(nNum) % (nRange));
  return nRes;
}

// generating the coin toss result, for computer
int GenCoinToss()
{
  int nRes = 0;
  nRes = GenRandNum(COINSIDE);
  return nRes;
}

// generating the coin toss result, player 
int GetCoinToss()
{
  int nRes = 0;
  while(1)
  {
    printf("Need to enter data(coin toss, 0: backside, 1: frontside): ");
    scanf("%d", &nRes);
    if ((nRes == COINBACKSIDE) || (nRes == COINFRONTSIDE))
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

// generating the continue flag
int GetContinueFlag()
{
  int nRes = 0;
  while(1)
  {
    printf("Continue?(0: exit, 1:continue): ");
    scanf("%d", &nRes);

    if ((nRes == 0) || (nRes == 1))
    {
      break;
    }
    else
    {
      printf("Please check your input..\n");
    }
  }
  printf("\n");
  return nRes;  
}

// printing result
void PrintCoinResult(int nPlayerRes, int nComRes)
{
  if (nPlayerRes == COINFRONTSIDE)
    printf("Status, Player: FrontSide\n");
  else
    printf("Status, Player: BackSide\n");

  if (nComRes == COINFRONTSIDE)
    printf("Status, Computer: FrontSide\n");
  else
    printf("Status, Computer: BackSide\n");   
}

int main(void)
{
  // assigning seed
  GenRandSeed();

  // main loop
  while (1)
  {
    // generating the coin toss result, computer
    int nComCoinToss = GenCoinToss();

    // generating the coin toss result, player
    int nPlayerCoinToss = GetCoinToss();

    // comparing the result
    PrintCoinResult(nPlayerCoinToss, nComCoinToss);
    if (nComCoinToss == nPlayerCoinToss)
      printf("Same result, Win: Player, Lose: Computer\n");
    else
      printf("Diff. result, Win: Computer, Lose: Player\n");

    // generating the continue flag
    if (GetContinueFlag() == 0)
      break; 
  }

  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}