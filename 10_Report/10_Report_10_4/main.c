#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

typedef struct 
{
	double x;
	double y;
} Pt2;

typedef struct 
{
	double i;
	double j;
} Vec2;

typedef struct 
{
	double i;
	double j;
  double k;
} Vec3;

typedef struct 
{
  double slope;
  double bias;
  Vec2 unitVec2Info;
  Pt2 pt2OnLine;
} Line;

Vec2 pt2ToVec2(Pt2 a, Pt2 b)
{
	Vec2 res;
	res.i = b.x - a.x;
	res.j = b.y - a.y;
	return res;
}

Vec2 vec2Add(Vec2 a, Vec2 b)
{
	Vec2 res;
	res.i = a.i + b.i;
	res.j = a.j + b.j;
	return res;
}

Vec2 vec2Sub(Vec2 a, Vec2 b)
{
	Vec2 res;
	res.i = a.i - b.i;
	res.j = a.j - b.j;
	return res;
}

Vec2 vec2Scalar(double scale, Vec2 in)
{
	Vec2 res;
	res.i = (scale) * (in.i);
	res.j = (scale) * (in.j);
	return res;
}

double vec2Norm(Vec2 in)
{
	return (sqrt((in.i * in.i) + (in.j * in.j)));
}

Vec2 vec2ToUnitVec2(Vec2 in)
{
	Vec2 res;
	res.i = (in.i)/(vec2Norm(in));
	res.j = (in.j)/(vec2Norm(in));
	return res;
}

double vec2InnerProd(Vec2 a, Vec2 b)
{
	return ((a.i * b.i) + (a.j * b.j));
}

Vec3 vec2OuterProd(Vec2 a, Vec2 b)
{
	Vec3 res;
	res.i = 0.0;
	res.j = 0.0;
  res.k = (a.i * b.j) - (a.j * b.i);
	return res;
}

// gathering line information
Line* GetPlaneLineInfo()
{
  // interaction: getting some information related to the problem
  Line* lineInfo = (Line*)(malloc(sizeof(Line)));
  printf("Need to enter data(planar line data, slope and bias):\n");
  scanf("%lf%lf", &lineInfo->slope, &lineInfo->bias);

  // for debugging
  printf("Your planar line info(slope, bias):(%.4lf, %.4lf)\n", lineInfo->slope, lineInfo->bias);

  // calculating the line intercepting information
  double dXaxisInterCept = (-lineInfo->bias)/(lineInfo->slope);
  double dYaxisInterCept = lineInfo->bias;

  // assigning the point data
  Pt2 ptInfoXaxisIntercept;
  Pt2 ptInfoYaxisIntercept;
  ptInfoXaxisIntercept.x = dXaxisInterCept;
  ptInfoXaxisIntercept.y = 0.0;
  ptInfoYaxisIntercept.x = 0.0;
  ptInfoYaxisIntercept.y = dYaxisInterCept;  

  // making the vector data
  Vec2 vec2Info;
  vec2Info = pt2ToVec2(ptInfoXaxisIntercept, ptInfoYaxisIntercept);

  // making the unit vector data
  Vec2 unitVec2Info;
  unitVec2Info = vec2ToUnitVec2(vec2Info);

  // saving the information
  lineInfo->pt2OnLine = ptInfoXaxisIntercept;
  lineInfo->unitVec2Info = unitVec2Info;

  return lineInfo;
}

// gathering point information
Pt2* GetPlanePointInfo()
{
  // interaction: getting some information related to the problem
  Pt2* pt2OnPlane = (Pt2*)(malloc(sizeof(Pt2)));
  printf("Need to enter data(planar point data, arbitrary):\n");
  scanf("%lf%lf", &pt2OnPlane->x, &pt2OnPlane->y);

  // for debugging
  printf("Your planar point info(x, y):(%.4lf, %.4lf)\n", pt2OnPlane->x, pt2OnPlane->y);

  return pt2OnPlane;
}

// calculating the vector-based minimal distance the give line and point
double CalcNormalDistBtwLineAndPoint(Line* line, Pt2* point)
{
  double dRes = 0.0;
  
  // calculating the a vector
  Vec2 vecA;
  Pt2 ptPlane;
  ptPlane.x = point->x;
  ptPlane.y = point->y;
  vecA = pt2ToVec2(ptPlane, line->pt2OnLine);
 
  // calculating the a2 vector
  Vec2 vecA2;
  vecA2.i = vecA.i - (vec2InnerProd(vecA, line->unitVec2Info)) * (line->unitVec2Info.i);
  vecA2.j = vecA.j - (vec2InnerProd(vecA, line->unitVec2Info)) * (line->unitVec2Info.j);  

  // calculating the l2 norm of a2 vector
  return vec2Norm(vecA2);
}

int main(void)
{
  // interaction: getting some information related to the problem
  Line* pLineInfo = GetPlaneLineInfo();
  printf("\nvector-based line information:\n");
  printf("(slope, bias, unitVec(i,j), onPoint(x,y)):(%.4lf, %.4lf, (%.4lf,%.4lf), (%.4lf,%.4lf))\n", 
         pLineInfo->slope, pLineInfo->bias, pLineInfo->unitVec2Info.i, pLineInfo->unitVec2Info.j, pLineInfo->pt2OnLine.x, pLineInfo->pt2OnLine.y);

  // interaction: getting some information related to the problem
  Pt2 *pPointOnPlaneInfo = GetPlanePointInfo();
  printf("\narbitrary planar point information:\n");   
  printf("OnPlanePoint(x,y):(%.4lf,%.4lf)\n", pPointOnPlaneInfo->x, pPointOnPlaneInfo->y);

  // calculating the minimal normal distance
  printf("\ncalculating the minimal normal distance:\n");     
  double dDist = CalcNormalDistBtwLineAndPoint(pLineInfo, pPointOnPlaneInfo);
  printf("result: %.4lf\n", dDist);

  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}