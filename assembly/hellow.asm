section .data
    hello db 'Hello, World!',0x0A  ; Define the string with a newline at the end
    hello_len equ $ - hello         ; Calculate the length of the string

	new_data dd 24234

section .text
    global _start                    ; Required for the linker

_start:
    ; Write "Hello, World!" to stdout
    mov eax, 4                       ; System call number for sys_write (4)
    mov ebx, 1                       ; File descriptor 1 is stdout
    mov ecx, hello                   ; Pointer to the string
    mov edx, hello_len               ; Length of the string
    int 0x80                         ; Call the kernel

	mov ecx, new_data
	mov edx, 3
	int 0x80

    ; Exit the program
    mov eax, 1                       ; System call number for sys_exit (1)
    xor ebx, ebx                     ; Exit code 0
    int 0x80                         ; Call the kernel
