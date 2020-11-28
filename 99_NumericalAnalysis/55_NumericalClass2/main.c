#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define MAXSIZE   63
#define STEPSIZE  0.1
#define PI        3.141592

int main()
{
  // preparing x-axis data
  double dXstate[MAXSIZE] = {};
  dXstate[0] = -PI;
  for (unsigned int i = 0; i < MAXSIZE; i++)
    dXstate[i + 1] = dXstate[i] + STEPSIZE;

  // for debugging
  // for (unsigned int i = 0; i < MAXSIZE; i++)
  //   printf("dXstste[%d]=%.4lf\n", i, dXstate[i]);

  // calculating the position data, y = sin(x)
  double dY[MAXSIZE] = {};
  for (unsigned int i = 0; i < MAXSIZE; i++)
    dY[i] = sin(dXstate[i]);

  // for debugging
  // for (unsigned int i = 0; i < MAXSIZE; i++)
  //   printf("[%d](x, sin(x))=(%.4lf,%.4lf)\n", i, dXstate[i], dY[i]);    

  // calculating the velocity data, y = cos(x), analytical result
  double dYDot[MAXSIZE] = {};
  for (unsigned int i = 0; i < MAXSIZE; i++)
    dYDot[i] = cos(dXstate[i]);

  // calculating the velocity data, backward numerical derivative 
  double dYDotBwd[MAXSIZE] = {};
  for (unsigned int i = 1; i < MAXSIZE; i++)
    dYDotBwd[i] = (sin(dXstate[i]) - sin(dXstate[i] - STEPSIZE))/(STEPSIZE);

  // calculating the velocity data, forward numerical derivative 
  double dYDotFwd[MAXSIZE] = {};
  for (unsigned int i = 0; i < MAXSIZE; i++)
    dYDotFwd[i] = (sin(dXstate[i] + STEPSIZE) - sin(dXstate[i]))/(STEPSIZE);

  // calculating the velocity data, central numerical derivative 
  double dYDotCen[MAXSIZE] = {};
  for (unsigned int i = 0; i < MAXSIZE; i++)
    dYDotCen[i] = (sin(dXstate[i] + STEPSIZE) - sin(dXstate[i] - STEPSIZE))/(2.0 * STEPSIZE);            

  // for debugging
  for (unsigned int i = 0; i < MAXSIZE; i++)
    printf("[%d](x, sin(x),cos(x),bwd,fwd,cen)=(%.4lf,%.4lf,%.4lf,%.4lf,%.4lf,%.4lf)\n", 
            i, dXstate[i], dY[i], dYDot[i], dYDotBwd[i], dYDotFwd[i], dYDotCen[i]);  
    
  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}