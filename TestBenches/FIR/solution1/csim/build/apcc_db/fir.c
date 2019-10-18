/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;

/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void FIR_filter(double *llvm_cbe_result, double llvm_cbe_input, signed short llvm_cbe_do_filter);


/* Global Variable Definitions and Initialization */
static double aesl_internal_shift[309];
static double aesl_internal_taps[309] = { 0x1.92cd060063217p-15, -0x1.2aef65ffe61cdp-14, -0x1.464420002cf1ep-13, -0x1.50b2bdffd520ap-13, -0x1.5633d20007664p-14, 0x1.66e3aa000e83bp-15, 0x1.390af5ffd62ccp-13, 0x1.7c86dffff0c71p-13, 0x1.f3bb920023554p-14, -0x1.3d34460247d06p-17, -0x1.259be5ffeee84p-13, -0x1.aaedebfff7ee2p-13, -0x1.54ace1fff5a1ep-13, -0x1.0b13efffb8de6p-15, 0x1.05611c0018481p-13, 0x1.d866e4002923cp-13, 0x1.bd0ec7ffdbf27p-13, 0x1.60ae3fffd52f3p-14, -0x1.9fe3f0003f0d9p-14, -0x1.fe5141ffdd042p-13, -0x1.18c9c9fffd38bp-12, -0x1.39cdf4001c916p-13, 0x1.efaae5ff6e608p-15, 0x1.098c4bffe97d6p-12, 0x1.569c92000cf76p-12, 0x1.e19ce40018259p-13, 0x0p0, -0x1.055c4400013ccp-12, -0x1.938cf3fffc4fap-12, -0x1.535d99ffec171p-12, -0x1.5788dc003041cp-14, 0x1.d7963bffe05acp-13, 0x1.c939fc000c21dp-12, 0x1.c1e741fff8177p-12, 0x1.8cb4960009897p-13, -0x1.6ba60bffdbfd1p-13, -0x1.ef88ba0009618p-12, -0x1.1ba6dffff9224p-11, -0x1.521b8a000a7b7p-12, 0x1.7399c2001b4d5p-14, 0x1.fd09ffffef0a4p-12, 0x1.55f4280004a93p-11, 0x1.f7518ffff5966p-12, 0x1.226029ffe0e7cp-15, -0x1.e78f36001241dp-12, -0x1.8ace29fffb901p-11, -0x1.5896aa0004044p-11, -0x1.a21fb200091e2p-13, 0x1.a4e7c3ffe9afep-12, 0x1.b4172e000899fp-11, 0x1.bbce9dfff6bb5p-11, 0x1.a9e95c000735fp-12, -0x1.2bbdba0008827p-12, -0x1.cae577fff5ec2p-11, -0x1.0fce87fffd884p-10, -0x1.55f5d6000b33p-11, 0x1.d2130c004835fp-14, 0x1.c7e199fff7401p-11, 0x1.3e5bf800030b3p-10, 0x1.e81a24000932p-11, 0x1.0b2530001d87fp-13, -0x1.a3bad800071b5p-11, -0x1.65391a000539fp-10, -0x1.42e605fffdf91p-10, -0x1.c3b391fff5ca9p-12, 0x1.57abf1fff798ap-11, 0x1.7f872e00024fep-10, 0x1.93a319ffff42fp-10, 0x1.a14c780004e0ep-11, -0x1.bc1304000a54p-12, -0x1.88164bfffc10ep-10, -0x1.e15411fffbb76p-10, -0x1.3e7aa3ffff1c8p-10, 0x1.968de1ffe5995p-14, 0x1.79a84bfffc26p-10, 0x1.130b3c0000616p-9, 0x1.b6f426000451dp-10, 0x1.5794fe0009142p-12, -0x1.4f3be200044d8p-10, -0x1.2da047ffff2eap-9, -0x1.1a989c0002752p-9, -0x1.bced95fff5371p-11, 0x1.045bf3ffff8bdp-10, 0x1.3ccd31ffffaep-9, 0x1.5974bffffffe1p-9, 0x1.7e548a00043bfp-10, -0x1.2add9c0005699p-11, -0x1.3cd05bffff4c1p-9, -0x1.9441320002167p-9, -0x1.18ed44000141bp-9, 0x0p0, 0x1.29e7080002998p-9, 0x1.c6989ffffeebp-9, 0x1.79d161fffefa1p-9, 0x1.79ff45fffe838p-11, -0x1.0071720001f8bp-9, -0x1.eb9335fffece8p-9, -0x1.de3f63fffff08p-9, -0x1.a1085c000005dp-10, 0x1.7a25c600030f1p-10, 0x1.fddd21fffd41cp-9, 0x1.20df39ffff5e5p-8, 0x1.54ee01fffdcbcp-9, -0x1.73245c000603ep-11, -0x1.f7c8980002b2cp-9, -0x1.4f7cd60000bc1p-8, -0x1.e9bdc1fffd356p-9, -0x1.185ac60000c7bp-12, 0x1.d3532c000233ap-9, 0x1.77e14bffffc09p-8, 0x1.460cc400006efp-8, 0x1.896be9fffed9ep-10, -0x1.8a11a20002afep-9, -0x1.9683860000e4cp-8, -0x1.9c2f6bfffee2dp-8, -0x1.8a6231fffe8b6p-9, 0x1.14ecd40001d83p-9, 0x1.a7540a0001635p-8, 0x1.f51fbdffff34p-8, 0x1.3b459e00005dcp-8, -0x1.ae216a000b079p-11, -0x1.a588b6000041p-8, -0x1.273a240000a9cp-7, -0x1.c66a5bffffe2ap-8, -0x1.f3e9fffff8fadp-11, 0x1.8b26cdffff8fcp-8, 0x1.52cc7a0000a55p-7, 0x1.34eb48000067cp-7, 0x1.b487a7ffff356p-9, -0x1.50009a00003f3p-8, -0x1.7bf4ddffffd5cp-7, -0x1.95e7e000000eep-7, -0x1.aac7340000587p-8, 0x1.ced69e000062ap-9, 0x1.a167abfffffabp-7, 0x1.0657bc00004a8p-6, 0x1.64770bffffb84p-7, -0x1.d4aab20001046p-11, -0x1.c1edebffffabbp-7, -0x1.53f68000001a6p-6, -0x1.1ab1860000488p-6, -0x1.cf80efffff178p-9, 0x1.dc733c00009f5p-7, 0x1.c6c28c0000456p-6, 0x1.c7b75bffffd3ep-6, 0x1.838db9ffffd86p-7, -0x1.f0123dffffc1cp-7, -0x1.4f4aefffffe66p-5, -0x1.9e9aa0000019ap-5, -0x1.0b91ebffffd5fp-5, 0x1.fc1f1a0000107p-7, 0x1.5ce614000002bp-4, 0x1.445f740000081p-3, 0x1.b5e79dfffff7p-3, 0x1.e02c6e0000015p-3, 0x1.b5e79dfffff7p-3, 0x1.445f740000081p-3, 0x1.5ce614000002bp-4, 0x1.fc1f1a0000107p-7, -0x1.0b91ebffffd5fp-5, -0x1.9e9aa0000019ap-5, -0x1.4f4aefffffe66p-5, -0x1.f0123dffffc1cp-7, 0x1.838db9ffffd86p-7, 0x1.c7b75bffffd3ep-6, 0x1.c6c28c0000456p-6, 0x1.dc733c00009f5p-7, -0x1.cf80efffff178p-9, -0x1.1ab1860000488p-6, -0x1.53f68000001a6p-6, -0x1.c1edebffffabbp-7, -0x1.d4aab20001046p-11, 0x1.64770bffffb84p-7, 0x1.0657bc00004a8p-6, 0x1.a167abfffffabp-7, 0x1.ced69e000062ap-9, -0x1.aac7340000587p-8, -0x1.95e7e000000eep-7, -0x1.7bf4ddffffd5cp-7, -0x1.50009a00003f3p-8, 0x1.b487a7ffff356p-9, 0x1.34eb48000067cp-7, 0x1.52cc7a0000a55p-7, 0x1.8b26cdffff8fcp-8, -0x1.f3e9fffff8fadp-11, -0x1.c66a5bffffe2ap-8, -0x1.273a240000a9cp-7, -0x1.a588b6000041p-8, -0x1.ae216a000b079p-11, 0x1.3b459e00005dcp-8, 0x1.f51fbdffff34p-8, 0x1.a7540a0001635p-8, 0x1.14ecd40001d83p-9, -0x1.8a6231fffe8b6p-9, -0x1.9c2f6bfffee2dp-8, -0x1.9683860000e4cp-8, -0x1.8a11a20002afep-9, 0x1.896be9fffed9ep-10, 0x1.460cc400006efp-8, 0x1.77e14bffffc09p-8, 0x1.d3532c000233ap-9, -0x1.185ac60000c7bp-12, -0x1.e9bdc1fffd356p-9, -0x1.4f7cd60000bc1p-8, -0x1.f7c8980002b2cp-9, -0x1.73245c000603ep-11, 0x1.54ee01fffdcbcp-9, 0x1.20df39ffff5e5p-8, 0x1.fddd21fffd41cp-9, 0x1.7a25c600030f1p-10, -0x1.a1085c000005dp-10, -0x1.de3f63fffff08p-9, -0x1.eb9335fffece8p-9, -0x1.0071720001f8bp-9, 0x1.79ff45fffe838p-11, 0x1.79d161fffefa1p-9, 0x1.c6989ffffeebp-9, 0x1.29e7080002998p-9, 0x0p0, -0x1.18ed44000141bp-9, -0x1.9441320002167p-9, -0x1.3cd05bffff4c1p-9, -0x1.2add9c0005699p-11, 0x1.7e548a00043bfp-10, 0x1.5974bffffffe1p-9, 0x1.3ccd31ffffaep-9, 0x1.045bf3ffff8bdp-10, -0x1.bced95fff5371p-11, -0x1.1a989c0002752p-9, -0x1.2da047ffff2eap-9, -0x1.4f3be200044d8p-10, 0x1.5794fe0009142p-12, 0x1.b6f426000451dp-10, 0x1.130b3c0000616p-9, 0x1.79a84bfffc26p-10, 0x1.968de1ffe5995p-14, -0x1.3e7aa3ffff1c8p-10, -0x1.e15411fffbb76p-10, -0x1.88164bfffc10ep-10, -0x1.bc1304000a54p-12, 0x1.a14c780004e0ep-11, 0x1.93a319ffff42fp-10, 0x1.7f872e00024fep-10, 0x1.57abf1fff798ap-11, -0x1.c3b391fff5ca9p-12, -0x1.42e605fffdf91p-10, -0x1.65391a000539fp-10, -0x1.a3bad800071b5p-11, 0x1.0b2530001d87fp-13, 0x1.e81a24000932p-11, 0x1.3e5bf800030b3p-10, 0x1.c7e199fff7401p-11, 0x1.d2130c004835fp-14, -0x1.55f5d6000b33p-11, -0x1.0fce87fffd884p-10, -0x1.cae577fff5ec2p-11, -0x1.2bbdba0008827p-12, 0x1.a9e95c000735fp-12, 0x1.bbce9dfff6bb5p-11, 0x1.b4172e000899fp-11, 0x1.a4e7c3ffe9afep-12, -0x1.a21fb200091e2p-13, -0x1.5896aa0004044p-11, -0x1.8ace29fffb901p-11, -0x1.e78f36001241dp-12, 0x1.226029ffe0e7cp-15, 0x1.f7518ffff5966p-12, 0x1.55f4280004a93p-11, 0x1.fd09ffffef0a4p-12, 0x1.7399c2001b4d5p-14, -0x1.521b8a000a7b7p-12, -0x1.1ba6dffff9224p-11, -0x1.ef88ba0009618p-12, -0x1.6ba60bffdbfd1p-13, 0x1.8cb4960009897p-13, 0x1.c1e741fff8177p-12, 0x1.c939fc000c21dp-12, 0x1.d7963bffe05acp-13, -0x1.5788dc003041cp-14, -0x1.535d99ffec171p-12, -0x1.938cf3fffc4fap-12, -0x1.055c4400013ccp-12, 0x0p0, 0x1.e19ce40018259p-13, 0x1.569c92000cf76p-12, 0x1.098c4bffe97d6p-12, 0x1.efaae5ff6e608p-15, -0x1.39cdf4001c916p-13, -0x1.18c9c9fffd38bp-12, -0x1.fe5141ffdd042p-13, -0x1.9fe3f0003f0d9p-14, 0x1.60ae3fffd52f3p-14, 0x1.bd0ec7ffdbf27p-13, 0x1.d866e4002923cp-13, 0x1.05611c0018481p-13, -0x1.0b13efffb8de6p-15, -0x1.54ace1fff5a1ep-13, -0x1.aaedebfff7ee2p-13, -0x1.259be5ffeee84p-13, -0x1.3d34460247d06p-17, 0x1.f3bb920023554p-14, 0x1.7c86dffff0c71p-13, 0x1.390af5ffd62ccp-13, 0x1.66e3aa000e83bp-15, -0x1.5633d20007664p-14, -0x1.50b2bdffd520ap-13, -0x1.464420002cf1ep-13, -0x1.2aef65ffe61cdp-14, 0x1.92cd060063217p-15 };


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

