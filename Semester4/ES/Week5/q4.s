#Assume that there are 10 32-bit numbers stored in Registers R1-R10.
#Write an ALP to sort the empty ascending stack using Selection Sort and 
#store the sorted array back into the registers. Use STM and LDMDB
#wherever necessary.


AREA RESET,DATA,READONLY
	EXPORT __Vectors

__Vectors
	
	DCD 0x10001000
	DCD Reset_Handler
		ALIGN
		AREA mycode,CODE,READONLY
		ENTRY
		EXPORT Reset_Handler	

Reset_Handler
		
		mov r1, #1
		mov r2, #6
		mov r3, #4
		mov r4, #7
		mov r5, #9
		mov r6, #3
		mov r7, #2
		mov r8, #5
		mov r9, #8
		mov r10, #10
		stmia r13!, {r1-r10}
		mov r0, r13 ;r0 stores the stack top
		mov r2, #10 ;r2 stores number of elements in stack
		mov r8,#0	;r8 is counter for outer loop
ol		cmp r8,r2
		beq exit
		
		mov r1, r0	
		mov r3, r0
		sub r3, #4
		add r9,r8,#1
il		cmp r9,r2
		beq exin
		add r9,#1
		ldmdb r1,{r4}
		ldmdb r3!,{r5}
		cmp r5,r4
		blt il
		stmdb r1,{r5}
		stm r3,{r4}
		b il
exin	sub r0,#4
		add r8,#1
		b ol
		
exit	
		ldmdb r13!,{r1-r10}
stop 	B stop

		AREA mydata,DATA,READWRITE

		END