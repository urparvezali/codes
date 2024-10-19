
_init:

;project.c,3 :: 		void init(){
;project.c,4 :: 		trisb = trisc = 0x00;
	CLRF       TRISC+0
	MOVF       TRISC+0, 0
	MOVWF      TRISB+0
;project.c,5 :: 		trisd = 0b11110000;
	MOVLW      240
	MOVWF      TRISD+0
;project.c,6 :: 		trisa = 0b000000;
	CLRF       TRISA+0
;project.c,7 :: 		trise = 0b000;
	CLRF       TRISE+0
;project.c,9 :: 		portb = portc = portd = 0x00;
	CLRF       PORTD+0
	MOVF       PORTD+0, 0
	MOVWF      PORTC+0
	MOVF       PORTC+0, 0
	MOVWF      PORTB+0
;project.c,10 :: 		porta = 0b000000;
	CLRF       PORTA+0
;project.c,11 :: 		porte = 0b000;
	CLRF       PORTE+0
;project.c,12 :: 		}
L_end_init:
	RETURN
; end of _init

_read_int:

;project.c,22 :: 		unsigned int read_int(unsigned int add){
;project.c,23 :: 		return EEPROM_Read(add) | (EEPROM_Read(add+1) << 8);
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
;project.c,24 :: 		}
L_end_read_int:
	RETURN
; end of _read_int

_write_int:

;project.c,25 :: 		void write_int(unsigned int add, unsigned int val){
;project.c,26 :: 		EEPROM_Write(add, (val & 0xff));
	MOVF       FARG_write_int_add+0, 0
	MOVWF      FARG_EEPROM_Write_Address+0
	MOVLW      255
	ANDWF      FARG_write_int_val+0, 0
	MOVWF      FARG_EEPROM_Write_data_+0
	CALL       _EEPROM_Write+0
;project.c,27 :: 		EEPROM_Write(add+1, ((val >> 8) & 0xff));
	INCF       FARG_write_int_add+0, 0
	MOVWF      FARG_EEPROM_Write_Address+0
	MOVF       FARG_write_int_val+1, 0
	MOVWF      R0+0
	CLRF       R0+1
	MOVLW      255
	ANDWF      R0+0, 0
	MOVWF      FARG_EEPROM_Write_data_+0
	CALL       _EEPROM_Write+0
;project.c,28 :: 		}
L_end_write_int:
	RETURN
; end of _write_int

_get_mode:

;project.c,30 :: 		void get_mode(){
;project.c,31 :: 		if (portd.f4){
	BTFSS      PORTD+0, 4
	GOTO       L_get_mode0
;project.c,32 :: 		mode = 1;
	MOVLW      1
	MOVWF      _mode+0
	MOVLW      0
	MOVWF      _mode+1
;project.c,33 :: 		} else{
	GOTO       L_get_mode1
L_get_mode0:
;project.c,34 :: 		mode = 0;
	CLRF       _mode+0
	CLRF       _mode+1
;project.c,35 :: 		}
L_get_mode1:
;project.c,36 :: 		}
L_end_get_mode:
	RETURN
; end of _get_mode

_read_rom:

;project.c,37 :: 		void read_rom(){
;project.c,38 :: 		on_time = read_int(0x00);
	CLRF       FARG_read_int_add+0
	CLRF       FARG_read_int_add+1
	CALL       _read_int+0
	MOVF       R0+0, 0
	MOVWF      _on_time+0
	MOVF       R0+1, 0
	MOVWF      _on_time+1
;project.c,39 :: 		off_time = read_int(0x02);
	MOVLW      2
	MOVWF      FARG_read_int_add+0
	MOVLW      0
	MOVWF      FARG_read_int_add+1
	CALL       _read_int+0
	MOVF       R0+0, 0
	MOVWF      _off_time+0
	MOVF       R0+1, 0
	MOVWF      _off_time+1
;project.c,40 :: 		channels = read_int(0x04);
	MOVLW      4
	MOVWF      FARG_read_int_add+0
	MOVLW      0
	MOVWF      FARG_read_int_add+1
	CALL       _read_int+0
	MOVF       R0+0, 0
	MOVWF      _channels+0
	MOVF       R0+1, 0
	MOVWF      _channels+1
;project.c,41 :: 		}
L_end_read_rom:
	RETURN
