#include <system/idt.h>

IDTGate idt[256];
IDTPtr idtr;

void setIDTGate(int n, uint64_t handler) {
    idt[n].offsetLow = (uint16_t)(handler >> 0);
    idt[n].selector = 0x08;
    idt[n].always0 = 0;
    idt[n].flags = 0x8E;
    idt[n].offsetMid = (uint16_t)(handler >> 16);
    idt[n].offset = (uint16_t)(handler >> 32);
    idt[n].always0again = 0;
}

void enableInterrupts() {
    asm volatile("sti");
}

void disableInterrupts() {
    asm volatile("cli");
}

void InitializeIDT() {
    idtr.size_16 = 256 * sizeof(IDTGate) - 1;
    idtr.offset_64 = (uint64_t)&idt;
    asm volatile("lidtq %0" : "=m"(idtr));
}