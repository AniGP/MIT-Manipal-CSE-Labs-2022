#ALP to convert 32-bit pacled BCD number into its hexadecimal equivalent number.

	AREA RESET, DATA, READONLY
	EXPORT __Vectors
		
__Vectors
	
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
	
Reset_Handler
	
	LDR R0,=N1
	LDR R1,=DST
	LDR R2,[R0]
	MOV R3,#1
	MOV R4,#0xA
	MOV R5,#0
	MOV R7,#0xF
up	MOV R6,R2
	AND R6,R7
	MLA R5,R6,R3,R5
	MUL R3,R4
	LSR R2,#4
	CMP R2,#0
	BNE up
	STR R5,[R1]

STOP
	B STOP
	
N1 DCD 0x0A
	AREA mydata, DATA, READWRITE
DST DCD 0
	END