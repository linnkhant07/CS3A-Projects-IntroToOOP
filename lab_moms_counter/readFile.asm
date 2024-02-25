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