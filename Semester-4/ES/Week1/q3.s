#To transfer a 32-bit number from one location 
#in the data memory to another in the data memory.

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
	
	LDR R0, =SRC
	LDR R1, =DST
	LDR R3, [R0]
	STR R3, [R1]
STOP
	B STOP
	AREA mydata, DATA, READWRITE
SRC DCD 8
DST DCD 0
	END