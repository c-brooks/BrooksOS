#include "idt.h"
#include "kbd.h"

extern kbd_intr();
extern write();

/** idt_register:
 *  Registering an entry in the IDT.
 *  @param intr_num    Interrupt code
 *  @param (*isr)()    Pointer to Interrupt Service Routine function
 *  @param pl          Privelige level
 */
void idt_register(int intr_num, int (*isr)(void), int pl)
{
    idt[intr_num].offset_LO = (unsigned short)
            ((unsigned int)(isr) & (unsigned int) 0xFFFF);
    idt[intr_num].segsel = (unsigned short) 0x0008;
    idt[intr_num].attr = (unsigned short) pl;
    idt[intr_num].offset_HI = (unsigned short)
            ((unsigned int)(isr) >> 16 & (unsigned int) 0xFFFF);
}

void idt_register_kbd() {
  idt_register(0x1C, kbd_intr, DEFAULT_PL);
  write(kbd_intr, 0x20, 0x100);
}

idt_entry idt[255] = {};

idt_descriptor IDT_DESC = { sizeof(idt)-1, (unsigned int)&idt };
