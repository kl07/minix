#include <sys/types.h>
#include <machine/cpu.h>
#include <minix/type.h>
#include <io.h>
#include "omap_intr.h"

static struct omap_intr {
	vir_bytes base;
} omap_intr;

int intr_init(const int auto_eoi)
{
#ifdef DM37XX
	omap_intr.base = OMAP3_DM37XX_INTR_BASE;
#endif
#ifdef AM335X
	omap_intr.base = OMAP3_AM335X_INTR_BASE;
#endif
    return 0;
}

void omap3_irq_handle(void) {
	/* Function called from assembly to handle interrupts */

	/* get irq */
	int irq = mmio_read(omap_intr.base + OMAP3_INTCPS_SIR_IRQ) & OMAP3_INTR_ACTIVEIRQ_MASK;
	/* handle irq */
	irq_handle(irq);
	/* re-enable. this should not trigger interrupts due to current cpsr state */
    	mmio_write(omap_intr.base + OMAP3_INTCPS_CONTROL,OMAP3_INTR_NEWIRQAGR);
	
}

void omap3_irq_unmask(int irq)
{
    mmio_write(OMAP3_INTR_MIR_CLEAR(omap_intr.base, irq >> 5), 1 << (irq & 0x1f));
}

void omap3_irq_mask(const int irq)
{
    mmio_write(OMAP3_INTR_MIR_SET(omap_intr.base, irq >> 5), 1 << (irq & 0x1f));
}
