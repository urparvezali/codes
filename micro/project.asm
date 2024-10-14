
_init:

;project.c,1 :: 		void init(){
;project.c,2 :: 		trisb = 0x00;
	CLRF       TRISB+0
;project.c,3 :: 		trisc = 0x00;
	CLRF       TRISC+0
;project.c,4 :: 		trisd = 0xff;
	MOVLW      255
	MOVWF      TRISD+0
;project.c,5 :: 		trisa = 0x00;
	CLRF       TRISA+0
;project.c,6 :: 		portb = 0x00;
	CLRF       PORTB+0
;project.c,7 :: 		portc = 0x00;
	CLRF       PORTC+0
;project.c,8 :: 		portd = 0x00;
	CLRF       PORTD+0
;project.c,9 :: 		porta = 0x00;
	CLRF       PORTA+0
;project.c,10 :: 		}
L_end_init:
	RETURN
; end of _init

_read_int:

;project.c,20 :: 		unsigned int read_int(unsigned int add){
;project.c,21 :: 		return EEPROM_Read(add) | (EEPROM_Read(add+1) << 8) ;
	MOVF       FARG_read_int_add+0, 0
	MOVWF      FARG_EEPROM_Read_Address+0
	CALL       _EEPROM_Read+0
	MOVF       R0+0, 0
	MOVWF      FLOC__read_int+0
	INCF       FARG_read_int_add+0, 0
	MOVWF      FARG_EEPROM_Read_Address+0
	CALL       _EEPROM_Read+0
	MOVF       R0+0, 0
	MOVWF      R2+1
	CLRF       R2+0
	MOVF       R2+0, 0
	IORWF      FLOC__read_int+0, 0
	MOVWF      R0+0
	MOVLW      0
	IORWF      R2+1, 0
	MOVWF      R0+1
;project.c,22 :: 		}
L_end_read_int:
	RETURN
; end of _read_int

_write_int:

;project.c,23 :: 		void write_int(unsigned int add, unsigned int val){
;project.c,24 :: 		EEPROM_Write(add, (val & 0xff));
	MOVF       FARG_write_int_add+0, 0
	MOVWF      FARG_EEPROM_Write_Address+0
	MOVLW      255
	ANDWF      FARG_write_int_val+0, 0
	MOVWF      FARG_EEPROM_Write_data_+0
	CALL       _EEPROM_Write+0
;project.c,25 :: 		EEPROM_Write(add+1, ((val >> 8) & 0xff));
	INCF       FARG_write_int_add+0, 0
	MOVWF      FARG_EEPROM_Write_Address+0
	MOVF       FARG_write_int_val+1, 0
	MOVWF      R0+0
	CLRF       R0+1
	MOVLW      255
	ANDWF      R0+0, 0
	MOVWF      FARG_EEPROM_Write_data_+0
	CALL       _EEPROM_Write+0
;project.c,26 :: 		}
L_end_write_int:
	RETURN
; end of _write_int

_get_mode:

;project.c,28 :: 		void get_mode(){
;project.c,29 :: 		delay_ms(100);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      4
	MOVWF      R12+0
	MOVLW      186
	MOVWF      R13+0
L_get_mode0:
	DECFSZ     R13+0, 1
	GOTO       L_get_mode0
	DECFSZ     R12+0, 1
	GOTO       L_get_mode0
	DECFSZ     R11+0, 1
	GOTO       L_get_mode0
	NOP
;project.c,30 :: 		if (portd.f0){
	BTFSS      PORTD+0, 0
	GOTO       L_get_mode1
;project.c,31 :: 		mode = 1;
	MOVLW      1
	MOVWF      _mode+0
	MOVLW      0
	MOVWF      _mode+1
;project.c,32 :: 		} else{
	GOTO       L_get_mode2
L_get_mode1:
;project.c,33 :: 		mode = 0;
	CLRF       _mode+0
	CLRF       _mode+1
;project.c,34 :: 		}
L_get_mode2:
;project.c,35 :: 		}
L_end_get_mode:
	RETURN
; end of _get_mode

_read_rom:

