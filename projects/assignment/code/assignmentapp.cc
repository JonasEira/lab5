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

	void AssignmentApp::addBall(float r, float x, float y) {
		Vector2D pos;
		Vector2D vel;
		Circle circle;
		circle = Circle(r);
		pos = Vector2D(x, y);
		circle.setColor(1.0f, 1.0f, 1.0f);
		circle.setPosition(pos);
		vel = Vector2D(0.005f, 0.015f);
		circle.velocity = vel;
		circles.push_back(circle);
	}

	void AssignmentApp::addSquare(float b, float h, float x, float y) {
		Vector2D pos;
		Square sq;
		sq = Square(b, h);
		pos = Vector2D(x, y);
		sq.setColor(1.0f, 1.0f, 1.0f);
		sq.setPosition(pos);
		sq.velocity = Vector2D(0.0f, 0.0f);
		sq.setRotation(0.0f);
		squares.push_back(sq);
	}

	void AssignmentApp::addPlayer() {
		float b = 0.1f;
		float h = 0.05f;
		float x = 0.0f;;
		float y = -0.8f;
		Vector2D pos;
		this->player = Square(b, h);
		pos = Vector2D(x, y);
		this->player.setColor(1.0f, 1.0f, 1.0f);
		this->player.setPosition(pos);
		this->player.setRotation(0.0f);
		this->player.velocity = Vector2D(0.0f, 0.0f);
	}

	void
		AssignmentApp::Setup()
	{
		float squareWidth = 0.1f;
		float squareHeight = 0.05f;
		float x;
		float y;
		float spacing = 0.01f;
		int n_squares = 17;

		AssignmentApp::addPlayer();
		AssignmentApp::addBall(0.02f, 0.0f, 0.0f);

		for (int n = 0; n < n_squares; n++) {
			x = n * (squareWidth + spacing) - n_squares * (squareWidth + spacing) / 2.0f;
			y = 0.5;
			addSquare(squareWidth, squareHeight, x, y);
		}


		Display::Window* window = this->window;
		window->SetKeyPressFunction([this](int key, int, int action, int mod) {

			/*cout << "key = " << key << endl;
			cout << "action = " << action << endl;
			cout << "mod = " << mod << endl;*/

			if (key == 262 && action == 1) {
				Vector2D* v = &player.velocity;
				v->setX(0.015f);
			}
			if (key == 262 && action == 0) {
				Vector2D* v = &player.velocity;
				v->setX(0.0f);
			}
			if (key == 263 && action == 1) {
				Vector2D* v = &player.velocity;
				v->setX(-0.015f);
			}
			if (key == 263 && action == 0) {
				Vector2D* v = &player.velocity;
				v->setX(0.0f);
			}
		}
		);

	}

	// Find the inner section between circle and square
	bool isInside(Square& s, Circle& c) {
		bool inside = false;
		Vector2D* s_pos = &s.position;
		Vector2D* c_pos = &c.position;
		if (c_pos->getX() > s_pos->getX()
			&& c_pos->getX() < s_pos->getX() + s.width
			&& c_pos->getY() > s_pos->getY()
			&& c_pos->getY() < s_pos->getY() + s.height) {
			return true;
		}

		return false;
	}

	//------------------------------------------------------------------------------
	/**
	*/
	void
		AssignmentApp::Update()
	{

		player.update();
		player.drawLines();
		;
		for (int n = 0; n < squares.size(); n++) {
			Square* s = &squares.at(n);
			for (int n = 0; n < circles.size(); n++) {
				Circle* c = &circles.at(n);

				if (isInside(*s, *c)) {
					s->enabled = false;
					
				}
				else {
					s->update();
					s->drawLines();
				}
			}
		}

		for (int n = 0; n < circles.size(); n++) {
			Circle* c = &circles.at(n);
			c->update();
			c->drawLines();
		}
	}

} // namespace Assignment
