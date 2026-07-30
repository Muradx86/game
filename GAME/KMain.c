#include "Math.h"
#include "Extern.h"
#include "Types.h"
#include "Gr/Gr.h"
#include "Pit.h"
U0 putpx(U32 x,U32 y);
U0 KStart(){
	SetTimer(100); //180HZ.
	asm volatile
	(	"CLD\n"
		"MOV EAX,CR0\n"
		"BTS EAX,5\n"
		"MOV CR0,EAX\n"
		"FNINIT"
	);
	KMemset((U0*)0xA0000,0x55,64000);
	MakeIdt();

	int i;
	F64 theta,x,y;
	for(i=0;i<=100;i++){
		theta=2*PI*i;
		x=Sin(theta)*20+100;
		y=Cos(theta)*20+50;
		putpx(x,y);
	}
	I32 random_check=RandomU32();

	if(random_check>0)
		Beep(100);

	while(1)  asm volatile("HLT");
}
U0 putpx(U32 x,U32 y)
{
	volatile U8* buff=(volatile U8*)0xA0000;
	buff[320*y+x]=6;
}
