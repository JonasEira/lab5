#include "Vector2D.h"
#include <iostream>
//

Vector2D::Vector2D()
{
	this->v[0] = 1;
	this->v[1] = 1;
	this->v[2] = 1;
}

Vector2D::Vector2D(float x, float y)
{
	this->v[0] = x;
	this->v[1] = y;
	this->v[2] = 1;
}

Vector2D::~Vector2D()
{
}

//-- X - pair
float Vector2D::getX() {
	return this->v[0];
}
void Vector2D::setX(float newX)
{
	this->v[0] = newX;
}
//-- Y - pair
float Vector2D::getY() {
	return this->v[1];
}

void Vector2D::setY(float newY)
{
	this->v[1] = newY;
}
//-- Z - pair
void Vector2D::setZ(float newZ)
{
	this->v[0] = newZ;
}

float Vector2D::getZ() {
	return this->v[2];
}
// --

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

Vector2D Vector2D::operator*(float n)
{
	Vector2D v;
	v.setX(n*this->getX());
	v.setY(n*this->getY());
	return v;
}

Vector2D Vector2D::rotate(float radians)
{
	Vector2D v = Vector2D(
		this->getX() * cos(radians) - this->getY() * sin(radians),
		this->getX() * sin(radians) + this->getY() * cos(radians)
	);
	return v;
}

Vector2D Vector2D::translate(Vector2D& vec)
{
	Vector2D v = Vector2D(
		vec.getX() + this->getX(),
		vec.getY() + this->getY()
	);
	return v;
}

float Vector2D::dot(Vector2D a, Vector2D b)
{
	return a.getX()*b.getX() + a.getY()*b.getY();
}

Vector2D Vector2D::operator=(Vector2D & vector)
{
	if (this != &vector) {
		copy(vector.v, vector.v + 3, v);
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
	cout << "Vector X=" << this->getX() 
		<< " Y=" << this->getY()
		<< " Z=" << this->getZ() << endl;
}




