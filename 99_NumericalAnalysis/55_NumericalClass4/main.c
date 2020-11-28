#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define INTEGSIZE		1.0
#define START		  	1.0
#define END					3.0

double func(double x)
{
	return (x * x);
}

int main()
{
	// assigning variables for the numerical integration
	const int nTotal = (((END - START)/(INTEGSIZE)) + 1);	
	double h = (END - START)/(nTotal - 1);

	// making x-axis states
	double dXstate[nTotal] = {};
	dXstate[0] = START;
	for (unsigned int i = 0; i < nTotal; i++)
		dXstate[i + 1] = dXstate[i] + h;

	// for debugging
	// printf("%d, %lf\n", nTotal, h);
	// for (unsigned int i = 0; i < nTotal; i++)
	// 	printf("[%d]dXstate(%.4lf)\n", i, dXstate[i]);

	// calculating the mid term
	double dSumMidTermTemp = 0.0;
	double dSumMidTerm = 0.0;	
	for (unsigned int i = 1; i < nTotal - 1; i++)
		dSumMidTermTemp += func(dXstate[i]);
	dSumMidTerm = (2.0) * (dSumMidTermTemp);

	// calculating the result
	double dIntegResult = ((0.5) * (h)) * (func(dXstate[0]) + dSumMidTerm + func(dXstate[nTotal - 1]));
	printf("Numerical Integration Result: %.4lf\n", dIntegResult);

  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}