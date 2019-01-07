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
	static AssignmentApp& GetInstance()
	{
		static AssignmentApp instance;
		return instance;
	}

	/// destructor
	~AssignmentApp();

	/// initialize, create shapes etc
	void Setup();

	void addCircle(float r, float x, float y);

	void addTriangle(float b, float h, float x, float y);

	void addSquare(float b, float h, float x, float y);

	/// update app, draw lines etc
	void Update();

	/// line drawing function
	static void DrawLine(const LineData & line);

private:
	/// constructor hidden because it is a singleton
	AssignmentApp();
	/// also hidden because of the singleton
	AssignmentApp(AssignmentApp const &);
	/// also hidden because of the singleton
	void operator=(AssignmentApp const &);

};

//------------------------------------------------------------------------------
/**
*/
inline void 
AssignmentApp::DrawLine( const LineData & line )
{
	AssignmentApp::GetInstance().AddLine(line);
}
