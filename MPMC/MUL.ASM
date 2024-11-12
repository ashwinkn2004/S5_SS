assume cs:code, ds:data
data segment
        a db 3
        b db 4
        c db ?
data ends
code segment
start:
        mov ax, data
        mov ds, ax
        mov al, a
        mov bl, b
        mul bl
        mov c, al
        mov ah, 4ch
        int 21h
code ends
end start
