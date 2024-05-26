
_main:

;sevensegment.c,4 :: 		void main() {
;sevensegment.c,5 :: 		int i=0;
	CLRF       main_i_L0+0
	CLRF       main_i_L0+1
;sevensegment.c,6 :: 		TRISB=0x00;
	CLRF       TRISB+0
;sevensegment.c,7 :: 		PORTB=0x00;
	CLRF       PORTB+0
;sevensegment.c,9 :: 		TRISC.f0=0xff;
	BSF        TRISC+0, 0
;sevensegment.c,10 :: 		TRISC.f1=0xff;
	BSF        TRISC+0, 1
;sevensegment.c,12 :: 		portc.f0=0x00;
	BCF        PORTC+0, 0
;sevensegment.c,13 :: 		portc.f0=0x00;
	BCF        PORTC+0, 0
;sevensegment.c,16 :: 		while(1){
L_main0:
;sevensegment.c,17 :: 		if(portc.f0 && i<9){
	BTFSS      PORTC+0, 0
	GOTO       L_main4
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main325
	MOVLW      9
	SUBWF      main_i_L0+0, 0
L__main325:
	BTFSC      STATUS+0, 0
	GOTO       L_main4
L__main323:
;sevensegment.c,18 :: 		while(portc.f0) delay_ms(10);
L_main5:
	BTFSS      PORTC+0, 0
	GOTO       L_main6
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main7:
	DECFSZ     R13+0, 1
	GOTO       L_main7
	DECFSZ     R12+0, 1
	GOTO       L_main7
	NOP
	GOTO       L_main5
L_main6:
;sevensegment.c,19 :: 		i++;
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;sevensegment.c,20 :: 		}
L_main4:
;sevensegment.c,22 :: 		if(portc.f1 && i>0){
	BTFSS      PORTC+0, 1
	GOTO       L_main10
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      main_i_L0+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main326
	MOVF       main_i_L0+0, 0
	SUBLW      0
L__main326:
	BTFSC      STATUS+0, 0
	GOTO       L_main10
L__main322:
;sevensegment.c,23 :: 		while(portc.f1) delay_ms(10);
L_main11:
	BTFSS      PORTC+0, 1
	GOTO       L_main12
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main13:
	DECFSZ     R13+0, 1
	GOTO       L_main13
	DECFSZ     R12+0, 1
	GOTO       L_main13
	NOP
	GOTO       L_main11
L_main12:
;sevensegment.c,24 :: 		i--;
	MOVLW      1
	SUBWF      main_i_L0+0, 1
	BTFSS      STATUS+0, 0
	DECF       main_i_L0+1, 1
;sevensegment.c,25 :: 		}
L_main10:
;sevensegment.c,26 :: 		portb=arr[i];
	MOVF       main_i_L0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;sevensegment.c,28 :: 		if(portc.f0 && i<9){
	BTFSS      PORTC+0, 0
	GOTO       L_main16
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main327
	MOVLW      9
	SUBWF      main_i_L0+0, 0
L__main327:
	BTFSC      STATUS+0, 0
	GOTO       L_main16
L__main321:
;sevensegment.c,29 :: 		while(portc.f0) delay_ms(10);
L_main17:
	BTFSS      PORTC+0, 0
	GOTO       L_main18
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main19:
	DECFSZ     R13+0, 1
	GOTO       L_main19
	DECFSZ     R12+0, 1
	GOTO       L_main19
	NOP
	GOTO       L_main17
L_main18:
;sevensegment.c,30 :: 		i++;
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;sevensegment.c,31 :: 		}
L_main16:
;sevensegment.c,33 :: 		if(portc.f1 && i>0){
	BTFSS      PORTC+0, 1
	GOTO       L_main22
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      main_i_L0+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main328
	MOVF       main_i_L0+0, 0
	SUBLW      0
L__main328:
	BTFSC      STATUS+0, 0
	GOTO       L_main22
L__main320:
;sevensegment.c,34 :: 		while(portc.f1) delay_ms(10);
L_main23:
	BTFSS      PORTC+0, 1
	GOTO       L_main24
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main25:
	DECFSZ     R13+0, 1
	GOTO       L_main25
	DECFSZ     R12+0, 1
	GOTO       L_main25
	NOP
	GOTO       L_main23
L_main24:
;sevensegment.c,35 :: 		i--;
	MOVLW      1
	SUBWF      main_i_L0+0, 1
	BTFSS      STATUS+0, 0
	DECF       main_i_L0+1, 1
;sevensegment.c,36 :: 		}
L_main22:
;sevensegment.c,37 :: 		portb=arr[i];
	MOVF       main_i_L0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;sevensegment.c,39 :: 		if(portc.f0 && i<9){
	BTFSS      PORTC+0, 0
	GOTO       L_main28
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main329
	MOVLW      9
	SUBWF      main_i_L0+0, 0
L__main329:
	BTFSC      STATUS+0, 0
	GOTO       L_main28
L__main319:
;sevensegment.c,40 :: 		while(portc.f0) delay_ms(10);
L_main29:
	BTFSS      PORTC+0, 0
	GOTO       L_main30
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main31:
	DECFSZ     R13+0, 1
	GOTO       L_main31
	DECFSZ     R12+0, 1
	GOTO       L_main31
	NOP
	GOTO       L_main29
L_main30:
;sevensegment.c,41 :: 		i++;
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;sevensegment.c,42 :: 		}
L_main28:
;sevensegment.c,44 :: 		if(portc.f1 && i>0){
	BTFSS      PORTC+0, 1
	GOTO       L_main34
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      main_i_L0+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main330
	MOVF       main_i_L0+0, 0
	SUBLW      0
L__main330:
	BTFSC      STATUS+0, 0
	GOTO       L_main34
L__main318:
;sevensegment.c,45 :: 		while(portc.f1) delay_ms(10);
L_main35:
	BTFSS      PORTC+0, 1
	GOTO       L_main36
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main37:
	DECFSZ     R13+0, 1
	GOTO       L_main37
	DECFSZ     R12+0, 1
	GOTO       L_main37
	NOP
	GOTO       L_main35
L_main36:
;sevensegment.c,46 :: 		i--;
	MOVLW      1
	SUBWF      main_i_L0+0, 1
	BTFSS      STATUS+0, 0
	DECF       main_i_L0+1, 1
;sevensegment.c,47 :: 		}
L_main34:
;sevensegment.c,48 :: 		portb=arr[i];
	MOVF       main_i_L0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;sevensegment.c,50 :: 		if(portc.f0 && i<9){
	BTFSS      PORTC+0, 0
	GOTO       L_main40
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main331
	MOVLW      9
	SUBWF      main_i_L0+0, 0
L__main331:
	BTFSC      STATUS+0, 0
	GOTO       L_main40
L__main317:
;sevensegment.c,51 :: 		while(portc.f0) delay_ms(10);
L_main41:
	BTFSS      PORTC+0, 0
	GOTO       L_main42
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main43:
	DECFSZ     R13+0, 1
	GOTO       L_main43
	DECFSZ     R12+0, 1
	GOTO       L_main43
	NOP
	GOTO       L_main41
L_main42:
;sevensegment.c,52 :: 		i++;
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;sevensegment.c,53 :: 		}
L_main40:
;sevensegment.c,55 :: 		if(portc.f1 && i>0){
	BTFSS      PORTC+0, 1
	GOTO       L_main46
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      main_i_L0+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main332
	MOVF       main_i_L0+0, 0
	SUBLW      0
L__main332:
	BTFSC      STATUS+0, 0
	GOTO       L_main46
L__main316:
;sevensegment.c,56 :: 		while(portc.f1) delay_ms(10);
L_main47:
	BTFSS      PORTC+0, 1
	GOTO       L_main48
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main49:
	DECFSZ     R13+0, 1
	GOTO       L_main49
	DECFSZ     R12+0, 1
	GOTO       L_main49
	NOP
	GOTO       L_main47
L_main48:
;sevensegment.c,57 :: 		i--;
	MOVLW      1
	SUBWF      main_i_L0+0, 1
	BTFSS      STATUS+0, 0
	DECF       main_i_L0+1, 1
;sevensegment.c,58 :: 		}
L_main46:
;sevensegment.c,59 :: 		portb=arr[i];
	MOVF       main_i_L0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;sevensegment.c,61 :: 		if(portc.f0 && i<9){
	BTFSS      PORTC+0, 0
	GOTO       L_main52
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main333
	MOVLW      9
	SUBWF      main_i_L0+0, 0
L__main333:
	BTFSC      STATUS+0, 0
	GOTO       L_main52
L__main315:
;sevensegment.c,62 :: 		while(portc.f0) delay_ms(10);
L_main53:
	BTFSS      PORTC+0, 0
	GOTO       L_main54
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main55:
	DECFSZ     R13+0, 1
	GOTO       L_main55
	DECFSZ     R12+0, 1
	GOTO       L_main55
	NOP
	GOTO       L_main53
L_main54:
;sevensegment.c,63 :: 		i++;
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;sevensegment.c,64 :: 		}
L_main52:
;sevensegment.c,66 :: 		if(portc.f1 && i>0){
	BTFSS      PORTC+0, 1
	GOTO       L_main58
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      main_i_L0+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main334
	MOVF       main_i_L0+0, 0
	SUBLW      0
L__main334:
	BTFSC      STATUS+0, 0
	GOTO       L_main58
L__main314:
;sevensegment.c,67 :: 		while(portc.f1) delay_ms(10);
L_main59:
	BTFSS      PORTC+0, 1
	GOTO       L_main60
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main61:
	DECFSZ     R13+0, 1
	GOTO       L_main61
	DECFSZ     R12+0, 1
	GOTO       L_main61
	NOP
	GOTO       L_main59
L_main60:
;sevensegment.c,68 :: 		i--;
	MOVLW      1
	SUBWF      main_i_L0+0, 1
	BTFSS      STATUS+0, 0
	DECF       main_i_L0+1, 1
;sevensegment.c,69 :: 		}
L_main58:
;sevensegment.c,70 :: 		portb=arr[i];
	MOVF       main_i_L0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;sevensegment.c,72 :: 		if(portc.f0 && i<9){
	BTFSS      PORTC+0, 0
	GOTO       L_main64
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main335
	MOVLW      9
	SUBWF      main_i_L0+0, 0
L__main335:
	BTFSC      STATUS+0, 0
	GOTO       L_main64
L__main313:
;sevensegment.c,73 :: 		while(portc.f0) delay_ms(10);
L_main65:
	BTFSS      PORTC+0, 0
	GOTO       L_main66
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main67:
	DECFSZ     R13+0, 1
	GOTO       L_main67
	DECFSZ     R12+0, 1
	GOTO       L_main67
	NOP
	GOTO       L_main65
L_main66:
;sevensegment.c,74 :: 		i++;
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;sevensegment.c,75 :: 		}
L_main64:
;sevensegment.c,77 :: 		if(portc.f1 && i>0){
	BTFSS      PORTC+0, 1
	GOTO       L_main70
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      main_i_L0+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main336
	MOVF       main_i_L0+0, 0
	SUBLW      0
L__main336:
	BTFSC      STATUS+0, 0
	GOTO       L_main70
L__main312:
;sevensegment.c,78 :: 		while(portc.f1) delay_ms(10);
L_main71:
	BTFSS      PORTC+0, 1
	GOTO       L_main72
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main73:
	DECFSZ     R13+0, 1
	GOTO       L_main73
	DECFSZ     R12+0, 1
	GOTO       L_main73
	NOP
	GOTO       L_main71
L_main72:
;sevensegment.c,79 :: 		i--;
	MOVLW      1
	SUBWF      main_i_L0+0, 1
	BTFSS      STATUS+0, 0
	DECF       main_i_L0+1, 1
;sevensegment.c,80 :: 		}
L_main70:
;sevensegment.c,81 :: 		portb=arr[i];
	MOVF       main_i_L0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;sevensegment.c,83 :: 		if(portc.f0 && i<9){
	BTFSS      PORTC+0, 0
	GOTO       L_main76
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main337
	MOVLW      9
	SUBWF      main_i_L0+0, 0
L__main337:
	BTFSC      STATUS+0, 0
	GOTO       L_main76
L__main311:
;sevensegment.c,84 :: 		while(portc.f0) delay_ms(10);
L_main77:
	BTFSS      PORTC+0, 0
	GOTO       L_main78
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main79:
	DECFSZ     R13+0, 1
	GOTO       L_main79
	DECFSZ     R12+0, 1
	GOTO       L_main79
	NOP
	GOTO       L_main77
L_main78:
;sevensegment.c,85 :: 		i++;
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;sevensegment.c,86 :: 		}
L_main76:
;sevensegment.c,88 :: 		if(portc.f1 && i>0){
	BTFSS      PORTC+0, 1
	GOTO       L_main82
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      main_i_L0+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main338
	MOVF       main_i_L0+0, 0
	SUBLW      0
L__main338:
	BTFSC      STATUS+0, 0
	GOTO       L_main82
L__main310:
;sevensegment.c,89 :: 		while(portc.f1) delay_ms(10);
L_main83:
	BTFSS      PORTC+0, 1
	GOTO       L_main84
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main85:
	DECFSZ     R13+0, 1
	GOTO       L_main85
	DECFSZ     R12+0, 1
	GOTO       L_main85
	NOP
	GOTO       L_main83
L_main84:
;sevensegment.c,90 :: 		i--;
	MOVLW      1
	SUBWF      main_i_L0+0, 1
	BTFSS      STATUS+0, 0
	DECF       main_i_L0+1, 1
;sevensegment.c,91 :: 		}
L_main82:
;sevensegment.c,92 :: 		portb=arr[i];
	MOVF       main_i_L0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;sevensegment.c,94 :: 		if(portc.f0 && i<9){
	BTFSS      PORTC+0, 0
	GOTO       L_main88
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main339
	MOVLW      9
	SUBWF      main_i_L0+0, 0
L__main339:
	BTFSC      STATUS+0, 0
	GOTO       L_main88
L__main309:
;sevensegment.c,95 :: 		while(portc.f0) delay_ms(10);
L_main89:
	BTFSS      PORTC+0, 0
	GOTO       L_main90
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main91:
	DECFSZ     R13+0, 1
	GOTO       L_main91
	DECFSZ     R12+0, 1
	GOTO       L_main91
	NOP
	GOTO       L_main89
L_main90:
;sevensegment.c,96 :: 		i++;
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;sevensegment.c,97 :: 		}
L_main88:
;sevensegment.c,99 :: 		if(portc.f1 && i>0){
	BTFSS      PORTC+0, 1
	GOTO       L_main94
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      main_i_L0+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main340
	MOVF       main_i_L0+0, 0
	SUBLW      0
L__main340:
	BTFSC      STATUS+0, 0
	GOTO       L_main94
L__main308:
;sevensegment.c,100 :: 		while(portc.f1) delay_ms(10);
L_main95:
	BTFSS      PORTC+0, 1
	GOTO       L_main96
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main97:
	DECFSZ     R13+0, 1
	GOTO       L_main97
	DECFSZ     R12+0, 1
	GOTO       L_main97
	NOP
	GOTO       L_main95
L_main96:
;sevensegment.c,101 :: 		i--;
	MOVLW      1
	SUBWF      main_i_L0+0, 1
	BTFSS      STATUS+0, 0
	DECF       main_i_L0+1, 1
;sevensegment.c,102 :: 		}
L_main94:
;sevensegment.c,103 :: 		portb=arr[i];
	MOVF       main_i_L0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;sevensegment.c,105 :: 		if(portc.f0 && i<9){
	BTFSS      PORTC+0, 0
	GOTO       L_main100
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main341
	MOVLW      9
	SUBWF      main_i_L0+0, 0
L__main341:
	BTFSC      STATUS+0, 0
	GOTO       L_main100
L__main307:
;sevensegment.c,106 :: 		while(portc.f0) delay_ms(10);
L_main101:
	BTFSS      PORTC+0, 0
	GOTO       L_main102
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main103:
	DECFSZ     R13+0, 1
	GOTO       L_main103
	DECFSZ     R12+0, 1
	GOTO       L_main103
	NOP
	GOTO       L_main101
L_main102:
;sevensegment.c,107 :: 		i++;
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;sevensegment.c,108 :: 		}
L_main100:
;sevensegment.c,110 :: 		if(portc.f1 && i>0){
	BTFSS      PORTC+0, 1
	GOTO       L_main106
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      main_i_L0+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main342
	MOVF       main_i_L0+0, 0
	SUBLW      0
L__main342:
	BTFSC      STATUS+0, 0
	GOTO       L_main106
L__main306:
;sevensegment.c,111 :: 		while(portc.f1) delay_ms(10);
L_main107:
	BTFSS      PORTC+0, 1
	GOTO       L_main108
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main109:
	DECFSZ     R13+0, 1
	GOTO       L_main109
	DECFSZ     R12+0, 1
	GOTO       L_main109
	NOP
	GOTO       L_main107
L_main108:
;sevensegment.c,112 :: 		i--;
	MOVLW      1
	SUBWF      main_i_L0+0, 1
	BTFSS      STATUS+0, 0
	DECF       main_i_L0+1, 1
;sevensegment.c,113 :: 		}
L_main106:
;sevensegment.c,114 :: 		portb=arr[i];
	MOVF       main_i_L0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;sevensegment.c,116 :: 		if(portc.f0 && i<9){
	BTFSS      PORTC+0, 0
	GOTO       L_main112
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main343
	MOVLW      9
	SUBWF      main_i_L0+0, 0
L__main343:
	BTFSC      STATUS+0, 0
	GOTO       L_main112
L__main305:
;sevensegment.c,117 :: 		while(portc.f0) delay_ms(10);
L_main113:
	BTFSS      PORTC+0, 0
	GOTO       L_main114
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main115:
	DECFSZ     R13+0, 1
	GOTO       L_main115
	DECFSZ     R12+0, 1
	GOTO       L_main115
	NOP
	GOTO       L_main113
L_main114:
;sevensegment.c,118 :: 		i++;
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;sevensegment.c,119 :: 		}
L_main112:
;sevensegment.c,121 :: 		if(portc.f1 && i>0){
	BTFSS      PORTC+0, 1
	GOTO       L_main118
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      main_i_L0+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main344
	MOVF       main_i_L0+0, 0
	SUBLW      0
L__main344:
	BTFSC      STATUS+0, 0
	GOTO       L_main118
L__main304:
;sevensegment.c,122 :: 		while(portc.f1) delay_ms(10);
L_main119:
	BTFSS      PORTC+0, 1
	GOTO       L_main120
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main121:
	DECFSZ     R13+0, 1
	GOTO       L_main121
	DECFSZ     R12+0, 1
	GOTO       L_main121
	NOP
	GOTO       L_main119
L_main120:
;sevensegment.c,123 :: 		i--;
	MOVLW      1
	SUBWF      main_i_L0+0, 1
	BTFSS      STATUS+0, 0
	DECF       main_i_L0+1, 1
;sevensegment.c,124 :: 		}
L_main118:
;sevensegment.c,125 :: 		portb=arr[i];
	MOVF       main_i_L0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;sevensegment.c,127 :: 		if(portc.f0 && i<9){
	BTFSS      PORTC+0, 0
	GOTO       L_main124
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main345
	MOVLW      9
	SUBWF      main_i_L0+0, 0
L__main345:
	BTFSC      STATUS+0, 0
	GOTO       L_main124
L__main303:
;sevensegment.c,128 :: 		while(portc.f0) delay_ms(10);
L_main125:
	BTFSS      PORTC+0, 0
	GOTO       L_main126
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main127:
	DECFSZ     R13+0, 1
	GOTO       L_main127
	DECFSZ     R12+0, 1
	GOTO       L_main127
	NOP
	GOTO       L_main125
L_main126:
;sevensegment.c,129 :: 		i++;
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;sevensegment.c,130 :: 		}
L_main124:
;sevensegment.c,132 :: 		if(portc.f1 && i>0){
	BTFSS      PORTC+0, 1
	GOTO       L_main130
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      main_i_L0+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main346
	MOVF       main_i_L0+0, 0
	SUBLW      0
L__main346:
	BTFSC      STATUS+0, 0
	GOTO       L_main130
L__main302:
;sevensegment.c,133 :: 		while(portc.f1) delay_ms(10);
L_main131:
	BTFSS      PORTC+0, 1
	GOTO       L_main132
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main133:
	DECFSZ     R13+0, 1
	GOTO       L_main133
	DECFSZ     R12+0, 1
	GOTO       L_main133
	NOP
	GOTO       L_main131
L_main132:
;sevensegment.c,134 :: 		i--;
	MOVLW      1
	SUBWF      main_i_L0+0, 1
	BTFSS      STATUS+0, 0
	DECF       main_i_L0+1, 1
;sevensegment.c,135 :: 		}
L_main130:
;sevensegment.c,136 :: 		portb=arr[i];
	MOVF       main_i_L0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;sevensegment.c,138 :: 		if(portc.f0 && i<9){
	BTFSS      PORTC+0, 0
	GOTO       L_main136
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main347
	MOVLW      9
	SUBWF      main_i_L0+0, 0
L__main347:
	BTFSC      STATUS+0, 0
	GOTO       L_main136
L__main301:
;sevensegment.c,139 :: 		while(portc.f0) delay_ms(10);
L_main137:
	BTFSS      PORTC+0, 0
	GOTO       L_main138
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main139:
	DECFSZ     R13+0, 1
	GOTO       L_main139
	DECFSZ     R12+0, 1
	GOTO       L_main139
	NOP
	GOTO       L_main137
L_main138:
;sevensegment.c,140 :: 		i++;
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;sevensegment.c,141 :: 		}
L_main136:
;sevensegment.c,143 :: 		if(portc.f1 && i>0){
	BTFSS      PORTC+0, 1
	GOTO       L_main142
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      main_i_L0+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main348
	MOVF       main_i_L0+0, 0
	SUBLW      0
L__main348:
	BTFSC      STATUS+0, 0
	GOTO       L_main142
L__main300:
;sevensegment.c,144 :: 		while(portc.f1) delay_ms(10);
L_main143:
	BTFSS      PORTC+0, 1
	GOTO       L_main144
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main145:
	DECFSZ     R13+0, 1
	GOTO       L_main145
	DECFSZ     R12+0, 1
	GOTO       L_main145
	NOP
	GOTO       L_main143
L_main144:
;sevensegment.c,145 :: 		i--;
	MOVLW      1
	SUBWF      main_i_L0+0, 1
	BTFSS      STATUS+0, 0
	DECF       main_i_L0+1, 1
;sevensegment.c,146 :: 		}
L_main142:
;sevensegment.c,147 :: 		portb=arr[i];
	MOVF       main_i_L0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;sevensegment.c,149 :: 		if(portc.f0 && i<9){
	BTFSS      PORTC+0, 0
	GOTO       L_main148
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main349
	MOVLW      9
	SUBWF      main_i_L0+0, 0
L__main349:
	BTFSC      STATUS+0, 0
	GOTO       L_main148
L__main299:
;sevensegment.c,150 :: 		while(portc.f0) delay_ms(10);
L_main149:
	BTFSS      PORTC+0, 0
	GOTO       L_main150
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main151:
	DECFSZ     R13+0, 1
	GOTO       L_main151
	DECFSZ     R12+0, 1
	GOTO       L_main151
	NOP
	GOTO       L_main149
L_main150:
;sevensegment.c,151 :: 		i++;
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;sevensegment.c,152 :: 		}
L_main148:
;sevensegment.c,154 :: 		if(portc.f1 && i>0){
	BTFSS      PORTC+0, 1
	GOTO       L_main154
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      main_i_L0+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main350
	MOVF       main_i_L0+0, 0
	SUBLW      0
L__main350:
	BTFSC      STATUS+0, 0
	GOTO       L_main154
L__main298:
;sevensegment.c,155 :: 		while(portc.f1) delay_ms(10);
L_main155:
	BTFSS      PORTC+0, 1
	GOTO       L_main156
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main157:
	DECFSZ     R13+0, 1
	GOTO       L_main157
	DECFSZ     R12+0, 1
	GOTO       L_main157
	NOP
	GOTO       L_main155
L_main156:
;sevensegment.c,156 :: 		i--;
	MOVLW      1
	SUBWF      main_i_L0+0, 1
	BTFSS      STATUS+0, 0
	DECF       main_i_L0+1, 1
;sevensegment.c,157 :: 		}
L_main154:
;sevensegment.c,158 :: 		portb=arr[i];
	MOVF       main_i_L0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;sevensegment.c,160 :: 		if(portc.f0 && i<9){
	BTFSS      PORTC+0, 0
	GOTO       L_main160
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main351
	MOVLW      9
	SUBWF      main_i_L0+0, 0
L__main351:
	BTFSC      STATUS+0, 0
	GOTO       L_main160
L__main297:
;sevensegment.c,161 :: 		while(portc.f0) delay_ms(10);
L_main161:
	BTFSS      PORTC+0, 0
	GOTO       L_main162
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main163:
	DECFSZ     R13+0, 1
	GOTO       L_main163
	DECFSZ     R12+0, 1
	GOTO       L_main163
	NOP
	GOTO       L_main161
L_main162:
;sevensegment.c,162 :: 		i++;
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;sevensegment.c,163 :: 		}
L_main160:
;sevensegment.c,165 :: 		if(portc.f1 && i>0){
	BTFSS      PORTC+0, 1
	GOTO       L_main166
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      main_i_L0+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main352
	MOVF       main_i_L0+0, 0
	SUBLW      0
L__main352:
	BTFSC      STATUS+0, 0
	GOTO       L_main166
L__main296:
;sevensegment.c,166 :: 		while(portc.f1) delay_ms(10);
L_main167:
	BTFSS      PORTC+0, 1
	GOTO       L_main168
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main169:
	DECFSZ     R13+0, 1
	GOTO       L_main169
	DECFSZ     R12+0, 1
	GOTO       L_main169
	NOP
	GOTO       L_main167
L_main168:
;sevensegment.c,167 :: 		i--;
	MOVLW      1
	SUBWF      main_i_L0+0, 1
	BTFSS      STATUS+0, 0
	DECF       main_i_L0+1, 1
;sevensegment.c,168 :: 		}
L_main166:
;sevensegment.c,169 :: 		portb=arr[i];
	MOVF       main_i_L0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;sevensegment.c,171 :: 		if(portc.f0 && i<9){
	BTFSS      PORTC+0, 0
	GOTO       L_main172
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main353
	MOVLW      9
	SUBWF      main_i_L0+0, 0
L__main353:
	BTFSC      STATUS+0, 0
	GOTO       L_main172
L__main295:
;sevensegment.c,172 :: 		while(portc.f0) delay_ms(10);
L_main173:
	BTFSS      PORTC+0, 0
	GOTO       L_main174
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main175:
	DECFSZ     R13+0, 1
	GOTO       L_main175
	DECFSZ     R12+0, 1
	GOTO       L_main175
	NOP
	GOTO       L_main173
L_main174:
;sevensegment.c,173 :: 		i++;
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;sevensegment.c,174 :: 		}
L_main172:
;sevensegment.c,176 :: 		if(portc.f1 && i>0){
	BTFSS      PORTC+0, 1
	GOTO       L_main178
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      main_i_L0+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main354
	MOVF       main_i_L0+0, 0
	SUBLW      0
L__main354:
	BTFSC      STATUS+0, 0
	GOTO       L_main178
L__main294:
;sevensegment.c,177 :: 		while(portc.f1) delay_ms(10);
L_main179:
	BTFSS      PORTC+0, 1
	GOTO       L_main180
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main181:
	DECFSZ     R13+0, 1
	GOTO       L_main181
	DECFSZ     R12+0, 1
	GOTO       L_main181
	NOP
	GOTO       L_main179
L_main180:
;sevensegment.c,178 :: 		i--;
	MOVLW      1
	SUBWF      main_i_L0+0, 1
	BTFSS      STATUS+0, 0
	DECF       main_i_L0+1, 1
;sevensegment.c,179 :: 		}
L_main178:
;sevensegment.c,180 :: 		portb=arr[i];
	MOVF       main_i_L0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;sevensegment.c,182 :: 		if(portc.f0 && i<9){
	BTFSS      PORTC+0, 0
	GOTO       L_main184
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main355
	MOVLW      9
	SUBWF      main_i_L0+0, 0
L__main355:
	BTFSC      STATUS+0, 0
	GOTO       L_main184
L__main293:
;sevensegment.c,183 :: 		while(portc.f0) delay_ms(10);
L_main185:
	BTFSS      PORTC+0, 0
	GOTO       L_main186
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main187:
	DECFSZ     R13+0, 1
	GOTO       L_main187
	DECFSZ     R12+0, 1
	GOTO       L_main187
	NOP
	GOTO       L_main185
L_main186:
;sevensegment.c,184 :: 		i++;
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;sevensegment.c,185 :: 		}
L_main184:
;sevensegment.c,187 :: 		if(portc.f1 && i>0){
	BTFSS      PORTC+0, 1
	GOTO       L_main190
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      main_i_L0+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main356
	MOVF       main_i_L0+0, 0
	SUBLW      0
L__main356:
	BTFSC      STATUS+0, 0
	GOTO       L_main190
L__main292:
;sevensegment.c,188 :: 		while(portc.f1) delay_ms(10);
L_main191:
	BTFSS      PORTC+0, 1
	GOTO       L_main192
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main193:
	DECFSZ     R13+0, 1
	GOTO       L_main193
	DECFSZ     R12+0, 1
	GOTO       L_main193
	NOP
	GOTO       L_main191
L_main192:
;sevensegment.c,189 :: 		i--;
	MOVLW      1
	SUBWF      main_i_L0+0, 1
	BTFSS      STATUS+0, 0
	DECF       main_i_L0+1, 1
;sevensegment.c,190 :: 		}
L_main190:
;sevensegment.c,191 :: 		portb=arr[i];
	MOVF       main_i_L0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;sevensegment.c,193 :: 		if(portc.f0 && i<9){
	BTFSS      PORTC+0, 0
	GOTO       L_main196
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main357
	MOVLW      9
	SUBWF      main_i_L0+0, 0
L__main357:
	BTFSC      STATUS+0, 0
	GOTO       L_main196
L__main291:
;sevensegment.c,194 :: 		while(portc.f0) delay_ms(10);
L_main197:
	BTFSS      PORTC+0, 0
	GOTO       L_main198
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main199:
	DECFSZ     R13+0, 1
	GOTO       L_main199
	DECFSZ     R12+0, 1
	GOTO       L_main199
	NOP
	GOTO       L_main197
L_main198:
;sevensegment.c,195 :: 		i++;
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;sevensegment.c,196 :: 		}
L_main196:
;sevensegment.c,198 :: 		if(portc.f1 && i>0){
	BTFSS      PORTC+0, 1
	GOTO       L_main202
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      main_i_L0+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main358
	MOVF       main_i_L0+0, 0
	SUBLW      0
L__main358:
	BTFSC      STATUS+0, 0
	GOTO       L_main202
L__main290:
;sevensegment.c,199 :: 		while(portc.f1) delay_ms(10);
L_main203:
	BTFSS      PORTC+0, 1
	GOTO       L_main204
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main205:
	DECFSZ     R13+0, 1
	GOTO       L_main205
	DECFSZ     R12+0, 1
	GOTO       L_main205
	NOP
	GOTO       L_main203
L_main204:
;sevensegment.c,200 :: 		i--;
	MOVLW      1
	SUBWF      main_i_L0+0, 1
	BTFSS      STATUS+0, 0
	DECF       main_i_L0+1, 1
;sevensegment.c,201 :: 		}
L_main202:
;sevensegment.c,202 :: 		portb=arr[i];
	MOVF       main_i_L0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;sevensegment.c,204 :: 		if(portc.f0 && i<9){
	BTFSS      PORTC+0, 0
	GOTO       L_main208
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main359
	MOVLW      9
	SUBWF      main_i_L0+0, 0
L__main359:
	BTFSC      STATUS+0, 0
	GOTO       L_main208
L__main289:
;sevensegment.c,205 :: 		while(portc.f0) delay_ms(10);
L_main209:
	BTFSS      PORTC+0, 0
	GOTO       L_main210
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main211:
	DECFSZ     R13+0, 1
	GOTO       L_main211
	DECFSZ     R12+0, 1
	GOTO       L_main211
	NOP
	GOTO       L_main209
L_main210:
;sevensegment.c,206 :: 		i++;
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;sevensegment.c,207 :: 		}
L_main208:
;sevensegment.c,209 :: 		if(portc.f1 && i>0){
	BTFSS      PORTC+0, 1
	GOTO       L_main214
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      main_i_L0+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main360
	MOVF       main_i_L0+0, 0
	SUBLW      0
L__main360:
	BTFSC      STATUS+0, 0
	GOTO       L_main214
L__main288:
;sevensegment.c,210 :: 		while(portc.f1) delay_ms(10);
L_main215:
	BTFSS      PORTC+0, 1
	GOTO       L_main216
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main217:
	DECFSZ     R13+0, 1
	GOTO       L_main217
	DECFSZ     R12+0, 1
	GOTO       L_main217
	NOP
	GOTO       L_main215
L_main216:
;sevensegment.c,211 :: 		i--;
	MOVLW      1
	SUBWF      main_i_L0+0, 1
	BTFSS      STATUS+0, 0
	DECF       main_i_L0+1, 1
;sevensegment.c,212 :: 		}
L_main214:
;sevensegment.c,213 :: 		portb=arr[i];
	MOVF       main_i_L0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;sevensegment.c,215 :: 		if(portc.f0 && i<9){
	BTFSS      PORTC+0, 0
	GOTO       L_main220
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main361
	MOVLW      9
	SUBWF      main_i_L0+0, 0
L__main361:
	BTFSC      STATUS+0, 0
	GOTO       L_main220
L__main287:
;sevensegment.c,216 :: 		while(portc.f0) delay_ms(10);
L_main221:
	BTFSS      PORTC+0, 0
	GOTO       L_main222
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main223:
	DECFSZ     R13+0, 1
	GOTO       L_main223
	DECFSZ     R12+0, 1
	GOTO       L_main223
	NOP
	GOTO       L_main221
L_main222:
;sevensegment.c,217 :: 		i++;
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;sevensegment.c,218 :: 		}
L_main220:
;sevensegment.c,220 :: 		if(portc.f1 && i>0){
	BTFSS      PORTC+0, 1
	GOTO       L_main226
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      main_i_L0+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main362
	MOVF       main_i_L0+0, 0
	SUBLW      0
L__main362:
	BTFSC      STATUS+0, 0
	GOTO       L_main226
L__main286:
;sevensegment.c,221 :: 		while(portc.f1) delay_ms(10);
L_main227:
	BTFSS      PORTC+0, 1
	GOTO       L_main228
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main229:
	DECFSZ     R13+0, 1
	GOTO       L_main229
	DECFSZ     R12+0, 1
	GOTO       L_main229
	NOP
	GOTO       L_main227
L_main228:
;sevensegment.c,222 :: 		i--;
	MOVLW      1
	SUBWF      main_i_L0+0, 1
	BTFSS      STATUS+0, 0
	DECF       main_i_L0+1, 1
;sevensegment.c,223 :: 		}
L_main226:
;sevensegment.c,224 :: 		portb=arr[i];
	MOVF       main_i_L0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;sevensegment.c,226 :: 		if(portc.f0 && i<9){
	BTFSS      PORTC+0, 0
	GOTO       L_main232
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main363
	MOVLW      9
	SUBWF      main_i_L0+0, 0
L__main363:
	BTFSC      STATUS+0, 0
	GOTO       L_main232
L__main285:
;sevensegment.c,227 :: 		while(portc.f0) delay_ms(10);
L_main233:
	BTFSS      PORTC+0, 0
	GOTO       L_main234
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main235:
	DECFSZ     R13+0, 1
	GOTO       L_main235
	DECFSZ     R12+0, 1
	GOTO       L_main235
	NOP
	GOTO       L_main233
L_main234:
;sevensegment.c,228 :: 		i++;
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;sevensegment.c,229 :: 		}
L_main232:
;sevensegment.c,231 :: 		if(portc.f1 && i>0){
	BTFSS      PORTC+0, 1
	GOTO       L_main238
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      main_i_L0+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main364
	MOVF       main_i_L0+0, 0
	SUBLW      0
L__main364:
	BTFSC      STATUS+0, 0
	GOTO       L_main238
L__main284:
;sevensegment.c,232 :: 		while(portc.f1) delay_ms(10);
L_main239:
	BTFSS      PORTC+0, 1
	GOTO       L_main240
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main241:
	DECFSZ     R13+0, 1
	GOTO       L_main241
	DECFSZ     R12+0, 1
	GOTO       L_main241
	NOP
	GOTO       L_main239
L_main240:
;sevensegment.c,233 :: 		i--;
	MOVLW      1
	SUBWF      main_i_L0+0, 1
	BTFSS      STATUS+0, 0
	DECF       main_i_L0+1, 1
;sevensegment.c,234 :: 		}
L_main238:
;sevensegment.c,235 :: 		portb=arr[i];
	MOVF       main_i_L0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;sevensegment.c,237 :: 		if(portc.f0 && i<9){
	BTFSS      PORTC+0, 0
	GOTO       L_main244
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main365
	MOVLW      9
	SUBWF      main_i_L0+0, 0
L__main365:
	BTFSC      STATUS+0, 0
	GOTO       L_main244
L__main283:
;sevensegment.c,238 :: 		while(portc.f0) delay_ms(10);
L_main245:
	BTFSS      PORTC+0, 0
	GOTO       L_main246
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main247:
	DECFSZ     R13+0, 1
	GOTO       L_main247
	DECFSZ     R12+0, 1
	GOTO       L_main247
	NOP
	GOTO       L_main245
L_main246:
;sevensegment.c,239 :: 		i++;
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;sevensegment.c,240 :: 		}
L_main244:
;sevensegment.c,242 :: 		if(portc.f1 && i>0){
	BTFSS      PORTC+0, 1
	GOTO       L_main250
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      main_i_L0+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main366
	MOVF       main_i_L0+0, 0
	SUBLW      0
L__main366:
	BTFSC      STATUS+0, 0
	GOTO       L_main250
L__main282:
;sevensegment.c,243 :: 		while(portc.f1) delay_ms(10);
L_main251:
	BTFSS      PORTC+0, 1
	GOTO       L_main252
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main253:
	DECFSZ     R13+0, 1
	GOTO       L_main253
	DECFSZ     R12+0, 1
	GOTO       L_main253
	NOP
	GOTO       L_main251
L_main252:
;sevensegment.c,244 :: 		i--;
	MOVLW      1
	SUBWF      main_i_L0+0, 1
	BTFSS      STATUS+0, 0
	DECF       main_i_L0+1, 1
;sevensegment.c,245 :: 		}
L_main250:
;sevensegment.c,246 :: 		portb=arr[i];
	MOVF       main_i_L0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;sevensegment.c,248 :: 		if(portc.f0 && i<9){
	BTFSS      PORTC+0, 0
	GOTO       L_main256
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main367
	MOVLW      9
	SUBWF      main_i_L0+0, 0
L__main367:
	BTFSC      STATUS+0, 0
	GOTO       L_main256
L__main281:
;sevensegment.c,249 :: 		while(portc.f0) delay_ms(10);
L_main257:
	BTFSS      PORTC+0, 0
	GOTO       L_main258
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main259:
	DECFSZ     R13+0, 1
	GOTO       L_main259
	DECFSZ     R12+0, 1
	GOTO       L_main259
	NOP
	GOTO       L_main257
L_main258:
;sevensegment.c,250 :: 		i++;
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;sevensegment.c,251 :: 		}
L_main256:
;sevensegment.c,253 :: 		if(portc.f1 && i>0){
	BTFSS      PORTC+0, 1
	GOTO       L_main262
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      main_i_L0+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main368
	MOVF       main_i_L0+0, 0
	SUBLW      0
L__main368:
	BTFSC      STATUS+0, 0
	GOTO       L_main262
L__main280:
;sevensegment.c,254 :: 		while(portc.f1) delay_ms(10);
L_main263:
	BTFSS      PORTC+0, 1
	GOTO       L_main264
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main265:
	DECFSZ     R13+0, 1
	GOTO       L_main265
	DECFSZ     R12+0, 1
	GOTO       L_main265
	NOP
	GOTO       L_main263
L_main264:
;sevensegment.c,255 :: 		i--;
	MOVLW      1
	SUBWF      main_i_L0+0, 1
	BTFSS      STATUS+0, 0
	DECF       main_i_L0+1, 1
;sevensegment.c,256 :: 		}
L_main262:
;sevensegment.c,257 :: 		portb=arr[i];
	MOVF       main_i_L0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;sevensegment.c,259 :: 		if(portc.f0 && i<9){
	BTFSS      PORTC+0, 0
	GOTO       L_main268
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main369
	MOVLW      9
	SUBWF      main_i_L0+0, 0
L__main369:
	BTFSC      STATUS+0, 0
	GOTO       L_main268
L__main279:
;sevensegment.c,260 :: 		while(portc.f0) delay_ms(10);
L_main269:
	BTFSS      PORTC+0, 0
	GOTO       L_main270
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main271:
	DECFSZ     R13+0, 1
	GOTO       L_main271
	DECFSZ     R12+0, 1
	GOTO       L_main271
	NOP
	GOTO       L_main269
L_main270:
;sevensegment.c,261 :: 		i++;
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;sevensegment.c,262 :: 		}
L_main268:
;sevensegment.c,264 :: 		if(portc.f1 && i>0){
	BTFSS      PORTC+0, 1
	GOTO       L_main274
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      main_i_L0+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main370
	MOVF       main_i_L0+0, 0
	SUBLW      0
L__main370:
	BTFSC      STATUS+0, 0
	GOTO       L_main274
L__main278:
;sevensegment.c,265 :: 		while(portc.f1) delay_ms(10);
L_main275:
	BTFSS      PORTC+0, 1
	GOTO       L_main276
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main277:
	DECFSZ     R13+0, 1
	GOTO       L_main277
	DECFSZ     R12+0, 1
	GOTO       L_main277
	NOP
	GOTO       L_main275
L_main276:
;sevensegment.c,266 :: 		i--;
	MOVLW      1
	SUBWF      main_i_L0+0, 1
	BTFSS      STATUS+0, 0
	DECF       main_i_L0+1, 1
;sevensegment.c,267 :: 		}
L_main274:
;sevensegment.c,268 :: 		portb=arr[i];
	MOVF       main_i_L0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;sevensegment.c,270 :: 		}
	GOTO       L_main0
;sevensegment.c,271 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
