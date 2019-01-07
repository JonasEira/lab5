#include "Shape.h"
#include <iostream>
void Shape::setPosition(Vector2D v)
{
	this->position = Vector2D(v.getX(), v.getY());
}

void Shape::update()
{
	drawLines();
}
void Shape::drawLines() {
	cout << "Drawlines shape" << endl;
}

Shape::Shape()
{
}


Shape::~Shape()
{
}
