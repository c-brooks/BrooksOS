#ifndef INCLUDE_IO_H
#define INCLUDE_IO_H

/** outb:
 *  Sends the given data to the given I/O port. Defined in io.s
 *
 *  @param port The I/O port to send the data
 *  @param data The data to send to the I/O port
 */
void         outb(unsigned short port, unsigned char data);

/** inb:
 *  Reads data from the given I/O port. Defined in io.s
 *
 *  @param port The I/O port from which to read the data
 *  @return     The data read
 */
unsigned char inb(unsigned short port);

#endif /* INCLUDE_IO_H */
