#include "gdt.h"

extern void loadGDT(gdtPtr *gdtptr);
void initGDT(struct limine_framebuffer *fb) {

    gdtEntry nullDescriptor = { 0, 0, 0, 0 };
    gdtEntry kmCodeSegment = { 0, 0xFFFFF, 0x9A, 0xA };
    gdtEntry kmDataSegment = { 0, 0xFFFFF, 0x92, 0xC };
    gdtEntry umCodeSegment = { 0, 0xFFFFF, 0xFA, 0xA };
    gdtEntry umDataSegment = { 0, 0xFFFFF, 0xF2, 0xC };

    uint8_t gdt[5 * 8];

    encodeGdtEntry(gdt, nullDescriptor);
    encodeGdtEntry(gdt + 0x08, kmCodeSegment);
    encodeGdtEntry(gdt + 0x10, kmDataSegment);
    encodeGdtEntry(gdt + 0x18, umCodeSegment);
    encodeGdtEntry(gdt + 0x20, umDataSegment);

    gdtPtr *gdtr;
    gdtr->base = (uint64_t)&gdt;
    gdtr->limit = sizeof(gdt) - 1;

    loadGDT(&gdtr);

    clear(fb, 0x000000);
}

void encodeGdtEntry(uint8_t *target, gdtEntry source) {
    if (source.limit > 0xFFFFF) return;
    target[0] = source.limit & 0xFF;
    target[1] = (source.limit >> 8) & 0xFF;
    target[6] = (source.limit >> 16) & 0x0F;
    target[2] = source.base & 0xFF;
    target[3] = (source.base >> 8) & 0xFF;
    target[4] = (source.base >> 16) & 0xFF;
    target[7] = (source.base >> 24) & 0xFF;
    target[5] = source.accessByte;
    target[6] |= (source.flags << 4);
}