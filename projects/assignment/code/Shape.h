#pragma once
#include "config.h"
#include "Vector2D.h"
#include "Matrix2D.h"
#include "2d/2dapp.h"
class Shape
{
public:
	App2D::BaseApp::Colour c;
	Vector2D position;
	float rotation;
	Vector2D velocity;

	virtual void drawLines();
	virtual void setPosition(Vector2D v);
	virtual void update();

	Shape();
	virtual ~Shape();
};

