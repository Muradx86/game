#include "Types.h"
extern U0 TIME();
extern U0 DoubleFault();
extern U0 RemapPic();
struct idt{
	U16 Offset_l;
	U16 Selector;
	U8 Unused;
	U8 Flags;
	U16 Offset_h; 
}__attribute__((packed));
struct idt idt[256];
//Function array reserved for further use.
U0 (*Handlers[256])() = 
{
	0,0,0,0,0,0,0,0,DoubleFault,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,TIME
};
U0 SetGate(U8 vctr,U32 func,U8 flag)
{	
	idt[vctr].Offset_l = func & 0xFFFF;
	idt[vctr].Selector = 0x8;
	idt[vctr].Unused = 0;
	idt[vctr].Flags = flag;
	idt[vctr].Offset_h = func >> 16;
}
U0 MakeIdt()
{
	asm volatile("CLI");
	struct idtr{
		U16 limit;
		U32 base;
	}__attribute__((packed));
	struct idtr idtr;
	idtr.limit = 0x7FF;
	idtr.base = (U32)(&idt);
	RemapPic();
	SetGate(0x20,(U32)TIME,0x8E);
	SetGate(0x8,(U32)DoubleFault,0x8F);
	SetGate(0x21,(U32)TIME,0x8E);
	asm volatile("LIDT %0": :"m"(idtr));
	asm volatile("STI");
}
