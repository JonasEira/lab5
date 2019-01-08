#pragma once

#include "Vector2D.h"
#include "Shape.h"

class Triangle :
	public Shape
{
public:
	float base = 0.0f;
	float height = 0.0f;
	vector<App2D::BaseApp::LineData> lines;
	Triangle();
	Triangle(float b, float h);
	void setColor(float r, float g, float b);
	void setRotation(float rot);
	void setPosition(Vector2D v);
	void update();
	void drawLines();
	~Triangle();
};

