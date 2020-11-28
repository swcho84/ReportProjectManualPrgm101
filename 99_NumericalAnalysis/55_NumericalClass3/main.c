#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define MAXSIZE   63
#define DT        0.1
#define PI        3.141592

int main()
{
  // preparing x-axis data
  double dTimestate[MAXSIZE] = {};
  dTimestate[0] = 0.0;
  for (unsigned int i = 0; i < MAXSIZE; i++)
    dTimestate[i + 1] = dTimestate[i] + DT;

  // for debugging
  for (unsigned int i = 0; i < MAXSIZE; i++)
    printf("dTimestate[%d]=%.4lf\n", i, dTimestate[i]);

  // calculating the position data, y = sin(x)
  double dY[MAXSIZE] = {};
  for (unsigned int i = 0; i < MAXSIZE; i++)
    dY[i] = sin(dTimestate[i]);

  // calculating the velocity data, y = cos(x), analytical result
  double dYDot[MAXSIZE] = {};
  for (unsigned int i = 0; i < MAXSIZE; i++)
    dYDot[i] = cos(dTimestate[i]);

  // calculating the velocity data, backward numerical derivative 
  double dYDotBwd[MAXSIZE] = {};
  for (unsigned int i = 1; i < MAXSIZE; i++)
    dYDotBwd[i] = (dY[i] - dY[i - 1])/(DT);    

  // for debugging
  for (unsigned int i = 0; i < MAXSIZE; i++)
    printf("[%d](x, sin(x),cos(x),bwd)=(%.4lf,%.4lf,%.4lf,%.4lf)\n", 
            i, dTimestate[i], dY[i], dYDot[i], dYDotBwd[i]);

  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}