;project.c,36 :: 		void read_rom(){
;project.c,37 :: 		on_time = read_int(0x00);
	CLRF       FARG_read_int_add+0
	CLRF       FARG_read_int_add+1
	CALL       _read_int+0
	MOVF       R0+0, 0
	MOVWF      _on_time+0
	MOVF       R0+1, 0
	MOVWF      _on_time+1
;project.c,38 :: 		off_time = read_int(0x02);
	MOVLW      2
	MOVWF      FARG_read_int_add+0
	MOVLW      0
	MOVWF      FARG_read_int_add+1
	CALL       _read_int+0
	MOVF       R0+0, 0
	MOVWF      _off_time+0
	MOVF       R0+1, 0
	MOVWF      _off_time+1
;project.c,39 :: 		channels = read_int(0x04);
	MOVLW      4
	MOVWF      FARG_read_int_add+0
	MOVLW      0
	MOVWF      FARG_read_int_add+1
	CALL       _read_int+0
	MOVF       R0+0, 0
	MOVWF      _channels+0
	MOVF       R0+1, 0
	MOVWF      _channels+1
;project.c,40 :: 		}
L_end_read_rom:
	RETURN
; end of _read_rom

_write_rom:

;project.c,41 :: 		void write_rom(){
;project.c,42 :: 		write_int(0x00, on_time);
	CLRF       FARG_write_int_add+0
	CLRF       FARG_write_int_add+1
	MOVF       _on_time+0, 0
	MOVWF      FARG_write_int_val+0
	MOVF       _on_time+1, 0
	MOVWF      FARG_write_int_val+1
	CALL       _write_int+0
;project.c,43 :: 		write_int(0x02, off_time);
	MOVLW      2
	MOVWF      FARG_write_int_add+0
	MOVLW      0
	MOVWF      FARG_write_int_add+1
	MOVF       _off_time+0, 0
	MOVWF      FARG_write_int_val+0
	MOVF       _off_time+1, 0
	MOVWF      FARG_write_int_val+1
	CALL       _write_int+0
;project.c,44 :: 		write_int(0x04, channels);
	MOVLW      4
	MOVWF      FARG_write_int_add+0
	MOVLW      0
	MOVWF      FARG_write_int_add+1
	MOVF       _channels+0, 0
	MOVWF      FARG_write_int_val+0
	MOVF       _channels+1, 0
	MOVWF      FARG_write_int_val+1
	CALL       _write_int+0
;project.c,45 :: 		}
L_end_write_rom:
	RETURN
; end of _write_rom

_show_led:

;project.c,46 :: 		void show_led(int value){
;project.c,47 :: 		digit1 = value%10;
	MOVLW      10
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVF       FARG_show_led_value+0, 0
	MOVWF      R0+0
	MOVF       FARG_show_led_value+1, 0
	MOVWF      R0+1
	CALL       _Div_16x16_S+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R8+1, 0
	MOVWF      R0+1
	MOVF       R0+0, 0
	MOVWF      _digit1+0
	MOVF       R0+1, 0
	MOVWF      _digit1+1
;project.c,48 :: 		digit0 = value/10;
	MOVLW      10
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVF       FARG_show_led_value+0, 0
	MOVWF      R0+0
	MOVF       FARG_show_led_value+1, 0
	MOVWF      R0+1
	CALL       _Div_16x16_S+0
	MOVF       R0+0, 0
	MOVWF      _digit0+0
	MOVF       R0+1, 0
	MOVWF      _digit0+1
;project.c,50 :: 		portc.f1 = 1;
	BSF        PORTC+0, 1
;project.c,51 :: 		portb = arr[digit0];
	MOVF       R0+0, 0
	MOVWF      R2+0
	RLF        R2+0, 1
	BCF        R2+0, 0
	MOVF       R2+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;project.c,52 :: 		portc.f0 = 0;
	BCF        PORTC+0, 0
;project.c,54 :: 		delay_ms(5);
	MOVLW      13
	MOVWF      R12+0
	MOVLW      251
	MOVWF      R13+0
L_show_led3:
	DECFSZ     R13+0, 1
	GOTO       L_show_led3
	DECFSZ     R12+0, 1
	GOTO       L_show_led3
	NOP
	NOP
;project.c,56 :: 		portc.f0 = 1;
	BSF        PORTC+0, 0
;project.c,57 :: 		portb = arr[digit1];
	MOVF       _digit1+0, 0
	MOVWF      R0+0
	RLF        R0+0, 1
	BCF        R0+0, 0
	MOVF       R0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;project.c,58 :: 		portc.f1 = 0;
	BCF        PORTC+0, 1
;project.c,60 :: 		delay_ms(5);
	MOVLW      13
	MOVWF      R12+0
	MOVLW      251
	MOVWF      R13+0
L_show_led4:
	DECFSZ     R13+0, 1
	GOTO       L_show_led4
	DECFSZ     R12+0, 1
	GOTO       L_show_led4
	NOP
	NOP
;project.c,61 :: 		}
L_end_show_led:
	RETURN
