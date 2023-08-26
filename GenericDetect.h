/*
 * The MIT License (MIT)
 * 
 * Copyright (c) 2023 Undefine <cqundefine@gmail.com>
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 * 
 * 
 * 
 * A simple header only library for detecting stuff like the target operating
 * system, the compiler, etc.
 * 
 * To check if using a compiler check if any of the macros listed below are
 * defined or use the GD_IS_COMPILER(x) macro with the compiler as a parameter,
 * e.g. GD_IS_COMPILER(GCC) to check for GCC.
 * 
 * Supported compilers:
 *  - Clang:            GD_COMPILER_CLANG
 *  - CodeWarrior:      GD_COMPILER_CODEWARRIOR
 *  - GCC:              GD_COMPILER_GCC
 *  - Green Hill C/C++: GD_COMPILER_GREEN_HILL
 *  - ICC:              GD_COMPILER_ICC
 *  - MSVC:             GD_COMPILER_MSVC
 *  - SDCC:             GD_COMPILER_SDCC
 * 
 * For convenience there is a GD_COMPILER_NAME which is defined with the with the
 * name of the used compiler, e.g. GD_COMPILER_NAME is "GCC" is GD_COMPILER_GCC is defined.
 * 
 * Every compiler's version is normalized into the same format which is: 0xAABBCCCC
 * (AA - major, BB - minor, CCCC - patch). For creating versions there is
 * a GD_MAKE_COMPILER_VERSION macro, and for extracting there are
 * GD_COMPILER_VERSION_MAJOR, GD_COMPILER_VERSION_MINOR and GD_COMPILER_VERSION_PATCH
 * macros. Each compiler defines GD_COMPILER_VERSION.
 * 
 * To check if building for an operating system check if any of the macros
 * listed below are defined or use the GD_IS_OS(x) macro with the operating
 * system as a parameter, e.g. GD_IS_OS(SOLARIS) to check for solaris.
 * 
 * Supported operating systems:
 *  - 386BSD:           GD_OS_386BSD
 *  - AIX:              GD_OS_AIX
 *  - Amiga Unix:       GD_OS_AMIX
 *  - Android:          GD_OS_ANDROID
 *  - BeOS:             GD_OS_BEOS
 *  - DragonFly BSD:    GD_OS_DRAGONFLY
 *  - FreeBSD:          GD_OS_FREEBSD
 *  - GNU/Hurd:         GD_OS_HURD
 *  - HP-UX:            GD_OS_HPUX
 *  - illumos:          GD_OS_ILLUMOS
 *  - iOS:              GD_OS_IOS
 *  - IPhone Simulator: GD_OS_IPHONE_SIMULATOR
 *  - IRIX:             GD_OS_IRIX
 *  - Linux:            GD_OS_LINUX
 *  - Mac Catalyst:     GD_OS_MACCATALYST
 *  - MacOS:            GD_OS_MACOS
 *  - MINIX:            GD_OS_MINIX
 *  - MS-DOS:           GD_OS_MSDOS
 *  - NetBSD:           GD_OS_NETBSD
 *  - NeXTSTEP:         GD_OS_NEXTSTEP
 *  - OpenBSD:          GD_OS_OPENBSD
 *  - OS/2:             GD_OS_OS2
 *  - Plan 9:           GD_OS_PLAN9
 *  - SerenityOS:       GD_OS_SERENITY
 *  - Solaris:          GD_OS_SOLARIS
 *  - SunOS:            GD_OS_SUNOS
 *  - Windows:          GD_OS_WINDOWS
 * 
 * Additional generic operating system defines:
 *  - Generic Unix (GD_OS_GENERIC_UNIX) defined by:
 *    - AIX, Amiga Unix, Android, DragonFly BSD, FreeBSD, GNU/Hurd, HP-UX, illumos,
 *      IRIX, Linux, MacOS, MINIX, NetBSD, NeXTSTEP, OpenBSD, Plan 9, SerenityOS, Solaris,
 *      SunOS, others if __unix__ is defined
 *  - Generic BSD (GD_OS_GENERIC_BSD) defined by:
 *    - 386BSD, DragonFly BSD, FreeBSD, NetBSD, OpenBSD
 *  - Generic Sun (GD_OS_GENERIC_SUN) defined by:
 *    - illumos, Solaris, SunOS
 *  - Generic Apple (GD_OS_GENERIC_APPLE) defined by:
 *    - iOS, IPhone Simulator, Mac Catalyst, MacOS
 * 
 * Similarly as with the compiler there is a GD_OS_NAME macro.
 * 
 * To detect the target architecture check if any of the below listed macros
 * are defined or use the GD_IS_ARCH(arch) macro in the same way as with the
 * compiler and the operating system.
 * 
 * Supported architectures:
 *  - AArch64:      GD_ARCH_AARCH64
 *  - Alpha:        GD_ARCH_ALPHA
 *  - Convex:       GD_ARCH_CONVEX
 *  - ARM:          GD_ARCH_ARM
 *  - HPPA:         GD_ARCH_HPPA
 *  - Itanium:      GD_ARCH_ITANIUM
 *  - LoongArch:    GD_ARCH_LOONGARCH
 *  - MIPS:         GD_ARCH_MIPS
 *    - MIPS:       GD_ARCH_MIPS32
 *    - MIPS64:     GD_ARCH_MIPS64
 *  - Motorola 68k: GD_ARCH_M68K
 *  - PowerPC:      GD_ARCH_POWERPC
 *    - PowerPC:    GD_ARCH_POWERPC32
 *    - PowerPC64:  GD_ARCH_POWERPC64
 *  - RISC-V:       GD_ARCH_RISCV
 *    - RISC-V 32:  GD_ARCH_RISCV32
 *    - RISC-V 64:  GD_ARCH_RISCV64
 *  - SPARC:        GD_ARCH_SPARC
 *  - x86:          GD_ARCH_X86
 *    - i386:       GD_ARCH_I386
 *    - i486:       GD_ARCH_I486
 *    - i586:       GD_ARCH_I586
 *    - i686:       GD_ARCH_I686
 *  - x86_64:       GD_ARCH_X86_64
 * 
 * There is also a GD_ARCH_NAME macro defined.
 * 
 * For some architectures there are GD_ARCH_VERSION and GD_ARCH_VERSION_NAME
 * macros defined. Their values are architecture specific.
 * 
 * For detecting the bit count of a architecture you can use the GD_BITS macro.
 * 
 * Library options:
 *  - GD_ANDROID_IS_NOT_LINUX - do not define GD_OS_LINUX if building for Android
 *  - GD_NO_CUSTOM_WARNINGS - do not use #warning as some compilers / standards
 *    do not support it
 *  - GD_NO_EXTERNAL_INCLUDES - do not include any external headers, might cause
 *    inaccuracies and inability to detect some platfors
 */