; end of _read_rom

_write_rom:

;project.c,42 :: 		void write_rom(){
;project.c,43 :: 		write_int(0x00, on_time);
	CLRF       FARG_write_int_add+0
	CLRF       FARG_write_int_add+1
	MOVF       _on_time+0, 0
	MOVWF      FARG_write_int_val+0
	MOVF       _on_time+1, 0
	MOVWF      FARG_write_int_val+1
	CALL       _write_int+0
;project.c,44 :: 		write_int(0x02, off_time);
	MOVLW      2
	MOVWF      FARG_write_int_add+0
	MOVLW      0
	MOVWF      FARG_write_int_add+1
	MOVF       _off_time+0, 0
	MOVWF      FARG_write_int_val+0
	MOVF       _off_time+1, 0
	MOVWF      FARG_write_int_val+1
	CALL       _write_int+0
;project.c,45 :: 		write_int(0x04, channels);
	MOVLW      4
	MOVWF      FARG_write_int_add+0
	MOVLW      0
	MOVWF      FARG_write_int_add+1
	MOVF       _channels+0, 0
	MOVWF      FARG_write_int_val+0
	MOVF       _channels+1, 0
	MOVWF      FARG_write_int_val+1
	CALL       _write_int+0
;project.c,46 :: 		}
L_end_write_rom:
	RETURN
; end of _write_rom

_led0:

;project.c,47 :: 		void led0(unsigned int value){
;project.c,48 :: 		digit1 = value%10;
	MOVLW      10
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVF       FARG_led0_value+0, 0
	MOVWF      R0+0
	MOVF       FARG_led0_value+1, 0
	MOVWF      R0+1
	CALL       _Div_16X16_U+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R8+1, 0
	MOVWF      R0+1
	MOVF       R0+0, 0
	MOVWF      _digit1+0
	MOVF       R0+1, 0
	MOVWF      _digit1+1
;project.c,49 :: 		digit0 = value/10;
	MOVLW      10
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVF       FARG_led0_value+0, 0
	MOVWF      R0+0
	MOVF       FARG_led0_value+1, 0
	MOVWF      R0+1
	CALL       _Div_16X16_U+0
	MOVF       R0+0, 0
	MOVWF      _digit0+0
	MOVF       R0+1, 0
	MOVWF      _digit0+1
;project.c,51 :: 		porta.f1 = 1;
	BSF        PORTA+0, 1
;project.c,52 :: 		portb = arr[digit0];
	MOVF       R0+0, 0
	MOVWF      R2+0
	RLF        R2+0, 1
	BCF        R2+0, 0
	MOVF       R2+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;project.c,53 :: 		porta.f0 = 0;
	BCF        PORTA+0, 0
;project.c,55 :: 		delay_ms(5);
	MOVLW      13
	MOVWF      R12+0
	MOVLW      251
	MOVWF      R13+0
L_led02:
	DECFSZ     R13+0, 1
	GOTO       L_led02
	DECFSZ     R12+0, 1
	GOTO       L_led02
	NOP
	NOP
;project.c,57 :: 		porta.f0 = 1;
	BSF        PORTA+0, 0
;project.c,58 :: 		portb = arr[digit1];
	MOVF       _digit1+0, 0
	MOVWF      R0+0
	RLF        R0+0, 1
	BCF        R0+0, 0
	MOVF       R0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTB+0
;project.c,59 :: 		porta.f1 = 0;
	BCF        PORTA+0, 1
;project.c,61 :: 		delay_ms(5);
	MOVLW      13
	MOVWF      R12+0
	MOVLW      251
	MOVWF      R13+0
L_led03:
	DECFSZ     R13+0, 1
	GOTO       L_led03
	DECFSZ     R12+0, 1
	GOTO       L_led03
	NOP
	NOP
;project.c,62 :: 		}
L_end_led0:
	RETURN
; end of _led0

_led1:

