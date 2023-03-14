#Add two 32-bit packed BCD numbers and store the result in packed BCD form.

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
	LDR R2,[R0]
	LDR R0,=N2
	LDR R3,[R0]
	LDR R0,=DST
	MOV R6,#0
up	MOV R7,R2
	MOV R8,R3
	AND R7,#0xF
	ADD R7,R6
	MOV R6,#0
	AND R8,#0xF
	BL addn
	LSR R2,#4
	CMP R2,#0
	BNE up
	STRB R6,[R0]
STOP
	B STOP
addn ADDS R7,R8
	CMP R7,#0xA
	BCC store
	SUB R7,#0xA
	ADD R6,#01
store STRB R7,[R0],#1

	bx lr

N1 DCD 0x0025
N2 DCD 0x0016
	AREA mydata,DATA,READWRITE
DST DCD 0
	END
	
	
	