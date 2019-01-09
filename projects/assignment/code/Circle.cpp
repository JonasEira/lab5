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
void Circle::setPosition(Vector2D& v)
{
	this->position = Vector2D(v);
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
	Vector2D vec = Vector2D(this->radius, 0.0f);
	Vector2D rot_v;
	Vector2D trans_rot_v;
	Vector2D trans_vec;

	float radians = 15.0f * 3.14159f / 180.0f;
	for (int n = 0; n < 25; n++) {
		rot_v = vec.rotate(radians);
		trans_rot_v = rot_v.translate(position);
		trans_vec = vec.translate(position);
		App2D::BaseApp::LineData l;
		l.x1 = trans_vec.getX();
		l.y1 = trans_vec.getY();
		l.c1 = c;
		l.x2 = trans_rot_v.getX();
		l.y2 = trans_rot_v.getY();
		l.c2 = c;
		lines.push_back(l);
		vec = rot_v;
	}

	for (App2D::BaseApp::LineData line : lines) {
		Assignment::AssignmentApp::DrawLine(line);
	}

}


Circle::~Circle()
{
}
