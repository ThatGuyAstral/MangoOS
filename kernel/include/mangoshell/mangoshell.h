#ifndef MANGOSHELL_H
#define MANGOSHELL_H
#include <flanterm/flanterm.h>

void mshMain(struct flanterm_context *ftctx);
void mshLog(struct flanterm_context *ftctx, int type, const char *msg);

#endif