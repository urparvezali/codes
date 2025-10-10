section .data
    msg db '0', 10

section .text
    global _start

_start:
	mov eax, 0
	push eax
myloop:
    mov eax, 4
    mov ebx, 1
    mov ecx, msg 
    mov edx, 2
    int 0x80

	pop eax
	inc eax
	push eax

	mov ecx, eax
	add ecx, '0'
	mov [msg], cl
	
	cmp eax, 10
	jl myloop

end:
    mov eax, 1
    xor ebx, ebx
    int 0x80
