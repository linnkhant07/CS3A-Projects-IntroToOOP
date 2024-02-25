.386
.model flat, stdcall
.stack 4096
ExitProcess PROTO, dwExitCode: DWORD

INCLUDE Irvine32.inc

.data
    ; define your variables here
    menuText BYTE "PRESS 1 for typing tutor game and 2 for word dropping game: ", 0   

    ;for typing tutor game (1)
    str1 BYTE "Staring at the bottom of your glass hoping one day you'll make a dream last but dreams come slow, and they go so fast You see her when you close your eyes", 0
    counter BYTE 0
    cordY BYTE 0
    maxX BYTE ?

    ;for word dropping game (2)
    strTEST BYTE "WORD DROPPING GAME", 0

    ;for now - length will be max 7
    array_of_strings BYTE "RONALDOOMESSIIII", 0


    arrXCords BYTE 20, 40
    arrYCords BYTE 2, 1
    ptrXCord DWORD ?
    ptrYcord DWORD ?

    blankText DWORD " ", 0
    finishLine BYTE "--------------------------------------------------------------------------------------",0
    lineHeight BYTE 25
    isTouchLine BYTE 0
    initTime DWORD ?
    timeRn DWORD ?
    mSec DWORD ?
    isLost BYTE 0
    msgLost BYTE "You lost! Try again", 0

    count DWORD 0
    wordsTyped DWORD 0
    charsTyped DWORD 0
    totalWords DWORD LENGTHOF arrYCords

    inputArr BYTE 8 DUP(?)
    input_correct BYTE 1
    error_count BYTE 0

.code

writePrompt PROC USES edx
;requires: the prompt needs to be in esi
    mov edx, esi
    call WriteString

ret
writePrompt ENDP


goToStart PROC USES edx
;go to start of the 0 x 0 on the screen

    mov dl, 0; column
    mov dh, 0; row
    call Gotoxy
ret
goToStart ENDP

setGreen PROC USES eax
    mov  eax,green+(black*16)
    call SetTextColor

ret
setGreen ENDP

setRed PROC USES eax
    mov  eax,red+(black*16)
    call SetTextColor

ret
setRed ENDP

resetColors PROC USES eax
;reset text color
    mov  eax,white+(black*16)
    call SetTextColor

ret
resetColors ENDP

dealBSpace PROC USES edx

    ;edgecase (1): x = 0
    cmp counter, 0
    jne NOT_EDGE

	;edgecase (2): also, y = 0
	cmp cordY, 0
	je NO_ACTION

	;if x = 0 but y != 0
	;set counter = largest column - 1
	call getMaxXY ;dl = highest column, dh = highest row
	mov counter, dl
	dec cordY

NOT_EDGE:
    ;going one step back
    dec counter 
    dec esi

	
    ;write the previous thing in black (backspace action)
    mov al, BYTE PTR [esi]
    call resetColors
    call locateCursor
    call WriteChar
    
    ;to maintain the correct looping
    add ecx, 1

NO_ACTION:
    add ecx, 1


ret
dealBSpace ENDP

locateCursor PROC USES edx

    mov dh, cordY
    mov dl, counter
    call gotoxy

ret
locateCursor ENDP

runTest PROC USES eax esi
;run typing test with given prompt, correct words will be green, wrong ones red
;requires: prompt is in the esi

L_INPUT: 

    ;read the char
    call ReadChar

    ;IF IT IS A BACKSPACE
    cmp al, 8   ;8 is ASCII for backspace
    jne NOT_BACKSPACE
	call dealBSpace
	jmp DONE


    ;IF IT IS NOT A BACKSPACE
NOT_BACKSPACE:
    ;compare the characters
    cmp BYTE PTR [esi], al
    jne CHAR_MISMATCH
    call setGreen
    jmp CHAR_MATCH

CHAR_MISMATCH: call setRed

CHAR_MATCH:
    mov al, BYTE PTR [esi]
    call WriteChar

    ;increment by each character
    inc esi
    inc counter

	;check if it goes over the bound
	call getMaxXY ;dl = highest column, dh = highest row

    dec dl
	cmp dl, counter
	jae IN_BOUND
	;out of bound
	inc cordY
	mov counter, 0

IN_BOUND:
	;do nothing if inbound

DONE: 
    call locateCursor
    loop L_INPUT

	;reset counter to re use next time
	mov counter, 0
ret
runTest ENDP

menu PROC USES edx

mov edx, OFFSET menuText
call WriteString

ret
menu ENDP

typingTutorGame PROC USES esi ecx

    mov esi, OFFSET str1
    mov ecx, LENGTHOF str1
    ;make sure to take one space off of null char
    dec ecx

    call writePrompt
    call goToStart ;go to 0x0 to type    

    ;call the typing test
    call runTest 
    

    call resetColors

ret
typingTutorGame ENDP

drawFinishLine PROC USES edx eax ecx

    ;get maxX and maxY
    call getMaxXY

    ;choose vertical position
    mov dh, lineHeight
    ;fill the screen horizontally
    movzx ecx, dl 
    dec ecx

    mov dl, 0
    mov al, '-'

loopFLine:
    inc dl
    call gotoxy
    call WriteChar

    loop loopFLine

ret
drawFinishLine ENDP

drawBaseLine PROC uses edx

    mov dl, 1
    mov dh, lineHeight
    call gotoxy

    mov edx, OFFSET finishLine
    call WriteString

ret
drawBaseLine ENDP

