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
float fast_atan2f(float llvm_cbe_y, float llvm_cbe_x);
float fabsf(float );


/* Global Variable Definitions and Initialization */
static float aesl_internal_fast_atan_table[257] = { 0x0p0, 0x1.0100acp-8, 0x1.00ffa6p-7, 0x1.817ceep-7, 0x1.00fb9ep-6, 0x1.4136b6p-6, 0x1.816f4cp-6, 0x1.c1a4dcp-6, 0x1.00eb6ep-5, 0x1.21026ap-5, 0x1.411722p-5, 0x1.612956p-5, 0x1.8138cp-5, 0x1.a14524p-5, 0x1.c14e4ap-5, 0x1.e153e2p-5, 0x1.00aadep-4, 0x1.10a9c6p-4, 0x1.20a68ep-4, 0x1.30a118p-4, 0x1.40993ep-4, 0x1.508ee4p-4, 0x1.6081eep-4, 0x1.707236p-4, 0x1.805fa4p-4, 0x1.904a18p-4, 0x1.a03164p-4, 0x1.b0158cp-4, 0x1.bff65ap-4, 0x1.cfd3b2p-4, 0x1.dfad6p-4, 0x1.ef837cp-4, 0x1.ff55b6p-4, 0x1.079208p-3, 0x1.0f772ap-3, 0x1.175a4p-3, 0x1.1f3b2ep-3, 0x1.2719eap-3, 0x1.2ef672p-3, 0x1.36d0acp-3, 0x1.3ea87cp-3, 0x1.467dfp-3, 0x1.4e50eep-3, 0x1.562168p-3, 0x1.5def42p-3, 0x1.65ba8ap-3, 0x1.6d8326p-3, 0x1.7548fap-3, 0x1.7d0c14p-3, 0x1.84cc4ep-3, 0x1.8c89bp-3, 0x1.944424p-3, 0x1.9bfb8ep-3, 0x1.a3affcp-3, 0x1.ab615ep-3, 0x1.b30f8cp-3, 0x1.baba96p-3, 0x1.c2626ep-3, 0x1.ca06f8p-3, 0x1.d1a834p-3, 0x1.d94614p-3, 0x1.e0e08ep-3, 0x1.e8779p-3, 0x1.f00b1p-3, 0x1.f79b0cp-3, 0x1.ff276ap-3, 0x1.03581cp-2, 0x1.071aa6p-2, 0x1.0adb5cp-2, 0x1.0e9a2cp-2, 0x1.12571ap-2, 0x1.16121ep-2, 0x1.19cb32p-2, 0x1.1d8256p-2, 0x1.213782p-2, 0x1.24eaa8p-2, 0x1.289bd2p-2, 0x1.2c4af6p-2, 0x1.2ff80ep-2, 0x1.33a316p-2, 0x1.374c04p-2, 0x1.3af2dep-2, 0x1.3e979ap-2, 0x1.423a38p-2, 0x1.45daaep-2, 0x1.4978fep-2, 0x1.4d151ap-2, 0x1.50af08p-2, 0x1.5446c4p-2, 0x1.57dc46p-2, 0x1.5b6f84p-2, 0x1.5f008ap-2, 0x1.628f48p-2, 0x1.661bc4p-2, 0x1.69a5f2p-2, 0x1.6d2dd2p-2, 0x1.70b362p-2, 0x1.74369ep-2, 0x1.77b784p-2, 0x1.7b360ep-2, 0x1.7eb23cp-2, 0x1.822c08p-2, 0x1.85a378p-2, 0x1.89187ep-2, 0x1.8c8b1cp-2, 0x1.8ffb48p-2, 0x1.936912p-2, 0x1.96d466p-2, 0x1.9a3d48p-2, 0x1.9da3b4p-2, 0x1.a107aap-2, 0x1.a46928p-2, 0x1.a7c83p-2, 0x1.ab24b4p-2, 0x1.ae7ecp-2, 0x1.b1d642p-2, 0x1.b52b46p-2, 0x1.b87dc6p-2, 0x1.bbcdc2p-2, 0x1.bf1b34p-2, 0x1.c2661ap-2, 0x1.c5ae74p-2, 0x1.c8f444p-2, 0x1.cc378ap-2, 0x1.cf7836p-2, 0x1.d2b65ep-2, 0x1.d5f1eep-2, 0x1.d92aecp-2, 0x1.dc6152p-2, 0x1.df9526p-2, 0x1.e2c66ap-2, 0x1.e5f50cp-2, 0x1.e9211ep-2, 0x1.ec4a92p-2, 0x1.ef7172p-2, 0x1.f295b4p-2, 0x1.f5b75ep-2, 0x1.f8d67p-2, 0x1.fbf2e2p-2, 0x1.ff0cb4p-2, 0x1.0111f8p-1, 0x1.029c46p-1, 0x1.042544p-1, 0x1.05acf6p-1, 0x1.073358p-1, 0x1.08b86cp-1, 0x1.0a3c2ep-1, 0x1.0bbea2p-1, 0x1.0d3fc6p-1, 0x1.0ebf9cp-1, 0x1.103e24p-1, 0x1.11bb5ap-1, 0x1.133744p-1, 0x1.14b1dep-1, 0x1.162b28p-1, 0x1.17a326p-1, 0x1.1919d2p-1, 0x1.1a8f34p-1, 0x1.1c0344p-1, 0x1.1d7606p-1, 0x1.1ee77ep-1, 0x1.2057a6p-1, 0x1.21c682p-1, 0x1.23341p-1, 0x1.24a054p-1, 0x1.260b48p-1, 0x1.2774f2p-1, 0x1.28dd5p-1, 0x1.2a4466p-1, 0x1.2baa3p-1, 0x1.2d0eaep-1, 0x1.2e71e2p-1, 0x1.2fd3cep-1, 0x1.31347p-1, 0x1.3293cep-1, 0x1.33f1dep-1, 0x1.354eaap-1, 0x1.36aa3p-1, 0x1.38046ep-1, 0x1.395d66p-1, 0x1.3ab51cp-1, 0x1.3c0b88p-1, 0x1.3d60b4p-1, 0x1.3eb49cp-1, 0x1.400742p-1, 0x1.4158a4p-1, 0x1.42a8c6p-1, 0x1.43f7a6p-1, 0x1.454548p-1, 0x1.4691aap-1, 0x1.47dccep-1, 0x1.4926b4p-1, 0x1.4a6f5ap-1, 0x1.4bb6c6p-1, 0x1.4cfcf4p-1, 0x1.4e41e8p-1, 0x1.4f85a4p-1, 0x1.50c826p-1, 0x1.52096ep-1, 0x1.53497ep-1, 0x1.548858p-1, 0x1.55c5fcp-1, 0x1.570266p-1, 0x1.583da2p-1, 0x1.5977a4p-1, 0x1.5ab078p-1, 0x1.5be818p-1, 0x1.5d1e86p-1, 0x1.5e53c2p-1, 0x1.5f87d2p-1, 0x1.60bab2p-1, 0x1.61ec66p-1, 0x1.631ceap-1, 0x1.644c42p-1, 0x1.657a72p-1, 0x1.66a776p-1, 0x1.67d352p-1, 0x1.68fe04p-1, 0x1.6a278ep-1, 0x1.6b4ff2p-1, 0x1.6c7732p-1, 0x1.6d9d4cp-1, 0x1.6ec242p-1, 0x1.6fe616p-1, 0x1.7108c8p-1, 0x1.722a5cp-1, 0x1.734acap-1, 0x1.746a1ep-1, 0x1.758854p-1, 0x1.76a568p-1, 0x1.77c166p-1, 0x1.78dc44p-1, 0x1.79f60cp-1, 0x1.7b0ebap-1, 0x1.7c264cp-1, 0x1.7d3ccep-1, 0x1.7e5234p-1, 0x1.7f6688p-1, 0x1.8079c8p-1, 0x1.818bf2p-1, 0x1.829d0cp-1, 0x1.83ad12p-1, 0x1.84bc0cp-1, 0x1.85c9f4p-1, 0x1.86d6cep-1, 0x1.87e29ep-1, 0x1.88ed6p-1, 0x1.89f718p-1, 0x1.8affc4p-1, 0x1.8c0768p-1, 0x1.8d0e02p-1, 0x1.8e1396p-1, 0x1.8f1826p-1, 0x1.901baep-1, 0x1.911e32p-1, 0x1.921fb6p-1, 0x1.921fb6p-1 };


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
static const ConstantDoubleTy FPConstant0 = 0x3F70100ACB464B24ULL;    /* 3.921549e-03 */
static const ConstantFloatTy FPConstant1 = 0x437F0000U;    /* 2.550000e+02 */
static const ConstantFloatTy FPConstant2 = 0x40490FDBU;    /* 3.141593e+00 */
static const ConstantFloatTy FPConstant3 = 0xC0490FDBU;    /* -3.141593e+00 */
static const ConstantFloatTy FPConstant4 = 0x3FC90FDBU;    /* 1.570796e+00 */
static const ConstantFloatTy FPConstant5 = 0xBFC90FDBU;    /* -1.570796e+00 */

