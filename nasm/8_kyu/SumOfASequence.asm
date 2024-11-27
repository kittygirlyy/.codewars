section .text
global sequence_sum

sequence_sum:
    push rbp
    mov rbp, rsp

    xor eax, eax
    mov ecx, edi
    mov esi, esi
    mov edx, edx

.loop:
    cmp ecx, esi
    jnle .end_loop

    add eax, ecx
    add ecx, edx
    jmp .loop

.end_loop:
    pop rbp
    ret
