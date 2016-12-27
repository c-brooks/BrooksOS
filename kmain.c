#define FB_GREEN     2
#define FB_DARK_GREY 8


/** fb_write_cell:
 *  Writes a character with the given foreground and background to position i
 *  in the FrameBuffer.
 *
 *  16-bit FrameBuffer data has this form:
 * Bit:     | 15 14 13 12 11 10 9 8 | 7 6 5 4 | 3 2 1 0 |
 * Content: | ASCII                 | FG      | BG      |
 *
 *  @param i  The location in the framebuffer
 *  @param c  The character
 *  @param fg The foreground color
 *  @param bg The background color
 */
void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg)
{
    fb[i] = c;
    fb[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F)
}

// Write the letter 'A' to the FrameBuffer in pos. (0,0)
fb_write_cell(0, 'A', FB_GREEN, FB_DARK_GREY);
