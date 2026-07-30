#include "Port.h"
#include "Types.h"
#include "Pit.h"
#define DEFAULT 1193180
volatile U32 CountDown;
U0 SetTimer(U32 Freq)
{
	U32 Divider = DEFAULT/Freq;
	OutU8(0x40,Divider&0xFF);
	OutU8(0x40,Divider>>8);
}
U0 SetSound(U32 Freq)
{
	OutU8(0x43,0xB6);
	U32 GetFreq=DEFAULT/Freq;
	U8 Status=InU8(0x61);
	Status|=3;
	OutU8(0x61,Status);
	OutU8(0x42,GetFreq&0xFF);
	OutU8(0x42,GetFreq>>8);
}
U0 Sleep(U32 millis)
{
	CountDown=millis;
	while(CountDown)
		__asm__ volatile("NOP");	
}
U0 StopSound()
{
	U8 Status=InU8(0x61)&0xFC;
	OutU8(0x61,Status);
}
U0 Beep(U32 Freq)
{
	SetSound(Freq);
	Sleep(100);
	StopSound();
}
U0 TimerIrq()
{
	CountDown--;
}