; end of _show_led

_program_mode:

;project.c,63 :: 		void program_mode(){
;project.c,64 :: 		on_time=0;
	CLRF       _on_time+0
	CLRF       _on_time+1
;project.c,65 :: 		off_time=0;
	CLRF       _off_time+0
	CLRF       _off_time+1
;project.c,66 :: 		channels=0;
	CLRF       _channels+0
	CLRF       _channels+1
;project.c,68 :: 		while (1){
L_program_mode5:
;project.c,70 :: 		if (portd.f1){
	BTFSS      PORTD+0, 1
	GOTO       L_program_mode7
;project.c,71 :: 		while (portd.f1) delay_ms(5);
L_program_mode8:
	BTFSS      PORTD+0, 1
	GOTO       L_program_mode9
	MOVLW      13
	MOVWF      R12+0
	MOVLW      251
	MOVWF      R13+0
L_program_mode10:
	DECFSZ     R13+0, 1
	GOTO       L_program_mode10
	DECFSZ     R12+0, 1
	GOTO       L_program_mode10
	NOP
	NOP
	GOTO       L_program_mode8
L_program_mode9:
;project.c,72 :: 		break;
	GOTO       L_program_mode6
;project.c,73 :: 		}
L_program_mode7:
;project.c,74 :: 		if (portd.f2){
	BTFSS      PORTD+0, 2
	GOTO       L_program_mode11
;project.c,75 :: 		while (portd.f2) delay_ms(5);
L_program_mode12:
	BTFSS      PORTD+0, 2
	GOTO       L_program_mode13
	MOVLW      13
	MOVWF      R12+0
	MOVLW      251
	MOVWF      R13+0
L_program_mode14:
	DECFSZ     R13+0, 1
	GOTO       L_program_mode14
	DECFSZ     R12+0, 1
	GOTO       L_program_mode14
	NOP
	NOP
	GOTO       L_program_mode12
L_program_mode13:
;project.c,76 :: 		on_time += on_time<99 ? 1 : 0;
	MOVLW      0
	SUBWF      _on_time+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__program_mode79
	MOVLW      99
	SUBWF      _on_time+0, 0
L__program_mode79:
	BTFSC      STATUS+0, 0
	GOTO       L_program_mode15
	MOVLW      1
	MOVWF      ?FLOC___program_modeT31+0
	GOTO       L_program_mode16
L_program_mode15:
	CLRF       ?FLOC___program_modeT31+0
L_program_mode16:
	MOVF       ?FLOC___program_modeT31+0, 0
	ADDWF      _on_time+0, 1
	BTFSC      STATUS+0, 0
	INCF       _on_time+1, 1
	MOVLW      0
	BTFSC      ?FLOC___program_modeT31+0, 7
	MOVLW      255
	ADDWF      _on_time+1, 1
;project.c,77 :: 		}
L_program_mode11:
;project.c,78 :: 		if (portd.f3){
	BTFSS      PORTD+0, 3
	GOTO       L_program_mode17
;project.c,79 :: 		while (portd.f3) delay_ms(5);
L_program_mode18:
	BTFSS      PORTD+0, 3
	GOTO       L_program_mode19
	MOVLW      13
	MOVWF      R12+0
	MOVLW      251
	MOVWF      R13+0
L_program_mode20:
	DECFSZ     R13+0, 1
	GOTO       L_program_mode20
	DECFSZ     R12+0, 1
	GOTO       L_program_mode20
	NOP
	NOP
	GOTO       L_program_mode18
L_program_mode19:
;project.c,80 :: 		on_time -= on_time>0 ? 1 : 0;
	MOVF       _on_time+1, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__program_mode80
	MOVF       _on_time+0, 0
	SUBLW      0
L__program_mode80:
	BTFSC      STATUS+0, 0
	GOTO       L_program_mode21
	MOVLW      1
	MOVWF      ?FLOC___program_modeT36+0
	GOTO       L_program_mode22
L_program_mode21:
	CLRF       ?FLOC___program_modeT36+0
L_program_mode22:
	MOVF       ?FLOC___program_modeT36+0, 0
	SUBWF      _on_time+0, 1
	MOVLW      0
	BTFSC      ?FLOC___program_modeT36+0, 7
	MOVLW      255
	BTFSS      STATUS+0, 0
	ADDLW      1
	SUBWF      _on_time+1, 1
;project.c,81 :: 		}
L_program_mode17:
;project.c,82 :: 		show_led(on_time);
	MOVF       _on_time+0, 0
	MOVWF      FARG_show_led_value+0
	MOVF       _on_time+1, 0
	MOVWF      FARG_show_led_value+1
	CALL       _show_led+0
;project.c,83 :: 		}
	GOTO       L_program_mode5
L_program_mode6:
;project.c,85 :: 		while (1){
L_program_mode23:
;project.c,87 :: 		if (portd.f1){
	BTFSS      PORTD+0, 1
	GOTO       L_program_mode25
;project.c,88 :: 		while (portd.f1) delay_ms(5);
L_program_mode26:
	BTFSS      PORTD+0, 1
	GOTO       L_program_mode27
	MOVLW      13
	MOVWF      R12+0
	MOVLW      251
	MOVWF      R13+0
L_program_mode28:
	DECFSZ     R13+0, 1
	GOTO       L_program_mode28
	DECFSZ     R12+0, 1
	GOTO       L_program_mode28
	NOP
	NOP
	GOTO       L_program_mode26
L_program_mode27:
;project.c,89 :: 		break;
	GOTO       L_program_mode24
;project.c,90 :: 		}
L_program_mode25:
;project.c,91 :: 		if (portd.f2){
	BTFSS      PORTD+0, 2
	GOTO       L_program_mode29
;project.c,92 :: 		while (portd.f2) delay_ms(5);
L_program_mode30:
	BTFSS      PORTD+0, 2
	GOTO       L_program_mode31
	MOVLW      13
	MOVWF      R12+0
	MOVLW      251
	MOVWF      R13+0
L_program_mode32:
	DECFSZ     R13+0, 1
	GOTO       L_program_mode32
	DECFSZ     R12+0, 1
	GOTO       L_program_mode32
	NOP
	NOP
	GOTO       L_program_mode30
L_program_mode31:
;project.c,93 :: 		off_time += 1;
	INCF       _off_time+0, 1
	BTFSC      STATUS+0, 2
	INCF       _off_time+1, 1
;project.c,94 :: 		}
L_program_mode29:
;project.c,95 :: 		if (portd.f3){
	BTFSS      PORTD+0, 3
	GOTO       L_program_mode33
;project.c,96 :: 		while (portd.f3) delay_ms(5);
L_program_mode34:
	BTFSS      PORTD+0, 3
	GOTO       L_program_mode35
	MOVLW      13
	MOVWF      R12+0
	MOVLW      251
	MOVWF      R13+0
L_program_mode36:
	DECFSZ     R13+0, 1
	GOTO       L_program_mode36
	DECFSZ     R12+0, 1
	GOTO       L_program_mode36
	NOP
	NOP
	GOTO       L_program_mode34
L_program_mode35:
;project.c,97 :: 		off_time -= off_time>0 ? 1 : 0;
	MOVF       _off_time+1, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__program_mode81
	MOVF       _off_time+0, 0
	SUBLW      0
L__program_mode81:
	BTFSC      STATUS+0, 0
	GOTO       L_program_mode37
	MOVLW      1
	MOVWF      ?FLOC___program_modeT46+0
	GOTO       L_program_mode38
L_program_mode37:
	CLRF       ?FLOC___program_modeT46+0
L_program_mode38:
	MOVF       ?FLOC___program_modeT46+0, 0
	SUBWF      _off_time+0, 1
	MOVLW      0
	BTFSC      ?FLOC___program_modeT46+0, 7
	MOVLW      255
	BTFSS      STATUS+0, 0
	ADDLW      1
	SUBWF      _off_time+1, 1
;project.c,98 :: 		}
L_program_mode33:
;project.c,99 :: 		show_led(off_time);
	MOVF       _off_time+0, 0
	MOVWF      FARG_show_led_value+0
	MOVF       _off_time+1, 0
	MOVWF      FARG_show_led_value+1
	CALL       _show_led+0
;project.c,100 :: 		}
	GOTO       L_program_mode23
L_program_mode24:
;project.c,102 :: 		while (1){
L_program_mode39:
;project.c,104 :: 		if (portd.f1){
	BTFSS      PORTD+0, 1
	GOTO       L_program_mode41
;project.c,105 :: 		while (portd.f1) delay_ms(5);
L_program_mode42:
	BTFSS      PORTD+0, 1
	GOTO       L_program_mode43
	MOVLW      13
	MOVWF      R12+0
	MOVLW      251
	MOVWF      R13+0
L_program_mode44:
	DECFSZ     R13+0, 1
	GOTO       L_program_mode44
	DECFSZ     R12+0, 1
	GOTO       L_program_mode44
	NOP
	NOP
	GOTO       L_program_mode42
L_program_mode43:
;project.c,106 :: 		break;
	GOTO       L_program_mode40
;project.c,107 :: 		}
L_program_mode41:
;project.c,108 :: 		if (portd.f2){
	BTFSS      PORTD+0, 2
	GOTO       L_program_mode45
;project.c,109 :: 		while (portd.f2) delay_ms(5);
L_program_mode46:
	BTFSS      PORTD+0, 2
	GOTO       L_program_mode47
	MOVLW      13
	MOVWF      R12+0
	MOVLW      251
	MOVWF      R13+0
L_program_mode48:
	DECFSZ     R13+0, 1
	GOTO       L_program_mode48
	DECFSZ     R12+0, 1
	GOTO       L_program_mode48
	NOP
	NOP
	GOTO       L_program_mode46
L_program_mode47:
;project.c,110 :: 		channels += channels<16 ? 1 : 0;
	MOVLW      0
	SUBWF      _channels+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__program_mode82
	MOVLW      16
	SUBWF      _channels+0, 0
L__program_mode82:
	BTFSC      STATUS+0, 0
	GOTO       L_program_mode49
	MOVLW      1
	MOVWF      ?FLOC___program_modeT53+0
	GOTO       L_program_mode50
L_program_mode49:
	CLRF       ?FLOC___program_modeT53+0
L_program_mode50:
	MOVF       ?FLOC___program_modeT53+0, 0
	ADDWF      _channels+0, 1
	BTFSC      STATUS+0, 0
	INCF       _channels+1, 1
	MOVLW      0
	BTFSC      ?FLOC___program_modeT53+0, 7
	MOVLW      255
	ADDWF      _channels+1, 1
;project.c,111 :: 		}
L_program_mode45:
;project.c,112 :: 		if (portd.f3){
	BTFSS      PORTD+0, 3
	GOTO       L_program_mode51
;project.c,113 :: 		while (portd.f3) delay_ms(5);
L_program_mode52:
	BTFSS      PORTD+0, 3
	GOTO       L_program_mode53
	MOVLW      13
	MOVWF      R12+0
	MOVLW      251
	MOVWF      R13+0
L_program_mode54:
	DECFSZ     R13+0, 1
	GOTO       L_program_mode54
	DECFSZ     R12+0, 1
	GOTO       L_program_mode54
	NOP
	NOP
	GOTO       L_program_mode52
L_program_mode53:
;project.c,114 :: 		channels -= channels>0 ? 1 : 0;
	MOVF       _channels+1, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__program_mode83
	MOVF       _channels+0, 0
	SUBLW      0
L__program_mode83:
	BTFSC      STATUS+0, 0
	GOTO       L_program_mode55
	MOVLW      1
	MOVWF      ?FLOC___program_modeT58+0
	GOTO       L_program_mode56
L_program_mode55:
	CLRF       ?FLOC___program_modeT58+0
L_program_mode56:
	MOVF       ?FLOC___program_modeT58+0, 0
	SUBWF      _channels+0, 1
	MOVLW      0
	BTFSC      ?FLOC___program_modeT58+0, 7
	MOVLW      255
	BTFSS      STATUS+0, 0
	ADDLW      1
	SUBWF      _channels+1, 1
;project.c,115 :: 		}
L_program_mode51:
;project.c,116 :: 		show_led(channels);
	MOVF       _channels+0, 0
	MOVWF      FARG_show_led_value+0
	MOVF       _channels+1, 0
	MOVWF      FARG_show_led_value+1
	CALL       _show_led+0
;project.c,117 :: 		}
	GOTO       L_program_mode39
L_program_mode40:
;project.c,118 :: 		write_rom();
	CALL       _write_rom+0
;project.c,119 :: 		}
L_end_program_mode:
	RETURN
