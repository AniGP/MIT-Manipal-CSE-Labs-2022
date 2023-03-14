#ALP to calculate Fibonacci Series upto 8 Terms.	

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
		
	MOV R5,=N
	LDR R0,=fib
	MOV R1,#0
	MOV R2,#1
	STRB R1,[R0],#1
	SUBS R5,=N
	BNE dwn
	B STOP
dwn STRB R2,[R0],#1
	MOV R3,R2
	ADD R2,R1
	MOV R1,R3
	B dwn
STOP
	B STOP
N DCD 8
	AREA mydata, DATA, READWRITE
fib DCD 0
	END