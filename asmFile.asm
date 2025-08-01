;Danica Marie Suizo
;Karl Andrei Ordinario

section .data
    inv255  dd 0.0039215686, 0.0039215686, 0.0039215686, 0.0039215686 ;float converter kasi tamad ako

section .text
bits 64
default rel
global imgCvtInttoFloat

imgCvtInttoFloat:
    push rbx

    ; basically calculates the total amount of pixels by h*w
    mov eax, ecx        ; ecx = height
    imul eax, edx       ; edx = width
    mov r10d, eax       ; r10d = total pixels
    xor r11d, r11d      ; r11d = counter

    ; Load 1/255.0 into xmm1(pang convert sa float)
    movups xmm1, [rel inv255]

.loop: ;loops till it reaches the total amount of pixels given lol
    cmp r11d, r10d
    jge .done

    movdqu xmm0, [r8 + r11 * 4]     ; FIXED
    cvtdq2ps xmm0, xmm0
    mulps xmm0, xmm1
    movups [r9 + r11 * 4], xmm0     ; FIXED

    add r11d, 4
    jmp .loop

.done:
    pop rbx
    ret
