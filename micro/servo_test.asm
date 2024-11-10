
_servoRotate0:

;servo_test.c,1 :: 		void servoRotate0()        // 0 Degree
;servo_test.c,4 :: 		for(i=0;i<50;i++)
	CLRF       R1+0
	CLRF       R1+1
L_servoRotate00:
	MOVLW      0
	SUBWF      R1+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__servoRotate023
	MOVLW      50
	SUBWF      R1+0, 0
L__servoRotate023:
	BTFSC      STATUS+0, 0
	GOTO       L_servoRotate01
;servo_test.c,6 :: 		PORTB.F0=1;
	BSF        PORTB+0, 0
;servo_test.c,7 :: 		Delay_us(1300);      //1ms = 0 degree
	MOVLW      4
	MOVWF      R12+0
	MOVLW      95
	MOVWF      R13+0
L_servoRotate03:
	DECFSZ     R13+0, 1
	GOTO       L_servoRotate03
	DECFSZ     R12+0, 1
	GOTO       L_servoRotate03
;servo_test.c,8 :: 		PORTB.F0=0;
	BCF        PORTB+0, 0
;servo_test.c,9 :: 		Delay_us(18700);
	MOVLW      49
	MOVWF      R12+0
	MOVLW      145
	MOVWF      R13+0
L_servoRotate04:
	DECFSZ     R13+0, 1
	GOTO       L_servoRotate04
	DECFSZ     R12+0, 1
	GOTO       L_servoRotate04
;servo_test.c,4 :: 		for(i=0;i<50;i++)
	INCF       R1+0, 1
	BTFSC      STATUS+0, 2
	INCF       R1+1, 1
;servo_test.c,10 :: 		}
	GOTO       L_servoRotate00
L_servoRotate01:
;servo_test.c,11 :: 		}
L_end_servoRotate0:
	RETURN
; end of _servoRotate0

_servoRotate90:

;servo_test.c,13 :: 		void servoRotate90()           // 90 Degree
;servo_test.c,16 :: 		for(i=0;i<50;i++)
	CLRF       R1+0
	CLRF       R1+1
L_servoRotate905:
	MOVLW      0
	SUBWF      R1+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__servoRotate9025
	MOVLW      50
	SUBWF      R1+0, 0
L__servoRotate9025:
	BTFSC      STATUS+0, 0
	GOTO       L_servoRotate906
;servo_test.c,18 :: 		PORTB.F0=1;
	BSF        PORTB+0, 0
;servo_test.c,19 :: 		Delay_us(1495);     //1.5ms = 90 degree
	MOVLW      4
	MOVWF      R12+0
	MOVLW      225
	MOVWF      R13+0
L_servoRotate908:
	DECFSZ     R13+0, 1
	GOTO       L_servoRotate908
	DECFSZ     R12+0, 1
	GOTO       L_servoRotate908
;servo_test.c,20 :: 		if(i==0);
	MOVLW      0
	XORWF      R1+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__servoRotate9026
	MOVLW      0
	XORWF      R1+0, 0
L__servoRotate9026:
	BTFSS      STATUS+0, 2
	GOTO       L_servoRotate909
L_servoRotate909:
;servo_test.c,21 :: 		PORTB.F0=0;
	BCF        PORTB+0, 0
;servo_test.c,22 :: 		Delay_us(18500);
	MOVLW      49
	MOVWF      R12+0
	MOVLW      11
	MOVWF      R13+0
L_servoRotate9010:
	DECFSZ     R13+0, 1
	GOTO       L_servoRotate9010
	DECFSZ     R12+0, 1
	GOTO       L_servoRotate9010
	NOP
	NOP
;servo_test.c,16 :: 		for(i=0;i<50;i++)
	INCF       R1+0, 1
	BTFSC      STATUS+0, 2
	INCF       R1+1, 1
;servo_test.c,23 :: 		}
	GOTO       L_servoRotate905
L_servoRotate906:
;servo_test.c,24 :: 		}
L_end_servoRotate90:
	RETURN
; end of _servoRotate90

_servoRotate180:

;servo_test.c,26 :: 		void servoRotate180()             // 180 Degree
;servo_test.c,29 :: 		for(i=0;i<50;i++)
	CLRF       R1+0
	CLRF       R1+1
