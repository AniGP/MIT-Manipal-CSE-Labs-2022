#To transfer a block of 10 32-bit numbers when the source 
#and destination blocks are overlapping.


	AREA RESET, DATA, READONLY
	EXPORT __Vectors

__Vectors
	
	DCD 0x10001000 
	DCD Reset_Handler 
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler

Reset_Handler
	
	LDR R0,=SRC 
	LDR R4,=1 
	MOV R6,#10
	MOV R7,#5
lp	STR R4,[R0],#4
	MUL R4,R7;
	SUBS R6,#1
	BNE lp
	LDR R5,=N
	LDR R0,=SRC+(N-1)*4
	MOV R1,R0
	SUB R1,#(OL-1)*4
	ADD R1,#(N-1)*4
UP	LDR R2,[R0],#-4
	STR R2,[R1],#-4
	SUBS R5,#1
	BNE UP
STOP
	B STOP

N EQU 10
OL EQU 2
	AREA mydata, DATA, READWRITE
SRC DCD 1,2,3,4,5,6,7,8,9,10 
	END