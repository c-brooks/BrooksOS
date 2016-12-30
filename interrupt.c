#include "io.h"
extern int kmain();
extern int write(char *buf, unsigned int len, unsigned int cursorStart);

/** interrupt_handler:
 *  Handles generic (for now) interrupt.
 *  Writes the interrupt code to the FrameBuffer.
 *
 *  @param int_code     the code for the interrupt
 */
void interrupt_handler(unsigned char int_code)
{
  write(int_code, 10, 70);
  int res = kmain();
}
