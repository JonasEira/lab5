#include "Matrix2D.h"
#include <iostream>

Matrix2D::Matrix2D()
{
}


Matrix2D::Matrix2D(float x1, float y1, float x2, float y2)
{
	data[0][0] = x1;
	data[0][1] = y1;
	data[1][0] = x2;
	data[1][1] = y2;
}

Matrix2D::Matrix2D(const Matrix2D& m)
{
	data[0][0] = m.data[0][0];
	data[0][1] = m.data[0][1];
	data[1][0] = m.data[1][0];
	data[1][1] = m.data[1][1];
}

Matrix2D::~Matrix2D() { }


Matrix2D & Matrix2D::operator*(Matrix2D & m)
{
	Matrix2D result;
	result.data[0][0] = data[0][0] * m.data[0][0] + data[1][0] * m.data[0][1];
	result.data[0][1] = data[0][0] * m.data[1][0] + data[1][0] * m.data[1][1];
	result.data[1][0] = data[0][1] * m.data[0][0] + data[1][1] * m.data[0][1];
	result.data[1][1] = data[0][1] * m.data[1][0] + data[1][1] * m.data[1][1];
	return result;
}

void Matrix2D::setData(float x1, float y1, float x2, float y2)
{
	this->data[0][0] = x1;
	this->data[0][1] = y1;
	this->data[1][0] = x2;
	this->data[1][1] = y2;
}


Matrix2D Matrix2D::rotate(float radians)
{
	Matrix2D rot = Matrix2D(
		this->data[0][0]*cos(radians)-this->data[1][1]*sin(radians),
		0,
		0,
		this->data[0][0]*sin(radians)+this->data[1][1]*cos(radians)
	);
	return rot;
}

float Matrix2D::getData(int n, int m)
{
	return data[n][m];
}


float* Matrix2D::getDataPtr()
{
	float* data = *this->data;
	return data;
}

void transpose(Matrix2D & m)
{
	Matrix2D tmp = Matrix2D(m);
	Matrix2D trans_m;
	trans_m.setData(1.0, -1.0, -1.0, 1.0);
	m = tmp * trans_m;
}

Matrix2D translate(Vector2D & v, Matrix2D & m)
{
	Matrix2D vect;
	vect.setData(v.getX()+m.getData(0,0), 
		v.getY() + m.getData(0,1), 
		v.getX() + m.getData(1,0), 
		v.getY() + m.getData(1,1));
	return vect;
}

Matrix2D unity()
{
	Matrix2D m;
	m.setData(1.0, 0.0, 0.0, 1.0);
	return m;
}



void Matrix2D::printMatrix()
{
	std::cout << "X:\tY:\n" << data[0][0] << "\t" << data[0][1] << "\n" << data[1][0] << "\t" << data[1][1] << "\n" << std::endl;
}
