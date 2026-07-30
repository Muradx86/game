#include "Port.h"
#include "Types.h"
#include <stdbool.h>
#define BREAK_CODE 0x80
#define WIDTH 	   320
#define UP		   0x48
#define LEFT	   0x4B
#define DOWN	   0x50
#define RIGHT	   0x4D
#define ENTER	   0x1C
static volatile U8* VideoBuffer=(volatile U8*)0xA0000;
struct Cursor{
	I32 x,y;
	U16 color;
};
struct Cursor* Cursor;
U0 Init()
{
	Cursor->x=0;
	Cursor->y=0;
	Cursor->color=1;
}
U8 Locker=FALSE;
U0 DrawMain()
{
	U8 ScanCode=InU8(0x64);
	bool Clicked=!(ScanCode&BREAK_CODE);
	if(!Clicked)
		goto end;
	switch(ScanCode){
		case UP: Cursor->y--; break;
		case DOWN: Cursor->y++; break;
		case LEFT: Cursor->x--; break;
		case RIGHT: Cursor->x++; break;
	}
	
end:
	return;
}