float fast_atan2f(float llvm_cbe_y, float llvm_cbe_x) {
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
  float llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  float llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_or_2e_cond_count = 0;
  bool llvm_cbe_or_2e_cond;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  float llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  float llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge_count = 0;
  float llvm_cbe_storemerge;
  float llvm_cbe_storemerge__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  double llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  float llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  unsigned int llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  unsigned int llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  float llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  float llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  unsigned long long llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  float *llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  float llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  unsigned long long llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  float *llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  float llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  float llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  float llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  float llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  float llvm_cbe_storemerge1;
  float llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  float llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  float llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  float llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  float llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  float llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  float llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  float llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge3_count = 0;
  float llvm_cbe_storemerge3;
  float llvm_cbe_storemerge3__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @fast_atan2f\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = tail call float @fabsf(float %%y) nounwind, !dbg !2 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_11_count);
  llvm_cbe_tmp__1 = (float ) /*tail*/ fabsf(llvm_cbe_y);
if (AESL_DEBUG_TRACE) {
printf("\nArgument y = %f",llvm_cbe_y);
printf("\nReturn  = %f",llvm_cbe_tmp__1);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = tail call float @fabsf(float %%x) nounwind, !dbg !3 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_18_count);
  llvm_cbe_tmp__2 = (float ) /*tail*/ fabsf(llvm_cbe_x);
