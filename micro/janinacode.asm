
_main:

;janinacode.c,1 :: 		void main() {
;janinacode.c,2 :: 		while(1){
L_main0:
;janinacode.c,3 :: 		trisb = 0x00;
	CLRF       TRISB+0
;janinacode.c,4 :: 		portb = 1;
	MOVLW      1
	MOVWF      PORTB+0
;janinacode.c,5 :: 		trisc = 0x00;
	CLRF       TRISC+0
;janinacode.c,6 :: 		portc = 1;
	MOVLW      1
	MOVWF      PORTC+0
;janinacode.c,13 :: 		}
	GOTO       L_main0
;janinacode.c,14 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
