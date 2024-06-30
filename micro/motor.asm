
_main:

;motor.c,3 :: 		void main() {
;motor.c,4 :: 		trisb = 0x00;
	CLRF       TRISB+0
;motor.c,5 :: 		portb= 0x00;
	CLRF       PORTB+0
;motor.c,7 :: 		while(1){
L_main0:
;motor.c,8 :: 		portb.f0=1;
	BSF        PORTB+0, 0
;motor.c,9 :: 		portb.f1=0;
	BCF        PORTB+0, 1
;motor.c,10 :: 		delay_ms(1000);
	MOVLW      11
	MOVWF      R11+0
	MOVLW      38
	MOVWF      R12+0
	MOVLW      93
	MOVWF      R13+0
L_main2:
	DECFSZ     R13+0, 1
	GOTO       L_main2
	DECFSZ     R12+0, 1
	GOTO       L_main2
	DECFSZ     R11+0, 1
	GOTO       L_main2
	NOP
	NOP
;motor.c,12 :: 		portb.f0=0;
	BCF        PORTB+0, 0
;motor.c,13 :: 		portb.f1=0;
	BCF        PORTB+0, 1
;motor.c,14 :: 		delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main3:
	DECFSZ     R13+0, 1
	GOTO       L_main3
	DECFSZ     R12+0, 1
	GOTO       L_main3
	DECFSZ     R11+0, 1
	GOTO       L_main3
	NOP
	NOP
;motor.c,16 :: 		portb.f0=0;
	BCF        PORTB+0, 0
;motor.c,17 :: 		portb.f1=1;
	BSF        PORTB+0, 1
;motor.c,18 :: 		delay_ms(1000);
	MOVLW      11
	MOVWF      R11+0
	MOVLW      38
	MOVWF      R12+0
	MOVLW      93
	MOVWF      R13+0
L_main4:
	DECFSZ     R13+0, 1
	GOTO       L_main4
	DECFSZ     R12+0, 1
	GOTO       L_main4
	DECFSZ     R11+0, 1
	GOTO       L_main4
	NOP
	NOP
;motor.c,20 :: 		portb.f0=0;
	BCF        PORTB+0, 0
;motor.c,21 :: 		portb.f1=0;
	BCF        PORTB+0, 1
;motor.c,22 :: 		delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_main5:
	DECFSZ     R13+0, 1
	GOTO       L_main5
	DECFSZ     R12+0, 1
	GOTO       L_main5
	DECFSZ     R11+0, 1
	GOTO       L_main5
	NOP
	NOP
;motor.c,23 :: 		}
	GOTO       L_main0
;motor.c,24 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
