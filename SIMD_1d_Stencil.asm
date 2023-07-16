; Name: Stephanie Joy R. Susada
; Section: S11

section .text
    global simd_1dstencil

simd_1dstencil:
    push rbp
    mov rbp, rsp

    mov rdi, rcx        ; 1st param
    mov rsi, rdx        ; 2nd param
    mov edx, r8d        ; 3rd param

    xor rax, rax

    mov ecx, 3 ; to start in index 3

loop_start:
    movdqu xmm0, [rdi+rcx*8-24]       
    movdqu xmm1, [rdi+rcx*8-16]       
    movdqu xmm2, [rdi+rcx*8-8]        
    movdqu xmm3, [rdi+rcx*8]          
    movdqu xmm4, [rdi+rcx*8+8]        
    movdqu xmm5, [rdi+rcx*8+16]       
    movdqu xmm6, [rdi+rcx*8+24]       
    paddd xmm3, xmm0                  
    paddd xmm3, xmm1                  
    paddd xmm3, xmm2                  
    paddd xmm3, xmm4                  
    paddd xmm3, xmm5                  
    paddd xmm3, xmm6                  
    movdqu [rsi+rcx*8-24], xmm3       

    inc ecx
    cmp ecx, edx
    jl loop_start

    pop rbp
    ret
