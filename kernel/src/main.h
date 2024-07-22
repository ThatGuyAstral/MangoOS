#ifndef MAIN_H
#define MAIN_H
#include <flanterm/flanterm.h>
#include <graphics.h>
#include <system/gdt.h>

void log(struct flanterm_context *ftctx, int type, const char *msg);

#endif