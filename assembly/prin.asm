extern exit
extern printf

section .data
	msg dd "Hellow World!",0
	msg2 dd "This is second btw",0
	fmt db "Output is here: %s \n %s",0

section .text
global main

main:
	push msg2
	push msg
	push fmt
	call printf
	push 1
	call exit

	

