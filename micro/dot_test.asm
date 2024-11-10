
_main:

;dot_test.c,7 :: 		void main() {
;dot_test.c,8 :: 		TRISB = 0x00;
	CLRF       TRISB+0
;dot_test.c,9 :: 		TRISD = 0x00;
	CLRF       TRISD+0
;dot_test.c,11 :: 		while (1) {
L_main0:
;dot_test.c,12 :: 		for (i = 0; i < 8; i++) {
	CLRF       _i+0
	CLRF       _i+1
L_main2:
	MOVLW      128
	XORWF      _i+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main7
	MOVLW      8
	SUBWF      _i+0, 0
L__main7:
	BTFSC      STATUS+0, 0
	GOTO       L_main3
;dot_test.c,13 :: 		PORTD = 1 << i;
	MOVF       _i+0, 0
	MOVWF      R1+0
	MOVLW      1
	MOVWF      R0+0
	MOVF       R1+0, 0
L__main8:
	BTFSC      STATUS+0, 2
	GOTO       L__main9
	RLF        R0+0, 1
	BCF        R0+0, 0
	ADDLW      255
	GOTO       L__main8
L__main9:
	MOVF       R0+0, 0
	MOVWF      PORTD+0
;dot_test.c,14 :: 		PORTB = letter[i];
	MOVF       _i+0, 0
	ADDLW      _letter+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;dot_test.c,15 :: 		Delay_ms(2);
	MOVLW      6
	MOVWF      R12+0
	MOVLW      48
	MOVWF      R13+0
L_main5:
	DECFSZ     R13+0, 1
	GOTO       L_main5
	DECFSZ     R12+0, 1
	GOTO       L_main5
	NOP
;dot_test.c,12 :: 		for (i = 0; i < 8; i++) {
	INCF       _i+0, 1
	BTFSC      STATUS+0, 2
	INCF       _i+1, 1
;dot_test.c,16 :: 		}
	GOTO       L_main2
L_main3:
;dot_test.c,17 :: 		}
	GOTO       L_main0
;dot_test.c,18 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
