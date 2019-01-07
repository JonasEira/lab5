#include "Vector2D.h"
#include <iostream>
//

Vector2D::Vector2D()
{

}

Vector2D::Vector2D(float x, float y)
{
	this->v[0] = x;
	this->v[1] = y;
}

Vector2D::~Vector2D()
{
}


float Vector2D::getX() {
	return this->v[0];
}
void Vector2D::setX(float newX)
{
	this->v[0] = newX;
}
float Vector2D::getY() {
	return this->v[1];
}

void Vector2D::setY(float newY)
{
	this->v[1] = newY;
}

Vector2D Vector2D::operator+(Vector2D & v)
{

	Vector2D vec = Vector2D(v.getX() + this->getX(), v.getY() + this->getY());
	return vec;
}


Vector2D Vector2D::operator-(Vector2D & v)
{
	Vector2D vec = Vector2D(v.getX() - this->getX(), v.getY() - this->getY());
	return vec;
}

Vector2D Vector2D::operator*(Vector2D & v)
{
	Vector2D vec = Vector2D(v.getX()*this->getY(), v.getY()*this->getX());
	return vec;
}

float Vector2D::dot(Vector2D a, Vector2D b)
{
	return a.getX()*b.getX() + a.getY()*b.getY();
}

Vector2D Vector2D::operator=(Vector2D & vector)
{
	if (this != &vector) { 
		copy(vector.v, vector.v + 2, v);
	}
	return *this;
}

bool & Vector2D::operator==(Vector2D & b)
{
	bool tmp = (this->getX() == b.getX()) && (this->getY() == b.getY());
	return tmp;
}

bool & Vector2D::operator!=(Vector2D & b)
{
	bool tmp = (this->getX() != b.getX()) || (this->getY() != b.getY());
	return tmp;
}

void Vector2D::printVector()
{
	cout << "Vector X=" << this->getX() << " Y=" << this->getY() << endl;
}




