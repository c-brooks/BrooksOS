#include "idt.h"

/** idt_register:
 *  Registering an entry in the IDT.
 *  @param intr_num    Interrupt code
 *  @param (*isr)()    Pointer to Interrupt Service Routine function
 *  @param pl          Privelige level
 */
void idt_register(int intr_num, void (*isr)(void), int pl)
{
    idt[intr_num].offset_LO = (unsigned short)
            ((unsigned int)(isr) & (unsigned int) 0xFFFF);
    idt[intr_num].segsel = (unsigned short) 0x0008;
    idt[intr_num].attr = (unsigned short) pl;
    idt[intr_num].offset_HI = (unsigned short)
            ((unsigned int)(isr) >> 16 & (unsigned int) 0xFFFF);
}


idt_entry idt[255] = {};

idt_descriptor IDT_DESC = { sizeof(idt)-1, (unsigned int)&idt };