if (AESL_DEBUG_TRACE) {
printf("\nArgument x = %f",llvm_cbe_x);
printf("\nReturn  = %f",llvm_cbe_tmp__2);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%or.cond = or i1 %%3, %%4, !dbg !3 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_or_2e_cond_count);
  llvm_cbe_or_2e_cond = (bool )(((llvm_fcmp_ogt(llvm_cbe_tmp__1, 0x0p0)) | (llvm_fcmp_ogt(llvm_cbe_tmp__2, 0x0p0)))&1);
if (AESL_DEBUG_TRACE)
printf("\nor.cond = 0x%X\n", llvm_cbe_or_2e_cond);
  if (llvm_cbe_or_2e_cond) {
    goto llvm_cbe_tmp__28;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (float )0x0p0;   /* for PHI node */
    goto llvm_cbe_tmp__29;
  }

llvm_cbe_tmp__28:
  if ((llvm_fcmp_olt(llvm_cbe_tmp__1, llvm_cbe_tmp__2))) {
    goto llvm_cbe_tmp__30;
  } else {
    goto llvm_cbe_tmp__31;
  }

llvm_cbe_tmp__30:
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = fdiv float %%1, %%2, !dbg !4 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_30_count);
  llvm_cbe_tmp__3 = (float )((float )(llvm_cbe_tmp__1 / llvm_cbe_tmp__2));
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__3);
  llvm_cbe_storemerge__PHI_TEMPORARY = (float )llvm_cbe_tmp__3;   /* for PHI node */
  goto llvm_cbe_tmp__32;