;project.c,63 :: 		void led1(unsigned int value){
;project.c,64 :: 		digit1 = value%10;
	MOVLW      10
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVF       FARG_led1_value+0, 0
	MOVWF      R0+0
	MOVF       FARG_led1_value+1, 0
	MOVWF      R0+1
	CALL       _Div_16X16_U+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R8+1, 0
	MOVWF      R0+1
	MOVF       R0+0, 0
	MOVWF      _digit1+0
	MOVF       R0+1, 0
	MOVWF      _digit1+1
;project.c,65 :: 		digit0 = value/10;
	MOVLW      10
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVF       FARG_led1_value+0, 0
	MOVWF      R0+0
	MOVF       FARG_led1_value+1, 0
	MOVWF      R0+1
	CALL       _Div_16X16_U+0
	MOVF       R0+0, 0
	MOVWF      _digit0+0
	MOVF       R0+1, 0
	MOVWF      _digit0+1
;project.c,67 :: 		porta.f3 = 1;
	BSF        PORTA+0, 3
;project.c,68 :: 		portc = arr[digit0];
	MOVF       R0+0, 0
	MOVWF      R2+0
	RLF        R2+0, 1
	BCF        R2+0, 0
	MOVF       R2+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTC+0
;project.c,69 :: 		porta.f2 = 0;
	BCF        PORTA+0, 2
;project.c,71 :: 		delay_ms(5);
	MOVLW      13
	MOVWF      R12+0
	MOVLW      251
	MOVWF      R13+0
L_led14:
	DECFSZ     R13+0, 1
	GOTO       L_led14
	DECFSZ     R12+0, 1
	GOTO       L_led14
	NOP
	NOP
;project.c,73 :: 		porta.f2 = 1;
	BSF        PORTA+0, 2
;project.c,74 :: 		portc = arr[digit1];
	MOVF       _digit1+0, 0
	MOVWF      R0+0
	RLF        R0+0, 1
	BCF        R0+0, 0
	MOVF       R0+0, 0
	ADDLW      _arr+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      PORTC+0
;project.c,75 :: 		porta.f3 = 0;
	BCF        PORTA+0, 3
;project.c,77 :: 		delay_ms(5);
	MOVLW      13
	MOVWF      R12+0
	MOVLW      251
	MOVWF      R13+0
L_led15:
	DECFSZ     R13+0, 1
	GOTO       L_led15
	DECFSZ     R12+0, 1
	GOTO       L_led15
	NOP
	NOP
;project.c,78 :: 		}
L_end_led1:
	RETURN
; end of _led1

_program_mode:

