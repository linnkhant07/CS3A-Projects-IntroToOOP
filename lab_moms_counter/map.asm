.386
.model flat, stdcall
.stack 4096
ExitProcess PROTO, dwExitCode: DWORD
Include Irvine32.inc

.data
MAX_BUFFER_SIZE = 1000
MAX_WORD_ARRAY_SIZE = 1000
temp dword 0
LocateArray WORD 100 DUP (?)

.data
    ;reading file
    
    filename1 BYTE "three.txt",0
    fileHandle HANDLE ?
    bytesRead DWORD ?
    buffer db MAX_BUFFER_SIZE dup(0)
    wordArray BYTE MAX_WORD_ARRAY_SIZE dup(?),0
    speed dword 1000
    msec dword ?
    
.code

    ReadingFile Proc 
    ; Open the file
    invoke CreateFile, addr fileName1, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0
    mov fileHandle, eax
   
    
    ; Read the file content into the buffer
    invoke ReadFile, fileHandle, addr buffer, MAX_BUFFER_SIZE, addr bytesRead, 0
    cmp bytesRead, 0
    je  close_file
    
    ; Tokenize the content and store words in the array
    mov esi, offset buffer
    mov edi, offset wordArray

tokenize_loop:
    ; Read a character from the buffer
    mov al, [esi]
    cmp al, 0
    je  tokenize_done

    ; Check for space or newline character
    cmp al, ' '
    jne  skip_char
    

    ; Store the character in the wordArray
    mov bl, 0
    mov [edi], bl
    inc edi
    inc esi
    jmp tokenize_loop

    skip_char:
    mov [edi], al
    inc edi

    inc esi
    jmp tokenize_loop

tokenize_done:
    
close_file:
    ; Close the file
    invoke CloseHandle, fileHandle
   
 ret
 ReadingFile ENDP
 ;-----------------------------------------------------------------------------------------------------------------------

 COMMENT $
 CheckKey PROC USES edx esi eax ecx

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

    ;THIS SAVED MY LIFE OMFFGGGGGGGGGGG!!!
    mov eax, 10
    call Delay
    call ReadKey
    ;nothing is read into
    jz DONE

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
     call PrintInputArr
        .IF charsTyped >= 8
        inc wordsTyped
        mov charsTyped, 0
    .ENDIF

    mov eax, totalWords
    .IF wordsTyped == eax
        mov isWon, 1
    .ENDIF


ret
CheckKey ENDP $
;----------------------------------------------------------------------------------------------------------------------------------------------------
 LocateXY PROC uses EAX EDX ESI ebx ECX
 ;need randomized Y for new word printed
 mov ebx, eax
 shl ebx, 1
 mov esi, OFFSET [locateArray]
 add esi, ebx
 mov dx,[esi]
 Call gotoXY
 ret
 LocateXY ENDP

 StoreXY PRoc uses eax esi ebx edx
 ;randomized and store the locations Dh, dl
 call GetmaxXY
 mov eax, 0
 mov al, dl
 call RandomRange
 mov esi, OFFSET [LocateArray] ;still need to increase the location in a loop
 mov ebx, temp
 shl ebx, 1 ;multiply ebx by 2
 add esi, ebx
 mov [esi], ax
 
 ret
 StoreXY endp

 MoveWordDown Proc uses eax edx ESI ecx
 ;deal with word array and locateArray
 ;call LocateXY
 mov esi, OFFSET [LocateArray]
 mov ecx, eax
 inc ecx
 ;add eax,2
 mov edx, 0
 L10:
     mov dx, [esi]
     inc dh
     mov [esi], dx
     add esi, 2
 loop L10
 ;Call gotoXY
 ret
 MoveWordDown ENDP

 WriteWord PRoc uses ECX ESI ebx eax
 ;write all the words one by one        
 ;might need another loop
 ;mov ecx, 3   ; three bacuse it is prototype
 ;mov edx, offSet WordArray ; temp might not work
 ;mov ebx, temp
 ;shl ebx, 2
 ;add edx, ebx
 ;add esi, edx
  ;L1:
 ;mov al, [esi]
 ;call WriteChar
 ;inc esi
 ;Loop L1

 call writeString
 ret
 WriteWord ENDP

 WriteWords Proc uses ECX eax
 mov edx, OFFSET wordArray
 ;inc temp
 mov eax, 0
 
 mov ecx, temp
 inc ecx
 
 L5:

 call locateXY
 call writeString

 inc eax
 add edx, 4
 loop L5
 call moveWordDown
 ret
 WriteWords ENDP

 .code

 main proc
 call ReadingFile
 mov ecx,40
 ;mov eax,500

call Getmseconds
add eax, speed
mov msec, eax
 L2:            ;jump nk yay ayan
 call storeXY
 call WriteWords
 ;call checkkey
 ;call delay
 
 L5:
 
 mov eax, 1
 call Delay
 call Getmseconds
 .IF eax >= msec
		call clrscr
		inc temp					;increment the number of printed string
		add eax, speed					;delay
		mov msec, eax
  .ELSE
  ;add eax, 500
    jmp L5
	.ENDIF
    
;wrg temp
 loop L2

INVOKE ExitProcess, 0
main ENDP
END main
