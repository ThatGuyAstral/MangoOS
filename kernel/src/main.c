#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <limine.h>
#include <main.h>
#include <system/smem.h>
// Set the base revision to 2, this is recommended as this is the latest
// base revision described by the Limine boot protocol specification.
// See specification for further info.

__attribute__((used, section(".requests")))
static volatile LIMINE_BASE_REVISION(2);

// The Limine requests can be placed anywhere, but it is important that
// the compiler does not optimise them away, so, usually, they should
// be made volatile or equivalent, _and_ they should be accessed at least
// once or marked as used with the "used" attribute as done here.

__attribute__((used, section(".requests")))
static volatile struct limine_framebuffer_request framebuffer_request = {
    .id = LIMINE_FRAMEBUFFER_REQUEST,
    .revision = 0
};

// Finally, define the start and end markers for the Limine requests.
// These can also be moved anywhere, to any .c file, as seen fit.

__attribute__((used, section(".requests_start_marker")))
static volatile LIMINE_REQUESTS_START_MARKER;

__attribute__((used, section(".requests_end_marker")))
static volatile LIMINE_REQUESTS_END_MARKER;

// Halt and catch fire function.
static void hcf(void) {
    asm("cli");
    for (;;) {
        asm("hlt");
    }
}

void log(struct flanterm_context *ftctx, int type, const char *msg) {
    switch (type) {
        // OK
        case 0:
            flanterm_write(ftctx, "\e[0m[  \e[32mOK\e[0m  ] ");
            flanterm_write(ftctx, msg);
            break;
    
        // WARN
        case 1:
            flanterm_write(ftctx, "\e[0m[ \e[33mWARN\e[0m ] ");
            flanterm_write(ftctx, msg);
            break;

        // ERROR
        case 2:
            flanterm_write(ftctx, "\e[0m[ \e[31mERROR\e[0m ] ");
            flanterm_write(ftctx, msg);
            break;

        // INFO
        case 3:
            flanterm_write(ftctx, "\e[0m[ \e[36mINFO\e[0m ] ");
            flanterm_write(ftctx, msg);
            break;

        default:
            flanterm_write(ftctx, msg);
            break;
    }
}

void _start(void) {
    // Ensure the bootloader actually understands our base revision (see spec).
    if (LIMINE_BASE_REVISION_SUPPORTED == false) {
        hcf();
    }

    // Ensure we got a framebuffer.
    if (framebuffer_request.response == NULL
     || framebuffer_request.response->framebuffer_count < 1) {
        hcf();
    }

    // Fetch the first framebuffer.
    fb = framebuffer_request.response->framebuffers[0];

    InitializeGDT();

    ftctx = flanterm_fb_init(NULL, NULL, fb->address, fb->width, fb->height, fb->pitch, fb->red_mask_size, fb->red_mask_shift, fb->green_mask_size, fb->green_mask_shift, fb->blue_mask_size, fb->blue_mask_shift, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 1, 0, 0, 0);

    flanterm_write(ftctx, "\e[33mmangoOS\e[0m version 0.1.0\n");
    flanterm_write(ftctx, "written with love by cosmicDev (https://github.com/ThatGuyAstral)");

    hcf();
}

