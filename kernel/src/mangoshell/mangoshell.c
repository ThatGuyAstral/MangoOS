#include <mangoshell/mangoshell.h>

// MangoShell is very unfinished, and i'll get back to it once I at least have a keyboard driver.

void mshMain(struct flanterm_context *ftctx) {
    flanterm_write(ftctx, "Hello, world!");
}