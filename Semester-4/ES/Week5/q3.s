#ALP to search an element in an array of 10 32-bit numbers using Linear Search.

	AREA RESET, DATA, READONLY
	EXPORT __Vectors

__Vectors
	
	DCD 0X10001000
	DCD Reset_Handler
	ALIGN
	AREA mycode, CODE,READONLY
	ENTRY
	EXPORT Reset_Handler

Reset_Handler
	
	LDR R0,=SRC
	LDR R1,=KEY
	LDR R4,=DST
	MOV R8,#10
	LDR R3,[R1]
UP	LDR R2,[R0],#4
	CMP R3,R2
	BEQ FOUND
	SUBS R8,#1
	CMP R8,#0
	BEQ DOWN
	BNE UP
DOWN MOV R9,#0
	STRB R9,[R4]
	B STOP
FOUND MOV R9,#1
	STRB R9,[R4]
STOP
	B STOP
SRC DCD 0,1,2,3,4,5,6,7,8,9
KEY DCD 3

	AREA mydata,DATA,READWRITE
DST DCD 0
	END