; end of _program_mode

_run_mode:

;project.c,121 :: 		void run_mode(){
;project.c,122 :: 		unsigned int i = 0;
	CLRF       run_mode_i_L0+0
	CLRF       run_mode_i_L0+1
	CLRF       run_mode_j_L0+0
	CLRF       run_mode_j_L0+1
;project.c,124 :: 		portc.f2=1;
	BSF        PORTC+0, 2
;project.c,126 :: 		while(1){
L_run_mode57:
;project.c,127 :: 		for(i = 0; i<channels; i++){
	CLRF       run_mode_i_L0+0
	CLRF       run_mode_i_L0+1
L_run_mode59:
	MOVF       _channels+1, 0
	SUBWF      run_mode_i_L0+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__run_mode85
	MOVF       _channels+0, 0
	SUBWF      run_mode_i_L0+0, 0
L__run_mode85:
	BTFSC      STATUS+0, 0
	GOTO       L_run_mode60
;project.c,128 :: 		portc.f2 = 1;
	BSF        PORTC+0, 2
;project.c,129 :: 		porta = i;
	MOVF       run_mode_i_L0+0, 0
	MOVWF      PORTA+0
;project.c,130 :: 		for(j = 0; j<on_time; j++){
	CLRF       run_mode_j_L0+0
	CLRF       run_mode_j_L0+1
L_run_mode62:
	MOVF       _on_time+1, 0
	SUBWF      run_mode_j_L0+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__run_mode86
	MOVF       _on_time+0, 0
	SUBWF      run_mode_j_L0+0, 0
L__run_mode86:
	BTFSC      STATUS+0, 0
	GOTO       L_run_mode63
;project.c,131 :: 		delay_ms(100);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      4
	MOVWF      R12+0
	MOVLW      186
	MOVWF      R13+0
L_run_mode65:
	DECFSZ     R13+0, 1
	GOTO       L_run_mode65
	DECFSZ     R12+0, 1
	GOTO       L_run_mode65
	DECFSZ     R11+0, 1
	GOTO       L_run_mode65
	NOP
;project.c,130 :: 		for(j = 0; j<on_time; j++){
	INCF       run_mode_j_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       run_mode_j_L0+1, 1
;project.c,132 :: 		}
	GOTO       L_run_mode62
L_run_mode63:
;project.c,133 :: 		portc.f2=0;
	BCF        PORTC+0, 2
;project.c,134 :: 		for(j = 0; j<off_time; j++){
	CLRF       run_mode_j_L0+0
	CLRF       run_mode_j_L0+1
L_run_mode66:
	MOVF       _off_time+1, 0
	SUBWF      run_mode_j_L0+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__run_mode87
	MOVF       _off_time+0, 0
	SUBWF      run_mode_j_L0+0, 0
L__run_mode87:
	BTFSC      STATUS+0, 0
	GOTO       L_run_mode67
;project.c,135 :: 		delay_ms(1000);
	MOVLW      11
	MOVWF      R11+0
	MOVLW      38
	MOVWF      R12+0
	MOVLW      93
	MOVWF      R13+0
L_run_mode69:
	DECFSZ     R13+0, 1
	GOTO       L_run_mode69
	DECFSZ     R12+0, 1
	GOTO       L_run_mode69
	DECFSZ     R11+0, 1
	GOTO       L_run_mode69
	NOP
	NOP
;project.c,134 :: 		for(j = 0; j<off_time; j++){
	INCF       run_mode_j_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       run_mode_j_L0+1, 1
;project.c,136 :: 		}
	GOTO       L_run_mode66
L_run_mode67:
;project.c,127 :: 		for(i = 0; i<channels; i++){
	INCF       run_mode_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       run_mode_i_L0+1, 1
;project.c,137 :: 		}
	GOTO       L_run_mode59
L_run_mode60:
;project.c,138 :: 		}
	GOTO       L_run_mode57
;project.c,139 :: 		}
L_end_run_mode:
	RETURN
; end of _run_mode

_main:

;project.c,141 :: 		void main(){
;project.c,142 :: 		init();
	CALL       _init+0
;project.c,143 :: 		get_mode();
	CALL       _get_mode+0
;project.c,144 :: 		read_rom();
	CALL       _read_rom+0
;project.c,145 :: 		if (mode){
	MOVF       _mode+0, 0
	IORWF      _mode+1, 0
	BTFSC      STATUS+0, 2
	GOTO       L_main70
;project.c,146 :: 		program_mode();
	CALL       _program_mode+0
;project.c,147 :: 		}
L_main70:
;project.c,148 :: 		run_mode();
	CALL       _run_mode+0
;project.c,149 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
