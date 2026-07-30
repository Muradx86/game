global TIME
global DoubleFault
extern TimerIrq
extern CountDown
TIME:
	CALL TimerIrq
	MOV DX,0x20
	MOV AL,0x20
	OUT DX,AL
	IRETD
DoubleFault:
	CLD
	MOV CX,0xFFFF
	MOV EDI,0xA0000
	MOV AX,1
	REP STOSB
	CLI
DIE:
	HLT
	JMP DIE 
