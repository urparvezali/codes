
_main:

;multiplexer.c,2 :: 		void main() {
;multiplexer.c,3 :: 		char mplx[]={0x0E,0x0D,0x0B,0x07};
;multiplexer.c,4 :: 		trisb=0x00;
	CLRF       TRISB+0
;multiplexer.c,5 :: 		trisc=0x00;
	CLRF       TRISC+0
;multiplexer.c,7 :: 		portb=0x00;
	CLRF       PORTB+0
;multiplexer.c,8 :: 		portc=0xff;
	MOVLW      255
	MOVWF      PORTC+0
;multiplexer.c,10 :: 		while(1){
L_main0:
;multiplexer.c,11 :: 		portc.f0=0;
	BCF        PORTC+0, 0
;multiplexer.c,12 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,13 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main2:
	DECFSZ     R13+0, 1
	GOTO       L_main2
	DECFSZ     R12+0, 1
	GOTO       L_main2
	NOP
;multiplexer.c,14 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,16 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,17 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,18 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main3:
	DECFSZ     R13+0, 1
	GOTO       L_main3
	DECFSZ     R12+0, 1
	GOTO       L_main3
	NOP
;multiplexer.c,19 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,21 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,22 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,23 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main4:
	DECFSZ     R13+0, 1
	GOTO       L_main4
	DECFSZ     R12+0, 1
	GOTO       L_main4
	NOP
;multiplexer.c,24 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,26 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,27 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,28 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main5:
	DECFSZ     R13+0, 1
	GOTO       L_main5
	DECFSZ     R12+0, 1
	GOTO       L_main5
	NOP
;multiplexer.c,29 :: 		portc.f3=1;
	BSF        PORTC+0, 3
;multiplexer.c,30 :: 		portc.f0=0;
	BCF        PORTC+0, 0
;multiplexer.c,31 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,32 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main6:
	DECFSZ     R13+0, 1
	GOTO       L_main6
	DECFSZ     R12+0, 1
	GOTO       L_main6
	NOP
;multiplexer.c,33 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,35 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,36 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,37 :: 		delay_ms(10);
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
;multiplexer.c,38 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,40 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,41 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,42 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main8:
	DECFSZ     R13+0, 1
	GOTO       L_main8
	DECFSZ     R12+0, 1
	GOTO       L_main8
	NOP
;multiplexer.c,43 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,45 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,46 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,47 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main9:
	DECFSZ     R13+0, 1
	GOTO       L_main9
	DECFSZ     R12+0, 1
	GOTO       L_main9
	NOP
;multiplexer.c,48 :: 		portc.f3=1;portc.f0=0;
	BSF        PORTC+0, 3
	BCF        PORTC+0, 0
;multiplexer.c,49 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,50 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main10:
	DECFSZ     R13+0, 1
	GOTO       L_main10
	DECFSZ     R12+0, 1
	GOTO       L_main10
	NOP
;multiplexer.c,51 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,53 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,54 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,55 :: 		delay_ms(10);
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
;multiplexer.c,56 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,58 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,59 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,60 :: 		delay_ms(10);
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
;multiplexer.c,61 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,63 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,64 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,65 :: 		delay_ms(10);
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
;multiplexer.c,66 :: 		portc.f3=1;portc.f0=0;
	BSF        PORTC+0, 3
	BCF        PORTC+0, 0
;multiplexer.c,67 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,68 :: 		delay_ms(10);
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
;multiplexer.c,69 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,71 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,72 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,73 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main15:
	DECFSZ     R13+0, 1
	GOTO       L_main15
	DECFSZ     R12+0, 1
	GOTO       L_main15
	NOP
;multiplexer.c,74 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,76 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,77 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,78 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main16:
	DECFSZ     R13+0, 1
	GOTO       L_main16
	DECFSZ     R12+0, 1
	GOTO       L_main16
	NOP
;multiplexer.c,79 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,81 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,82 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,83 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main17:
	DECFSZ     R13+0, 1
	GOTO       L_main17
	DECFSZ     R12+0, 1
	GOTO       L_main17
	NOP
;multiplexer.c,84 :: 		portc.f3=1;portc.f0=0;
	BSF        PORTC+0, 3
	BCF        PORTC+0, 0
;multiplexer.c,85 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,86 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main18:
	DECFSZ     R13+0, 1
	GOTO       L_main18
	DECFSZ     R12+0, 1
	GOTO       L_main18
	NOP
;multiplexer.c,87 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,89 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,90 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,91 :: 		delay_ms(10);
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
;multiplexer.c,92 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,94 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,95 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,96 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main20:
	DECFSZ     R13+0, 1
	GOTO       L_main20
	DECFSZ     R12+0, 1
	GOTO       L_main20
	NOP
;multiplexer.c,97 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,99 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,100 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,101 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main21:
	DECFSZ     R13+0, 1
	GOTO       L_main21
	DECFSZ     R12+0, 1
	GOTO       L_main21
	NOP
;multiplexer.c,102 :: 		portc.f3=1;portc.f0=0;
	BSF        PORTC+0, 3
	BCF        PORTC+0, 0
;multiplexer.c,103 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,104 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main22:
	DECFSZ     R13+0, 1
	GOTO       L_main22
	DECFSZ     R12+0, 1
	GOTO       L_main22
	NOP
;multiplexer.c,105 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,107 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,108 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,109 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main23:
	DECFSZ     R13+0, 1
	GOTO       L_main23
	DECFSZ     R12+0, 1
	GOTO       L_main23
	NOP
;multiplexer.c,110 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,112 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,113 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,114 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main24:
	DECFSZ     R13+0, 1
	GOTO       L_main24
	DECFSZ     R12+0, 1
	GOTO       L_main24
	NOP
;multiplexer.c,115 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,117 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,118 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,119 :: 		delay_ms(10);
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
;multiplexer.c,120 :: 		portc.f3=1;portc.f0=0;
	BSF        PORTC+0, 3
	BCF        PORTC+0, 0
;multiplexer.c,121 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,122 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main26:
	DECFSZ     R13+0, 1
	GOTO       L_main26
	DECFSZ     R12+0, 1
	GOTO       L_main26
	NOP
;multiplexer.c,123 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,125 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,126 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,127 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main27:
	DECFSZ     R13+0, 1
	GOTO       L_main27
	DECFSZ     R12+0, 1
	GOTO       L_main27
	NOP
;multiplexer.c,128 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,130 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,131 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,132 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main28:
	DECFSZ     R13+0, 1
	GOTO       L_main28
	DECFSZ     R12+0, 1
	GOTO       L_main28
	NOP
;multiplexer.c,133 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,135 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,136 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,137 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main29:
	DECFSZ     R13+0, 1
	GOTO       L_main29
	DECFSZ     R12+0, 1
	GOTO       L_main29
	NOP
;multiplexer.c,138 :: 		portc.f3=1;portc.f0=0;
	BSF        PORTC+0, 3
	BCF        PORTC+0, 0
;multiplexer.c,139 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,140 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main30:
	DECFSZ     R13+0, 1
	GOTO       L_main30
	DECFSZ     R12+0, 1
	GOTO       L_main30
	NOP
;multiplexer.c,141 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,143 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,144 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,145 :: 		delay_ms(10);
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
;multiplexer.c,146 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,148 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,149 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,150 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main32:
	DECFSZ     R13+0, 1
	GOTO       L_main32
	DECFSZ     R12+0, 1
	GOTO       L_main32
	NOP
;multiplexer.c,151 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,153 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,154 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,155 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main33:
	DECFSZ     R13+0, 1
	GOTO       L_main33
	DECFSZ     R12+0, 1
	GOTO       L_main33
	NOP
;multiplexer.c,156 :: 		portc.f3=1;portc.f0=0;
	BSF        PORTC+0, 3
	BCF        PORTC+0, 0
;multiplexer.c,157 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,158 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main34:
	DECFSZ     R13+0, 1
	GOTO       L_main34
	DECFSZ     R12+0, 1
	GOTO       L_main34
	NOP
;multiplexer.c,159 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,161 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,162 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,163 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main35:
	DECFSZ     R13+0, 1
	GOTO       L_main35
	DECFSZ     R12+0, 1
	GOTO       L_main35
	NOP
;multiplexer.c,164 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,166 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,167 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,168 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main36:
	DECFSZ     R13+0, 1
	GOTO       L_main36
	DECFSZ     R12+0, 1
	GOTO       L_main36
	NOP
;multiplexer.c,169 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,171 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,172 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,173 :: 		delay_ms(10);
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
;multiplexer.c,174 :: 		portc.f3=1;portc.f0=0;
	BSF        PORTC+0, 3
	BCF        PORTC+0, 0
;multiplexer.c,175 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,176 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main38:
	DECFSZ     R13+0, 1
	GOTO       L_main38
	DECFSZ     R12+0, 1
	GOTO       L_main38
	NOP
;multiplexer.c,177 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,179 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,180 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,181 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main39:
	DECFSZ     R13+0, 1
	GOTO       L_main39
	DECFSZ     R12+0, 1
	GOTO       L_main39
	NOP
;multiplexer.c,182 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,184 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,185 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,186 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main40:
	DECFSZ     R13+0, 1
	GOTO       L_main40
	DECFSZ     R12+0, 1
	GOTO       L_main40
	NOP
;multiplexer.c,187 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,189 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,190 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,191 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main41:
	DECFSZ     R13+0, 1
	GOTO       L_main41
	DECFSZ     R12+0, 1
	GOTO       L_main41
	NOP
;multiplexer.c,192 :: 		portc.f3=1;portc.f0=0;
	BSF        PORTC+0, 3
	BCF        PORTC+0, 0
;multiplexer.c,193 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,194 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main42:
	DECFSZ     R13+0, 1
	GOTO       L_main42
	DECFSZ     R12+0, 1
	GOTO       L_main42
	NOP
;multiplexer.c,195 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,197 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,198 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,199 :: 		delay_ms(10);
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
;multiplexer.c,200 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,202 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,203 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,204 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main44:
	DECFSZ     R13+0, 1
	GOTO       L_main44
	DECFSZ     R12+0, 1
	GOTO       L_main44
	NOP
;multiplexer.c,205 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,207 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,208 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,209 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main45:
	DECFSZ     R13+0, 1
	GOTO       L_main45
	DECFSZ     R12+0, 1
	GOTO       L_main45
	NOP
;multiplexer.c,210 :: 		portc.f3=1;portc.f0=0;
	BSF        PORTC+0, 3
	BCF        PORTC+0, 0
;multiplexer.c,211 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,212 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main46:
	DECFSZ     R13+0, 1
	GOTO       L_main46
	DECFSZ     R12+0, 1
	GOTO       L_main46
	NOP
;multiplexer.c,213 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,215 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,216 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,217 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main47:
	DECFSZ     R13+0, 1
	GOTO       L_main47
	DECFSZ     R12+0, 1
	GOTO       L_main47
	NOP
;multiplexer.c,218 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,220 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,221 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,222 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main48:
	DECFSZ     R13+0, 1
	GOTO       L_main48
	DECFSZ     R12+0, 1
	GOTO       L_main48
	NOP
;multiplexer.c,223 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,225 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,226 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,227 :: 		delay_ms(10);
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
;multiplexer.c,228 :: 		portc.f3=1;portc.f0=0;
	BSF        PORTC+0, 3
	BCF        PORTC+0, 0
;multiplexer.c,229 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,230 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main50:
	DECFSZ     R13+0, 1
	GOTO       L_main50
	DECFSZ     R12+0, 1
	GOTO       L_main50
	NOP
;multiplexer.c,231 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,233 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,234 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,235 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main51:
	DECFSZ     R13+0, 1
	GOTO       L_main51
	DECFSZ     R12+0, 1
	GOTO       L_main51
	NOP
;multiplexer.c,236 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,238 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,239 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,240 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main52:
	DECFSZ     R13+0, 1
	GOTO       L_main52
	DECFSZ     R12+0, 1
	GOTO       L_main52
	NOP
;multiplexer.c,241 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,243 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,244 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,245 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main53:
	DECFSZ     R13+0, 1
	GOTO       L_main53
	DECFSZ     R12+0, 1
	GOTO       L_main53
	NOP
;multiplexer.c,246 :: 		portc.f3=1;portc.f0=0;
	BSF        PORTC+0, 3
	BCF        PORTC+0, 0
;multiplexer.c,247 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,248 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main54:
	DECFSZ     R13+0, 1
	GOTO       L_main54
	DECFSZ     R12+0, 1
	GOTO       L_main54
	NOP
;multiplexer.c,249 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,251 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,252 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,253 :: 		delay_ms(10);
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
;multiplexer.c,254 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,256 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,257 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,258 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main56:
	DECFSZ     R13+0, 1
	GOTO       L_main56
	DECFSZ     R12+0, 1
	GOTO       L_main56
	NOP
;multiplexer.c,259 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,261 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,262 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,263 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main57:
	DECFSZ     R13+0, 1
	GOTO       L_main57
	DECFSZ     R12+0, 1
	GOTO       L_main57
	NOP
;multiplexer.c,264 :: 		portc.f3=1;portc.f0=0;
	BSF        PORTC+0, 3
	BCF        PORTC+0, 0
;multiplexer.c,265 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,266 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main58:
	DECFSZ     R13+0, 1
	GOTO       L_main58
	DECFSZ     R12+0, 1
	GOTO       L_main58
	NOP
;multiplexer.c,267 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,269 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,270 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,271 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main59:
	DECFSZ     R13+0, 1
	GOTO       L_main59
	DECFSZ     R12+0, 1
	GOTO       L_main59
	NOP
;multiplexer.c,272 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,274 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,275 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,276 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main60:
	DECFSZ     R13+0, 1
	GOTO       L_main60
	DECFSZ     R12+0, 1
	GOTO       L_main60
	NOP
;multiplexer.c,277 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,279 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,280 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,281 :: 		delay_ms(10);
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
;multiplexer.c,282 :: 		portc.f3=1;portc.f0=0;
	BSF        PORTC+0, 3
	BCF        PORTC+0, 0
;multiplexer.c,283 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,284 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main62:
	DECFSZ     R13+0, 1
	GOTO       L_main62
	DECFSZ     R12+0, 1
	GOTO       L_main62
	NOP
;multiplexer.c,285 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,287 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,288 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,289 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main63:
	DECFSZ     R13+0, 1
	GOTO       L_main63
	DECFSZ     R12+0, 1
	GOTO       L_main63
	NOP
;multiplexer.c,290 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,292 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,293 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,294 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main64:
	DECFSZ     R13+0, 1
	GOTO       L_main64
	DECFSZ     R12+0, 1
	GOTO       L_main64
	NOP
;multiplexer.c,295 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,297 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,298 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,299 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main65:
	DECFSZ     R13+0, 1
	GOTO       L_main65
	DECFSZ     R12+0, 1
	GOTO       L_main65
	NOP
;multiplexer.c,300 :: 		portc.f3=1;portc.f0=0;
	BSF        PORTC+0, 3
	BCF        PORTC+0, 0
;multiplexer.c,301 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,302 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main66:
	DECFSZ     R13+0, 1
	GOTO       L_main66
	DECFSZ     R12+0, 1
	GOTO       L_main66
	NOP
;multiplexer.c,303 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,305 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,306 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,307 :: 		delay_ms(10);
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
;multiplexer.c,308 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,310 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,311 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,312 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main68:
	DECFSZ     R13+0, 1
	GOTO       L_main68
	DECFSZ     R12+0, 1
	GOTO       L_main68
	NOP
;multiplexer.c,313 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,315 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,316 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,317 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main69:
	DECFSZ     R13+0, 1
	GOTO       L_main69
	DECFSZ     R12+0, 1
	GOTO       L_main69
	NOP
;multiplexer.c,318 :: 		portc.f3=1;portc.f0=0;
	BSF        PORTC+0, 3
	BCF        PORTC+0, 0
;multiplexer.c,319 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,320 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main70:
	DECFSZ     R13+0, 1
	GOTO       L_main70
	DECFSZ     R12+0, 1
	GOTO       L_main70
	NOP
;multiplexer.c,321 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,323 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,324 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,325 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main71:
	DECFSZ     R13+0, 1
	GOTO       L_main71
	DECFSZ     R12+0, 1
	GOTO       L_main71
	NOP
;multiplexer.c,326 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,328 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,329 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,330 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main72:
	DECFSZ     R13+0, 1
	GOTO       L_main72
	DECFSZ     R12+0, 1
	GOTO       L_main72
	NOP
;multiplexer.c,331 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,333 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,334 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,335 :: 		delay_ms(10);
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
;multiplexer.c,336 :: 		portc.f3=1;portc.f0=0;
	BSF        PORTC+0, 3
	BCF        PORTC+0, 0
;multiplexer.c,337 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,338 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main74:
	DECFSZ     R13+0, 1
	GOTO       L_main74
	DECFSZ     R12+0, 1
	GOTO       L_main74
	NOP
;multiplexer.c,339 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,341 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,342 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,343 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main75:
	DECFSZ     R13+0, 1
	GOTO       L_main75
	DECFSZ     R12+0, 1
	GOTO       L_main75
	NOP
;multiplexer.c,344 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,346 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,347 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,348 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main76:
	DECFSZ     R13+0, 1
	GOTO       L_main76
	DECFSZ     R12+0, 1
	GOTO       L_main76
	NOP
;multiplexer.c,349 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,351 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,352 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,353 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main77:
	DECFSZ     R13+0, 1
	GOTO       L_main77
	DECFSZ     R12+0, 1
	GOTO       L_main77
	NOP
;multiplexer.c,354 :: 		portc.f3=1;portc.f0=0;
	BSF        PORTC+0, 3
	BCF        PORTC+0, 0
;multiplexer.c,355 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,356 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main78:
	DECFSZ     R13+0, 1
	GOTO       L_main78
	DECFSZ     R12+0, 1
	GOTO       L_main78
	NOP
;multiplexer.c,357 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,359 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,360 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,361 :: 		delay_ms(10);
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
;multiplexer.c,362 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,364 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,365 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,366 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main80:
	DECFSZ     R13+0, 1
	GOTO       L_main80
	DECFSZ     R12+0, 1
	GOTO       L_main80
	NOP
;multiplexer.c,367 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,369 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,370 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,371 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main81:
	DECFSZ     R13+0, 1
	GOTO       L_main81
	DECFSZ     R12+0, 1
	GOTO       L_main81
	NOP
;multiplexer.c,372 :: 		portc.f3=1;portc.f0=0;
	BSF        PORTC+0, 3
	BCF        PORTC+0, 0
;multiplexer.c,373 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,374 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main82:
	DECFSZ     R13+0, 1
	GOTO       L_main82
	DECFSZ     R12+0, 1
	GOTO       L_main82
	NOP
;multiplexer.c,375 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,377 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,378 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,379 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main83:
	DECFSZ     R13+0, 1
	GOTO       L_main83
	DECFSZ     R12+0, 1
	GOTO       L_main83
	NOP
;multiplexer.c,380 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,382 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,383 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,384 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main84:
	DECFSZ     R13+0, 1
	GOTO       L_main84
	DECFSZ     R12+0, 1
	GOTO       L_main84
	NOP
;multiplexer.c,385 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,387 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,388 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,389 :: 		delay_ms(10);
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
;multiplexer.c,390 :: 		portc.f3=1;portc.f0=0;
	BSF        PORTC+0, 3
	BCF        PORTC+0, 0
;multiplexer.c,391 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,392 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main86:
	DECFSZ     R13+0, 1
	GOTO       L_main86
	DECFSZ     R12+0, 1
	GOTO       L_main86
	NOP
;multiplexer.c,393 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,395 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,396 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,397 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main87:
	DECFSZ     R13+0, 1
	GOTO       L_main87
	DECFSZ     R12+0, 1
	GOTO       L_main87
	NOP
;multiplexer.c,398 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,400 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,401 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,402 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main88:
	DECFSZ     R13+0, 1
	GOTO       L_main88
	DECFSZ     R12+0, 1
	GOTO       L_main88
	NOP
;multiplexer.c,403 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,405 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,406 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,407 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main89:
	DECFSZ     R13+0, 1
	GOTO       L_main89
	DECFSZ     R12+0, 1
	GOTO       L_main89
	NOP
;multiplexer.c,408 :: 		portc.f3=1;portc.f0=0;
	BSF        PORTC+0, 3
	BCF        PORTC+0, 0
;multiplexer.c,409 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,410 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main90:
	DECFSZ     R13+0, 1
	GOTO       L_main90
	DECFSZ     R12+0, 1
	GOTO       L_main90
	NOP
;multiplexer.c,411 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,413 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,414 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,415 :: 		delay_ms(10);
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
;multiplexer.c,416 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,418 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,419 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,420 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main92:
	DECFSZ     R13+0, 1
	GOTO       L_main92
	DECFSZ     R12+0, 1
	GOTO       L_main92
	NOP
;multiplexer.c,421 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,423 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,424 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,425 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main93:
	DECFSZ     R13+0, 1
	GOTO       L_main93
	DECFSZ     R12+0, 1
	GOTO       L_main93
	NOP
;multiplexer.c,426 :: 		portc.f3=1;portc.f0=0;
	BSF        PORTC+0, 3
	BCF        PORTC+0, 0
;multiplexer.c,427 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,428 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main94:
	DECFSZ     R13+0, 1
	GOTO       L_main94
	DECFSZ     R12+0, 1
	GOTO       L_main94
	NOP
;multiplexer.c,429 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,431 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,432 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,433 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main95:
	DECFSZ     R13+0, 1
	GOTO       L_main95
	DECFSZ     R12+0, 1
	GOTO       L_main95
	NOP
;multiplexer.c,434 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,436 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,437 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,438 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main96:
	DECFSZ     R13+0, 1
	GOTO       L_main96
	DECFSZ     R12+0, 1
	GOTO       L_main96
	NOP
;multiplexer.c,439 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,441 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,442 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,443 :: 		delay_ms(10);
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
;multiplexer.c,444 :: 		portc.f3=1;portc.f0=0;
	BSF        PORTC+0, 3
	BCF        PORTC+0, 0
;multiplexer.c,445 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,446 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main98:
	DECFSZ     R13+0, 1
	GOTO       L_main98
	DECFSZ     R12+0, 1
	GOTO       L_main98
	NOP
;multiplexer.c,447 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,449 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,450 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,451 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main99:
	DECFSZ     R13+0, 1
	GOTO       L_main99
	DECFSZ     R12+0, 1
	GOTO       L_main99
	NOP
;multiplexer.c,452 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,454 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,455 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,456 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main100:
	DECFSZ     R13+0, 1
	GOTO       L_main100
	DECFSZ     R12+0, 1
	GOTO       L_main100
	NOP
;multiplexer.c,457 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,459 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,460 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,461 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main101:
	DECFSZ     R13+0, 1
	GOTO       L_main101
	DECFSZ     R12+0, 1
	GOTO       L_main101
	NOP
;multiplexer.c,462 :: 		portc.f3=1;portc.f0=0;
	BSF        PORTC+0, 3
	BCF        PORTC+0, 0
;multiplexer.c,463 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,464 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main102:
	DECFSZ     R13+0, 1
	GOTO       L_main102
	DECFSZ     R12+0, 1
	GOTO       L_main102
	NOP
;multiplexer.c,465 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,467 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,468 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,469 :: 		delay_ms(10);
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
;multiplexer.c,470 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,472 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,473 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,474 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main104:
	DECFSZ     R13+0, 1
	GOTO       L_main104
	DECFSZ     R12+0, 1
	GOTO       L_main104
	NOP
;multiplexer.c,475 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,477 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,478 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,479 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main105:
	DECFSZ     R13+0, 1
	GOTO       L_main105
	DECFSZ     R12+0, 1
	GOTO       L_main105
	NOP
;multiplexer.c,480 :: 		portc.f3=1;portc.f0=0;
	BSF        PORTC+0, 3
	BCF        PORTC+0, 0
;multiplexer.c,481 :: 		portb=arr[1];
	MOVF       _arr+1, 0
	MOVWF      PORTB+0
;multiplexer.c,482 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main106:
	DECFSZ     R13+0, 1
	GOTO       L_main106
	DECFSZ     R12+0, 1
	GOTO       L_main106
	NOP
;multiplexer.c,483 :: 		portc.f0=1;
	BSF        PORTC+0, 0
;multiplexer.c,485 :: 		portc.f1=0;
	BCF        PORTC+0, 1
;multiplexer.c,486 :: 		portb=arr[3];
	MOVF       _arr+3, 0
	MOVWF      PORTB+0
;multiplexer.c,487 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main107:
	DECFSZ     R13+0, 1
	GOTO       L_main107
	DECFSZ     R12+0, 1
	GOTO       L_main107
	NOP
;multiplexer.c,488 :: 		portc.f1=1;
	BSF        PORTC+0, 1
;multiplexer.c,490 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;multiplexer.c,491 :: 		portb=arr[5];;
	MOVF       _arr+5, 0
	MOVWF      PORTB+0
;multiplexer.c,492 :: 		delay_ms(10);
	MOVLW      26
	MOVWF      R12+0
	MOVLW      248
	MOVWF      R13+0
L_main108:
	DECFSZ     R13+0, 1
	GOTO       L_main108
	DECFSZ     R12+0, 1
	GOTO       L_main108
	NOP
;multiplexer.c,493 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;multiplexer.c,495 :: 		portc.f3=0;
	BCF        PORTC+0, 3
;multiplexer.c,496 :: 		portb=arr[7];
	MOVF       _arr+7, 0
	MOVWF      PORTB+0
;multiplexer.c,497 :: 		delay_ms(10);
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
;multiplexer.c,498 :: 		portc.f3=1;
	BSF        PORTC+0, 3
;multiplexer.c,499 :: 		}
	GOTO       L_main0
;multiplexer.c,500 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
