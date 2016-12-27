global loader                   ; the entry symbol for ELF
extern kmain

MAGIC_NUMBER equ 0x1BADB002     ; define the magic number constant
FLAGS        equ 0x0            ; multiboot flags
CHECKSUM     equ -MAGIC_NUMBER  ; calculate checksum
                                ; (magic num + checksum + flags should = 0)
KERNEL_STACK_SIZE equ 4096      ; size of stack (bytes)

section .bss
align 4
kernel_stack:                   ; label points to beginning of memory
    resb KERNEL_STACK_SIZE      ; reserve stack for kernel

section .text:                  ; start of the text (code) section
align 4                         ; the code must be 4 byte aligned
    dd MAGIC_NUMBER             ; write the magic number to the machine code,
    dd FLAGS                    ; the flags,
    dd CHECKSUM                 ; and the checksum

loader:                         ; define loader label (entry point in linker script)
    mov eax, 0xCAFEBABE         ; place number 0xCAFEBABE in the register eax
    mov esp, kernel_stack + KERNEL_STACK_SIZE
                                ; point esp to start of stack

call kmain
.loop:
    jmp .loop                   ; loop
