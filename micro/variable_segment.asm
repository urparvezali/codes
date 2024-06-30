
_main:

;variable_segment.c,3 :: 		void main() {
;variable_segment.c,4 :: 		char mplx[]={0x0E,0x0D,0x0B,0x07};
;variable_segment.c,5 :: 		int num[4],i=0,j=0;
	CLRF       main_i_L0+0
	CLRF       main_i_L0+1
	CLRF       main_j_L0+0
	CLRF       main_j_L0+1
;variable_segment.c,6 :: 		for(i=0;i<4;i++){num[i]=0;}
	CLRF       main_i_L0+0
	CLRF       main_i_L0+1
L_main0:
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main16
	MOVLW      4
	SUBWF      main_i_L0+0, 0
L__main16:
	BTFSC      STATUS+0, 0
	GOTO       L_main1
	MOVF       main_i_L0+0, 0
	MOVWF      R0+0
	MOVF       main_i_L0+1, 0
	MOVWF      R0+1
	RLF        R0+0, 1
	RLF        R0+1, 1
	BCF        R0+0, 0
	MOVF       R0+0, 0
	ADDLW      R3+0
	MOVWF      FSR
	CLRF       INDF+0
	INCF       FSR, 1
	CLRF       INDF+0
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
	GOTO       L_main0
L_main1:
;variable_segment.c,7 :: 		i=0;
	CLRF       main_i_L0+0
	CLRF       main_i_L0+1
;variable_segment.c,10 :: 		trisb=0x00;
	CLRF       TRISB+0
;variable_segment.c,11 :: 		trisc=0x00;
	CLRF       TRISC+0
;variable_segment.c,13 :: 		portb=0x00;
	CLRF       PORTB+0
;variable_segment.c,14 :: 		portc=0xff;
	MOVLW      255
	MOVWF      PORTC+0
;variable_segment.c,15 :: 		while(1){
L_main3:
;variable_segment.c,16 :: 		if(i==25){
	MOVLW      0
	XORWF      main_i_L0+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main17
	MOVLW      25
	XORWF      main_i_L0+0, 0
L__main17:
	BTFSS      STATUS+0, 2
	GOTO       L_main5
;variable_segment.c,17 :: 		i=0;
	CLRF       main_i_L0+0
	CLRF       main_i_L0+1
;variable_segment.c,18 :: 		for(j=0;j<4;j++){
	CLRF       main_j_L0+0
	CLRF       main_j_L0+1
L_main6:
	MOVLW      128
	XORWF      main_j_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main18
	MOVLW      4
	SUBWF      main_j_L0+0, 0
L__main18:
	BTFSC      STATUS+0, 0
	GOTO       L_main7
;variable_segment.c,19 :: 		if(num[j]==9){
	MOVF       main_j_L0+0, 0
	MOVWF      R0+0
	MOVF       main_j_L0+1, 0
	MOVWF      R0+1
	RLF        R0+0, 1
	RLF        R0+1, 1
	BCF        R0+0, 0
	MOVF       R0+0, 0
	ADDLW      R3+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R1+0
	INCF       FSR, 1
	MOVF       INDF+0, 0
	MOVWF      R1+1
	MOVLW      0
	XORWF      R1+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main19
	MOVLW      9
	XORWF      R1+0, 0
L__main19:
	BTFSS      STATUS+0, 2
	GOTO       L_main9
;variable_segment.c,20 :: 		num[j]=0;
	MOVF       main_j_L0+0, 0
	MOVWF      R0+0
	MOVF       main_j_L0+1, 0
	MOVWF      R0+1
	RLF        R0+0, 1
	RLF        R0+1, 1
	BCF        R0+0, 0
	MOVF       R0+0, 0
	ADDLW      R3+0
	MOVWF      FSR
	CLRF       INDF+0
	INCF       FSR, 1
	CLRF       INDF+0
;variable_segment.c,21 :: 		} else {
	GOTO       L_main10
L_main9:
;variable_segment.c,22 :: 		num[j]++;
	MOVF       main_j_L0+0, 0
	MOVWF      R0+0
	MOVF       main_j_L0+1, 0
	MOVWF      R0+1
	RLF        R0+0, 1
	RLF        R0+1, 1
	BCF        R0+0, 0
	MOVF       R0+0, 0
	ADDLW      R3+0
	MOVWF      R2+0
	MOVF       R2+0, 0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      R0+0
	INCF       FSR, 1
	MOVF       INDF+0, 0
	MOVWF      R0+1
	INCF       R0+0, 1
	BTFSC      STATUS+0, 2
	INCF       R0+1, 1
	MOVF       R2+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
	MOVF       R0+1, 0
	INCF       FSR, 1
	MOVWF      INDF+0
;variable_segment.c,23 :: 		break;
	GOTO       L_main7
;variable_segment.c,24 :: 		}
L_main10:
;variable_segment.c,18 :: 		for(j=0;j<4;j++){
	INCF       main_j_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_j_L0+1, 1
;variable_segment.c,25 :: 		}
	GOTO       L_main6
L_main7:
;variable_segment.c,26 :: 		}
L_main5:
;variable_segment.c,27 :: 		portc.f0=0;
	BCF        PORTC+0, 0
;variable_segment.c,28 :: 		portb=arr[num[3]];
	MOVF       R3+6, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;variable_segment.c,29 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main11:
	DECFSZ     R13+0, 1
	GOTO       L_main11
	DECFSZ     R12+0, 1
	GOTO       L_main11
	NOP
;variable_segment.c,30 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;variable_segment.c,32 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;variable_segment.c,33 :: 		portb=arr[num[2]];
	MOVF       R3+4, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;variable_segment.c,34 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main12:
	DECFSZ     R13+0, 1
	GOTO       L_main12
	DECFSZ     R12+0, 1
	GOTO       L_main12
	NOP
;variable_segment.c,35 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;variable_segment.c,37 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;variable_segment.c,38 :: 		portb=arr[num[1]];;
	MOVF       R3+2, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;variable_segment.c,39 :: 		delay_ms(10);
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
;variable_segment.c,40 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;variable_segment.c,42 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;variable_segment.c,43 :: 		portb=arr[num[0]];
	MOVF       R3+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;variable_segment.c,44 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main14:
	DECFSZ     R13+0, 1
	GOTO       L_main14
	DECFSZ     R12+0, 1
	GOTO       L_main14
	NOP
;variable_segment.c,45 :: 		portc.f3=1;
	BSF        PORTC+0, 3
;variable_segment.c,47 :: 		i+=1;
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;variable_segment.c,48 :: 		}
	GOTO       L_main3
;variable_segment.c,49 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
