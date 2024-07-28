#pragma once
#include <system/gdt.h>

typedef struct {
    uint16_t size_16;
    uint64_t offset_64;
} __attribute__((packed)) IDTPtr;

typedef struct {
    uint16_t offsetLow;
    uint16_t selector;
    uint8_t always0;
    uint8_t flags;
    uint16_t offsetMid;
    uint32_t offset;
    uint32_t always0again;
} __attribute__((packed)) IDTGate;

void InitializeIDT();
void enableInterrupts();
void disableInterrupts();
void setIDTGate(int n, uint64_t handler);