#ifndef GENERIC_DETECT_H_
#define GENERIC_DETECT_H_

/* Options */

/* Do not detect android as linux */
#ifndef GD_ANDROID_IS_NOT_LINUX
    #define GD_ANDROID_IS_NOT_LINUX 0
#endif

/* Do not use #warning */
#ifndef GD_NO_CUSTOM_WARNINGS
    #define GD_NO_CUSTOM_WARNINGS 0
#endif

/* Do not use #include */
#ifndef GD_NO_EXTERNAL_INCLUDES
    #define GD_NO_EXTERNAL_INCLUDES 0
#endif

/* Compiler detection */

#define GD_IS_COMPILER(compiler) (defined(GD_COMPILER_##compiler))

#define GD_MAKE_COMPILER_VERSION(major,minor,patch) (((major) << 24) + ((minor) << 16) + (patch))
#define GD_COMPILER_VERSION_MAJOR(version) (version >> 24)
#define GD_COMPILER_VERSION_MINOR(version) ((version >> 16) & 0xFF)
#define GD_COMPILER_VERSION_PATCH(version) (version & 0xFFFF)

#ifdef __clang__ /* Clang */
    #define GD_COMPILER_CLANG
    #define GD_COMPILER_NAME "Clang"
    #define GD_COMPILER_VERSION GD_MAKE_COMPILER_VERSION(__clang_major__, __clang_minor__, __clang_patchlevel__)
