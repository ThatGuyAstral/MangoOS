#pragma once
#include <system/gdt.h>

typedef struct {
    uint16_t size;
    uint64_t offset;
} __attribute__((packed)) IDTDescriptor;