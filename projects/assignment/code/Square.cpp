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

void Square::setPosition(Vector2D& v)
{
	this->position = Vector2D(v);

}

void Square::setVelocity(Vector2D & v)
{
	this->velocity = Vector2D(v);
}

void Square::setRotation(float rot)
{
	this->rotation = rot;
}

void Square::update()
{
	
}

void Square::drawLines() {
	
	Vector2D newPos = position.translate(velocity);
	this->setPosition(newPos);

	for (int n = 0; n < 4; n++) {
		App2D::BaseApp::LineData l;
		lines.push_back(l);
	}

	
	Vector2D p1_norm = Vector2D(0.0f, 0.0f);
	Vector2D p2_norm = Vector2D(width, 0.0f);
	Vector2D p3_norm = Vector2D(width, height);
	Vector2D p4_norm = Vector2D(0.0f, height);
	Vector2D p1 = p1_norm.rotate(rotation);
	Vector2D p2 = p2_norm.rotate(rotation);
	Vector2D p3 = p3_norm.rotate(rotation);
	Vector2D p4 = p4_norm.rotate(rotation);
	Vector2D pt1 = p1.translate(position);
	Vector2D pt2 = p2.translate(position);
	Vector2D pt3 = p3.translate(position);
	Vector2D pt4 = p4.translate(position);
	Matrix2D m1 = Matrix2D(pt1.getX(), pt1.getY(), pt2.getX(), pt2.getY());
	Matrix2D m2 = Matrix2D(pt2.getX(), pt2.getY(), pt3.getX(), pt3.getY());
	Matrix2D m3 = Matrix2D(pt3.getX(), pt3.getY(), pt4.getX(), pt4.getY());
	Matrix2D m4 = Matrix2D(pt4.getX(), pt4.getY(), pt1.getX(), pt1.getY());

	
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

	lines.at(3).x1 = m4.getData(0, 0);
	lines.at(3).y1 = m4.getData(0, 1);
	lines.at(3).x2 = m4.getData(1, 0);
	lines.at(3).y2 = m4.getData(1, 1);
	lines.at(3).c1 = c;
	lines.at(3).c2 = c;
	for (App2D::BaseApp::LineData line : lines) {
		Assignment::AssignmentApp::DrawLine(line);
	}

}

Square::~Square()
{
}
