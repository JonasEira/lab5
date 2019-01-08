#pragma once
using namespace std;
class Vector2D
{
private:

public:
	float v[2];
	Vector2D();
	Vector2D(float x, float y);
	~Vector2D();


	float getX();
	void setX(float newX);
	float getY();
	void setY(float newY);
	Vector2D operator+(Vector2D &v);
	Vector2D operator-(Vector2D &v);
	Vector2D operator*(Vector2D &v);

	Vector2D rotate(float radians);
	float dot(Vector2D a, Vector2D b);
	Vector2D operator=(Vector2D &vector);

	bool & operator==(Vector2D &b);
	bool & operator!=(Vector2D &b);
	
	void printVector();

};



