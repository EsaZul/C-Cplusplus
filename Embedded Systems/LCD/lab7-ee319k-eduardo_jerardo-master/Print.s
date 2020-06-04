; Print.s
; Student names: change this to your names or look very silly
; Last modification date: change this to the last modification date or look very silly
; Runs on LM4F120 or TM4C123
; EE319K lab 7 device driver for any LCD
;
; As part of Lab 7, students need to implement these LCD_OutDec and LCD_OutFix
; This driver assumes two low-level LCD functions
; ST7735_OutChar   outputs a single 8-bit ASCII character
; ST7735_OutString outputs a null-terminated string 

    IMPORT   ST7735_OutChar
    IMPORT   ST7735_OutString
    EXPORT   LCD_OutDec
    EXPORT   LCD_OutFix

    AREA    |.text|, CODE, READONLY, ALIGN=2
    THUMB

  

;-----------------------LCD_OutDec-----------------------
; Output a 32-bit number in unsigned decimal format
; Input: R0 (call by value) 32-bit unsigned number
; Output: none
; Invariables: This function must not permanently modify registers R4 to R11
LCD_OutDec

int 	EQU 0					; int variable
factor	EQU 4			     	; factor of 10
	
		POP {R4, LR}
		CMP R0, #0				
		BEQ special				; if the input is 0, special case
		SUB SP, #8			    ; two variables space
		MOV R1, #9		
		MOV R4, #1				; R4 ignores leading 0s
		
decOUT	
banner	CMP R4, #1				; if R4 is 1, don't output zeros
		BE nothing
		ADD R0, #48				; ASCII
		POP {R0, R1, R4, R3}
		BL ST7735_OutChar		; left most integer ouptu
		POP {R0, R1, R4, R3}
		SUBC R0, #48
		
nothing	MUL R0, R3
		SUB R1, R1, R0			; R1 = int - (R0 * 10^factor) --> remainder
		ORR R0, R1				; R0 = R1
		LDR R1, [SP, #factor]
		SUBS R1, #1				
		BGE decOUT				; if factor is less than zero, return to mainSTR R1, [SP, #factor]	; factor into R1
		STR R0, [SP, #int]		; int into R0
		
		ORR R3, #1				; R3 mask 10^factor
		MOV R2, #10
		CMP R1, #0
		BEQ ones				; ones decimal place
		
left	MUL R3, R2				
		SUBS R1, #1				; R1 = R1 - 1
		BNE left				; if not zero, we want the leftmost integer so multiphy by 10
		
ones	LDR R1, [SP, #int]		; R1 = int
		UDIV R0, R1, R3			; R0 = int / (10^factor)
		CMP R0, #0
		BEQ banner
		MOV R4, #0				; R4 is cleared if not a leading zero
		

		
		ADD SP, #8
		
stop	POP {R4, LR}
		BX  LR	 

special	MOV R0, #48
		BL ST7735_OutChar
		B stop

;* * * * * * * * End of LCD_OutDec * * * * * * * *

; -----------------------LCD _OutFix----------------------
; Output characters to LCD display in fixed-point format
; unsigned decimal, resolution 0.001, range 0.000 to 9.999
; Inputs:  R0 is an unsigned 32-bit number
; Outputs: none
; E.g., R0=0,    then output "0.000 "
;       R0=3,    then output "0.003 "
;       R0=89,   then output "0.089 "
;       R0=123,  then output "0.123 "
;       R0=9999, then output "9.999 "
;       R0>9999, then output "*.*** "
; Invariables: This function must not permanently modify registers R4 to R11
LCD_OutFix

over	EQU 0					; left over, remainder
ponent	EQU 4					; exponent
	
	
out		CMP R1, #2
		BNE none				; put the decimal
		Pop {R0, R1, R4, R3}
		BL dot
		POP {R0, R1, R4, R3}
none	STR R1, [SP, #ponent]	; ponent = R1
		STR R0, [SP, #over]		; over = R0
		
		MOV R3, #1				; R3 mask 10^exp
		ORR R2, #10
		CMP R1, #0
		BEQ ones2				; ones decimal place
left2	MUL R3, R2				
		SUBS R1, #1				; R1 = R1 - 1
		BNE left2				; if not zero, leftmost int so x10
		PUSH {R4, LR}
		MOV R1, #10000
		CMP R0, R1
		BHS stars				; if the input is greater than 9999, output stars
		SUB SP, #8			    ; space fro two variables
		MOV R1, #3		

ones2	LDR R1, [SP, #over]		; R1 = over
		UDIV R0, R1, R3			; R0 = over / (10^ponent)
		ADD R0, #48				; ASCII
		PUSH {R0, R1, R4, R3}
		BL ST7735_OutChar		; left most integer, output
		POP {R0, R1, R4, R3}
		SUBS R0, #48
		MUL R0, R3
		SUB R1, R1, R0			; R1 = over - (R0 * 10^ponent) --> remainder
		MOV R0, R1				; R0 = R1
		LDR R1, [SP, #ponent]
		SUBS R1, #1				
		BGE out					; if ponent less than zero, return tomain
		
		ADD SP, #8
Sstop	POP {R4, LR}

		BX   LR
		
dot
		PUSH {R4, LR}
		MOV R0, #46
		BL ST7735_OutChar
		POP {R4, LR}
		BX LR
	
star
		PUSH {R4, LR}
		MOV R0, #42
		BL ST7735_OutChar
		POP {R4, LR}
			
stars							; this subroutine outputs *.***

		BL star
		BL dot
		BL star
		BL star
		BL star
		B  Sstop				; stars stop, or end
	

		
		BX LR
		
		ALIGN
;* * * * * * * * End of LCD_OutFix * * * * * * * *

		ALIGN                   ; make sure the end of this section is aligned
		END                     ; end of file
