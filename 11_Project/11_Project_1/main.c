#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI    3.141592
#define R2D   180.0/PI
#define D2R   PI/180.0

int main(void)
{
  // initializing variables
  double dAngDeg = 0.0;  
  double dAngRad = 0.0;

  // interaction: getting some information related to the problem
  printf("Need to enter data(angle in [deg.]):\n");
  scanf("%lf", &dAngDeg);
  printf("Your raw input: %.4lf [deg.]\n", dAngDeg);

  // calculating the converted angle, -180.0[deg.] to +180.0[deg.]
  dAngRad = fmod((dAngDeg * D2R), (2.0 * PI));
  if (dAngRad < -PI)
    dAngRad += 2.0 * PI;
  else if (dAngRad > PI)
    dAngRad -= 2.0 * PI;
  else
    dAngRad = dAngRad;

  // printing the converted result
  printf("Converted: %.4lf [deg.]\n", (dAngRad * (R2D)));
  
  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}