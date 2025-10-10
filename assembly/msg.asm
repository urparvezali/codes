section .data
    msg db '0', 10

section .text
    global _start

_start:
	mov eax, 0
	push eax
myloop:
    mov eax, 4        ; sys_write syscall number
    mov ebx, 1        ; file descriptor 1 (stdout)
    mov ecx, msg      ; address of the message
    mov edx, 2       ; length of the message (including the newline)
    int 0x80          ; call the kernel

	pop eax
	inc eax
	push eax

	mov ecx, eax
	add ecx, '0'
	mov [msg], cl
	
	cmp eax, 10
	jl myloop

end:
    mov eax, 1        ; sys_exit syscall number
    xor ebx, ebx      ; exit code 0
    int 0x80          ; call the kernel
