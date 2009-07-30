#include <system.h>

#include <dux/drivers/core/console.h>
#include <dux/mm/memory.h>

#include <krnl/stop.h>
#include <stdint.h>

#include <hal.h>
#include <dux/message_handler.h>

#include <multiboot.h>

#include <buildid.h>

#include <dux/krnl/core.h>

/* Main loop! */
void kmain(uint32_t magic, multiboot_info_t *mbd)
{
	void *userland = NULL;

	if (magic != MULTIBOOT_BOOTLOADER_MAGIC) {
		KrnlStop(STOP_BAD_MULTIBOOT_SIGNATURE, magic, 0, 0, 0);
	}

	CoLowerIpl(IPL_PASSIVE);

	// Init the Hal
	HalInit((*MessageReceiver));

	ArchDisplayInit();
	ArchDisplayString("Dux Operating System Version %s" SCM_REV "\n");

	/* mbd->flags */
	int i;
	module_t *module;
	if (mbd->flags>>3&1) {
		module = (module_t*)mbd->mods_addr;
		for (i = 0; i < mbd->mods_count; i++, module++) {
			printka("\nModule name: %s\n", module->string);
			if (strcmp(module->string, "/System/userland") >= 0){
				userland = (void*) module->mod_start;
				printka("\nUserland: %x\n", userland);
			}
		}
	}

	if (dux_intro) {
		dux_intro();
	}

	ArchDisplayInit();
	ArchDisplayClear();
	printf("hello world? %x\n", 0x4874);

	while (1);

	/* Initialize the console for user mode. */
	/* Can't we take this out someday... */
	console_init();

	/* Initialize pseudo-user mode */
	if (userland != NULL)
		LoadUserland(userland);
	else {
		KrnlEasyStop(STOP_NO_USERLAND);
	}
}
