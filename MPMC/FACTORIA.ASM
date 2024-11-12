assume cs:code, ds:data
data segment
	a db 5
        b db 2
data ends
code segment
start:
        ;n!
	mov ax,data
	mov ds, ax
	mov al, a
	mov ah, 00h
	mov cl, al
l1: 	dec cl
	mul cl
	cmp cl, 1
	jne l1
	mov dl, al

        ;(n-r)!
	mov al, a
	mov ah, 00h
        mov bl, b
        mov bh, 00h
	sub al, bl
	mov cl, al
l2:     dec cl
	mul cl
	cmp cl, 1
        jne l2
        mov cl, al

        !moving denominator to numerator
        mov ax, dl
        div cl

	mov ah, 4ch
	int 21h
code ends
end start