llvm_cbe_tmp__31:
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = fdiv float %%2, %%1, !dbg !4 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__4 = (float )((float )(llvm_cbe_tmp__2 / llvm_cbe_tmp__1));
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__4);
  llvm_cbe_storemerge__PHI_TEMPORARY = (float )llvm_cbe_tmp__4;   /* for PHI node */
  goto llvm_cbe_tmp__32;

llvm_cbe_tmp__32:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge = phi float [ %%10, %%9 ], [ %%8, %%7  for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_storemerge_count);
  llvm_cbe_storemerge = (float )llvm_cbe_storemerge__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge = %f",llvm_cbe_storemerge);
printf("\n = %f",llvm_cbe_tmp__4);
printf("\n = %f",llvm_cbe_tmp__3);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = fpext float %%storemerge to double, !dbg !4 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_40_count);
  llvm_cbe_tmp__5 = (double )((double )llvm_cbe_storemerge);
if (AESL_DEBUG_TRACE)
printf("\n = %lf\n", llvm_cbe_tmp__5);
  if ((llvm_fcmp_olt(llvm_cbe_tmp__5, (*(double*)&FPConstant0)))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (float )llvm_cbe_storemerge;   /* for PHI node */
    goto llvm_cbe_tmp__33;
  } else {
    goto llvm_cbe_tmp__34;
  }

llvm_cbe_tmp__34:
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = fmul float %%storemerge, 2.550000e+02, !dbg !4 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__6 = (float )((float )(llvm_cbe_storemerge * (*(float*)&FPConstant1)));
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = fptosi float %%15 to i32, !dbg !5 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_48_count);
  llvm_cbe_tmp__7 = (unsigned int )((signed int )llvm_cbe_tmp__6&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__7);
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = and i32 %%16, 255, !dbg !5 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_49_count);
  llvm_cbe_tmp__8 = (unsigned int )llvm_cbe_tmp__7 & 255u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = sitofp i32 %%17 to float, !dbg !5 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_55_count);
  llvm_cbe_tmp__9 = (float )((float )(signed int )llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = fsub float %%15, %%18, !dbg !5 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_56_count);
  llvm_cbe_tmp__10 = (float )((float )(llvm_cbe_tmp__6 - llvm_cbe_tmp__9));
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = zext i32 %%17 to i64, !dbg !5 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__11 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__8&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = getelementptr inbounds [257 x float]* @aesl_internal_fast_atan_table, i64 0, i64 %%20, !dbg !5 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__12 = (float *)(&aesl_internal_fast_atan_table[(((signed long long )llvm_cbe_tmp__11))
#ifdef AESL_BC_SIM
 % 257
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__11));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__11) < 257)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_fast_atan_table' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = load float* %%21, align 4, !dbg !5 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__13 = (float )*llvm_cbe_tmp__12;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = add nsw i32 %%17, 1, !dbg !5 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_74_count);
  llvm_cbe_tmp__14 = (unsigned int )((unsigned int )(llvm_cbe_tmp__8&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__14&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = zext i32 %%23 to i64, !dbg !5 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_75_count);
  llvm_cbe_tmp__15 = (unsigned long long )((unsigned long long )(unsigned int )llvm_cbe_tmp__14&4294967295U);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = getelementptr inbounds [257 x float]* @aesl_internal_fast_atan_table, i64 0, i64 %%24, !dbg !5 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_76_count);
  llvm_cbe_tmp__16 = (float *)(&aesl_internal_fast_atan_table[(((signed long long )llvm_cbe_tmp__15))
#ifdef AESL_BC_SIM
 % 257
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__15));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__15) < 257)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_fast_atan_table' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = load float* %%25, align 4, !dbg !5 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_77_count);
  llvm_cbe_tmp__17 = (float )*llvm_cbe_tmp__16;
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = fsub float %%26, %%22, !dbg !5 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_78_count);
  llvm_cbe_tmp__18 = (float )((float )(llvm_cbe_tmp__17 - llvm_cbe_tmp__13));
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = fmul float %%27, %%19, !dbg !5 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__19 = (float )((float )(llvm_cbe_tmp__18 * llvm_cbe_tmp__10));
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = fadd float %%22, %%28, !dbg !5 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_80_count);
  llvm_cbe_tmp__20 = (float )((float )(llvm_cbe_tmp__13 + llvm_cbe_tmp__19));
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__20);
  llvm_cbe_storemerge1__PHI_TEMPORARY = (float )llvm_cbe_tmp__20;   /* for PHI node */
  goto llvm_cbe_tmp__33;