void FIR_filter(double *llvm_cbe_result, double llvm_cbe_input, signed short llvm_cbe_do_filter) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  unsigned int llvm_cbe_storemerge3;
  unsigned int llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  unsigned int llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  unsigned long long llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  double *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  double llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  unsigned long long llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  double *llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge12_count = 0;
  unsigned int llvm_cbe_storemerge12;
  unsigned int llvm_cbe_storemerge12__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  double llvm_cbe_tmp__7;
  double llvm_cbe_tmp__7__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  unsigned long long llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  double *llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  double llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  double *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  double llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  double llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  double llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  double llvm_cbe_tmp__16;
  double llvm_cbe_tmp__16__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @FIR_filter\n");
  llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )308u;   /* for PHI node */
  goto llvm_cbe_tmp__17;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__17:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi i32 [ 308, %%0 ], [ %%2, %%1  for 0x%I64xth hint within @FIR_filter  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (unsigned int )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = 0x%X",llvm_cbe_storemerge3);
printf("\n = 0x%X",308u);
printf("\n = 0x%X",llvm_cbe_tmp__1);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = add i32 %%storemerge3, -1, !dbg !4 for 0x%I64xth hint within @FIR_filter  --> \n", ++aesl_llvm_cbe_20_count);
  llvm_cbe_tmp__1 = (unsigned int )((unsigned int )(llvm_cbe_storemerge3&4294967295ull)) + ((unsigned int )(4294967295u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__1&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = zext i32 %%2 to i64, !dbg !4 for 0x%I64xth hint within @FIR_filter  --> \n", ++aesl_llvm_cbe_21_count);
  llvm_cbe_tmp__2 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__1&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr inbounds [309 x double]* @aesl_internal_shift, i64 0, i64 %%3, !dbg !4 for 0x%I64xth hint within @FIR_filter  --> \n", ++aesl_llvm_cbe_22_count);
  llvm_cbe_tmp__3 = (double *)(&aesl_internal_shift[(((signed long long )llvm_cbe_tmp__2))
#ifdef AESL_BC_SIM
 % 309
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__2));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__2) < 309)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_shift' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = load double* %%4, align 8, !dbg !4 for 0x%I64xth hint within @FIR_filter  --> \n", ++aesl_llvm_cbe_23_count);
  llvm_cbe_tmp__4 = (double )*llvm_cbe_tmp__3;
if (AESL_DEBUG_TRACE)
printf("\n = %lf\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = zext i32 %%storemerge3 to i64, !dbg !4 for 0x%I64xth hint within @FIR_filter  --> \n", ++aesl_llvm_cbe_24_count);
  llvm_cbe_tmp__5 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge3&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__5);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds [309 x double]* @aesl_internal_shift, i64 0, i64 %%6, !dbg !4 for 0x%I64xth hint within @FIR_filter  --> \n", ++aesl_llvm_cbe_25_count);
  llvm_cbe_tmp__6 = (double *)(&aesl_internal_shift[(((signed long long )llvm_cbe_tmp__5))
#ifdef AESL_BC_SIM
 % 309
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__5));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__5) < 309 && "Write access out of array 'aesl_internal_shift' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store double %%5, double* %%7, align 8, !dbg !4 for 0x%I64xth hint within @FIR_filter  --> \n", ++aesl_llvm_cbe_26_count);
  *llvm_cbe_tmp__6 = llvm_cbe_tmp__4;
