#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

void PrintMat22(float (*pInput)[2], char *strInput)
{
  printf("%s=\n", strInput);
  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      printf("%.4f\t", pInput[i][j]);
    }
    printf("\n");
  }
}

void PrintMat33(float (*pInput)[3], char *strInput)
{
  printf("%s=\n", strInput);
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("%.4f\t", pInput[i][j]);
    }
    printf("\n");
  }
}

void CalcMat22()
{
  // 2x2 matrix
  float fMatA22[2][2] = {{1.0f, 2.0f}, {3.0f, 4.0f}};
  float fMatB22[2][2] = {{5.0f, 6.0f}, {7.0f, 8.0f}};

  PrintMat22(fMatA22, "A");
  PrintMat22(fMatB22, "B");
  
  // calculating matrix addition
  float fMatResAdd[2][2] = {};
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      fMatResAdd[i][j] = fMatA22[i][j] + fMatB22[i][j];
  printf("\n");
  PrintMat22(fMatResAdd, "Addition, C1");
  printf("\n");

  // calculating matrix subtraction
  float fMatResSub[2][2] = {};
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      fMatResSub[i][j] = fMatA22[i][j] - fMatB22[i][j];
  PrintMat22(fMatResSub, "Subtraction, C2");
  printf("\n");

  // calculating matrix multiplication
  float fMatResMul[2][2] = {};
  for (int i = 0; i < 2; i++)
  {    
    for (int j = 0; j < 2; j++)
    {
      fMatResMul[i][j] = 0;
      for (int m = 0; m < 2; m++)
        fMatResMul[i][j] += fMatA22[i][m] * fMatB22[m][j];  
    }
  }
  PrintMat22(fMatResMul, "Multiplication, C3");
  printf("\n");

  // calculating matrix inverse
  float fMatResInv[2][2] = {};
  float fDetA = (fMatA22[0][0] * fMatA22[1][1] - fMatA22[0][1] * fMatA22[1][0]);
  if (fDetA != 0.0f)
  {
    for (int i = 0; i < 2; i++)
    {
      for (int j = 0; j < 2; j++)
      {
        if (i == j) 
          fMatResInv[i][j] = fMatA22[1 - i][1 - j] / fDetA;
        else
          fMatResInv[i][j] = -fMatA22[i][j] / fDetA;
      }
    }
    PrintMat22(fMatResInv, "Inverse, invA");
    printf("\n");
  }
  else
    printf("determinant is zero...please check the matrix..\n");
  
  float fDetB = (fMatA22[0][0] * fMatA22[1][1] - fMatA22[0][1] * fMatA22[1][0]);
  if (fDetB != 0.0f)
  {
    for (int i = 0; i < 2; i++)
    {
      for (int j = 0; j < 2; j++)
      {
        if (i == j) 
          fMatResInv[i][j] = fMatB22[1 - i][1 - j] / fDetB;
        else
          fMatResInv[i][j] = -fMatB22[i][j] / fDetB;
      }
    }
    PrintMat22(fMatResInv, "Inverse, invB");
    printf("\n");
  }
  else
    printf("determinant is zero...please check the matrix..\n");

  // calculating transpose matrix
  float fMatResTranspose[2][2] = {};
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      fMatResTranspose[i][j] = fMatA22[j][i];
  printf("\n");
  PrintMat22(fMatResTranspose, "Transpose, A^{T}");
  printf("\n");    
}

void CalcMat33()
{
  // 3x3 matrix
  float fMatA33[3][3] = {{3.0f, 4.0f, 3.0f}, {4.0f, 5.0f, 6.0f}, {7.0f, 8.0f, 9.0f}};
  float fMatB33[3][3] = {{5.0f, 6.0f, 7.0f}, {8.0f, 9.0f, 10.0f}, {11.0f, 12.0f, 13.0f}};

  PrintMat33(fMatA33, "A");
  PrintMat33(fMatB33, "B");
  
  // calculating matrix addition
  float fMatResAdd[3][3] = {};
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      fMatResAdd[i][j] = fMatA33[i][j] + fMatB33[i][j];
  printf("\n");
  PrintMat33(fMatResAdd, "Addition, C1");
  printf("\n");

  // calculating matrix subtraction
  float fMatResSub[3][3] = {};
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      fMatResSub[i][j] = fMatA33[i][j] - fMatB33[i][j];
  PrintMat33(fMatResSub, "Subtraction, C2");
  printf("\n");

  // calculating matrix multiplication
  float fMatResMul[3][3] = {};
  for (int i = 0; i < 3; i++)
  {    
    for (int j = 0; j < 3; j++)
    {
      fMatResMul[i][j] = 0;
      for (int m = 0; m < 3; m++)
        fMatResMul[i][j] += fMatA33[i][m] * fMatB33[m][j];  
    }
  }
  PrintMat33(fMatResMul, "Multiplication, C3");
  printf("\n");

  // calculating matrix inverse
  float fMatResInv[3][3] = {};  
  float fDetA = fMatA33[0][0]*fMatA33[1][1]*fMatA33[2][2] - fMatA33[0][0]*fMatA33[1][2]*fMatA33[2][1]
                + fMatA33[0][1]*fMatA33[1][2]*fMatA33[2][0] - fMatA33[0][1]*fMatA33[1][0]*fMatA33[2][2]
                + fMatA33[0][2]*fMatA33[1][0]*fMatA33[2][1] - fMatA33[0][2]*fMatA33[1][1]*fMatA33[2][0];
  if(fDetA != 0.0f)
  {
    for(int i = 0; i < 3; i++) 
    {
      for(int j = 0; j < 3; j++) 
      {
        fMatResInv[i][j] = (1.0f/fDetA) *
                           (fMatA33[(j + 1)%3][(i + 1)%3]*fMatA33[(j + 2)%3][(i + 2)%3] 
                            - fMatA33[(j + 1)%3][(i + 2)%3]*fMatA33[(j + 2)%3][(i + 1)%3]);
      }
    }
  }
  else
    printf("determinant is zero...please check the matrix..\n");
  PrintMat33(fMatResInv, "Inverse, invA");
  printf("\n");  


  // calculating transpose matrix
  float fMatResTranspose[3][3] = {};
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      fMatResTranspose[i][j] = fMatA33[j][i];
  printf("\n");
  PrintMat33(fMatResTranspose, "Transpose, A^{T}");
  printf("\n");    
}

int main(void)
{
  // CalcMat22();

  CalcMat33();

  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}