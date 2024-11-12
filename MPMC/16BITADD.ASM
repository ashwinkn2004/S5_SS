assume cs:code, ds:data
data segment
        a dw 5096h
        b dw 2390h
        sum dw ?
        carry dw 0000h
data ends
code segment
start:
        mov ax, data
        mov ds, ax

        mov ax,a
        add ax, b
        mov sum, ax
        jnc skip
        inc carry
skip:   mov ah, 4ch
        int 21h
code ends
end start