L_servoRotate18011:
	MOVLW      0
	SUBWF      R1+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__servoRotate18028
	MOVLW      50
	SUBWF      R1+0, 0
L__servoRotate18028:
	BTFSC      STATUS+0, 0
	GOTO       L_servoRotate18012
;servo_test.c,31 :: 		PORTB.F0=1;
	BSF        PORTB+0, 0
;servo_test.c,32 :: 		Delay_us(2200);      //2ms = 180 degree
	MOVLW      6
	MOVWF      R12+0
	MOVLW      181
	MOVWF      R13+0
L_servoRotate18014:
	DECFSZ     R13+0, 1
	GOTO       L_servoRotate18014
	DECFSZ     R12+0, 1
	GOTO       L_servoRotate18014
	NOP
	NOP
;servo_test.c,33 :: 		PORTB.F0=0;
	BCF        PORTB+0, 0
;servo_test.c,34 :: 		Delay_us(17800);
	MOVLW      47
	MOVWF      R12+0
	MOVLW      58
	MOVWF      R13+0
L_servoRotate18015:
	DECFSZ     R13+0, 1
	GOTO       L_servoRotate18015
	DECFSZ     R12+0, 1
	GOTO       L_servoRotate18015
	NOP
;servo_test.c,29 :: 		for(i=0;i<50;i++)
	INCF       R1+0, 1
	BTFSC      STATUS+0, 2
	INCF       R1+1, 1
;servo_test.c,35 :: 		}
	GOTO       L_servoRotate18011
L_servoRotate18012:
;servo_test.c,36 :: 		}
L_end_servoRotate180:
	RETURN
; end of _servoRotate180

_main:

;servo_test.c,40 :: 		void main() {
;servo_test.c,42 :: 		TRISB=0;          // PortB as output port
	CLRF       TRISB+0
;servo_test.c,43 :: 		while(1){
L_main16:
;servo_test.c,44 :: 		servoRotate0();          // 0 Degree
	CALL       _servoRotate0+0
;servo_test.c,45 :: 		Delay_ms(2000);
	MOVLW      21
	MOVWF      R11+0
	MOVLW      75
	MOVWF      R12+0
	MOVLW      190
	MOVWF      R13+0
L_main18:
	DECFSZ     R13+0, 1
	GOTO       L_main18
	DECFSZ     R12+0, 1
	GOTO       L_main18
	DECFSZ     R11+0, 1
	GOTO       L_main18
	NOP
;servo_test.c,47 :: 		servoRotate90();          // 90 Degree
	CALL       _servoRotate90+0
;servo_test.c,48 :: 		Delay_ms(2000);
	MOVLW      21
	MOVWF      R11+0
	MOVLW      75
	MOVWF      R12+0
	MOVLW      190
	MOVWF      R13+0
L_main19:
	DECFSZ     R13+0, 1
	GOTO       L_main19
	DECFSZ     R12+0, 1
	GOTO       L_main19
	DECFSZ     R11+0, 1
	GOTO       L_main19
	NOP
;servo_test.c,50 :: 		servoRotate180();         // 180 Degree
	CALL       _servoRotate180+0
;servo_test.c,51 :: 		Delay_ms(2000);
	MOVLW      21
	MOVWF      R11+0
	MOVLW      75
	MOVWF      R12+0
	MOVLW      190
	MOVWF      R13+0
L_main20:
	DECFSZ     R13+0, 1
	GOTO       L_main20
	DECFSZ     R12+0, 1
	GOTO       L_main20
	DECFSZ     R11+0, 1
	GOTO       L_main20
	NOP
;servo_test.c,54 :: 		servoRotate90();         // 90 Degree
	CALL       _servoRotate90+0
;servo_test.c,55 :: 		Delay_ms(2000);
	MOVLW      21
	MOVWF      R11+0
	MOVLW      75
	MOVWF      R12+0
	MOVLW      190
	MOVWF      R13+0
L_main21:
	DECFSZ     R13+0, 1
	GOTO       L_main21
	DECFSZ     R12+0, 1
	GOTO       L_main21
	DECFSZ     R11+0, 1
	GOTO       L_main21
	NOP
;servo_test.c,57 :: 		}
	GOTO       L_main16
;servo_test.c,58 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
