#include "Triangle.h"
#include "assignmentapp.h"

Triangle::Triangle()
{
	this->base = 0.1f;
	this->height = 0.1f;
}

Triangle::Triangle(float b, float h)
{
	this->base = b;
	this->height = h;
	
}

void Triangle::setColor(float r, float g, float b) {
	this->c.r = r;
	this->c.g = g;
	this->c.b = b;
}

void Triangle::setPosition(Vector2D v)
{
	this->position = Vector2D(v.getX() - this->base / 2.0f, v.getY() - this->height / 2.0f);
}

void Triangle::update() {
	drawLines();
};

void Triangle::drawLines() 
{
	for (int n = 0; n < 3; n++) {
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
	lines.at(1).x2 = position.getX() + base;
	lines.at(1).y2 = position.getY();
	lines.at(1).c1 = c;
	lines.at(1).c2 = c;

	lines.at(2).x1 = position.getX() + base;
	lines.at(2).y1 = position.getY();
	lines.at(2).x2 = position.getX();
	lines.at(2).y2 = position.getY();
	lines.at(2).c1 = c;
	lines.at(2).c2 = c;

	for (App2D::BaseApp::LineData line : lines) {
		Assignment::AssignmentApp::DrawLine(line);
	}
	
}


Triangle::~Triangle()
{
}
