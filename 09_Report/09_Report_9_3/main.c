#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

void swap(char* type, void* pa, void* pb)
{
  if (strcmp(type, "int"))
  {
    int tempInt;
    tempInt = *(int*)(pa); 
    *(int*)(pa) = *(int*)(pb);
    *(int*)pb = tempInt;
  }
  else if (strcmp(type, "double"))
  {
    double tempDouble;
    tempDouble = *(double*)(pa); 
    *(double*)(pa) = *(double*)(pb);
    *(double*)(pb) = tempDouble;
  }
  else if (strcmp(type, "float"))
  {
    float tempFloat;
    tempFloat = *(float*)(pa); 
    *(float*)(pa) = *(float*)(pb);
    *(float*)(pb) = tempFloat;
  }
  else
    printf("Please check your variable type..\n");
}

int main()
{
  int nAge1 = 0, nAge2 = 0;
  double dHeight1 = 0.0, dHeight2 = 0.0;

  printf("Enter 1st person Info(age, height[cm]): ");   
  scanf("%d %lf", &nAge1, &dHeight1); 
  printf("Enter 2nd person Info(age, height[cm]): ");   
  scanf("%d %lf", &nAge2, &dHeight2); 

  swap("int", &nAge1, &nAge2);
  swap("double", &dHeight1, &dHeight2);

  printf("Age and height of the first person : %d, %.1lf\n", nAge1, dHeight1);   //print result 1
  printf("Age and height of the second person : %d, %.1lf\n", nAge2, dHeight2);   //print result 2
  
  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}