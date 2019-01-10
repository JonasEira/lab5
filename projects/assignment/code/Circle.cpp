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
	this->position.setX(v.getX());
	this->position.setY(v.getY());
}

void Circle::setVelocity(Vector2D & v)
{
	this->velocity.setX(v.getX());
	this->velocity.setY(v.getY());
}

void Circle::setRotation(float rot)
{
	this->rotation = rot;
}

void Circle::update()
{
	Vector2D newPos = position.translate(velocity);
	Vector2D newVelocity;
	Matrix2D area = Matrix2D(1.0f, -1.0f, 1.0f, -1.0f);
	newVelocity = checkOutsideArea(newPos, area);
	this->setVelocity(newVelocity);
	this->setPosition(newPos);
}

Vector2D Circle::checkOutsideArea(Vector2D v, Matrix2D area) {
	Vector2D newPos;
	newPos = v;
	Vector2D newVelocity = velocity;
	Vector2D norm;
	if (newPos.getX() > area.getData(0,0) && velocity.getX() > 0) {
		norm = Vector2D(-1.0f, 0.0f);
		float vn = velocity*norm;
		float nn = norm * norm;
		float quota = 2.0f * vn / nn;
		Vector2D otherMult = norm*quota;
		newVelocity = otherMult - velocity;
	}
	if (newPos.getX() < area.getData(1,0) && velocity.getX() < 0) {
		norm = Vector2D(1.0f, 0.0f);
		float vn = velocity * norm;
		float nn = norm * norm;
		float quota = 2 * vn / nn;
		Vector2D otherMult = norm * quota;
		newVelocity = otherMult - velocity;
	}
	if (newPos.getY() > area.getData(1, 0) && velocity.getY() > 0) {
		norm = Vector2D(0.0f, -1.0f);
		float vn = velocity * norm;
		float nn = norm * norm;
		float quota = 2 * vn / nn;
		Vector2D otherMult = norm * quota;
		newVelocity = otherMult - velocity;
	}
	if (newPos.getY() < area.getData(1, 1) && velocity.getY() < 0) {
		norm = Vector2D(0.0f, 1.0f);
		float vn = velocity * norm;
		float nn = norm * norm;
		float quota = 2 * vn / nn;
		Vector2D otherMult = norm * quota;
		newVelocity =  otherMult - velocity;
	}
	App2D::BaseApp::LineData l;
	l.x1 = 0.0f;
	l.y1 = 0.0f;
	l.c1 = c;
	l.x2 = newVelocity.getX();
	l.y2 = newVelocity.getY();
	l.c2 = c;
	Assignment::AssignmentApp::DrawLine(l);
	return newVelocity;
}

void Circle::drawLines() 
{
	
	Vector2D vec = Vector2D(this->radius, 0.0f);
	Vector2D rot_v;
	Vector2D trans_rot_v;
	Vector2D trans_vec;
	velocity.printVector();
	float radians = 15.0f * 3.14159f / 180.0f;
	lines.clear();
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