if (AESL_DEBUG_TRACE)
printf("\n = %lf\n", llvm_cbe_tmp__4);
  if (((llvm_cbe_tmp__1&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe_tmp__18;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__1;   /* for PHI node */
    goto llvm_cbe_tmp__17;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__18:
if (AESL_DEBUG_TRACE)
printf("\n  store double %%input, double* getelementptr inbounds ([309 x double]* @aesl_internal_shift, i64 0, i64 0), align 16, !dbg !2 for 0x%I64xth hint within @FIR_filter  --> \n", ++aesl_llvm_cbe_38_count);
  *((&aesl_internal_shift[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 309
#endif
])) = llvm_cbe_input;
if (AESL_DEBUG_TRACE)
printf("\ninput = %lf\n", llvm_cbe_input);
  if (((llvm_cbe_do_filter&65535U) == (((unsigned short )0)&65535U))) {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    llvm_cbe_tmp__7__PHI_TEMPORARY = (double )0x0p0;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  } else {
    llvm_cbe_tmp__16__PHI_TEMPORARY = (double )0x0p0;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  }

  do {     /* Syntactic loop '.preheader' to make GCC happy */
llvm_cbe__2e_preheader:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge12 = phi i32 [ %%19, %%.preheader ], [ 0, %%9  for 0x%I64xth hint within @FIR_filter  --> \n", ++aesl_llvm_cbe_storemerge12_count);
  llvm_cbe_storemerge12 = (unsigned int )llvm_cbe_storemerge12__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge12 = 0x%X",llvm_cbe_storemerge12);
printf("\n = 0x%X",llvm_cbe_tmp__15);
printf("\n = 0x%X",0u);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = phi double [ %%18, %%.preheader ], [ 0.000000e+00, %%9  for 0x%I64xth hint within @FIR_filter  --> \n", ++aesl_llvm_cbe_41_count);
  llvm_cbe_tmp__7 = (double )llvm_cbe_tmp__7__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %lf",llvm_cbe_tmp__7);
printf("\n = %lf",llvm_cbe_tmp__14);
printf("\n = %lf",0x0p0);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = zext i32 %%storemerge12 to i64, !dbg !3 for 0x%I64xth hint within @FIR_filter  --> \n", ++aesl_llvm_cbe_42_count);
  llvm_cbe_tmp__8 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_storemerge12&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds [309 x double]* @aesl_internal_shift, i64 0, i64 %%12, !dbg !3 for 0x%I64xth hint within @FIR_filter  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__9 = (double *)(&aesl_internal_shift[(((signed long long )llvm_cbe_tmp__8))
#ifdef AESL_BC_SIM
 % 309
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__8));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__8) < 309)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_shift' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load double* %%13, align 8, !dbg !3 for 0x%I64xth hint within @FIR_filter  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__10 = (double )*llvm_cbe_tmp__9;
if (AESL_DEBUG_TRACE)
printf("\n = %lf\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds [309 x double]* @aesl_internal_taps, i64 0, i64 %%12, !dbg !3 for 0x%I64xth hint within @FIR_filter  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__11 = (double *)(&aesl_internal_taps[(((signed long long )llvm_cbe_tmp__8))
#ifdef AESL_BC_SIM
 % 309
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__8));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__8) < 309)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_taps' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load double* %%15, align 8, !dbg !3 for 0x%I64xth hint within @FIR_filter  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__12 = (double )*llvm_cbe_tmp__11;
if (AESL_DEBUG_TRACE)
printf("\n = %lf\n", llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = fmul double %%14, %%16, !dbg !3 for 0x%I64xth hint within @FIR_filter  --> \n", ++aesl_llvm_cbe_47_count);
  llvm_cbe_tmp__13 = (double )llvm_cbe_tmp__10 * llvm_cbe_tmp__12;
if (AESL_DEBUG_TRACE)
printf("\n = %lf\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = fadd double %%11, %%17, !dbg !3 for 0x%I64xth hint within @FIR_filter  --> \n", ++aesl_llvm_cbe_48_count);
  llvm_cbe_tmp__14 = (double )llvm_cbe_tmp__7 + llvm_cbe_tmp__13;
if (AESL_DEBUG_TRACE)
printf("\n = %lf\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = add i32 %%storemerge12, 1, !dbg !4 for 0x%I64xth hint within @FIR_filter  --> \n", ++aesl_llvm_cbe_52_count);
  llvm_cbe_tmp__15 = (unsigned int )((unsigned int )(llvm_cbe_storemerge12&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__15&4294967295ull)));
  if (((llvm_cbe_tmp__15&4294967295U) == (309u&4294967295U))) {
    llvm_cbe_tmp__16__PHI_TEMPORARY = (double )llvm_cbe_tmp__14;   /* for PHI node */
    goto llvm_cbe__2e_loopexit;
  } else {
    llvm_cbe_storemerge12__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__15;   /* for PHI node */
    llvm_cbe_tmp__7__PHI_TEMPORARY = (double )llvm_cbe_tmp__14;   /* for PHI node */
    goto llvm_cbe__2e_preheader;
  }

  } while (1); /* end of syntactic loop '.preheader' */
llvm_cbe__2e_loopexit:
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = phi double [ 0.000000e+00, %%9 ], [ %%18, %%.preheader  for 0x%I64xth hint within @FIR_filter  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__16 = (double )llvm_cbe_tmp__16__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = %lf",llvm_cbe_tmp__16);
printf("\n = %lf",0x0p0);
printf("\n = %lf",llvm_cbe_tmp__14);
}
if (AESL_DEBUG_TRACE)
printf("\n  store double %%20, double* %%result, align 8, !dbg !2 for 0x%I64xth hint within @FIR_filter  --> \n", ++aesl_llvm_cbe_64_count);
  *llvm_cbe_result = llvm_cbe_tmp__16;
if (AESL_DEBUG_TRACE)
printf("\n = %lf\n", llvm_cbe_tmp__16);
  if (AESL_DEBUG_TRACE)
      printf("\nEND @FIR_filter}\n");
  return;
}

