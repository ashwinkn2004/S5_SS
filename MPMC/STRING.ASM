assume cs:code, ds:data
data segment
     string1 db "HELLO", 0
     string2 db "HELLO", 0
     errmsg db "Not Equal$", 0
     msg db "Equal$", 0
data ends
code segment
start:
        mov ax, data
        mov ds, ax

        lea si, string1
        lea di, string2
compare:
        mov al, [si]
        mov bl, [di]
        cmp al, bl
        jne not_equal
        cmp al, 0
        je equal
        inc si
        inc di
        jmp compare

not_equal:
	 lea dx, errmsg
	 jmp display

equal:
         lea dx, msg
display:
	 mov ah, 09h
	 int 21h

endpgm:
        mov ah, 4ch
        int 21h

code ends
end start
