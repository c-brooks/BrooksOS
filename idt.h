#ifndef _IDT_H
#define _IDT_H

#define DEFAULT_PL 0x8E00
#define USER_PL    0xEE00

void idt_register(int intr_num, void (*isr)(void), int pl);


/* Interrupt Description Table Descriptor
 *
 * Bit:     | 31                      16 | 15          0 |
 * Content: | length of IDT (255 Bytes)  | Start Address |
 *
 */
typedef struct str_idt_descriptor {
	unsigned short idt_length;
	unsigned int idt_addr;
} __attribute__((__packed__)) idt_descriptor;

/* 64-Bit IDT Entry
 * HIGH 32
 * Bit:     | 31        16 | 15 | 14 13 | 12 | 11 | 10 9 8 | 7 6 5 | 4 3 2 1 0 |
 * Content: | offset high  | P  | DPL   | 0  | D  | 1  1 0 | 0 0 0 | reserved  |
 * LOW 32
 * Bit:     | 31              16 | 15              0 |
 * Content: | segment selector   | offset low        |
 *
 */
typedef struct str_idt_entry_fld {
		unsigned short offset_HI;
		unsigned short segsel;
		unsigned short attr;
		unsigned short offset_LO;
} __attribute__((__packed__, aligned (8))) idt_entry;

extern idt_entry idt[];
extern idt_descriptor IDT_DESC;

#endif /* _IDT_H */
