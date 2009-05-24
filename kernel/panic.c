#include <isr.h>
#include <system.h>

void stack_dump(void);
void register_dump(void);

void panic(char *text)
{
	printk("\nPanic: %s", text);
	stack_dump();
	panic("Inside panic");
	asm("cli");
	asm("hlt");
}

void panic_dump_hex(unsigned int *stack)
{
	unsigned int orig_stack = (unsigned int) stack;
	printk("\nStack Contents\n");
	while ((unsigned int) stack < ((orig_stack+0x1000) & ~(0x1000-1))) {
		printk("0x%x: 0x%x\n", stack, *stack);
		stack++;
	}
}
