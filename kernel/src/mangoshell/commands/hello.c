#include "commands.h"

void hello(struct flanterm_context *ftctx/*int argc, char** argv*/)
{
    printf(ftctx, "Hello!");
}