;project.c,80 :: 		void program_mode(){
;project.c,81 :: 		unsigned int counter = 0;
	CLRF       program_mode_counter_L0+0
	CLRF       program_mode_counter_L0+1
;project.c,82 :: 		on_time = 0;
	CLRF       _on_time+0
	CLRF       _on_time+1
;project.c,83 :: 		off_time = 0;
	CLRF       _off_time+0
	CLRF       _off_time+1
;project.c,84 :: 		channels = 0;
	CLRF       _channels+0
	CLRF       _channels+1
;project.c,86 :: 		porte = 0b001;
	MOVLW      1
	MOVWF      PORTE+0
;project.c,88 :: 		while (1){
L_program_mode6:
;project.c,90 :: 		if (portd.f5){
	BTFSS      PORTD+0, 5
	GOTO       L_program_mode8
;project.c,91 :: 		while (portd.f5){
L_program_mode9:
	BTFSS      PORTD+0, 5
	GOTO       L_program_mode10
;project.c,92 :: 		counter += 1;
	INCF       program_mode_counter_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       program_mode_counter_L0+1, 1
;project.c,93 :: 		delay_ms(5);
	MOVLW      13
	MOVWF      R12+0
	MOVLW      251
	MOVWF      R13+0
L_program_mode11:
	DECFSZ     R13+0, 1
	GOTO       L_program_mode11
	DECFSZ     R12+0, 1
	GOTO       L_program_mode11
	NOP
	NOP
;project.c,94 :: 		};
	GOTO       L_program_mode9
L_program_mode10:
;project.c,95 :: 		if (counter>=200){
	MOVLW      0
	SUBWF      program_mode_counter_L0+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__program_mode90
	MOVLW      200
	SUBWF      program_mode_counter_L0+0, 0
L__program_mode90:
	BTFSS      STATUS+0, 0
	GOTO       L_program_mode12
;project.c,96 :: 		break;
	GOTO       L_program_mode7
;project.c,97 :: 		}
L_program_mode12:
;project.c,99 :: 		}
L_program_mode8:
;project.c,100 :: 		if (portd.f6){
	BTFSS      PORTD+0, 6
	GOTO       L_program_mode13
;project.c,101 :: 		while (portd.f6) delay_ms(5);
L_program_mode14:
	BTFSS      PORTD+0, 6
	GOTO       L_program_mode15
	MOVLW      13
	MOVWF      R12+0
	MOVLW      251
	MOVWF      R13+0
L_program_mode16:
	DECFSZ     R13+0, 1
	GOTO       L_program_mode16
	DECFSZ     R12+0, 1
	GOTO       L_program_mode16
	NOP
	NOP
	GOTO       L_program_mode14
L_program_mode15:
;project.c,102 :: 		on_time += on_time<99 ? 1 : 0;
	MOVLW      0
	SUBWF      _on_time+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__program_mode91
	MOVLW      99
	SUBWF      _on_time+0, 0
L__program_mode91:
	BTFSC      STATUS+0, 0
	GOTO       L_program_mode17
	MOVLW      1
	MOVWF      ?FLOC___program_modeT51+0
	GOTO       L_program_mode18
L_program_mode17:
	CLRF       ?FLOC___program_modeT51+0
L_program_mode18:
	MOVF       ?FLOC___program_modeT51+0, 0
	ADDWF      _on_time+0, 1
	BTFSC      STATUS+0, 0
	INCF       _on_time+1, 1
	MOVLW      0
	BTFSC      ?FLOC___program_modeT51+0, 7
	MOVLW      255
	ADDWF      _on_time+1, 1
;project.c,103 :: 		}
L_program_mode13:
;project.c,104 :: 		if (portd.f7){
	BTFSS      PORTD+0, 7
	GOTO       L_program_mode19
;project.c,105 :: 		while (portd.f7) delay_ms(5);
L_program_mode20:
	BTFSS      PORTD+0, 7
	GOTO       L_program_mode21
	MOVLW      13
	MOVWF      R12+0
	MOVLW      251
	MOVWF      R13+0
L_program_mode22:
	DECFSZ     R13+0, 1
	GOTO       L_program_mode22
	DECFSZ     R12+0, 1
	GOTO       L_program_mode22
	NOP
	NOP
	GOTO       L_program_mode20
L_program_mode21:
;project.c,106 :: 		on_time -= on_time>0 ? 1 : 0;
	MOVF       _on_time+1, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__program_mode92
	MOVF       _on_time+0, 0
	SUBLW      0
L__program_mode92:
	BTFSC      STATUS+0, 0
	GOTO       L_program_mode23
	MOVLW      1
	MOVWF      ?FLOC___program_modeT56+0
	GOTO       L_program_mode24
L_program_mode23:
	CLRF       ?FLOC___program_modeT56+0
L_program_mode24:
	MOVF       ?FLOC___program_modeT56+0, 0
	SUBWF      _on_time+0, 1
	MOVLW      0
	BTFSC      ?FLOC___program_modeT56+0, 7
	MOVLW      255
	BTFSS      STATUS+0, 0
	ADDLW      1
	SUBWF      _on_time+1, 1
;project.c,107 :: 		}
L_program_mode19:
;project.c,108 :: 		led0(on_time);
	MOVF       _on_time+0, 0
	MOVWF      FARG_led0_value+0
	MOVF       _on_time+1, 0
	MOVWF      FARG_led0_value+1
	CALL       _led0+0
;project.c,109 :: 		led1(channels);
	MOVF       _channels+0, 0
	MOVWF      FARG_led1_value+0
	MOVF       _channels+1, 0
	MOVWF      FARG_led1_value+1
	CALL       _led1+0
;project.c,110 :: 		}
	GOTO       L_program_mode6
L_program_mode7:
;project.c,112 :: 		counter = 0;
	CLRF       program_mode_counter_L0+0
	CLRF       program_mode_counter_L0+1
;project.c,113 :: 		porte = 0b010;
	MOVLW      2
	MOVWF      PORTE+0
;project.c,114 :: 		while (1){
L_program_mode25:
;project.c,116 :: 		if (portd.f5){
	BTFSS      PORTD+0, 5
	GOTO       L_program_mode27
;project.c,117 :: 		while (portd.f5){
L_program_mode28:
	BTFSS      PORTD+0, 5
	GOTO       L_program_mode29
;project.c,118 :: 		counter += 1;
	INCF       program_mode_counter_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       program_mode_counter_L0+1, 1
;project.c,119 :: 		delay_ms(5);
	MOVLW      13
	MOVWF      R12+0
	MOVLW      251
	MOVWF      R13+0
L_program_mode30:
	DECFSZ     R13+0, 1
	GOTO       L_program_mode30
	DECFSZ     R12+0, 1
	GOTO       L_program_mode30
	NOP
	NOP
;project.c,120 :: 		};
	GOTO       L_program_mode28
L_program_mode29:
;project.c,121 :: 		if (counter>=200){
	MOVLW      0
	SUBWF      program_mode_counter_L0+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__program_mode93
	MOVLW      200
	SUBWF      program_mode_counter_L0+0, 0
L__program_mode93:
	BTFSS      STATUS+0, 0
	GOTO       L_program_mode31
;project.c,122 :: 		break;
	GOTO       L_program_mode26
;project.c,123 :: 		}
L_program_mode31:
;project.c,124 :: 		}
L_program_mode27:
;project.c,125 :: 		if (portd.f6){
	BTFSS      PORTD+0, 6
	GOTO       L_program_mode32
;project.c,126 :: 		while (portd.f6) delay_ms(5);
L_program_mode33:
	BTFSS      PORTD+0, 6
	GOTO       L_program_mode34
	MOVLW      13
	MOVWF      R12+0
	MOVLW      251
	MOVWF      R13+0
L_program_mode35:
	DECFSZ     R13+0, 1
	GOTO       L_program_mode35
	DECFSZ     R12+0, 1
	GOTO       L_program_mode35
	NOP
	NOP
	GOTO       L_program_mode33
L_program_mode34:
;project.c,127 :: 		off_time += 1;
	INCF       _off_time+0, 1
	BTFSC      STATUS+0, 2
	INCF       _off_time+1, 1
;project.c,128 :: 		}
L_program_mode32:
;project.c,129 :: 		if (portd.f7){
	BTFSS      PORTD+0, 7
	GOTO       L_program_mode36
;project.c,130 :: 		while (portd.f7) delay_ms(5);
L_program_mode37:
	BTFSS      PORTD+0, 7
	GOTO       L_program_mode38
	MOVLW      13
	MOVWF      R12+0
	MOVLW      251
	MOVWF      R13+0
L_program_mode39:
	DECFSZ     R13+0, 1
	GOTO       L_program_mode39
	DECFSZ     R12+0, 1
	GOTO       L_program_mode39
	NOP
	NOP
	GOTO       L_program_mode37
L_program_mode38:
;project.c,131 :: 		off_time -= off_time>0 ? 1 : 0;
	MOVF       _off_time+1, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__program_mode94
	MOVF       _off_time+0, 0
	SUBLW      0
L__program_mode94:
	BTFSC      STATUS+0, 0
	GOTO       L_program_mode40
	MOVLW      1
	MOVWF      ?FLOC___program_modeT68+0
	GOTO       L_program_mode41
L_program_mode40:
	CLRF       ?FLOC___program_modeT68+0
L_program_mode41:
	MOVF       ?FLOC___program_modeT68+0, 0
	SUBWF      _off_time+0, 1
	MOVLW      0
	BTFSC      ?FLOC___program_modeT68+0, 7
	MOVLW      255
	BTFSS      STATUS+0, 0
	ADDLW      1
	SUBWF      _off_time+1, 1
;project.c,132 :: 		}
L_program_mode36:
;project.c,133 :: 		led0(off_time);
	MOVF       _off_time+0, 0
	MOVWF      FARG_led0_value+0
	MOVF       _off_time+1, 0
	MOVWF      FARG_led0_value+1
	CALL       _led0+0
;project.c,134 :: 		led1(channels);
	MOVF       _channels+0, 0
	MOVWF      FARG_led1_value+0
	MOVF       _channels+1, 0
	MOVWF      FARG_led1_value+1
	CALL       _led1+0
;project.c,135 :: 		}
	GOTO       L_program_mode25
L_program_mode26:
;project.c,137 :: 		counter = 0;
	CLRF       program_mode_counter_L0+0
	CLRF       program_mode_counter_L0+1
;project.c,138 :: 		porte = 0b100;
	MOVLW      4
	MOVWF      PORTE+0
;project.c,139 :: 		while (1){
L_program_mode42:
;project.c,141 :: 		if (portd.f5){
	BTFSS      PORTD+0, 5
	GOTO       L_program_mode44
;project.c,142 :: 		while (portd.f5){
L_program_mode45:
	BTFSS      PORTD+0, 5
	GOTO       L_program_mode46
;project.c,143 :: 		counter += 1;
	INCF       program_mode_counter_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       program_mode_counter_L0+1, 1
;project.c,144 :: 		delay_ms(5);
	MOVLW      13
	MOVWF      R12+0
	MOVLW      251
	MOVWF      R13+0
L_program_mode47:
	DECFSZ     R13+0, 1
	GOTO       L_program_mode47
	DECFSZ     R12+0, 1
	GOTO       L_program_mode47
	NOP
	NOP
;project.c,145 :: 		};
	GOTO       L_program_mode45
L_program_mode46:
;project.c,146 :: 		if (counter>=200){
	MOVLW      0
	SUBWF      program_mode_counter_L0+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__program_mode95
	MOVLW      200
	SUBWF      program_mode_counter_L0+0, 0
L__program_mode95:
	BTFSS      STATUS+0, 0
	GOTO       L_program_mode48
;project.c,147 :: 		break;
	GOTO       L_program_mode43
;project.c,148 :: 		}
L_program_mode48:
;project.c,149 :: 		}
L_program_mode44:
;project.c,150 :: 		if (portd.f6){
	BTFSS      PORTD+0, 6
	GOTO       L_program_mode49
;project.c,151 :: 		while (portd.f6) delay_ms(5);
L_program_mode50:
	BTFSS      PORTD+0, 6
	GOTO       L_program_mode51
	MOVLW      13
	MOVWF      R12+0
	MOVLW      251
	MOVWF      R13+0
L_program_mode52:
	DECFSZ     R13+0, 1
	GOTO       L_program_mode52
	DECFSZ     R12+0, 1
	GOTO       L_program_mode52
	NOP
	NOP
	GOTO       L_program_mode50
L_program_mode51:
;project.c,152 :: 		channels += channels<16 ? 1 : 0;
	MOVLW      0
	SUBWF      _channels+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__program_mode96
	MOVLW      16
	SUBWF      _channels+0, 0
L__program_mode96:
	BTFSC      STATUS+0, 0
	GOTO       L_program_mode53
	MOVLW      1
	MOVWF      ?FLOC___program_modeT77+0
	GOTO       L_program_mode54
L_program_mode53:
	CLRF       ?FLOC___program_modeT77+0
L_program_mode54:
	MOVF       ?FLOC___program_modeT77+0, 0
	ADDWF      _channels+0, 1
	BTFSC      STATUS+0, 0
	INCF       _channels+1, 1
	MOVLW      0
	BTFSC      ?FLOC___program_modeT77+0, 7
	MOVLW      255
	ADDWF      _channels+1, 1
;project.c,153 :: 		}
L_program_mode49:
;project.c,154 :: 		if (portd.f7){
	BTFSS      PORTD+0, 7
	GOTO       L_program_mode55
;project.c,155 :: 		while (portd.f7) delay_ms(5);
L_program_mode56:
	BTFSS      PORTD+0, 7
	GOTO       L_program_mode57
	MOVLW      13
	MOVWF      R12+0
	MOVLW      251
	MOVWF      R13+0
L_program_mode58:
	DECFSZ     R13+0, 1
	GOTO       L_program_mode58
	DECFSZ     R12+0, 1
	GOTO       L_program_mode58
	NOP
	NOP
	GOTO       L_program_mode56
L_program_mode57:
;project.c,156 :: 		channels -= channels>0 ? 1 : 0;
	MOVF       _channels+1, 0
	SUBLW      0
	BTFSS      STATUS+0, 2
	GOTO       L__program_mode97
	MOVF       _channels+0, 0
	SUBLW      0
L__program_mode97:
	BTFSC      STATUS+0, 0
	GOTO       L_program_mode59
	MOVLW      1
	MOVWF      ?FLOC___program_modeT82+0
	GOTO       L_program_mode60
L_program_mode59:
	CLRF       ?FLOC___program_modeT82+0
L_program_mode60:
	MOVF       ?FLOC___program_modeT82+0, 0
	SUBWF      _channels+0, 1
	MOVLW      0
	BTFSC      ?FLOC___program_modeT82+0, 7
	MOVLW      255
	BTFSS      STATUS+0, 0
	ADDLW      1
	SUBWF      _channels+1, 1
;project.c,157 :: 		}
L_program_mode55:
;project.c,158 :: 		led0(0);
	CLRF       FARG_led0_value+0
	CLRF       FARG_led0_value+1
	CALL       _led0+0
;project.c,159 :: 		led1(channels);
	MOVF       _channels+0, 0
	MOVWF      FARG_led1_value+0
	MOVF       _channels+1, 0
	MOVWF      FARG_led1_value+1
	CALL       _led1+0
;project.c,160 :: 		}
	GOTO       L_program_mode42
L_program_mode43:
;project.c,161 :: 		write_rom();
	CALL       _write_rom+0
;project.c,162 :: 		porte = 0b111;
	MOVLW      7
	MOVWF      PORTE+0
;project.c,163 :: 		}
L_end_program_mode:
	RETURN
