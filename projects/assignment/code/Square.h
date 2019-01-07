#pragma once

#include "Vector2D.h"
#include "Shape.h"


class Square :
	public Shape
	
{
public:
	float width;
	float height;
	
	vector<App2D::BaseApp::LineData> lines;
	Square();
	Square(float width, float height);
	
	void setPosition(Vector2D v);
	void update();
	void drawLines();

	~Square();
};


