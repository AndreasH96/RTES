/*
    Part of the Real-Time Embedded Systems course at Halmstad University
    Copyright (c) 2017, Sebastian Kunze <sebastian.kunze@hh.se>
    All rights reserved.
*/

/* PiFace Hardware Description */

/* MCP23S17 Control Register */
#define MCP_IODIRA      0x00
#define MCP_IODIRB      0x01
#define MCP_IPOLA       0x02
#define MCP_IPOLB       0x03
#define MCP_GPINTENA    0x04
#define MCP_GPINTENB    0x05
#define MCP_DEFVALA     0x06
#define MCP_DEFVALB     0x07
#define MCP_INTCONA     0x08
#define MCP_INTCONB     0x09
#define MCP_IOCON       0x0A
#define MCP_IOCON_      0x0B
#define MCP_GPPUA       0x0C
#define MCP_GPPUB       0x0D
#define MCP_INTFA       0x0E
#define MCP_INTFB       0x0F
#define MCP_INTCAPA     0x10
#define MCP_INTCAPB     0x11
#define MCP_GPIOA       0x12
#define MCP_GPIOB       0x13
#define MCP_OLATA       0x14
#define MCP_OLATB       0x15

/* HD44780 Control Pins */
#define LCD_DB4     (1 << 0)
#define LCD_DB5     (1 << 1)
#define LCD_DB6     (1 << 2)
#define LCD_DB7     (1 << 3)
#define LCD_EN      (1 << 4)
#define LCD_RW      (1 << 5)
#define LCD_RS      (1 << 6)
#define LCD_BL      (1 << 7)

/* void piface_putc(char c)
@description Prints the input c character on the PiFace Control & Display 2. 

@pre-condition c != NULL 

@post-condition Character is printed on screen, cursor is incremented by 1 and row is shifted if
necessary.  

*/
void piface_putc(char);

/* void piface_puts(char s[])
@description Prints the input string character on the PiFace Control & Display 2 by utilizing 
piface_putc. 

@pre-condition s[] != NULL 

@post-condition string is printed on screen, cursor is incremented by length of the array and row is shifted if
necessary.  

*/

void piface_puts(char[]);





/* void piface_clear(void)
@description Clears the PiFace Control & Display 2 screen and sets cursor to 0

@pre-condition None

@post-condition Display is cleared and cursor is set to 0

*/

void piface_clear(void);

/* void piface_switchLine(void)
@description Sets the cursor to the first position of the line to be changed to. 
If the cursor is between 0 and 16, the line will be changed to the lower one.
If the cursor is between 17 and 32 the line will be changed to the upper one.

@pre-condition None

@post-condition Cursor is changed to the other line as explained in description.

*/

void piface_switchLine(void);
