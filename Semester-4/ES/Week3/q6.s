#ALP to covert 32-bit BCD number in the unpacked form to packed form.

	AREA RESET, DATA, READONLY
	EXPORT __Vectors

__Vectors
	
	DCD 0x1001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler

Reset_Handler

	LDR R0, =SRC
	LDR R2, =DST
	MOV R5, #2
UP	LDRB R1, [R0], #1
	LDRB R4, [R0], #1
	LSL R1, #4
	ADD R3, R1, R4
	STRB R3, [R2], #1
	SUBS R5, #1
	BNE UP
STOP
	B STOP
SRC DCD 0x01020304
	AREA mydata, DATA, READWRITE
DST DCD 0
	END