#endif

#if defined(__MWERKS__) || defined(__CWCC__) /* CodeWarrior */
    #define GD_COMPILER_CODEWARRIOR
    #define GD_COMPILER_NAME "CodeWarrior"
    #if __MWERKS__ == 1
        #define GD_COMPILER_VERSION GD_MAKE_COMPILER_VERSION(1, 0, 0)
    #else
        #define GD_COMPILER_VERSION GD_MAKE_COMPILER_VERSION(__MWERKS__ >> 24, (__MWERKS__ >> 16) & 8, __MWERKS__ & 16)
    #endif
#endif

#ifdef __DMC__ /* Digital Mars */
    #define GD_COMPILER_DIGITALMARS
    #define GD_COMPILER_NAME "Digital Mars"
    #define GD_COMPILER_VERSION GD_MAKE_COMPILER_VERSION(__DMC__ >> 16, (__DMC__ >> 8) & 8, __DMC__ & 8)
#endif

#ifdef __ghs__ /* Green Hill C/C++ */
    #define GD_COMPILER_GREEN_HILL
    #define GD_COMPILER_NAME "Green Hill C/C++"
    #define GD_COMPILER_VERSION GD_MAKE_COMPILER_VERSION(__GHS_VERSION_NUMBER__ / 100, (__GHS_VERSION_NUMBER__ / 10) % 10, __GHS_VERSION_NUMBER__ % 10)
#endif

#if defined(__INTEL_COMPILER) || defined(__ICC) || defined(__ECC) || defined(__ICL) /* ICC */
    #define GD_COMPILER_ICC
    #define GC_COMPILER_NAME "ICC"
    #define GD_COMPILER_VERSION (__INTEL_COMPILER < 2000 ? GD_MAKE_COMPILER_VERSION(__INTEL_COMPILER / 100, __INTEL_COMPILER % 100, __INTEL_COMPILER_UPDATE) : GD_MAKE_COMPILER_VERSION(__INTEL_COMPILER, __INTEL_COMPILER_UPDATE, 0))
#endif

/* NOTE: This is not in order for a reason, because Clang and ICC also define __GNUC__ */
#ifdef __GNUC__ /* GCC */
    #ifndef GD_COMPILER_NAME
        #define GD_COMPILER_GCC
        #define GD_COMPILER_NAME "GCC"
        #ifndef __GNUC_MINOR__
            #define GD_COMPILER_VERSION GD_MAKE_COMPILER_VERSION(__GNUC__, 0, 0)
        #elif !defined(__GNUC_PATCHLEVEL__)
            #define GD_COMPILER_VERSION GD_MAKE_COMPILER_VERSION(__GNUC__, __GNUC_MINOR__, 0)
        #else
            #define GD_COMPILER_VERSION GD_MAKE_COMPILER_VERSION(__GNUC__, __GNUC_MINOR__, __GNUC_PATCHLEVEL__)
        #endif
    #endif
#endif

