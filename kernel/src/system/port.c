#include <system/port.h>

inline uint8_t inb(uint16_t port) {
    uint8_t val;
    asm volatile("inb %1, %0" : "=a"(val) : "Nd"(port));
    return val;
}

inline void outb(uint8_t value, uint16_t port) {
    asm volatile("outb %0, %1" : "a"(value) : "Nd"(port));
}