CheckTouchLine PROC 

    ;check if any words have touched the base line
    cmp isTouchLine, 1
    jne CONTINUE_DROP
    mov ecx, 1
    mov isLost, 1

CONTINUE_DROP:

ret
CheckTouchLine ENDP

PrintWords PROC USES edx ecx esi eax ebx

    ;adjust loop count for completed words
    mov ecx, 2
    sub ecx, wordsTyped

loopWords:

        mov ebx, count
        ;don't print if a word is completed
        add ebx, wordsTyped

        ;adjust the pointer to next word
        push ecx
        .IF wordsTyped > 0
        mov ecx, wordsTyped
        movESI:
            add esi, 8
        loop movESI
        .ENDIF 
        pop ecx

        mov dl, arrXcords[ebx]
        mov dh, arrYcords[ebx]
        call gotoxy

        ;check if it has touched the base line

        cmp dh, lineHeight
        jne CONTINUE_LW
        mov isTouchLine, 1
CONTINUE_LW:
       
        push ecx
        mov ecx, 8
    LOOP_CHAR:
            mov al, BYTE PTR [esi]
            call WriteChar
            inc esi
    loop LOOP_CHAR
        pop ecx
        

        ;increase business
        inc count

        loop loopWords

         ;reset count
         mov count, 0
ret
PrintWords ENDP

PrintInputArr PROC USES edx ecx esi eax ebx

    mov ebx, wordsTyped
    mov dl, arrXcords[ebx]
    mov dh, arrYcords[ebx]
    call gotoxy

    ;no need to check touchLine
    mov ecx, charsTyped

    ;esi points to InputArr
    mov esi, OFFSET inputArr

    .IF input_correct == 0
        inc error_count
        call setRed
    .ELSEIF input_correct == 1
        call setGreen
    .ENDIF

    .IF charsTyped > 0
        LOOP_CHAR:
                mov al, BYTE PTR [esi]
                call WriteChar
                inc esi
        loop LOOP_CHAR
    .ENDIF    

    ;show the incorrect character
;-----------------------------------------
.IF (input_correct == 0) && (error_count >= 1)
    mov esi, OFFSET array_of_strings
    add esi, charsTyped
    .IF wordsTyped > 0
        mov ecx, wordsTyped
        movESI:
            add esi, 8
        loop movESI
    .ENDIF

    mov al, BYTE PTR [esi]
    call WriteChar
.ENDIF
;-------------------------------------

    call resetColors
    ;increase business
    inc count
        ;reset count
    mov count, 0
ret
PrintInputArr ENDP

CheckKey PROC USES edx esi eax ecx
    
    .IF charsTyped >= 8
        inc wordsTyped
        mov charsTyped, 0
    .ENDIF

    add esi, charsTyped

    .IF wordsTyped > 0
        mov ecx, wordsTyped
        movESI:
            add esi, 8
        loop movESI
    .ENDIF  
    
    .IF charsTyped < 8 
        mov eax, charsTyped
        add dl, al
    .ENDIF

    .IF wordsTyped < 2
        call gotoxy
    .ENDIF

    
    call ReadKey
    ;nothing is read into
    jz NOTHING_READ

    cmp BYTE PTR [esi], al
    jne CHAR_MISMATCH
    call setGreen
    jmp CHAR_MATCH

CHAR_MISMATCH: 
    mov input_correct, 0
    jmp DONE

CHAR_MATCH:
    inc charsTyped

    ;update input array
    mov edx, OFFSET inputArr
    add edx, charsTyped
    dec edx
    mov [edx], al
    inc edx

    ;set input_correct
    mov input_correct, 1

DONE:  

NOTHING_READ:
    call resetColors

ret
CheckKey ENDP

wordDroppingGame PROC USES edx ebx eax esi

;for now - loop infinitely until the finishline
    mov ecx, -1

;get initial time before program starts
    call GetMseconds
    mov initTime, eax

    ;time interval for dropping words by one line
    mov msec, eax


loopWD:

    ;-----------------
    ;hardcode ecx / the number of arrays for now
    mov ecx, 2
    mov esi, OFFSET array_of_strings

    call drawFinishLine
    ;call drawBaseLine

    ;print all the words in the array
    call printWords

    call CheckKey
    call printInputArr

    call GetMseconds ;time right now -> eax

    ;only jump line if 1 sec has passed
    .IF eax > msec
        
        ;increase each y coords

        push ecx
        mov ecx, 2
        increase_y:
            inc arrYcords[ecx - 1]
        loop increase_y
        pop ecx
        
        call clrscr
        add msec, 4000
    .ENDIF  
   
        
    call CheckTouchLine

NOT_NOW:
    mov count, 0

loop loopWD

ret
wordDroppingGame ENDP


main PROC
    
    call menu
    mov eax, 0
    ;user has chosen mode
    ;1 for typing tutor & 2 for word dropping
    call ReadInt ;response in eax
    call Clrscr

    cmp eax, 1
    je MODE_1

    cmp eax, 2
    je MODE_2

    MODE_1: 
    call typingTutorGame
    jmp DONE
        
    MODE_2:
    call wordDroppingGame

    DONE:

    ;check if they lost
    cmp isLost, 1
    jne ENDPROGRAM
    call clrscr
    mov dl, 27
    mov dh, 10
    call gotoxy

    mov edx, OFFSET msgLost
    call WriteString

    mov eax, 1000
    call delay

ENDPROGRAM:    

    INVOKE ExitProcess, 0
main ENDP
END main