#ifdef _MSC_VER /* MSVC / Visual Studio */
    #ifndef GD_COMPILER_NAME
        #define GD_COMPILER_MSVC
        #define GD_COMPILER_NAME "MSVC"
        #ifdef _MSC_FULL_VER
            #define GD_COMPILER_VERSION (_MSC_FULL_VER < 100000000 ? GD_MAKE_COMPILER_VERSION(_MSC_FULL_VER / 1000000, (_MSC_FULL_VER % 1000000) / 10000, _MSC_FULL_VER % 10000) : GD_MAKE_COMPILER_VERSION(_MSC_FULL_VER / 10000000, (_MSC_FULL_VER % 10000000) / 10000, _MSC_FULL_VER % 100000))
        #else
            #define GD_COMPILER_VERSION GD_MAKE_COMPILER_VERSION(_MSC_VER / 100, _MSC_VER % 100, 0)
        #endif
    #endif
#endif

#if defined(__SDCC) || defined(SDCC) /* SDCC */
    #define GD_COMPILER_SDCC
    #define GD_COMPILER_NAME "SDCC"
    #define GD_COMPILER_VERSION GD_MAKE_COMPILER_VERSION(__SDCC_VERSION_MAJOR, __SDCC_VERSION_MINOR, __SDCC_VERSION_PATCH)
#endif

#ifndef GD_COMPILER_NAME
    #if !GD_NO_CUSTOM_WARNINGS
        #warning "Unknown compiler"
    #endif
    #define GD_COMPILER_NAME "Unknown"
    #define GD_COMPILER_VERSION GD_MAKE_COMPILER_VERSION(1, 0, 0)
#endif

#ifndef GD_COMPILER_VERSION
    #define GD_COMPILER_VERSION GD_MAKE_COMPILER_VERSION(1, 0, 0)
#endif

/* OS detection */

#define GD_IS_OS(os) (defined(GD_OS_##os))

#if defined(____386BSD____) || defined(__386BSD__) /* 386BSD */
    #define GD_OS_386BSD
    #define GD_OS_GENERIC_BSD
    #define GD_OS_GENERIC_UNIX
    #define GD_OS_NAME "386BSD"
#endif

#if defined(_AIX) || defined(__TOS_AIX__) /* AIX */
    #define GD_OS_AIX
    #define GD_OS_GENERIC_UNIX
    #define GD_OS_NAME "AIX"
#endif

#ifdef AMIX /* Amiga Unix / AMIX */
    #define GD_OS_AMIX
    #define GD_OS_GENERIC_UNIX
    #define GD_OS_NAME "Amiga Unix"
#endif

#ifdef __ANDROID__ /* Android */
    #define GD_OS_ANDROID
    #if !GD_ANDROID_IS_NOT_LINUX
        #define GD_OS_LINUX
    #endif
    #define GD_OS_GENERIC_UNIX
    #define GD_OS_NAME "Android"
#endif

#ifdef __BEOS__ /* BeOS */
    #define GD_OS_BEOS
    #define GD_OS_GENERIC_UNIX
    #define GD_OS_NAME "BeOS"
#endif

#ifdef __DragonFly__ /* DragonFly BSD */
    #define GD_OS_DRAGONFLY
    #define GD_OS_GENERIC_BSD
    #define GD_OS_GENERIC_UNIX
    #define GD_OS_NAME "DragonFly BSD"
#endif

#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) /* FreeBSD */
    #define GD_OS_FREEBSD
    #define GD_OS_GENERIC_BSD
    #define GD_OS_GENERIC_UNIX
    #define GD_OS_NAME "FreeBSD"
#endif

#ifdef __gnu_hurd__ /* GNU/Hurd */
    #define GD_OS_HURD
    #define GD_OS_GENERIC_UNIX
    #define GD_OS_NAME "GNU/Hurd"
#endif

#if defined(_hpux) || defined(hpux) || defined(__hpux) /* HP-UX */
    #define GD_OS_HPUX
    #define GD_OS_GENERIC_UNIX
    #define GD_OS_NAME "HP-UX"
#endif

#if defined(sgi) || defined(__sgi) /* IRIX */
    #define GD_OS_IRIX
    #define GD_OS_GENERIC_UNIX
    #define GD_OS_NAME "IRIX"
#endif

