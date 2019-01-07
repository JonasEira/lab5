#pragma once
#include"Vector2D.h"
#include <math.h>
class Matrix2D
{
private:
	float data[2][2];

public:

	Matrix2D(float x1, float x2, float y1, float y2);
	Matrix2D(const Matrix2D & m);
	Matrix2D();
	
	void printMatrix();
	
	void setData(float x1, float y1, float x2, float y2);
	
	Matrix2D transform(Vector2D &v, Matrix2D &m);

	Matrix2D rotate(float radians);

	float getData(int n, int m);
	float* getDataPtr();

	Matrix2D & operator*(Matrix2D &m);

	~Matrix2D();
};
void transpose(Matrix2D &m);
Matrix2D unity();

