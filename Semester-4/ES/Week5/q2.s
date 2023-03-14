#ALP to find the factorial of an unsigned number using recursion.

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

	LDR R0,=input
	LDR R1,=result
	LDR R2,[R0]
	BL fct
	STR R2,[R1]
HERE B HERE
fct PUSH{R3,LR}
	MOV R3,R2
	CMP R2,#0
	BNE dwn
	MOV R2,#1
	B dwn1
dwn SUB R2,#1
	BL fct
	MOV R4,R3
	MUL R2,R4
dwn1 POP{R3,LR}
	BX LR
	
input DCD 0x5
	AREA mydata, DATA, READWRITE
result DCD 0
	END