#pragma once
#include "config.h"
#include "Vector2D.h"
#include "Matrix2D.h"
#include "2d/2dapp.h"
class Shape
{
public:
	float red = 1.0f;
	float green = 1.0f;
	float blue = 0.0f;
	Vector2D position;
	Matrix2D rotation;
	
	virtual void drawLines();
	virtual void setPosition(Vector2D v);
	virtual void update();

	Shape();
	virtual ~Shape();
};