llvm_cbe_tmp__33:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi float [ %%29, %%14 ], [ %%storemerge, %%11  for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (float )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = %f",llvm_cbe_storemerge1);
printf("\n = %f",llvm_cbe_tmp__20);
printf("\nstoremerge = %f",llvm_cbe_storemerge);
}
  if ((llvm_fcmp_olt(llvm_cbe_tmp__1, llvm_cbe_tmp__2))) {
    goto llvm_cbe_tmp__35;
  } else {
    goto llvm_cbe_tmp__36;
  }

llvm_cbe_tmp__35:
  if ((llvm_fcmp_ult(llvm_cbe_x, 0x0p0))) {
    goto llvm_cbe_tmp__37;
  } else {
    goto llvm_cbe_tmp__38;
  }

llvm_cbe_tmp__38:
  if ((llvm_fcmp_ult(llvm_cbe_y, 0x0p0))) {
    goto llvm_cbe_tmp__39;
  } else {
    llvm_cbe_storemerge3__PHI_TEMPORARY = (float )llvm_cbe_storemerge1;   /* for PHI node */
    goto llvm_cbe_tmp__29;
  }

llvm_cbe_tmp__39:
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = fsub float -0.000000e+00, %%storemerge1, !dbg !5 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_98_count);
  llvm_cbe_tmp__21 = (float )((float )(-(llvm_cbe_storemerge1)));
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__21);
  llvm_cbe_storemerge3__PHI_TEMPORARY = (float )llvm_cbe_tmp__21;   /* for PHI node */
  goto llvm_cbe_tmp__29;

llvm_cbe_tmp__37:
  if ((llvm_fcmp_ult(llvm_cbe_y, 0x0p0))) {
    goto llvm_cbe_tmp__40;
  } else {
    goto llvm_cbe_tmp__41;
  }

llvm_cbe_tmp__41:
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = fsub float 0x400921FB60000000, %%storemerge1, !dbg !5 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_111_count);
  llvm_cbe_tmp__22 = (float )((float )((*(float*)&FPConstant2) - llvm_cbe_storemerge1));
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__22);
  llvm_cbe_storemerge3__PHI_TEMPORARY = (float )llvm_cbe_tmp__22;   /* for PHI node */
  goto llvm_cbe_tmp__29;

llvm_cbe_tmp__40:
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = fadd float %%storemerge1, 0xC00921FB60000000, !dbg !6 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_114_count);
  llvm_cbe_tmp__23 = (float )((float )(llvm_cbe_storemerge1 + (*(float*)&FPConstant3)));
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__23);
  llvm_cbe_storemerge3__PHI_TEMPORARY = (float )llvm_cbe_tmp__23;   /* for PHI node */
  goto llvm_cbe_tmp__29;

