#pragma once

#include "Vector2D.h"
#include "Shape.h"
#include <math.h>
class Circle :
	public Shape
{
public:
	float radius = 0.0f;
	vector<App2D::BaseApp::LineData> lines;
	Circle();
	Circle(float r);
	void setColor(float r, float g, float b);
	void setPosition(Vector2D& v);
	void setVelocity(Vector2D& v);
	void setRotation(float f);
	Vector2D checkOutsideArea(Vector2D v, Matrix2D area);
	void update();
	void drawLines();
	~Circle();
};

