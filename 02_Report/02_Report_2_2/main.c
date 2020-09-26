#include <stdio.h>

int main(void)
{
  // initializing variables
  double dWeight = 0.0;
  double dHeight = 0.0;
  double dBmi = 0.0;

  // interaction: getting some information related to the problem
  printf("Need to enter data(order: weight[kg] and height[cm]):\n");
  scanf("%lf%lf", &dWeight, &dHeight);

  // calculating the mbti information
  dBmi = (dWeight) / (dHeight * dHeight);

  // using conditional expression (no need to design the return variable)
  ((dBmi < 20.0) || (dBmi >= 25.0)) ? 
   (printf("MBTI result: You need to manage your weight\n")) : 
   (printf("MBTI result: You have the standard weight status\n"));

  // end of program..
  printf("End of the program..\n");
  return 0;
}