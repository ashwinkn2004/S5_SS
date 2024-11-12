assume cs:code, ds:data
data segment
        a dd 00000007h
        b dw 0002h
	msg1 db "QUO = $", 0
	msg2 db "REM = $", 0
        quo dw ?
        rem dw ?
data ends
code segment
start:
        mov ax, data
        mov ds, ax
        lea si, a

        mov ax,[si]
        mov dx,[si+2]

        div b
        mov quo, ax
        mov rem, dx

	        ; Display quotient (3)
	lea dx, msg1
	mov ah, 09h
	int 21h

        add quo, '0'          ; Convert quotient to ASCII ('3')
        mov dl, quo           ; Load quotient into DL
        mov ah, 02h           ; DOS function to print a character
        int 21h 
	
	mov dl, 0Ah              ; Linefeed (newline)
   	mov ah, 02h              ; DOS function to print a character
    	int 21h

              ; Display character (3)

        ; Display remainder (1)
	lea dx, msg2
	mov ah, 09h
	int 21h

        add rem, '0'          ; Convert remainder to ASCII ('1')
        mov dl, rem           ; Load remainder into DL
        mov ah, 02h           ; DOS function to print a character
        int 21h               ; Display character (1)

        mov ah, 4ch
        int 21h
code ends
end start
