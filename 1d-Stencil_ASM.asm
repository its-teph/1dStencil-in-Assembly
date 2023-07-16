; Name: Stephanie Joy R. Susada
; Section: S11
section .text
    global asm_stencil_function

asm_stencil_function:
    push rbp
    mov rbp, rsp

    mov rdi, rcx        ; X array pointer
    mov rsi, rdx        ; Y array pointer
    mov edx, r8d        ; n

    xor rax, rax       

    mov ecx, 3         

loop_start:
    mov rax, qword [rdi+rcx*8-24]      ; X[i-3]
    add rax, qword [rdi+rcx*8-16]      ; X[i-2]
    add rax, qword [rdi+rcx*8-8]       ; X[i-1]
    add rax, qword [rdi+rcx*8]         ; X[i]
    add rax, qword [rdi+rcx*8+8]       ; X[i+1]
    add rax, qword [rdi+rcx*8+16]      ; X[i+2]
    add rax, qword [rdi+rcx*8+24]      ; X[i+3]

    mov qword [rsi+rcx*8-24], rax      ; Store in Y[i]

    inc ecx                           
    cmp ecx, edx                      
    jl loop_start                    

    pop rbp
    ret
