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

void Triangle::setRotation(float rot)
{
	this->rotation = rot;
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

	Vector2D p1_norm = Vector2D(position.getX(), position.getY());
	Vector2D p2_norm = Vector2D(position.getX() + base, position.getY());
	Vector2D p3_norm = Vector2D(position.getX() + base, position.getY() + height);
	

	Vector2D p1 = p1_norm.rotate(rotation);
	Vector2D p2 = p2_norm.rotate(rotation);
	Vector2D p3 = p3_norm.rotate(rotation);
	

	Matrix2D m1 = Matrix2D(p1.getX(), p1.getY(), p2.getX(), p2.getY());
	Matrix2D m2 = Matrix2D(p2.getX(), p2.getY(), p3.getX(), p3.getY());
	Matrix2D m3 = Matrix2D(p3.getX(), p3.getY(), p1.getX(), p1.getY());
	

	lines.at(0).x1 = m1.getData(0, 0);
	lines.at(0).y1 = m1.getData(0, 1);
	lines.at(0).x2 = m1.getData(1, 0);
	lines.at(0).y2 = m1.getData(1, 1);
	lines.at(0).c1 = c;
	lines.at(0).c2 = c;

	lines.at(1).x1 = m2.getData(0, 0);
	lines.at(1).y1 = m2.getData(0, 1);
	lines.at(1).x2 = m2.getData(1, 0);
	lines.at(1).y2 = m2.getData(1, 1);
	lines.at(1).c1 = c;
	lines.at(1).c2 = c;

	lines.at(2).x1 = m3.getData(0, 0);
	lines.at(2).y1 = m3.getData(0, 1);
	lines.at(2).x2 = m3.getData(1, 0);
	lines.at(2).y2 = m3.getData(1, 1);
	lines.at(2).c1 = c;
	lines.at(2).c2 = c;

	for (App2D::BaseApp::LineData line : lines) {
		Assignment::AssignmentApp::DrawLine(line);
	}
	
}


Triangle::~Triangle()
{
}
