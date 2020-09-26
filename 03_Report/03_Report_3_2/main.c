#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NONE  0
#define ADD	  1
#define SUB	  2
#define MUL	  3
#define DIV	  4
#define MOD	  5

int main(void)
{
  // initializing variables
  int nA = 0;
  int nB = 0;
  int nCase = NONE;
  char cCal;

  // entering with respect to (w.r.t) the given problem
	printf("Four standard calculation:\n");
	int nResScanf = scanf("%d%c%d", &nA, &cCal, &nB);

	if (nResScanf > 0)
	{
	  if (cCal == '+')
		nCase = ADD;
	  else if (cCal == '-')
		nCase = SUB;
	  else if (cCal == '*')
		nCase = MUL;
	  else if (cCal == '/')
		nCase = DIV;
	  else if (cCal == '%')
		nCase = MOD;
	  else
		nCase = NONE;
	}
	else
	{
	  printf("Wrong input: number or symbol..please check..\n");
    
    // related in C of windows (system("pause"))
    int c = getchar();
    return 1;
	}

	switch (nCase)
	{
	  case ADD:  // can use '+' because it can be considered as integer
	  {
		int nRes = nA + nB;
		printf("addition: %d %c %d = %d\n", nA, cCal, nB, nRes);
		break;
	  }
	  case SUB: // can use '-' because it can be considered as integer
	  {
		int nRes = nA - nB;
		printf("subtraction: %d %c %d = %d\n", nA, cCal, nB, nRes);
		break;
	  }
	  case MUL: // can use '*' because it can be considered as integer
	  {
		int nRes = nA * nB;
		printf("multiplication: %d %c %d = %d\n", nA, cCal, nB, nRes);
		break;
	  }
	  case DIV:  // can use '/' because it can be considered as integer
	  {
		float fRes = (float)(nA) / (float)(nB);
		printf("division: %d %c %d = %.4f\n", nA, cCal, nB, fRes);
		break;
	  }
	  case MOD:  // can use '%' because it can be considered as integer
	  {
		int nRes = 0;
		double dRes = 0.0;
		if (nA > nB)
		{
		  nRes = nA % nB;
		  printf("reminder: %d %c %d = %d\n", nA, cCal, nB, nRes);
		}
		else
		{
		  dRes = fmod((double)(nA), (double)(nB));
		  printf("reminder: %d %c %d = %.4f\n", nA, cCal, nB, dRes);
		}
		break;
	  }
	  default:
	  case NONE:
	  {
		printf("Wrong input: not fundamental calculation..please check..\n");
		break;
	  }

	printf("\n");
  }

  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}