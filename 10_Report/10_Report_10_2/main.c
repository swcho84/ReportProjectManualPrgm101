#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define NUMSTUDENT    2

typedef struct
{
  int nID;            
  char strName[20];        
  int nScoreKor;
  int nScoreEng;
  int nScoreMath;
  int nScoreTotal;
  double dScoreAvg;
  char chrGrade;
} StudentInfo;

StudentInfo* GetStudentData(int nSize)
{
  StudentInfo* result = (StudentInfo*)(malloc(sizeof(StudentInfo) * nSize));

  printf("Input:\n");
  for (int i = 0; i < nSize; i++)
  {
    printf("[%d](ID, Name, Score info(Korean, English, Math)): \n", i);
    scanf("%d %s %d %d %d", &result[i].nID, result[i].strName, &result[i].nScoreKor, &result[i].nScoreEng, &result[i].nScoreMath);

    result[i].nScoreTotal = result[i].nScoreKor + result[i].nScoreEng + result[i].nScoreMath;
    result[i].dScoreAvg = (double)(result[i].nScoreTotal)/(3.0);

    int nGrade = (int)((result[i].dScoreAvg)/(10.0));
    switch (nGrade)
    {
      case 10: 
      case 9: 
      {
        result[i].chrGrade = 'A';
        break;
      }
      case 8: 
      {
        result[i].chrGrade = 'B';
        break;
      }
      case 7: 
      {
        result[i].chrGrade = 'C';
        break;
      }
      default:
      {
        result[i].chrGrade = 'F';
        break;
      }      
    }
  }
  return result;
}

void SortStudentData(StudentInfo* input, int nSize)
{
  StudentInfo temp;
  int nIdxMax = 0;;

  for (int i = 0; i < nSize - 1; i++)
  {
    nIdxMax = i;
    for (int j = i + 1; j < nSize; j++)
    {
      if (input[nIdxMax].nScoreTotal < input[j].nScoreTotal)
        nIdxMax = j;
    }

    if (nIdxMax != i)
    {
      temp = input[nIdxMax];
      input[nIdxMax] = input[i];
      input[i] = temp;
    }
  }
}

void ShowStudentData(StudentInfo* input, int nSize)
{
  printf("Result:(ID, Name, Score info(Korean, English, Math), TotalScore, Avg.Score, Grade)\n");
  for (int i = 0; i < nSize; i++)
    printf("[%d]input: %5d %7s %5d %5d %5d %5d %.2lf %c\n", 
            i, input[i].nID, input[i].strName, 
            input[i].nScoreKor, input[i].nScoreEng, input[i].nScoreMath,
            input[i].nScoreTotal, input[i].dScoreAvg, input[i].chrGrade);
}

int main()
{
  StudentInfo* studentInfo = GetStudentData(NUMSTUDENT);

  printf("Before sorting..\n");
  ShowStudentData(studentInfo, NUMSTUDENT);

  printf("After sorting..\n");
  SortStudentData(studentInfo, NUMSTUDENT);
  ShowStudentData(studentInfo, NUMSTUDENT);

  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}