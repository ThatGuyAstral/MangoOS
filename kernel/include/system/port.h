#pragma once
#include <stdint.h>

inline uint8_t inb(uint16_t port);
inline void outb(uint8_t value, uint16_t port);