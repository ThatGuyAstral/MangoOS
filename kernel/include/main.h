#ifndef MAIN_H
#define MAIN_H
#include <flanterm/flanterm.h>
#include <graphics.h>
#include <system/gdt.h>
#include <system/idt.h>
#include <system/smem.h>
#include <limine.h>

/// @brief The framebuffer.
struct limine_framebuffer *fb;

/// @brief Logs a message.
/// @param type The type of log. (0 = OK, 1 = WARN, 2 = ERROR, 3 = INFO)
/// @param msg The message to log.
void log(struct flanterm_context *ftctx, int type, const char *msg);

#endif