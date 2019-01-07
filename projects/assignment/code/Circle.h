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
	void setPosition(Vector2D v);
	void update();
	void drawLines();
	~Circle();
};

