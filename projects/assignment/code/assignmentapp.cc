//------------------------------------------------------------------------------
// assignmentapp.cc
// (C) 2015-2017 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "assignmentapp.h"
#include <iostream>
#include <math.h>

namespace Assignment
{

//------------------------------------------------------------------------------
/**
*/
AssignmentApp::AssignmentApp()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
AssignmentApp::~AssignmentApp()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/

void AssignmentApp::addCircle(float r, float x, float y) {
	Vector2D pos;
	Circle circle;
	circle = Circle(r);
	pos = Vector2D(x, y);
	float red = rand() / 100000.0f;
	float green = rand() / 100000.0f;
	float blue = rand() / 100000.0f;
	circle.setColor(red, green, blue);
	circle.setPosition(pos);
	circles.push_back(circle);
}
void AssignmentApp::addTriangle(float b, float h, float x, float y) {
	Vector2D pos;
	Triangle tri;
	float red = rand() / 100000.0f;
	float green = rand() / 100000.0f;
	float blue = rand() / 100000.0f;
	tri = Triangle(b,h);
	tri.setColor(red, green, blue);
	pos = Vector2D(x, y);
	tri.setPosition(pos);
	tri.setRotation(2.0f*3.1415f*rand() / 100000.0f);
	triangles.push_back(tri);
}
void AssignmentApp::addSquare(float b, float h, float x, float y) {
	Vector2D pos;
	Square sq;
	sq = Square(b,h);
	pos = Vector2D(x, y);
	float red = rand() / 100000.0f;
	float green = rand() / 100000.0f;
	float blue = rand() / 100000.0f;
	sq.setColor(red, green, blue);
	sq.setPosition(pos);
	sq.setRotation(2.0f*3.1415f*rand() / 100000.0f);
	squares.push_back(sq);
}

void 
AssignmentApp::Setup()
{
	Display::Window* window = this->window;
	window->SetKeyPressFunction([this](int key, int, int action, int mod) {
		
		/*cout << "key = " << key << endl;
		cout << "action = " << action << endl;
		cout << "mod = " << mod << endl;*/
		
		float rand_x = 2.0f*((float)rand()) / RAND_MAX - 1.0f;
		float rand_y = 2.0f*((float)rand()) / RAND_MAX - 1.0f;

		//cout << "rand_x = " << rand_x << " rand_y = " << rand_y << endl;

		if (key == 49 && action == 1) {
			AssignmentApp::addSquare(0.2f, 0.2f, rand_x, rand_y);
		}
		if (key == 50 && action == 1) {
			AssignmentApp::addTriangle(0.2f, 0.2f, rand_x, rand_y);
		}
		if (key == 51 && action == 1) {
			AssignmentApp::addCircle(0.2f, rand_x, rand_y);
		}
		if ((key == 113 || key == 81) && action == 1) {
			AssignmentApp::squares.clear();
		}
		if ((key == 119 || key == 87) && action == 1) {
			AssignmentApp::triangles.clear();
		}
		if ((key == 101 || key == 69) && action == 1) {
			AssignmentApp::circles.clear();
		}
	}
	);

}

//------------------------------------------------------------------------------
/**
*/
void
AssignmentApp::Update()
{
	for (int n = 0; n < squares.size(); n++) {
		Square s_ptr = squares.at(n);
		s_ptr.update();
	}
	for (int n = 0; n < circles.size(); n++) {
		Circle c_ptr = circles.at(n);
		c_ptr.update();
	}
	for (int n = 0; n < triangles.size(); n++) {
		Triangle t_ptr = triangles.at(n);
		t_ptr.update();
	}
	//AssignmentApp::PrintText("triangle", 0.5f, 0.5f);
}

} // namespace Assignment
