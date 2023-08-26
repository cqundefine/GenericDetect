#include "GenericDetect.h"

#ifdef NO_EXTERNAL_INCLUDES
int printf(const char*, ...);
#else
#include <stdio.h>
#endif

#if defined(GD_OS_GENERIC_UNIX)
#define UNIX "yes"
#else
#define UNIX "no"
#endif

#if defined(GD_OS_GENERIC_BSD)
#define BSD "yes"
#else
#define BSD "no"
#endif

#if defined(GD_OS_GENERIC_SUN)
#define SUN "yes"
#else
#define SUN "no"
#endif

#if defined(GD_OS_GENERIC_APPLE)
#define APPLE "yes"
#else
#define APPLE "no"
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
    printf("  - Unix: %s\n", UNIX);
    printf("  - BSD: %s\n", BSD);
    printf("  - Sun: %s\n", SUN);
    printf("  - Apple: %s\n", APPLE);
    return 0;
}
