#ALP to convert hexadecimal to unpacked ASCII.

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

	LDR R6, =DST
	MOV R2, #0
	LDR R0, =SRC
	LDR R1, [R0]
UP	CMP R1, #0XA
	BCC STORE
	SUB R1, #0XA
	ADD R2, #01
	B UP
STORE
	ADD R1, #0X30
	STRB R1, [R6], #1
	MOV R1, R2
	MOV R2, #0
	CMP R1, #0XA
	BCS UP
	ADD R1, #0X30
	STRB R1, [R6]
STOP 
	B STOP
SRC DCD 0XFF
	AREA mydata, DATA, READWRITE
DST DCD 0
	END
