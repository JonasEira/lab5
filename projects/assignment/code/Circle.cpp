#include "Circle.h"
#include "assignmentapp.h"
Circle::Circle()
{
	radius = 0.5f;
	
}

Circle::Circle(float r)
{
	this->radius = r;
}

void Circle::setColor(float r, float g, float b) {
	this->c.r = r;
	this->c.g = g;
	this->c.b = b;
}
void Circle::setPosition(Vector2D v)
{
	this->position = Vector2D(v.getX() - this->radius / 2.0f, v.getY() - this->radius / 2.0f);
}

void Circle::setRotation(float rot)
{
	this->rotation = rot;
}

void Circle::update()
{
	drawLines();
}

void Circle::drawLines() 
{
	
	Matrix2D rad = Matrix2D(this->radius, 0.0f, 0.0f, 0.0f);
	Matrix2D rot;
	Matrix2D trans_rot;
	Matrix2D trans_rad;
	
	float radians = 15.0f * 3.14159f / 180.0f;
	for (int n = 0; n < 25; n++) {
		rot = rad.rotate(radians);
		trans_rot = translate(position, rot);
		trans_rad = translate(position, rad);
		App2D::BaseApp::LineData l;
		l.x1 = trans_rad.getData(0, 0);
		l.y1 = trans_rad.getData(1, 1);
		l.c1 = c;
		l.x2 = trans_rot.getData(0, 0);
		l.y2 = trans_rot.getData(1, 1);
		l.c2 = c;
		lines.push_back(l);
		rad = rot;
	}

	for (App2D::BaseApp::LineData line : lines) {
		Assignment::AssignmentApp::DrawLine(line);
	}

}


Circle::~Circle()
{
}
