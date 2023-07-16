; Name: Stephanie Joy R. Susada
; Section: S11
section .text
    global asm_stencil_function

asm_stencil_function:
    push rbp
    mov rbp, rsp

    mov rdi, rcx        
    mov rsi, rdx        
    mov edx, r8d        

    xor rax, rax       

    mov ecx, 3         

loop_start:
    mov rax, qword [rdi+rcx*8-24]      ; i-3
    add rax, qword [rdi+rcx*8-16]      ; i-2
    add rax, qword [rdi+rcx*8-8]       ; i-1
    add rax, qword [rdi+rcx*8]         ; i
    add rax, qword [rdi+rcx*8+8]       ; i+1
    add rax, qword [rdi+rcx*8+16]      ; i+2
    add rax, qword [rdi+rcx*8+24]      ; i+3

    mov qword [rsi+rcx*8-24], rax     

    inc ecx                           
    cmp ecx, edx                      
    jl loop_start                    

    pop rbp
    ret
