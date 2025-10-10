SECTION .data
message:        db      "Hello world!", 0x0A

SECTION .text
global  _start

_start:
    ; Print "Hello world!".
    mov     eax, 1
    mov     edi, 1
    mov     esi, message
    mov     edx, 13
    syscall

    ; Exit the program
    mov     eax, 60
    mov     edi, 0
    syscall