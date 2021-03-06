#ifndef HAL_SCHEDULER_H
#define HAL_SCHEDULER_H

struct proc_regs {
	unsigned int gs, fs, es, ds;
	unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;
	unsigned int int_no, err_code;
	unsigned int eip, cs, eflags, useresp, ss; 
};

void HalSchedulerEnable();
void HalSchedulerDisable();
int HalIsSchedulerEnabled();
/*
 * Defined in core/scheduler.h:
 * void HalSchedulerRunProcess(SchedulerProcess proc);
 */

#endif /* end of include guard: HAL_SCHEDULER_H */