#if defined(__linux__) || defined(linux) || defined(__linux) /* Linux */
    #if !(defined(GD_OS_ANDROID) && GD_ANDROID_IS_NOT_LINUX)
        #define GD_OS_LINUX
        #define GD_OS_GENERIC_UNIX
    #endif
    #ifndef GD_OS_NAME
        #define GD_OS_NAME "Linux"
    #endif
#endif

#if (defined(__APPLE__) && defined(__MACH__)) || defined(macintosh) || defined(Macintosh) /* MacOS */
        #define GD_OS_MACOS
        #define GD_OS_GENERIC_APPLE
        #define GD_OS_GENERIC_UNIX
        #define GD_OS_NAME "MacOS"
#elif defined(__APPLE__) || !defined(GD_NO_EXTERNAL_INCLUDES)
    #include <TargetConditionals.h>
    #if TARGET_IPHONE_SIMULATOR
        #define GD_OS_IPHONE_SIMULATOR
        #define GD_OS_GENERIC_APPLE
        #define GD_OS_NAME "IPhone Simulator"
    #elif TARGET_OS_MACCATALYST
        #define GD_OS_MACCATALYST
        #define GD_OS_GENERIC_APPLE
        #define GD_OS_NAME "Mac Catalyst"
    #elif TARGET_OS_IPHONE
        #define GD_OS_IOS
        #define GD_OS_GENERIC_APPLE
        #define GD_OS_NAME "iOS"
    #else
        #if !GD_NO_CUSTOM_WARNINGS
            #warning "Unknown architecture"
        #endif
    #endif
#endif

#ifdef __minix /* MINIX */
    #define GD_OS_MINIX
    #define GD_OS_GENERIC_UNIX
    #define GD_OS_NAME "MINIX"
#endif

#if defined(MSDOS) || defined(__MSDOS__) || defined(_MSDOS) || defined(__DOS__) /* MS-DOS */
    #define GD_OS_MSDOS
    #define GD_OS_NAME "MS-DOS"
#endif

#ifdef __NetBSD__ /* NetBSD */
    #define GD_OS_NETBSD
    #define GD_OS_GENERIC_BSD
    #define GD_OS_GENERIC_UNIX
    #define GD_OS_NAME "NetBSD"
#endif

#ifdef NeXT /* NeXTSTEP */
    #define GD_OS_NEXTSTEP
    #define GD_OS_GENERIC_UNIX
    #define GD_OS_NAME "NeXTSTEP"
#endif

#ifdef __OpenBSD__ /* OpenBSD */
    #define GD_OS_OPENBSD
    #define GD_OS_GENERIC_BSD
    #define GD_OS_GENERIC_UNIX
    #define GD_OS_NAME "OpenBSD"
#endif

#if defined(OS2) || defined(_OS2) || defined(__OS2__) || defined(__TOS_OS2__) /* OS/2 */
    #define GD_OS_OS2
    #define GD_OS_NAME "OS/2"
#endif

#if defined(EPLAN9) /* Plan 9 */
    #define GD_OS_PLAN9
    #define GD_OS_GENERIC_UNIX
    #define GD_OS_NAME "Plan 9"
#endif

#ifdef __serenity__ /* SerenityOS */
    #define GD_OS_SERENITY
    #define GD_OS_GENERIC_UNIX
    #define GD_OS_NAME "SerenityOS"
#endif

#if defined(sun) || defined(__sun) /* Solaris / SunOS */
    #define GD_OS_GENERIC_SUN
    #define GD_OS_GENERIC_UNIX
    #if defined(__illumos__)
        #define GD_OS_ILLUMOS
        #define GD_OS_NAME "illumos"
    #elif defined(__SVR4) || defined(__svr4__)
        #define GD_OS_SOLARIS
        #define GD_OS_NAME "Solaris"
    #else
        #define GD_OS_SUNOS
        #define GD_OS_NAME "SunOS"
    #endif
