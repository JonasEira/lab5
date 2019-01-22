//------------------------------------------------------------------------------
/**
	Application class used for Assignment applications.
	Based on 2D app
	
	(C) 2015-2017 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "config.h"
#include "core/app.h"
#include "render/window.h"
#include "2d/2dapp.h"
#include <vector>
#include "Triangle.h"
#include "Circle.h"
#include "Square.h"
namespace Assignment
{
class AssignmentApp : public App2D::BaseApp
{
public:
	vector<Circle> circles;
	vector<Square> squares;
	vector<Triangle> triangles;
	Square player;
	static AssignmentApp& GetInstance()
	{
		static AssignmentApp instance;
		return instance;
	}

	/// destructor
	~AssignmentApp();

	/// initialize, create shapes etc
	void Setup();

	/// update app, draw lines etc
	void Update();

	/// line drawing function
	static void DrawLine(const LineData & line);

	void addBall(float r, float x, float y);

	void addSquare(float b, float h, float x, float y);

	void addPlayer();

private:
	/// constructor hidden because it is a singleton
	AssignmentApp();
	/// also hidden because of the singleton
	AssignmentApp(AssignmentApp const &);
	/// also hidden because of the singleton
	void operator=(AssignmentApp const &);

	Matrix2D AssignmentApp::getSquareBounds(Square* sq);

	bool WIN = false;
	bool OUTSIDE = false;
};

//------------------------------------------------------------------------------
/**
*/
inline void 
AssignmentApp::DrawLine( const LineData & line )
{
	AssignmentApp::GetInstance().AddLine(line);
}
} // namespace Assignment