llvm_cbe_tmp__36:
  if ((llvm_fcmp_ult(llvm_cbe_y, 0x0p0))) {
    goto llvm_cbe_tmp__42;
  } else {
    goto llvm_cbe_tmp__43;
  }

llvm_cbe_tmp__43:
  if ((llvm_fcmp_ult(llvm_cbe_x, 0x0p0))) {
    goto llvm_cbe_tmp__44;
  } else {
    goto llvm_cbe_tmp__45;
  }

llvm_cbe_tmp__45:
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = fsub float 0x3FF921FB60000000, %%storemerge1, !dbg !6 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_129_count);
  llvm_cbe_tmp__24 = (float )((float )((*(float*)&FPConstant4) - llvm_cbe_storemerge1));
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__24);
  llvm_cbe_storemerge3__PHI_TEMPORARY = (float )llvm_cbe_tmp__24;   /* for PHI node */
  goto llvm_cbe_tmp__29;

llvm_cbe_tmp__44:
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = fadd float %%storemerge1, 0x3FF921FB60000000, !dbg !6 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_132_count);
  llvm_cbe_tmp__25 = (float )((float )(llvm_cbe_storemerge1 + (*(float*)&FPConstant4)));
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__25);
  llvm_cbe_storemerge3__PHI_TEMPORARY = (float )llvm_cbe_tmp__25;   /* for PHI node */
  goto llvm_cbe_tmp__29;

llvm_cbe_tmp__42:
  if ((llvm_fcmp_ult(llvm_cbe_x, 0x0p0))) {
    goto llvm_cbe_tmp__46;
  } else {
    goto llvm_cbe_tmp__47;
  }

llvm_cbe_tmp__47:
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = fadd float %%storemerge1, 0xBFF921FB60000000, !dbg !6 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_145_count);
  llvm_cbe_tmp__26 = (float )((float )(llvm_cbe_storemerge1 + (*(float*)&FPConstant5)));
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__26);
  llvm_cbe_storemerge3__PHI_TEMPORARY = (float )llvm_cbe_tmp__26;   /* for PHI node */
  goto llvm_cbe_tmp__29;

llvm_cbe_tmp__46:
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = fsub float 0xBFF921FB60000000, %%storemerge1, !dbg !6 for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_148_count);
  llvm_cbe_tmp__27 = (float )((float )((*(float*)&FPConstant5) - llvm_cbe_storemerge1));
if (AESL_DEBUG_TRACE)
printf("\n = %f\n", llvm_cbe_tmp__27);
  llvm_cbe_storemerge3__PHI_TEMPORARY = (float )llvm_cbe_tmp__27;   /* for PHI node */
  goto llvm_cbe_tmp__29;

llvm_cbe_tmp__29:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge3 = phi float [ %%36, %%35 ], [ %%42, %%41 ], [ %%40, %%39 ], [ %%50, %%49 ], [ %%48, %%47 ], [ %%56, %%55 ], [ %%54, %%53 ], [ %%storemerge1, %%33 ], [ 0.000000e+00, %%0  for 0x%I64xth hint within @fast_atan2f  --> \n", ++aesl_llvm_cbe_storemerge3_count);
  llvm_cbe_storemerge3 = (float )llvm_cbe_storemerge3__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge3 = %f",llvm_cbe_storemerge3);
printf("\n = %f",llvm_cbe_tmp__21);
printf("\n = %f",llvm_cbe_tmp__23);
printf("\n = %f",llvm_cbe_tmp__22);
printf("\n = %f",llvm_cbe_tmp__25);
printf("\n = %f",llvm_cbe_tmp__24);
printf("\n = %f",llvm_cbe_tmp__27);
printf("\n = %f",llvm_cbe_tmp__26);
printf("\nstoremerge1 = %f",llvm_cbe_storemerge1);
printf("\n = %f",0x0p0);
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @fast_atan2f}\n");
  return llvm_cbe_storemerge3;
}

