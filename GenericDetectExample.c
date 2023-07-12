/*#include <stdio.h>*/
#include "GenericDetect.h"

int printf(const char*, ...);

int main(void)
{
    printf("Hello from GenericDetectExample running on %s for %s (%s) - a %u bit machine built with %s %u.%u.%u!\n", GD_OS_NAME, GD_ARCH_NAME, GD_ARCH_VERSION_NAME, GD_BITS, GD_COMPILER_NAME, GD_COMPILER_VERSION_MAJOR(GD_COMPILER_VERSION), GD_COMPILER_VERSION_MINOR(GD_COMPILER_VERSION), GD_COMPILER_VERSION_PATCH(GD_COMPILER_VERSION));
    return 0;
}
