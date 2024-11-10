
_init:

;lcd_test.c,15 :: 		void init(){
;lcd_test.c,16 :: 		lcd_init();
	CALL       _Lcd_Init+0
;lcd_test.c,17 :: 		}
L_end_init:
	RETURN
; end of _init

_main:

;lcd_test.c,20 :: 		void main() {
;lcd_test.c,21 :: 		init();
	CALL       _init+0
;lcd_test.c,22 :: 		while(1){
L_main0:
;lcd_test.c,23 :: 		lcd_out(1,1,"Parvez    ");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr1_lcd_test+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;lcd_test.c,24 :: 		lcd_out(2,1,"Ali        ");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr2_lcd_test+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;lcd_test.c,25 :: 		delay_ms(1000);
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
;lcd_test.c,26 :: 		}
	GOTO       L_main0
;lcd_test.c,27 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
