section .data
	num DB 1
	num2 DB 2

section .text
global _start

_start:
	mov ebx,[num]
	mov ecx,[num2]
	mov eax,1
	int 80h