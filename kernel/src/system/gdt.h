#ifndef GDT_H
#define GDT_H
#include <stdint.h>
#include "../main.h"

typedef struct {
    uint64_t base;
    uint16_t limit;
    uint8_t accessByte, flags;
} __attribute__((packed)) gdtEntry;

typedef struct {
    uint64_t base;
    uint16_t limit;
} __attribute__((packed)) gdtPtr;

void initGDT(struct limine_framebuffer *fb);

#endif