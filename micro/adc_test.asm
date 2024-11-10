
_init:

;adc_test.c,1 :: 		void init(){
;adc_test.c,2 :: 		trisb = 0x00;
	CLRF       TRISB+0
;adc_test.c,3 :: 		portb = 0x00;
	CLRF       PORTB+0
;adc_test.c,4 :: 		uart1_init(9600);
	MOVLW      51
	MOVWF      SPBRG+0
	BSF        TXSTA+0, 2
	CALL       _UART1_Init+0
;adc_test.c,5 :: 		adc_init();
	CALL       _ADC_Init+0
;adc_test.c,6 :: 		}
L_end_init:
	RETURN
; end of _init

_main:

;adc_test.c,9 :: 		void main() {
;adc_test.c,10 :: 		init();
	CALL       _init+0
;adc_test.c,11 :: 		while(1){
L_main0:
;adc_test.c,12 :: 		portb = 0x0f;
	MOVLW      15
	MOVWF      PORTB+0
;adc_test.c,13 :: 		temp = adc_read(0);
	CLRF       FARG_ADC_Read_channel+0
	CALL       _ADC_Read+0
	MOVF       R0+0, 0
	MOVWF      _temp+0
	MOVF       R0+1, 0
	MOVWF      _temp+1
;adc_test.c,14 :: 		inttostr(temp, arr);
	MOVF       R0+0, 0
	MOVWF      FARG_IntToStr_input+0
	MOVF       R0+1, 0
	MOVWF      FARG_IntToStr_input+1
	MOVLW      _arr+0
	MOVWF      FARG_IntToStr_output+0
	CALL       _IntToStr+0
;adc_test.c,15 :: 		uart1_write_text(arr);
	MOVLW      _arr+0
	MOVWF      FARG_UART1_Write_Text_uart_text+0
	CALL       _UART1_Write_Text+0
;adc_test.c,16 :: 		uart1_write(13);
	MOVLW      13
	MOVWF      FARG_UART1_Write_data_+0
	CALL       _UART1_Write+0
;adc_test.c,17 :: 		delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
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
;adc_test.c,18 :: 		}
	GOTO       L_main0
;adc_test.c,19 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
