extern printf
section .data
    msg db "Hello, Holberton", 0
    fmt db "%s", 10, 0

section .text
    global main
main:
    push rbp
    mov rdi, fmt
    mov rsi, msg
    xor eax, eax ; clear the return value register
    call printf
    pop rbp
    xor eax, eax ; clear the return value register again
    ret