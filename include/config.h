#ifndef CONFIG_H
#define CONFIG_H

/* The following line, if defined, has printf() and friends use memory management.
 * If commented, they will not use memory management at all
 */
//#define PRINTF_USE_MM

/* Interrupt for syscalls:
 *   default is 0x21
 *   used to use 0x80 (got the idea from Linux)
 * This must also be changed in HalIsrSyscall - line 15 in
 * src/metodo/hal/i386/exceptions.asm
 */
#define IA32_SYSCALL_INTERRUPT 0x20

/* For the next one, a nice big thank you to inline assembly
 * see src/lib/krnllib/krnllib.c for details
 */
#define IA32_SYSCALL_INTERRUPT_STR "0x20"

#endif
