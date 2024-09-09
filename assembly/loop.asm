section .data
	list db 1,2,3,4,5

section .text
global _start

_start:
	mov eax, 0
	mov ecx, 0
looping:
	add ecx, [list + eax]
	add eax, 1
	cmp eax, 5
	je end
	jmp looping
end:
	mov eax, 1
	mov ebx, 1
	int 80h
	