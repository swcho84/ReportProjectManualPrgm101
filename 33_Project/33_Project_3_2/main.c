#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define SIZE_VEC_LINE_INFO    4

// gathering line information
double* GetPlaneLineInfo()
{
  double dSlope, dBias = 0.0;
  printf("Need to enter data(planar line data, slope and bias):\n");
  scanf("%lf%lf", &dSlope, &dBias);

  printf("Your planar line info(slope, bias):(%.4lf, %.4lf)\n", dSlope, dBias);

  double dXaxisInterCept = (-dBias)/(dSlope);
  double dYaxisInterCept = dBias;
  double dVecXcomp = -dXaxisInterCept;
  double dVecYcomp = dYaxisInterCept;
  double dVecNorm = sqrt((dVecXcomp) * (dVecXcomp) + (dVecYcomp) * (dVecYcomp));

  double dOutput[SIZE_VEC_LINE_INFO] = {(dVecXcomp/dVecNorm), (dVecYcomp/dVecNorm), dXaxisInterCept, 0.0};
  double *pdOutput = malloc(sizeof(double) * (SIZE_VEC_LINE_INFO));
  for (int i = 0; i < SIZE_VEC_LINE_INFO; i++)
    pdOutput[i] = dOutput[i];
  return pdOutput;
}

// gathering point information
double* GetPlanePointInfo()
{
  double dPtX, dPtY = 0.0;
  printf("Need to enter data(planar point data, arbitrary):\n");
  scanf("%lf%lf", &dPtX, &dPtY);

  printf("Your planar point info(x, y):(%.4lf, %.4lf)\n", dPtX, dPtY);

  double dOutput[2] = {dPtX, dPtY};
  double *pdOutput = malloc(sizeof(double) * (SIZE_VEC_LINE_INFO/2));
  for (int i = 0; i < (SIZE_VEC_LINE_INFO/2.0); i++)
    pdOutput[i] = dOutput[i];
  return pdOutput;
}

// calculating the dot product
double CalcPlanarDotProduct(double* pA, double *pB)
{
  return ((pA[0]) * (pB[0])) + ((pA[1]) * (pB[1]));
}

// calculating the vector-based minimal distance the give line and point
double CalcNormalDistBtwLineAndPoint(double* dVecLine, double* dPoint)
{
  double dRes = 0.0;
  
  // calculating the a vector
  double dVecA[2] = {(dPoint[0] - dVecLine[2]), (dPoint[1] - dVecLine[3])};
  double *pVecA = dVecA;

  // calculating the unit line vector
  double dVecUnitLine[2] = {dVecLine[0], dVecLine[1]};
  double *pVecUnitLine = dVecUnitLine; 
  
  // calculating the a2 vector
  double dVecA2[2] = {0.0, 0.0};
  dVecA2[0] = dVecA[0] - (CalcPlanarDotProduct(pVecA, pVecUnitLine)) * (pVecUnitLine[0]);
  dVecA2[1] = dVecA[1] - (CalcPlanarDotProduct(pVecA, pVecUnitLine)) * (pVecUnitLine[1]);  

  // calculating the l2 norm of a2 vector
  dRes = sqrt((dVecA2[0]) * (dVecA2[0]) + (dVecA2[1]) * (dVecA2[1]));

  return dRes;
}

int main(void)
{
  // interaction: getting some information related to the problem
  double *pVecLineInfo = GetPlaneLineInfo();

  // calculating the vector-based line information
  printf("\nvector-based line information:\n");
  for (int i = 0; i < SIZE_VEC_LINE_INFO; i++)
    printf("[%d] %.4lf\n", i, pVecLineInfo[i]);

  // interaction: getting some information related to the problem
  printf("\narbitrary planar point information:\n");   
  double *pVecPointInfo = GetPlanePointInfo();
  for (int i = 0; i < (SIZE_VEC_LINE_INFO/2.0); i++)
    printf("[%d] %.4lf\n", i, pVecPointInfo[i]);

  // calculating the minimal normal distance
  printf("\ncalculating the minimal normal distance:\n");     
  double dDist = CalcNormalDistBtwLineAndPoint(pVecLineInfo, pVecPointInfo);
  printf("result: %.4lf\n", dDist);

  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}