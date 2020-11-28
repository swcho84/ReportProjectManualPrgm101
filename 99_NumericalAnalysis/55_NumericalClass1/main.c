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
	double x;
	double y;
	double z;
} Pt3;

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
	Vec3 pos;
	Vec3 vel;
	Vec3 acc;
	Vec3 att;
	Vec3 angrate;

} UAV;

Vec3 pt3ToVec3(Pt3 a, Pt3 b)
{
	Vec3 res;
	res.i = b.x - a.x;
	res.j = b.y - a.y;
	res.k = b.z - a.z;
	return res;
}

Vec3 vec3Add(Vec3 a, Vec3 b)
{
	Vec3 res;
	res.i = a.i + b.i;
	res.j = a.j + b.j;
	res.k = a.k + b.k;
	return res;
}

Vec3 vec3Sub(Vec3 a, Vec3 b)
{
	Vec3 res;
	res.i = a.i - b.i;
	res.j = a.j - b.j;
	res.k = a.k - b.k;
	return res;
}

Vec3 vec3Scalar(double scale, Vec3 in)
{
	Vec3 res;
	res.i = (scale) * (in.i);
	res.j = (scale) * (in.j);
	res.k = (scale) * (in.k);
	return res;
}

double vec3Norm(Vec3 in)
{
	return (sqrt((in.i * in.i) + (in.j * in.j) + (in.k * in.k)));
}

Vec3 vec3ToUnitVec3(Vec3 in)
{
	Vec3 res;
	res.i = (in.i)/(vec3Norm(in));
	res.j = (in.j)/(vec3Norm(in));
	res.k = (in.k)/(vec3Norm(in));		
	return res;
}

double vec3InnerProd(Vec3 a, Vec3 b)
{
	return ((a.i * b.i) + (a.j * b.j) + (a.k * b.k));
}

Vec3 vec3OuterProd(Vec3 a, Vec3 b)
{
	Vec3 res;
	res.i = (a.j * b.k) - (a.k * b.j);
	res.j = -((a.i * b.k) - (a.k * b.i));
	res.k = (a.i * b.j) - (a.j * b.i);
	return res;
}

int main(void)
{
	// assigning two points in three-dim.
	Pt3 ptA;
	ptA.x = 4.0;
	ptA.y = 6.0;
	ptA.z = -2.0;

	Pt3 ptB;
	ptB.x = 1.0;
	ptB.y = 8.0;
	ptB.z = 3.0;

	// for debugging
	printf("ptA(x,y,z):(%.4lf,%.4lf,%.4lf)\n", ptA.x, ptA.y, ptA.z);
	printf("ptB(x,y,z):(%.4lf,%.4lf,%.4lf)\n", ptB.x, ptB.y, ptB.z);

	// calculating the vector between point A and B
	Vec3 vA = pt3ToVec3(ptA, ptB);

	// for debugging
	printf("vA(i,j,k):(%.4lf,%.4lf,%.4lf)\n", vA.i, vA.j, vA.k);

	// calculating the norm w.r.t the given vector
	double dNormA = vec3Norm(vA);

	// for debugging
	printf("dNormA:(%.4lf)\n", dNormA);

	// calculating the unit vector w.r.t the given vector
	Vec3 vUnitA = vec3ToUnitVec3(vA);

	// for debugging
	printf("vUnitA(i,j,k):(%.4lf,%.4lf,%.4lf)\n", vUnitA.i, vUnitA.j, vUnitA.k);	
	printf("dNormUnitA:(%.4lf)\n", vec3Norm(vUnitA));

	Vec3 vUnitAA = vec3Scalar((1.0/dNormA), vA);
	printf("vUnitAA(i,j,k):(%.4lf,%.4lf,%.4lf)\n", vUnitAA.i, vUnitAA.j, vUnitAA.k);	

  // related in C of windows (system("pause"))
  int c = getchar();
  return 0;
}