#endif

#if defined(_WIN16) || defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__) /* Windows */
    #define GD_OS_WINDOWS
    #define GD_OS_NAME "Windows"
#endif

#ifndef GD_OS_NAME
    #if defined(__sysv__) || defined(__SVR4) || defined(__svr4__) || defined(_SYSTYPE_SVR4) /* Generic System V Unix*/
        #define GD_OS_GENERIC_UNIX
        #define GD_OS_NAME "Unknown System V Unix"
    #elif defined(__unix__) || defined(__unix) || defined(unix) || defined(_POSIX_VERSION) || defined(_XOPEN_VERSION) || defined(_XOPEN_UNIX) /* Generic Unix */
        #define GD_OS_GENERIC_UNIX
        #define GD_OS_NAME "Unknown Unix"
    #else
        #if !GD_NO_CUSTOM_WARNINGS
            #warning "Unknown operating system"
        #endif
        #define GD_OS_NAME "Unknown"
    #endif
#endif

/* Archictecture detection */

#define GD_IS_ARCH(arch) (defined(GD_ARCH_##arch))

#if defined(__aarch64__) || defined(_M_ARM64) /* AArch64 */
    #define GD_ARCH_AARCH64
    #define GD_ARCH_NAME "AArch64"
    #define GD_BITS 64
#endif

#if defined(__alpha__) || defined(__alpha) || defined(_M_ALPHA) /* Alpha */
    #define GD_ARCH_ALPHA
    #define GD_ARCH_NAME "Alpha"
    #define GD_BITS 64
#endif

#if defined(__arm__) || defined(__thumb__) || defined(__TARGET_ARCH_ARM) \
  || defined(__TARGET_ARCH_THUMB) || defined(_ARM) || defined(_M_ARM) \
  || defined(_M_ARMT) || defined(__arm) || defined(arm) || defined(__arm32__) \
  || defined(arm32) /* ARM */
    #define GD_ARCH_ARM
    #define GD_ARCH_NAME "ARM"
    #define GD_BITS 32
#endif

#ifdef __convex__ /* Convex */
    #define GD_ARCH_CONVEX
    #define GD_ARCH_NAME "Convex"
#endif

#if defined(__hppa__) || defined(__HPPA__) || defined(__hppa) /* HPPA */
    #define GD_ARCH_HPPA
    #define GD_ARCH_NAME "HPPA"
#endif

#if defined(__ia64__) || defined(_IA64) || defined(__IA64__) || defined(__ia64) \
 || defined(_M_IA64) || defined(__itanium__) /* Itanium */
    #define GD_ARCH_ITANIUM
    #define GD_ARCH_NAME "Itanium"
    #define GD_BITS 64
#endif

#ifdef __loongarch__ /* LoongArch */
    #define GD_ARCH_LOONGARCH
    #define GD_ARCH_NAME "LoongArch"
    #define GD_BITS __loongarch_grlen
#endif

#if defined(__mips__) || defined(mips) || defined(__mips) || defined(__MIPS__) /* MIPS */
    #define GD_ARCH_MIPS
    #if defined(__LP64__) || defined(_LP64)
        #define GD_ARCH_MIPS64
        #define GD_ARCH_NAME "MIPS64"
        #define GD_BITS 64
    #else
        #define GD_ARCH_MIPS32
        #define GD_ARCH_NAME "MIPS"
        #define GD_BITS 32
    #endif
#endif

#if defined(__m68k__) || defined(M68000) || defined(__MC68K__) || defined(mc68000) || defined(m68k) \
 || defined(m68) || defined(mc68k) /* Motorola 68k */
    #define GD_ARCH_M68K
    #define GD_ARCH_NAME "Motorola 68k"
#endif

#if defined(__powerpc64__) || defined(__ppc64__) || defined(__PPC64__) || defined(_ARCH_PPC64) /* PowerPC64 */
    #define GD_ARCH_POWERPC
    #define GD_ARCH_POWERPC64
    #define GD_ARCH_NAME "PowerPC64"
    #define GD_BITS 64