; end of _program_mode

_run_mode:

;project.c,165 :: 		void run_mode(){
;project.c,166 :: 		unsigned int i = 0;
	CLRF       run_mode_i_L0+0
	CLRF       run_mode_i_L0+1
	CLRF       run_mode_j_L0+0
	CLRF       run_mode_j_L0+1
	CLRF       run_mode_k_L0+0
	CLRF       run_mode_k_L0+1
;project.c,169 :: 		portc.f2 = 1;
	BSF        PORTC+0, 2
;project.c,171 :: 		while (1){
L_run_mode61:
;project.c,172 :: 		for (i = 0; i<channels; i++){
	CLRF       run_mode_i_L0+0
	CLRF       run_mode_i_L0+1
L_run_mode63:
	MOVF       _channels+1, 0
	SUBWF      run_mode_i_L0+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__run_mode99
	MOVF       _channels+0, 0
	SUBWF      run_mode_i_L0+0, 0
L__run_mode99:
	BTFSC      STATUS+0, 0
	GOTO       L_run_mode64
;project.c,173 :: 		porta.f4 = 1;
	BSF        PORTA+0, 4
;project.c,174 :: 		portd = i;
	MOVF       run_mode_i_L0+0, 0
	MOVWF      PORTD+0
;project.c,176 :: 		for (j = 0; j<on_time; j++){
	CLRF       run_mode_j_L0+0
	CLRF       run_mode_j_L0+1
L_run_mode66:
	MOVF       _on_time+1, 0
	SUBWF      run_mode_j_L0+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__run_mode100
	MOVF       _on_time+0, 0
	SUBWF      run_mode_j_L0+0, 0
L__run_mode100:
	BTFSC      STATUS+0, 0
	GOTO       L_run_mode67
;project.c,177 :: 		for (k = 0; k < 5; k++){
	CLRF       run_mode_k_L0+0
	CLRF       run_mode_k_L0+1
L_run_mode69:
	MOVLW      0
	SUBWF      run_mode_k_L0+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__run_mode101
	MOVLW      5
	SUBWF      run_mode_k_L0+0, 0
L__run_mode101:
	BTFSC      STATUS+0, 0
	GOTO       L_run_mode70
;project.c,178 :: 		led0(0);
	CLRF       FARG_led0_value+0
	CLRF       FARG_led0_value+1
	CALL       _led0+0
;project.c,179 :: 		led1(i+1);
	MOVF       run_mode_i_L0+0, 0
	ADDLW      1
	MOVWF      FARG_led1_value+0
	MOVLW      0
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      run_mode_i_L0+1, 0
	MOVWF      FARG_led1_value+1
	CALL       _led1+0
;project.c,177 :: 		for (k = 0; k < 5; k++){
	INCF       run_mode_k_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       run_mode_k_L0+1, 1
;project.c,180 :: 		}
	GOTO       L_run_mode69
L_run_mode70:
;project.c,176 :: 		for (j = 0; j<on_time; j++){
	INCF       run_mode_j_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       run_mode_j_L0+1, 1
;project.c,181 :: 		}
	GOTO       L_run_mode66
L_run_mode67:
;project.c,182 :: 		portc.f2 = 0;
	BCF        PORTC+0, 2
;project.c,183 :: 		for (j = 0; j<off_time; j++){
	CLRF       run_mode_j_L0+0
	CLRF       run_mode_j_L0+1
L_run_mode72:
	MOVF       _off_time+1, 0
	SUBWF      run_mode_j_L0+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__run_mode102
	MOVF       _off_time+0, 0
	SUBWF      run_mode_j_L0+0, 0
L__run_mode102:
	BTFSC      STATUS+0, 0
	GOTO       L_run_mode73
;project.c,184 :: 		for (k = 0; k < 50; k++){
	CLRF       run_mode_k_L0+0
	CLRF       run_mode_k_L0+1
L_run_mode75:
	MOVLW      0
	SUBWF      run_mode_k_L0+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__run_mode103
	MOVLW      50
	SUBWF      run_mode_k_L0+0, 0
L__run_mode103:
	BTFSC      STATUS+0, 0
	GOTO       L_run_mode76
;project.c,185 :: 		led0(off_time-j);
	MOVF       run_mode_j_L0+0, 0
	SUBWF      _off_time+0, 0
	MOVWF      FARG_led0_value+0
	MOVF       run_mode_j_L0+1, 0
	BTFSS      STATUS+0, 0
	ADDLW      1
	SUBWF      _off_time+1, 0
	MOVWF      FARG_led0_value+1
	CALL       _led0+0
;project.c,186 :: 		if (i+1==channels) led1(1);
	MOVF       run_mode_i_L0+0, 0
	ADDLW      1
	MOVWF      R1+0
	MOVLW      0
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDWF      run_mode_i_L0+1, 0
	MOVWF      R1+1
	MOVF       R1+1, 0
	XORWF      _channels+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__run_mode104
	MOVF       _channels+0, 0
	XORWF      R1+0, 0
L__run_mode104:
	BTFSS      STATUS+0, 2
	GOTO       L_run_mode78
	MOVLW      1
	MOVWF      FARG_led1_value+0
	MOVLW      0
	MOVWF      FARG_led1_value+1
	CALL       _led1+0
	GOTO       L_run_mode79
L_run_mode78:
;project.c,187 :: 		else led1(i+2);
	MOVLW      2
	ADDWF      run_mode_i_L0+0, 0
	MOVWF      FARG_led1_value+0
	MOVF       run_mode_i_L0+1, 0
	BTFSC      STATUS+0, 0
	ADDLW      1
	MOVWF      FARG_led1_value+1
	CALL       _led1+0
L_run_mode79:
;project.c,184 :: 		for (k = 0; k < 50; k++){
	INCF       run_mode_k_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       run_mode_k_L0+1, 1
;project.c,188 :: 		}
	GOTO       L_run_mode75
L_run_mode76:
;project.c,183 :: 		for (j = 0; j<off_time; j++){
	INCF       run_mode_j_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       run_mode_j_L0+1, 1
;project.c,189 :: 		}
	GOTO       L_run_mode72
L_run_mode73:
;project.c,172 :: 		for (i = 0; i<channels; i++){
	INCF       run_mode_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       run_mode_i_L0+1, 1
;project.c,190 :: 		}
	GOTO       L_run_mode63
L_run_mode64:
;project.c,191 :: 		}
	GOTO       L_run_mode61
;project.c,192 :: 		}
L_end_run_mode:
	RETURN
; end of _run_mode

_main:

;project.c,194 :: 		void main(){
;project.c,195 :: 		init();
	CALL       _init+0
;project.c,196 :: 		get_mode();
	CALL       _get_mode+0
;project.c,197 :: 		read_rom();
	CALL       _read_rom+0
;project.c,198 :: 		if (mode){
	MOVF       _mode+0, 0
	IORWF      _mode+1, 0
	BTFSC      STATUS+0, 2
	GOTO       L_main80
;project.c,199 :: 		program_mode();
	CALL       _program_mode+0
;project.c,200 :: 		}
L_main80:
;project.c,201 :: 		run_mode();
	CALL       _run_mode+0
;project.c,202 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
