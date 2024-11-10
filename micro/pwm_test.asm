
_InitMain:

;pwm_test.c,1 :: 		void InitMain() {
;pwm_test.c,2 :: 		trisb = 0x00;
	CLRF       TRISB+0
;pwm_test.c,3 :: 		portb = 0x00;
	CLRF       PORTB+0
;pwm_test.c,4 :: 		trisc = 0x00;
	CLRF       TRISC+0
;pwm_test.c,5 :: 		portc = 0x00;
	CLRF       PORTC+0
;pwm_test.c,6 :: 		trisd = 0xff;
	MOVLW      255
	MOVWF      TRISD+0
;pwm_test.c,7 :: 		portd = 0x00;
	CLRF       PORTD+0
;pwm_test.c,8 :: 		}
L_end_InitMain:
	RETURN
; end of _InitMain

_main:

;pwm_test.c,10 :: 		void main() {
;pwm_test.c,11 :: 		InitMain();
	CALL       _InitMain+0
;pwm_test.c,12 :: 		while (1) {
L_main0:
;pwm_test.c,13 :: 		if(portd.B0){
	BTFSS      PORTD+0, 0
	GOTO       L_main2
;pwm_test.c,14 :: 		while(portd.b0);
L_main3:
	BTFSS      PORTD+0, 0
	GOTO       L_main4
	GOTO       L_main3
L_main4:
;pwm_test.c,15 :: 		ii+=ii+1>10?0:1;
	MOVF       _ii+0, 0
	ADDLW      1
	MOVWF      R1+0
	MOVLW      0
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      _ii+1, 0
	MOVWF      R1+1
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      R1+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main26
	MOVF       R1+0, 0
	SUBLW      10
L__main26:
	BTFSC      STATUS+0, 0
	GOTO       L_main5
	CLRF       ?FLOC___mainT4+0
	GOTO       L_main6
L_main5:
	MOVLW      1
	MOVWF      ?FLOC___mainT4+0
L_main6:
	MOVF       ?FLOC___mainT4+0, 0
	ADDWF      _ii+0, 1
	BTFSC      STATUS+0, 0
	INCF       _ii+1, 1
	MOVLW      0
	BTFSC      ?FLOC___mainT4+0, 7
	MOVLW      255
	ADDWF      _ii+1, 1
;pwm_test.c,16 :: 		jj-=jj-1<0?0:1;
	MOVLW      1
	SUBWF      _jj+0, 0
	MOVWF      R1+0
	MOVLW      0
	BTFSS      STATUS+0, 0
	ADDLW      1
	SUBWF      _jj+1, 0
	MOVWF      R1+1
	MOVLW      128
	XORWF      R1+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main27
	MOVLW      0
	SUBWF      R1+0, 0
L__main27:
	BTFSC      STATUS+0, 0
	GOTO       L_main7
	CLRF       ?FLOC___mainT8+0
	GOTO       L_main8
L_main7:
	MOVLW      1
	MOVWF      ?FLOC___mainT8+0
L_main8:
	MOVF       ?FLOC___mainT8+0, 0
	SUBWF      _jj+0, 1
	MOVLW      0
	BTFSC      ?FLOC___mainT8+0, 7
	MOVLW      255
	BTFSS      STATUS+0, 0
	ADDLW      1
	SUBWF      _jj+1, 1
;pwm_test.c,17 :: 		}
L_main2:
;pwm_test.c,18 :: 		if(portd.B1){
	BTFSS      PORTD+0, 1
	GOTO       L_main9
;pwm_test.c,19 :: 		while(portd.b1);
L_main10:
	BTFSS      PORTD+0, 1
	GOTO       L_main11
	GOTO       L_main10
L_main11:
;pwm_test.c,20 :: 		ii-=ii-1<0?0:1;
	MOVLW      1
	SUBWF      _ii+0, 0
	MOVWF      R1+0
	MOVLW      0
	BTFSS      STATUS+0, 0
	ADDLW      1
	SUBWF      _ii+1, 0
	MOVWF      R1+1
	MOVLW      128
	XORWF      R1+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main28
	MOVLW      0
	SUBWF      R1+0, 0
L__main28:
	BTFSC      STATUS+0, 0
	GOTO       L_main12
	CLRF       ?FLOC___mainT14+0
	GOTO       L_main13
L_main12:
	MOVLW      1
	MOVWF      ?FLOC___mainT14+0
L_main13:
	MOVF       ?FLOC___mainT14+0, 0
	SUBWF      _ii+0, 1
	MOVLW      0
	BTFSC      ?FLOC___mainT14+0, 7
	MOVLW      255
	BTFSS      STATUS+0, 0
	ADDLW      1
	SUBWF      _ii+1, 1
;pwm_test.c,21 :: 		jj+=jj+1>10?0:1;
	MOVF       _jj+0, 0
	ADDLW      1
	MOVWF      R1+0
	MOVLW      0
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      _jj+1, 0
	MOVWF      R1+1
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      R1+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main29
	MOVF       R1+0, 0
	SUBLW      10
L__main29:
	BTFSC      STATUS+0, 0
	GOTO       L_main14
	CLRF       ?FLOC___mainT18+0
	GOTO       L_main15
L_main14:
	MOVLW      1
	MOVWF      ?FLOC___mainT18+0
L_main15:
	MOVF       ?FLOC___mainT18+0, 0
	ADDWF      _jj+0, 1
	BTFSC      STATUS+0, 0
	INCF       _jj+1, 1
	MOVLW      0
	BTFSC      ?FLOC___mainT18+0, 7
	MOVLW      255
	ADDWF      _jj+1, 1
;pwm_test.c,22 :: 		}
L_main9:
;pwm_test.c,23 :: 		portb=0b01;
	MOVLW      1
	MOVWF      PORTB+0
;pwm_test.c,24 :: 		for(i=0;i<ii;i++) delay_ms(1);
	CLRF       _i+0
	CLRF       _i+1
L_main16:
	MOVLW      128
	XORWF      _i+1, 0
	MOVWF      R0+0
	MOVLW      128
	XORWF      _ii+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main30
	MOVF       _ii+0, 0
	SUBWF      _i+0, 0
L__main30:
	BTFSC      STATUS+0, 0
	GOTO       L_main17
	MOVLW      3
	MOVWF      R12+0
	MOVLW      151
	MOVWF      R13+0
L_main19:
	DECFSZ     R13+0, 1
	GOTO       L_main19
	DECFSZ     R12+0, 1
	GOTO       L_main19
	NOP
	NOP
	INCF       _i+0, 1
	BTFSC      STATUS+0, 2
	INCF       _i+1, 1
	GOTO       L_main16
L_main17:
;pwm_test.c,25 :: 		portb=0b00;
	CLRF       PORTB+0
;pwm_test.c,26 :: 		for(j=0;j<jj;j++) delay_ms(1);
	CLRF       _j+0
	CLRF       _j+1
L_main20:
	MOVLW      128
	XORWF      _j+1, 0
	MOVWF      R0+0
	MOVLW      128
	XORWF      _jj+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main31
	MOVF       _jj+0, 0
	SUBWF      _j+0, 0
L__main31:
	BTFSC      STATUS+0, 0
	GOTO       L_main21
	MOVLW      3
	MOVWF      R12+0
	MOVLW      151
	MOVWF      R13+0
L_main23:
	DECFSZ     R13+0, 1
	GOTO       L_main23
	DECFSZ     R12+0, 1
	GOTO       L_main23
	NOP
	NOP
	INCF       _j+0, 1
	BTFSC      STATUS+0, 2
	INCF       _j+1, 1
	GOTO       L_main20
L_main21:
;pwm_test.c,27 :: 		}
	GOTO       L_main0
;pwm_test.c,28 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
