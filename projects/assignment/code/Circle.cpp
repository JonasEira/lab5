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

void Circle::setPosition(Vector2D v)
{
	this->position = Vector2D(v.getX() - this->radius / 2.0f, v.getY() - this->radius / 2.0f);
}

void Circle::update()
{
	drawLines();
}

void Circle::drawLines() 
{
	
	Matrix2D rad = Matrix2D(this->radius, 0.0f, 0.0f, 0.0f);
	Matrix2D trans = translate(position, rad);
	Matrix2D rot;
	
	float radians = 15.0f * 3.14159f / 180.0f;
	for (int n = 0; n < 25; n++) {
		rot = trans.rotate(radians);
		App2D::BaseApp::LineData l;
		l.x1 = trans.getData(0, 0);
		l.y1 = trans.getData(1, 1);
		l.x2 = rot.getData(0, 0);
		l.y2 = rot.getData(1, 1);
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
