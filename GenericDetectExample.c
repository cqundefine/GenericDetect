#include "GenericDetect.h"

#ifdef NO_EXTERNAL_INCLUDES
int printf(const char*, ...);
#else
#include <stdio.h>
#endif

int main(void)
{
    printf("GenericDetect machine info:\n");
    printf("- Operating system: %s\n", GD_OS_NAME);
    printf("- Architecture: %s\n", GD_ARCH_NAME);
    printf("- Architecture version: %s\n", GD_ARCH_VERSION_NAME);
    printf("- Bits: %u\n", GD_BITS);
    printf("- Compiler: %s\n", GD_COMPILER_NAME);
    printf("- Compiler version: %u.%u.%u\n", GD_COMPILER_VERSION_MAJOR(GD_COMPILER_VERSION), GD_COMPILER_VERSION_MINOR(GD_COMPILER_VERSION), GD_COMPILER_VERSION_PATCH(GD_COMPILER_VERSION));
    printf("- OS type groups:\n");
    printf("  - Unix: %s\n", (GD_IS_OS_UNIX ? "yes" : "no"));
    printf("  - BSD: %s\n", (GD_IS_OS_BSD ? "yes" : "no"));
    printf("  - Sun: %s\n", (GD_IS_OS_SUN ? "yes" : "no"));
    printf("  - Apple: %s\n", (GD_IS_OS_APPLE ? "yes" : "no"));
    return 0;
}
