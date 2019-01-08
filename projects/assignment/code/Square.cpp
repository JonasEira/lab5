#include "Square.h"
#include "assignmentapp.h"
#include <iostream>
Square::Square() {}
Square::Square(float width, float height)
{
	this->width = width;
	this->height = height;
	
}

void Square::setColor(float r, float g, float b) {
	this->c.r = r;
	this->c.g = g;
	this->c.b = b;
}

void Square::setPosition(Vector2D v)
{
	this->position = Vector2D(v.getX() - this->width/2.0f, v.getY() - this->height/2.0f);
}

void Square::update()
{
	drawLines();
}

void Square::drawLines() {	
	for (int n = 0; n < 4; n++) {
		App2D::BaseApp::LineData l;
		lines.push_back(l);
	}


	lines.at(0).x1 = position.getX();
	lines.at(0).y1 = position.getY();
	lines.at(0).x2 = position.getX();
	lines.at(0).y2 = position.getY() + height;
	lines.at(0).c1 = c;
	lines.at(0).c2 = c;
	
	lines.at(1).x1 = position.getX();
	lines.at(1).y1 = position.getY() + height;
	lines.at(1).x2 = position.getX() + width;
	lines.at(1).y2 = position.getY() + height;
	lines.at(1).c1 = c;
	lines.at(1).c2 = c;
	
	lines.at(2).x1 = position.getX() + width;
	lines.at(2).y1 = position.getY() + height;
	lines.at(2).x2 = position.getX() + width;
	lines.at(2).y2 = position.getY();
	lines.at(2).c1 = c;
	lines.at(2).c2 = c;

	lines.at(3).x1 = position.getX() + width;
	lines.at(3).y1 = position.getY();
	lines.at(3).x2 = position.getX();
	lines.at(3).y2 = position.getY();
	lines.at(3).c1 = c;
	lines.at(3).c2 = c;
	for (App2D::BaseApp::LineData line : lines) {
		Assignment::AssignmentApp::DrawLine(line);
	}

}

Square::~Square()
{
}