#elif defined(__powerpc) || defined(__powerpc__) || defined(__POWERPC__) || defined(__ppc__) \
   || defined(__PPC__) || defined(_ARCH_PPC) /* PowerPC */
    #define GD_ARCH_POWERPC
    #define GD_ARCH_POWERPC32
    #define GD_ARCH_NAME "PowerPC"
    #define GD_BITS 32
#endif

#ifdef __riscv /* RISC-V */
    #define GD_ARCH_RISCV
    #define GD_ARCH_NAME "RISC-V"
    #if defined(__riscv_32len)
        #define GD_ARCH_RISCV32
        #define GD_ARCH_VERSION_NAME "RISC-V 32"
        #define GD_BITS 32
    #elif defined(__riscv_64len)
        #define GD_ARCH_RISCV64
        #define GD_ARCH_VERSION_NAME "RISC-V 64"
        #define GD_BITS 64
    #endif
#endif

#if defined(__sparc__) || defined(__sparc) /* SPARC */
    #define GD_ARCH_SPARC
    #define GD_ARCH_NAME "SPARC"
#endif

#if defined(i386) || defined(__i386) || defined(__i386__) || defined(__IA32__) \
 || defined(_M_I86) || defined(_M_IX86) || defined(__X86__) || defined(_X86_) \
 || defined(__THW_INTEL__) || defined(__I86__) || defined(__INTEL__) || defined(__386) \
 || defined(_I386) || defined(sun386) /* x86 */
    #define GD_ARCH_X86
    #define GD_ARCH_NAME "x86"
    #if defined(__i686__) || _M_IX86 == 600 || __I86__ == 6
        #define GD_ARCH_I686
        #define GD_ARCH_VERSION 6
        #define GD_ARCH_VERSION_NAME "i686"
        #define GD_BITS 32
    #elif defined(__i585__) || _M_IX86 == 500 || __I86__ == 5
        #define GD_ARCH_I586
        #define GD_ARCH_VERSION 5
        #define GD_ARCH_VERSION_NAME "i586"
        #define GD_BITS 32
    #elif defined(__i486__) || _M_IX86 == 400 || __I86__ == 4
        #define GD_ARCH_I486
        #define GD_ARCH_VERSION 4
        #define GD_ARCH_VERSION_NAME "i486"
        #define GD_BITS 32
    #elif defined(__i386__) || _M_IX86 == 300 || __I86__ == 3
        #define GD_ARCH_I386
        #define GD_ARCH_VERSION 3
        #define GD_ARCH_VERSION_NAME "i386"
        #define GD_BITS 32
    #elif defined(__386__) || defined(_M_I386)
        #define GD_BITS 32
    #elif defined(_M_I86)
        #define GD_BITS 16
    #else
        #if !GD_NO_CUSTOM_WARNINGS
            #warning "Failed to identify x86 bit count, assuming 32..."
        #endif
        #define GD_BITS 32
    #endif
#endif

#if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) \
 || defined(_M_X64) || defined(_M_AMD64) /* x86_64 */
    #define GD_ARCH_X86_64
    #define GD_ARCH_NAME "x86_64"
    #define GD_BITS 64
#endif

#ifndef GD_ARCH_NAME
    #if !GD_NO_CUSTOM_WARNINGS
        #warning "Unknown architecture"
    #endif
    #define GD_ARCH_NAME "Unknown"
#endif

#ifndef GD_ARCH_VERSION
    #define GD_ARCH_VERSION 1
    #define GD_ARCH_VERSION_NAME ""
#endif

#if !defined(GD_BITS) && (defined(__LP64__) || defined(_LP64))
    #define GD_BITS 64
#endif

#ifndef GD_BITS
    #define GD_BITS -1
#endif

#endif
