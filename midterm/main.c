#include <stdio.h>

int AddRecursion1(int num)
{
  if (num == 1)
    return 1;
  
  return num + AddRecursion1(num - 1);
}

int AddRecursion2(int num)
{
  if (num == 10)
    return 10;
  
  return num + AddRecursion2(num + 1);
}

int Sum(void)
{
  static int a = 0;
  a++;
  return a;
}

void func1(int *pInput)
{
  static int nData = 5;
  pInput = &nData;
}

int* func2(int *pInput)
{
  static int nData = 5;
  pInput = &nData;
  return pInput;
}

void func3(int *pInput)
{
  static int nData = 5;
  *pInput = nData;
}

int main(void)
{
  // answer#4-1, ok
  // for(int i = 0; i < 5; i++)
  // {
  //   for(int j = 0; j < (5 - i); j++)
  //   {
	//     printf("*");
  //   }
  //   printf("\n");
  // }

  // answer#4-2, ok
  // for(int i = 0; i < 5; i++)
  // {
  //   for(int j = 0; j < 5; j++)
  //   {
  //     if (j <= (4 - i))
  // 	    printf("*");
  //   }
  //   printf("\n");
  // }

  // answer#4-3, ok
  // for(int i = 0; i < 5; i++)
  // {
  //   for(int j = 0; j+i < 5; j++)
  //   {
	//     printf("*");
  //   }
  //   printf("\n");
  // }    

  // answer#4-4, ok
  // for(int i = 0; i < 5; i++)
  // {
  //   for(int j = 0; j < 5; j++)
  //   {
  //     if ((i + j) <= 4)
	//       printf("*");
  //   }
  //   printf("\n");
  // }

  // answer#4-5, ok
  // for(int i = 5; i > 0; i--)
  // {
  //   for(int j = 0; j < i; j++)
  //   {
  //     printf("*");
  //   }
  //   printf("\n");
  // } 

  // answer#4-6, ok
  // for(int i = 5; i >= 1; i--)
  // {
  //   for(int j = 0; j < i; j++)
  //   {
  //     printf("*");
  //   }
  //   printf("\n");
  // } 

  // answer#8
  // printf("sum:%d\n", AddRecursion1(10));
  // printf("sum:%d\n", AddRecursion2(1));  

  // answer#11
  // int nX = 6;
  // int *pX = &nX;
  // printf("%d\n", --(*pX));
  // printf("%d\n", (*pX)++);

  // answer#13-1
  // int nP = 1;
  // int *pP = &nP;
  // func1(pP);
  // printf("%d\n", *pP);

  // answer#13-2
  // int nP = 1;
  // int *pP = &nP;
  // pP = func2(pP);
  // printf("%d\n", *pP);

  // answer#13-3
  // int nP = 1;
  // int *pP = &nP;
  // func3(pP);
  // printf("%d\n", *pP);  
  return 0;
}