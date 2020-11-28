#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define N 4

typedef struct 
{
	int n;
	double **elems;
} SquareMatrix;

// calculating the initial square matrix 
SquareMatrix CalcInitSquareMatrix(int n, double elems[n][n]) 
{
	SquareMatrix A = {.n = n, .elems = malloc(n * sizeof(double *))};
	for (int i = 0; i < n; ++i) 
	{
		A.elems[i] = malloc(n * sizeof(double));
		for (int j = 0; j < n; ++j)
			A.elems[i][j] = elems[i][j];
	}
	return A;
}
 
// calculating the copied square matrix
SquareMatrix CopySquareMatrix(SquareMatrix src) 
{
  SquareMatrix dest;
  dest.n = src.n;
  dest.elems = malloc(dest.n * sizeof(double *));
  for (int i = 0; i < dest.n; ++i) 
	{
    dest.elems[i] = malloc(dest.n * sizeof(double));
    for (int j = 0; j < dest.n; ++j)
      dest.elems[i][j] = src.elems[i][j];
  } 
  return dest;
}
 
// calculating the determinant of the given matrix
double CalcDet(SquareMatrix A) 
{
	double det = 1;

	for (int j = 0; j < A.n; ++j) 
	{
		int iMax = j;
		for (int i = j; i < A.n; ++i)
			if (A.elems[i][j] > A.elems[iMax][j])
				iMax = i;

		if (iMax != j) 
		{
			for (int k = 0; k < A.n; ++k) 
			{
				double tmp = A.elems[iMax][k];
				A.elems[iMax][k] = A.elems[j][k];
				A.elems[j][k] = tmp;
			}
			det *= -1;
		}

		if (fabs(A.elems[j][j]) < 1e-12) 
		{
			puts("Singular matrix!");
			return NAN;
		}

		for(int i = j + 1; i < A.n; ++i) 
		{
			double mult = -(A.elems[i][j]) / (A.elems[j][j]);
			for(int k = 0; k < A.n; ++k)
				A.elems[i][k] += mult * A.elems[j][k];
		}
	}

	for(int i = 0; i < A.n; ++i)
		det *= A.elems[i][i];

	return det;
}

// releasing the heap memory 
void ReleaseSquareMat(SquareMatrix A) 
{
  for(int i = 0; i < A.n; ++i)
    free(A.elems[i]);
  free(A.elems);
}

// calculating the simultaneous equation using Crammer`s rule
double CalcCrammerSolver(SquareMatrix A, double det_A, double *b, int var) 
{
  SquareMatrix tmp = CopySquareMatrix(A);
  for(int i = 0; i < tmp.n; ++i)
    tmp.elems[i][var] = b[i];
 
  double det_tmp = CalcDet(tmp);
  ReleaseSquareMat(tmp);
 
  return det_tmp / det_A;
}
 
int main(int argc, char **argv) 
{
  double elems[N][N] = {
    { 2, -1,  5,  1},
    { 3,  2,  2, -6},
    { 1,  3,  3, -1},
    { 5, -2, -3,  3}
  };

  SquareMatrix A = CalcInitSquareMatrix(N, elems);
 
  SquareMatrix tmp = CopySquareMatrix(A);
  int nDetA = CalcDet(tmp);
  ReleaseSquareMat(tmp);
 
  double b[] = {-3, -32, -47, 49};
  for (int i = 0; i < N; ++i)
 	 printf("%7.3lf\n", CalcCrammerSolver(A, nDetA, b, i));
 
  ReleaseSquareMat(A);
  return EXIT_SUCCESS;
}