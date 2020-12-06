/*******************************************************************************
File name       : user_led.s
Description     : Assembly language function for controlling the user LED
*******************************************************************************/   

    EXTERN delay                    // delay() is defined outside this file

    PUBLIC control_user_led1        // Exports symbols to other modules

// Code is split into logical sections using the SECTION directive.
// Source: http://ftp.iar.se/WWWfiles/arm/webic/doc/EWARM_AssemblerReference.ENU.pdf
// SECTION  section  :type [:flag] [(align)]
//      The data section is used for declaring initialized data or constants. This data does not change at runtime
//      The bss section is used for declaring variables. The syntax for declaring bss section is -
//      The text section is used for keeping the actual code.

// CODE: Interprets subsequent instructions as Arm or Thumb instructions, 
// depending on the setting of related assembler options.

// NOREORDER (the default mode) starts a new fragment in the section
// with the given name, or a new section if no such section exists.
// REORDER starts a new section with the given name.

// NOROOT means that the section fragment is discarded by the linker if
// no symbols in this section fragment are referred to. Normally, all
// section fragments except startup code and interrupt vectors should
// set this flag.

// The (2) is for the (align)
// The power of two to which the address should be aligned.
// The permitted range is 0 to 8. 
// Code aligned at 4 Bytes.

    SECTION .text:CODE:REORDER:NOROOT(2)
    
    THUMB               // Indicates THUMB code is used
                        // Subsequent instructions are assembled as THUMB instructions
    
/*******************************************************************************
Function Name   : control_user_led1
Description     : - Uses Peripheral registers at base 0x4800.0000
                    to set GPIOA Output Data Register.
                  - Calls another assembly function delay to insert
                    delay loop

C Prototype     : void control_user_led(uint32_t state, uint32_t duration)
                : Where state indicates if LED should be on or off.
Parameters      : R0: uint32_t state
                : R1: uint32_t duration
Return value    : None
*******************************************************************************/  

//GPIOA_BASE  EQU 0x48000000
//GPIOA_ODR   EQU 0x14
//GPIOA_BIT_5 EQU 0x20

control_user_led1
    
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // GPIOA Base Address: 0x48000000
    // Address offset: 0x14
    // Set bit[5] to 1 --> 0x20; // Turn LED ON
    // Set bit[5] to 0 --> 0x0; // Turn LED OFF
    
    MOV R3, LR // load LR into R3 for user_led() exit/return

    CMP R0, #1 // compare R1 to 1 to see if "on" 
    BEQ On // if they are equal, jump to On 

    CMP R0, #0 // compare R1 to 0 to see if "off" 
    BEQ Off // if they are equal, jump to Off 
    
    // GPIOA_ODR |= ORD5;

    On:
    LDR R5, [R2] // loads the value pointed to by p_GPIOA_ODR
    ORR R5, R5, #0x20 // or // Set bit[5] to 1 --> 0x20; // Turn LED ON          
    STR R5, [R2] // store
    BL delay // enters delay() branch
    BX R3 // exit per LR in R3
    
    // GPIOA_ODR ^= ORD5;

    Off: 
    LDR R5, [R2] // loads the value pointed to by p_GPIOA_ODR
    ORR R5, R5, #0x20 // or to set bit to know value         
    BIC R5, R5, #0x20 // inverts 0x20 bits makig bit[5]=0 and all others 1 -- then logical ands with R5/GPIOA_ODR value       
    STR R5, [R2] // store
    BL delay // enters delay() branch
    BX R3 // exit per LR in R3
    
    END
    
    
