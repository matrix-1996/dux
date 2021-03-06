#ifndef HAL_ISR_H
#define HAL_ISR_H

typedef struct registers
{
   int ds;                  // Data segment selector
   int edi, esi, ebp, esp, ebx, edx, ecx, eax; // Pushed by pusha.
   int int_no, err_code;    // Interrupt number and error code (if applicable)
   int eip, cs, eflags, useresp, ss; // Pushed by the processor automatically.
} registers_t;

struct regs {
	unsigned int gs, fs, es, ds;
	unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;
	unsigned int int_no, err_code;
	unsigned int eip, cs, eflags, useresp, ss; 
};

extern void HalIsrInstall(void);
extern void HalIsrHandler(struct regs *r);

extern void HalIsr0();
extern void HalIsr1();
extern void HalIsr2();
extern void HalIsr3();
extern void HalIsr4();
extern void HalIsr5();
extern void HalIsr6();
extern void HalIsr7();
extern void HalIsr8();
extern void HalIsr9();
extern void HalIsr10();
extern void HalIsr11();
extern void HalIsr12();
extern void HalIsr13();
extern void HalIsr14();
extern void HalIsr15();
extern void HalIsr16();
extern void HalIsr17();
extern void HalIsr18();
extern void HalIsr19();
extern void HalIsr20();
extern void HalIsr21();
extern void HalIsr22();
extern void HalIsr23();
extern void HalIsr24();
extern void HalIsr25();
extern void HalIsr26();
extern void HalIsr27();
extern void HalIsr28();
extern void HalIsr29();
extern void HalIsr30();
extern void HalIsr31();

#endif /* end of include guard: HAL_ISR_H */
