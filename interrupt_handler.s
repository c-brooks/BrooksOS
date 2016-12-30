; Generic Interrupt Handler

extern interrupt_handler                  ; The C function

%macro no_error_code_interrupt_handler 1
   global interrupt_handler_%1
   interrupt_handler_%1:
       push    dword 0                     ; push 0 as error code
       push    dword %1                    ; push the interrupt number
       jmp     common_interrupt_handler    ; jump to the common handler
   %endmacro

   %macro error_code_interrupt_handler 1
   global interrupt_handler_%1
   interrupt_handler_%1:
       push    dword %1                    ; push the interrupt number
       jmp     common_interrupt_handler    ; jump to the common handler
   %endmacro

   common_interrupt_handler:               ; the common parts of the generic interrupt handler
       ; save the registers
       push    eax
       push    ebx
       push    ecx
       push    edx
       push    esp
       push    ebp
       push    esi
       push    edi

       ; call the C function
       call    interrupt_handler

       ; restore the registers
       pop     edi
       pop     esi
       pop     ebp
       pop     esp
       pop     edx
       pop     ecx
       pop     ebx
       pop     eax

       ; restore the esp
       add     esp, 8

       ; return to the code that got interrupted
       iret

   no_error_code_interrupt_handler 0       ; DIVISION BY 0
   no_error_code_interrupt_handler 1       ; DEBUGGER SINGLE STEP
   ; etc
   error_code_interrupt_handler    7       ; PROCESSOR EXTENSION NOT AVAILABLE
   no_error_code_interrupt_handler 9       ; PROCESSOR EXTENSION PROTECTION ERROR
   no_error_code_interrupt_handler 16      ; GET KEYSTROKE
   no_error_code_interrupt_handler 1Ch     ; SYSTEM TIMER TICK
