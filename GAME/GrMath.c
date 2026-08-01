#include "Gr.h"
#include "../Types.h"
#include "../Math.h"
static volatile U32* idle; 
GrCoordinates* Mat2x2Rot(U32 x,U32 y,F64 deg)
{
	F64 X,Y;
	GrCoordinates* NewCoordinates;
	X=x*Cos(deg)-y*Sin(deg);
	Y=x*Sin(deg)+y*Cos(deg);
	NewCoordinates=(GrCoordinates*)idle;
	NewCoordinates->x=X;
	NewCoordinates->y=Y;
	return NewCoordinates;
}
