//------------------------------------------------------------------------------
// assignmentapp.cc
// (C) 2015-2017 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "assignmentapp.h"
#include "Square.h"
#include "Triangle.h"
#include "Circle.h"
namespace Assignment 
{

	//------------------------------------------------------------------------------
	/**
	*/
	
	AssignmentApp::AssignmentApp()
	{
		// empty
	}

	void AssignmentApp::operator=(AssignmentApp const &)
	{
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
	void AssignmentApp::Setup() {
		Display::Window* window = this->window;
		window->SetKeyPressFunction([this](int key, int, int action, int mod) {
		
			if (key == 49) {
				addSquare(0.2f, 0.2f, 0.0f, 0.0f);
			}
			if (key == 50) {
				addTriangle(0.2f, 0.2f, 0.0f, 0.0f);
			}
			if (key == 51) {
				addCircle(0.2f, 0.0f, 0.0f);
			}
			if (key == 113) {
				squares.clear();
			}
			if (key == 119) {
				triangles.clear();
			}
			if (key == 101) {
				circles.clear();
			}
		}
		);

	}

	void AssignmentApp::addCircle(float r, float x, float y) {
		Vector2D pos = Vector2D(0.5f, 0.0f);
		Circle circle;
		circle = Circle(0.2f);
		pos = Vector2D(0.0f, 0.0f);
		circle.setPosition(pos);
		circles.emplace_back(circle);
	}
	void AssignmentApp::addTriangle(float b, float h, float x, float y) {
		Vector2D pos = Vector2D(0.5f, 0.0f);
		Triangle tri;
		tri = Triangle(0.2f, 0.2f);
		pos = Vector2D(0.0f, 0.0f);
		tri.setPosition(pos);
		triangles.push_back(tri);
	}
	void AssignmentApp::addSquare(float b, float h, float x, float y) {
		Vector2D pos = Vector2D(0.5f, 0.0f);
		Square sq;
		sq = Square(0.2f, 0.2f);
		pos = Vector2D(0.0f, 0.0f);
		sq.setPosition(pos);
		squares.push_back(sq);
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

		/*sq.update();
		for (App2D::BaseApp::LineData line : sq.lines) {
			AssignmentApp::DrawLine(line);
		}
		tri.update();
		for (App2D::BaseApp::LineData line : tri.lines) {
			AssignmentApp::DrawLine(line);
		}
		circle.update();
		for (App2D::BaseApp::LineData line : circle.lines) {
			AssignmentApp::DrawLine(line);
		}*/

		//// demo line drawing code
		//LineData line;
		//line.x1 = -0.3f;
		//line.y1 = -0.3f;
		//line.x2 = 0.0f;
		//line.y2 = 0.5f;
		//line.c1.r = 1.0f;
		//AssignmentApp::DrawLine(line);	
		//line.x1 = 0.0f;
		//line.y1 = 0.5f;
		//line.x2 = 0.3f;
		//line.y2 = -0.3f;	
		//AssignmentApp::DrawLine(line);	
		//line.x1 = 0.3f;
		//line.y1 = -0.3f;
		//line.x2 = -0.3f;
		//line.y2 = -0.3f;
		//AssignmentApp::DrawLine(line);	
		//AssignmentApp::PrintText("triangle", 0.5f, 0.5f);
	}

} // namespace Assignment
