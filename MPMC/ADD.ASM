assume cs: code, ds: data
data segment
        a db 3
        b db 4
        carry db 0
        sum db ?
data ends
code segment
start:  mov ax,data
        mov ds,ax
        mov al, a
        mov bl, b
	mov ah, 0
	mov bh, 0
        add al, bl
        mov sum, al
        jnc skip
        inc carry
skip:   mov ah, 4ch
        int 21h
code ends
end start
