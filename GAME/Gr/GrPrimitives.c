#include "../Types.h"
#include "../Math.h"
volatile U8* VideoBuf=(volatile U8*)0xA0000;
U0 PutPixel(U32 x,U32 y,U8 color)
{
	VideoBuf[320*y+x]=color;
}
U0 DrawCircle(U32 x,U32 y,U32 r,U8 color)
{
	F64 Theta,X,Y;
	int i;
	for(i=0;i<=360;i++){
		Theta=2*PI*i;
		X=Cos(Theta)*r+x;
		Y=Sin(Theta)*r+y;
		PutPixel(X,Y,color);
	}
}
