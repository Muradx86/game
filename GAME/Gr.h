#ifndef GR_H
#define GR_H
#include "../Types.h"
typedef struct Coordinates{
	I32 x,y;
}GrCoordinates;
U0 PutPixel(U32 x,U32 y,U8 color);
U0 DrawCircle(U32 x,U32 y,U32 r,U8 color);
U0 DrawSquare(U32 x,U32 y,U32 l,U8 color); 
GrCoordinates* Mat2x2Rot(U32 x,U32 y,F64 deg);
#endif
