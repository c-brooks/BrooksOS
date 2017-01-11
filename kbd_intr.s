global kbd_intr
; extern reset_intr_pic1
; extern reset_intr_pic2
; extern kbd_key
extern kmain

kbd_intr:
    pushad
    ; xor eax, eax
    in al, 0x60               ; Read 0x60 into al
    push eax
    ; call kbd_key
    call kmain                ; Print something
    add esp, 4
    ; call reset_intr_pic1
    ; call reset_intr_pic2
    popad
    iret
