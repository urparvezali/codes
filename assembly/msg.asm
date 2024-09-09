section .data
    msg db '1', 0xA   ; Define the message (ASCII for '1' and newline)

section .text
    global _start     ; Required for the entry point

_start:
    ; Write '1' to stdout
    mov eax, 4        ; sys_write syscall number
    mov ebx, 1        ; file descriptor 1 (stdout)
    mov ecx, msg      ; address of the message
    mov edx, 2        ; length of the message (including the newline)
    int 0x80          ; call the kernel

    ; Exit the program
    mov eax, 1        ; sys_exit syscall number
    xor ebx, ebx      ; exit code 0
    int 0x80          ; call the kernel
