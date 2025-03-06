                   ??=ifndef __stdlib
                   ??=ifdef __COMPILER_VER__
                     ??=pragma filetag("IBM-1047")
                   ??=endif
                   #define __stdlib 1
                   #pragma nomargins nosequence
                   #pragma checkout(suspend)
  /***************************************************************
  * <stdlib.h> header file                                       *
  *                                                              *
  * LICENSED MATERIALS - PROPERTY OF IBM                         *
  *                                                              *
  * 5650-ZOS                                                     *
  *                                                              *
  * COPYRIGHT IBM CORP. 1988, 2015                               *
  *                                                              *
  * US GOVERNMENT USERS RESTRICTED RIGHTS - USE,                 *
  * DUPLICATION OR DISCLOSURE RESTRICTED BY GSA ADP              *
  * SCHEDULE CONTRACT WITH IBM CORP.                             *
  *                                                              *
  * STATUS = HLE77A0                                             *
  ***************************************************************/
 
  #if defined(__IBM_METAL__) 
 
    #error Language Environment standard C headers \
cannot be used when METAL option is used. \
Correct your header search path.
 
  #endif /* __IBM_METAL__ */
 
  #ifdef __cplusplus
  extern "C" {
  #endif
 
  #ifndef __EDC_LE
    #define __EDC_LE 0x10000000
  #endif
 
  #if __TARGET_LIB__ >= __EDC_LE
    #if !defined(__features_h)  || defined(__inc_features)
      #include <features.h>
    #endif
  #endif
 
  #ifndef __size_t
    #ifdef _LP64
      typedef unsigned long size_t;
    #else
      typedef unsigned int size_t;
    #endif /* _LP64 */
    #define __size_t 1
  #endif
 
  #if __TARGET_LIB__ >= __EDC_LE
    typedef struct __div_t
  #else
    typedef struct div_t
  #endif
      {
      int quot;        /* quotient of integer division       */
      int rem;         /* remainder of integer division      */
      } div_t;
 
  #if __TARGET_LIB__ >= __EDC_LE
    typedef struct __ldiv_t
  #else
    typedef struct ldiv_t
  #endif
      {
      long int quot;   /* quotient of long integer division  */
      long int rem;    /* remainder of long integer division */
      } ldiv_t;
 
  #ifdef __LL
   typedef struct {
               long long quot;  /*quotient */
               long long rem;   /* remainder */
   } lldiv_t;
  #endif
 
  #if __TARGET_LIB__ >= __EDC_LE
    #if !defined(__hreport)
       #define __hreport  1
       typedef struct {
                 long  __uheap_size;
                 long  __uheap_bytes_alloc;
                 long  __uheap_bytes_free;
       } hreport_t;
    #endif
  #endif
 
  #if (__COMPILER_VER__ < 0x41020000 || !defined(__cplusplus)  \
                                     || __EDC_TARGET < __EDC_LE4102 )
    #ifndef __wchar_t
      #ifdef _LP64
        typedef unsigned int wchar_t;
      #else
        typedef unsigned short wchar_t;
      #endif  /* _LP64 */
      #define __wchar_t 1
    #endif
 
  #endif
 
  #ifndef NULL
     #ifdef __cplusplus
           #define NULL 0
     #else
           #define NULL ((void *)0)
     #endif
  #endif
 
  #define EXIT_SUCCESS      0
  #define EXIT_FAILURE      8
 
  #define RAND_MAX      32767
 
  #ifndef __gtab
    #define __gtab(x) _Gtab(x)
    #if !defined(__clang__)
      #ifdef __cplusplus
        extern "builtin"
      #else
        #pragma linkage(_Gtab, builtin)
      #endif
      void **_Gtab(int);
    #endif
  #endif
 
  #ifndef __gtca
    #define __gtca() _gtca()
    #if !defined(__clang__)
      #ifdef __cplusplus
        extern "builtin"
      #else
        #pragma linkage(_gtca,builtin)
      #endif
      const void *_gtca(void);
    #endif
  #endif
 
  #ifndef MB_CUR_MAX
 
    #ifdef __NATIVE_ASCII_F
      #define __MB_CUR_MAX_i 38
    #else
      #define __MB_CUR_MAX_i 23
    #endif /* __NATIVE_ASCII_F */
 
    #define MB_CUR_MAX         \
               ((size_t const) (*(__gtab(__MB_CUR_MAX_i))))
 
    #if ( __EDC_TARGET >= __EDC_LE4102 && defined(__XPLINK__) )
      #define __MB_CUR_MAX_A_i  38
      #define __MB_CUR_MAX_E_i  23
      #define _MB_CUR_MAX_A     \
               ((size_t const) (*(__gtab(__MB_CUR_MAX_A_i))))
      #define _MB_CUR_MAX_E     \
               ((size_t const) (*(__gtab(__MB_CUR_MAX_E_i))))
    #endif  /* __EDC_LE4102 && __XPLINK__ */
 
  #endif /* MB_CUR_MAX */
 
  #ifdef __AE_BIMODAL_F
    #pragma map (__atof_a,    "\174\174A00164")
    #pragma map (__atof_e,    "ATOF")
    #pragma map (__atoi_a,    "\174\174A00165")
    #pragma map (__atoi_e,    "ATOI")
    #pragma map (__atol_a,    "\174\174A00166")
    #pragma map (__atol_e,    "ATOL")
    #pragma map (__strtod_a,  "\174\174A00167")
    #pragma map (__strtod_e,  "STRTOD")
    #pragma map (__strtol_a,  "\174\174A00168")
    #pragma map (__strtol_e,  "STRTOL")
    #pragma map (__strtoul_a, "\174\174A00169")
    #pragma map (__strtoul_e, "STRTOUL")
  #endif /* __AE_BIMODAL_F */
 
  #ifdef __NATIVE_ASCII_F
    #pragma map (atof,      "\174\174A00164")
    #pragma map (atoi,      "\174\174A00165")
    #pragma map (atol,      "\174\174A00166")
    #pragma map (strtod,    "\174\174A00167")
    #pragma map (strtol,    "\174\174A00168")
    #pragma map (strtoul,   "\174\174A00169")
  #else
    #ifdef __LIBASCII_F
      #pragma map (atof,     "\174\174ATOF\174")
      #pragma map (atoi,     "\174\174ATOI\174")
      #pragma map (atol,     "\174\174ATOL\174")
      #pragma map (strtod,   "\174\174STTOD\174")
      #pragma map (strtol,   "\174\174STTOL\174")
      #pragma map (strtoul,  "\174\174STTOU\174")
    #endif /* __LIBASCII_F*/
  #endif /* __NATIVE_ASCII_F */
 
  #if __COMPILER_VER__ >= 0x22060000
    #ifdef __LL
      __new29(long long int, strtoll, (const char * __restrict__,
               char * * __restrict__, int));
      __new29(unsigned long long int, strtoull,
            (const char * __restrict__, char * * __restrict__, int));
      #ifdef __AE_BIMODAL_F
        #pragma map (__strtoll_a, "\174\174A00343")
        #pragma map (__strtoll_e, "\174\174STRLL")
        #pragma map (__strtoull_a, "\174\174A00344")
        #pragma map (__strtoull_e, "\174\174STRULL")
      #endif /* __AE_BIMODAL_F */
      #ifdef __NATIVE_ASCII_F
        #pragma map (strtoll,     "\174\174A00343")
        #pragma map (strtoull,    "\174\174A00344")
      #elif __EDC_TARGET >= 0x22090000
        #pragma map (strtoll,   "\174\174STRLL")
        #pragma map (strtoull,  "\174\174STRULL")
      #endif /* __NATIVE_ASCII_F */
    #endif /* __LL */
  #endif /* __COMPILER_VER__ >= 0x22060000 */
 
  #ifdef _NO_PROTO
    double   atof ();
    int      atoi ();
    long int atol ();
    double   strtod ();
    long int strtol ();
    unsigned long int strtoul ();
    int      rand ();
    void     srand ();
    #if __EDC_TARGET >= 0x22090000
      #ifdef __LL
        long long int strtoll ();
        unsigned long long int strtoull ();
      #endif /* __LL */
    #endif /* __EDC_TARGET >= 0x22090000 */
  #else
    double   atof (const char *);
    int      atoi (const char *);
    long int atol (const char *);
    double   strtod (const char * __restrict__, char * * __restrict__);
    long int strtol (const char * __restrict__, char * * __restrict__,
                      int);
    unsigned long int strtoul (const char * __restrict__,
                                char * * __restrict__, int);
    int      rand (void);
    void     srand (unsigned int);
    #if __EDC_TARGET >= 0x22090000
      #ifdef __LL
        long long int strtoll (const char * __restrict__,
                                char * * __restrict__, int);
        unsigned long long int strtoull (const char * __restrict__,
                                          char * * __restrict__, int);
      #endif /* __LL */
    #endif /* __EDC_TARGET >= 0x22090000 */
  #endif /* _NO_PROTO */
 
  #ifdef __AE_BIMODAL_F
    __new4102(double,__atof_a,(const char *));
    __new4102(double,__atof_e,(const char *));
    __new4102(int,__atoi_a,(const char *));
    __new4102(int,__atoi_e,(const char *));
    __new4102(long int,__atol_a,(const char *));
    __new4102(long int,__atol_e,(const char *));
    __new4102(double,__strtod_a,(const char *, char * *));
    __new4102(double,__strtod_e,(const char *, char * *));
    __new4102(long int,__strtol_a,(const char *, char * *, int));
    __new4102(long int,__strtol_e,(const char *, char * *, int));
    __new4102(unsigned long int,__strtoul_a,(const char *, char * *, int));
    __new4102(unsigned long int,__strtoul_e,(const char *, char * *, int));
    #ifdef __LL
      __new4102(long long int,__strtoll_a,(const char *, char * *, int));
      __new4102(long long int,__strtoll_e,(const char *, char * *, int));
      __new4102(unsigned long long int,__strtoull_a,
                (const char *, char * *, int));
      __new4102(unsigned long long int,__strtoull_e,
                (const char *, char * *, int));
    #endif /* __LL */
  #endif /* __AE_BIMODAL_F */
 
  #if (defined(__C99) || defined(__TR1) || __cplusplus >= 201103L) 
    #ifdef __AE_BIMODAL_F
      #ifdef __LL
        #pragma map (__atoll_a,   "\174\174A00455")
        #pragma map (__atoll_e,   "ATOLL")
      #endif /* __LL */
      #pragma map (__strtof_a,  "\174\174A00456")
      #pragma map (__strtof_e,  "STRTOF")
      #pragma map (__strtold_a, "\174\174A00457")
      #pragma map (__strtold_e, "STRTOLD")
    #endif /* __AE_BIMODAL_F */
 
    #ifdef __NATIVE_ASCII_F
      #ifdef __LL
        #pragma map (atoll,      "\174\174A00455")
      #endif /* __LL */
      #pragma map (strtof,     "\174\174A00456")
      #pragma map (strtold,    "\174\174A00457")
    #endif /* __NATIVE_ASCII_F */
 
    #ifdef __LL
      __new4107(long long,atoll,(const char *));
    #endif /* __LL */
 
    __new4107(float,strtof,(const char * __restrict__,
                                  char ** __restrict__ ));
    __new4107(long double,strtold,(const char * __restrict__,
                                  char ** __restrict__ ));
 
    #ifdef __AE_BIMODAL_F
      #ifdef __LL
        __new4107(long long,__atoll_a,(const char *));
        __new4107(long long,__atoll_e,(const char *));
      #endif /* __LL */
      __new4107(float,__strtof_a,(const char * __restrict__,
                                  char ** __restrict__));
      __new4107(float,__strtof_e,(const char * __restrict__,
                                  char ** __restrict__));
      __new4107(long double,__strtold_a,(const char * __restrict__,
                                  char ** __restrict__));
      __new4107(long double,__strtold_e,(const char * __restrict__,
                                  char ** __restrict__));
    #endif /* __AE_BIMODAL_F */
  #endif /* __C99 OR __TR1 */
 
  #ifdef _LP64
    #if !defined(_NO_PRAGMA)
      #pragma map(__malloc24, "\174\174MALL24")
      #pragma map(__malloc31, "\174\174MALL31")
    #endif /* !defined(_NO_PRAGMA) */
  #elif __EDC_TARGET >= __EDC_LE4105
    #define __malloc31(x) malloc(x)
  #endif /* _LP64 */
 
  #ifdef _NO_PROTO
    #ifndef __spc
      void *   calloc ();
      void     free ();
      void *   malloc ();
      void *   realloc ();
    #endif
  #else
    #ifndef __spc
      void *   calloc (size_t, size_t);
      void     free (void *);
      void *   malloc (size_t);
      void *   realloc (void *, size_t);
    #endif
  #endif /* _NO_PROTO */
 
  #ifdef _LP64
    __new4106(void *,__malloc24,(size_t));
    __new4106(void *,__malloc31,(size_t));
 
    #if __EDC_TARGET >= __EDC_LE410A 
      struct __mopl_s { 
        unsigned long 
               __moplrequestsize; 
        int    __mopldumppriority; 
        unsigned int 
               __moplgetstorflags; 
       #if __EDC_TARGET >= __EDC_LE410B 
        #define __MOPL_PAGEFRAMESIZE1MEG 0x80000000 
        #define __MOPL_PAGEFRAMESIZEMAX  0x40000000 
       #endif           /* __EDC_TARGET >= __EDC_LE410B */ 
       #if __EDC_TARGET >= __EDC_LE4201 
        #define __MOPL_PAGEFRAMESIZE_PAGEABLE1MEG\
                                         0x20000000 
        #define __MOPL_PAGEFRAMESIZE_2G  0x10000000 
        #define __MOPL_USE2GTO32G        0x08000000 
       #endif           /* __EDC_TARGET >= __EDC_LE4201 */ 
        long   __moplreserved; 
        int    __mopl_iarv64_rc; 
        int    __mopl_iarv64_rsn; 
      }; 
 
      typedef struct __mopl_s __mopl_t; 
 
      /* __moservices() Request Types                   */ 
      #define __MO_GETSTOR               1 
      #define __MO_DETACH                2 
      #define __MO_SHMDUMPPRIORITY       3 
 
      /* __moservices() Dump Priorities                 */ 
      #define __MO_DUMP_PRIORITY_STACK   5 
      #define __MO_DUMP_PRIORITY_HEAP    15 
 
    #endif              /* __EDC_TARGET >= __EDC_LE410A */ 
 
    __new410A(int,__moservices,(int,
                                size_t,
                                __mopl_t *,
                                void **)); 
 
  #endif /* _LP64 */
 
  #ifdef _EXT
    #ifndef _NO_PRAGMA
      #pragma map(exit,"EDC\173EXIT")
    #endif /* _NO_PRAGMA */
  #endif
 
  #if !defined(__clang__)
    #ifdef __cplusplus
      extern "builtin"
    #else
      #pragma linkage(__abs,builtin)
    #endif
    #ifdef _NO_PROTO
      int       __abs ();
    #else
      int       __abs (int);
    #endif
  #endif
 
  #ifndef _NO_PRAGMA
    #pragma map (__heaprpt, "\174\174HSRPT")
  #endif /* _NO_PRAGMA */
 
   /* pragma maps for __getenv enhanced_ascii */
   #if defined (__NATIVE_ASCII_F) && (__EA_F >= __EA_F_4106)
     #pragma map (__getenv,        "\174\174A00423")
   #else
     #pragma map (__getenv,        "\174\174GETENV")
   #endif /* __NATIVE_ASCII_F && __EA_F >= __EA_F_4106 */
 
  #ifdef __AE_BIMODAL_F
    #pragma map (__getenv_a,  "\174\174A00181")
    #pragma map (__getenv_e,  "GETENV")
    #pragma map (__system_a,  "\174\174A00189")
    #pragma map (__system_e,  "SYSTEM")
    #pragma map (____getenv_a,    "\174\174A00423")
    #pragma map (____getenv_e,    "\174\174GETENV")
  #endif /* __AE_BIMODAL_F */
 
  #ifdef __NATIVE_ASCII_F
    #pragma map (getenv,      "\174\174A00181")
    #pragma map (system,      "\174\174A00189")
  #else
  #ifdef __LIBASCII_F
    #pragma map (getenv,   "\174\174GTENV\174")
    #pragma map (system,   "\174\174SYSTM\174")
  #endif /* __LIBASCII_F*/
  #endif /* __NATIVE_ASCII_F */

  #if __cplusplus >= 201103L
    [[noreturn]] void     abort (void) noexcept;
    int      atexit (void (*)(void)) noexcept;
    [[noreturn]] void     exit (int) noexcept;
  #else
    #ifdef _NO_PROTO
      void     abort (); 
      int      atexit ();
      void     exit (); 
    #else
      void     abort (void); 
      int      atexit (void (*)(void));
      void     exit (int); 
    #endif
  #endif
 
  #ifdef _NO_PROTO
    char *   getenv ();
    char *   __getenv ();
    int      system ();
    void *   bsearch ();
    void     qsort ();
  #else
    char *   getenv (const char *);
    char *   __getenv (const char *);
    int      system (const char *);
    void *   bsearch (const void *, const void *,
                      size_t, size_t,
                      int (*)(const void *,
                                    const void *));
    void     qsort (void *, size_t, size_t,
                    int (*)(const void *,
                                  const void *));
  #endif /* _NO_PROTO */
 
  #ifdef _EXT
    __new4102(int,unatexit,(void (*)(void)));
  #endif  /* _EXT */
 
  #ifdef __AE_BIMODAL_F
    __new4102(char *,__getenv_a,(const char *));
    __new4102(char *,__getenv_e,(const char *));
    __new4102(int,__system_a,(const char *));
    __new4102(int,__system_e,(const char *));
    __new4106(char *,____getenv_a,(const char *));
    __new4106(char *,____getenv_e,(const char *));
  #endif /* __AE_BIMODAL_F */
 
  #ifdef __hreport
     #ifdef _NO_PROTO
        int      __heaprpt();
     #else
        int      __heaprpt(hreport_t *);
     #endif /* _NO_PROTO */
  #endif /* __hreport */
 
  #ifdef __cplusplus
    extern "C++" {
      inline int abs (int x) { return __abs(x); }
    }
  #else
    #define abs(x) __abs(x)
    #ifdef _EXT
      #pragma map(abs ,"EDC\173ABS")
    #endif
 
    #ifdef _NO_PROTO
      int     (abs) ();
    #else
      int     (abs) (int);
    #endif /* _NO_PROTO */
 
  #endif
 
  #ifdef __LIBASCII_F
    #pragma map (mbstowcs, "\174\174MBTWS\174")
    #pragma map (mbtowc,   "\174\174MBTWC\174")
  #endif /* __LIBASCII_F*/
 
 
  #ifdef __AE_BIMODAL_F
 
    #pragma map (__mblen_a,    "\174\174A00002")
    #pragma map (__mbtowc_a,   "\174\174A00008")
    #pragma map (__wctomb_a,   "\174\174A00023")
    #pragma map (__mbstowcs_a, "\174\174A00006")
    #pragma map (__wcstombs_a, "\174\174A00013")
 
    #pragma map (__mblen_e,    "MBLEN")
    #pragma map (__mbtowc_e,   "MBTOWC")
    #pragma map (__wctomb_e,   "WCTOMB")
    #pragma map (__mbstowcs_e, "MBSTOWCS")
    #pragma map (__wcstombs_e, "WCSTOMBS")
 
  #endif /* __AE_BIMODAL_F */
 
  #ifdef __NATIVE_ASCII_F
    #pragma map (mblen,    "\174\174A00002")
    #pragma map (mbtowc,   "\174\174A00008")
    #pragma map (wctomb,   "\174\174A00023")
    #pragma map (mbstowcs, "\174\174A00006")
    #pragma map (wcstombs, "\174\174A00013")
  #endif /* __NATIVE_ASCII_F*/
 
 
  #ifdef _NO_PROTO
    div_t    div ();
    long int labs ();
    ldiv_t   ldiv ();
    int      mblen ();
    int      mbtowc ();
    int      wctomb ();
    size_t   mbstowcs ();
    size_t   wcstombs ();
  #else
    div_t    div (int, int);
    long int labs (long int);
    ldiv_t   ldiv (long int, long int);
    int      mblen (const char *, size_t);
    int      mbtowc (wchar_t * __restrict__,
                      const char * __restrict__, size_t);
    int      wctomb (char *, wchar_t);
    size_t   mbstowcs (wchar_t * __restrict__,
                        const char * __restrict__, size_t);
    size_t   wcstombs (char * __restrict__,
                        const wchar_t * __restrict__, size_t);
  #endif /* _NO_PROTO */
 
  #ifdef __AE_BIMODAL_F
    __new4102(int, __mblen_a,(const char *, size_t));
    __new4102(int, __mblen_e,(const char *, size_t));
    __new4102(int, __mbtowc_a,(wchar_t *, const char *, size_t));
    __new4102(int, __mbtowc_e,(wchar_t *, const char *, size_t));
    __new4102(int, __wctomb_a,(char *, wchar_t));
    __new4102(int, __wctomb_e,(char *, wchar_t));
    __new4102(size_t, __mbstowcs_a,(wchar_t *, const char *, size_t));
    __new4102(size_t, __mbstowcs_e,(wchar_t *, const char *, size_t));
    __new4102(size_t, __wcstombs_a,(char *, const wchar_t *, size_t));
    __new4102(size_t, __wcstombs_e,(char *, const wchar_t *, size_t));
  #endif /* __AE_BIMODAL_F */
 
  #ifdef __LL
      __new210(long long, llabs, (long long ));
      __new210(lldiv_t, lldiv, (long long , long long ));
  #endif /* __LL */
 
  #ifndef __sysplist
 
     #ifndef __SYSPLIST_INDEX
       #ifdef _LP64 
         #define __SYSPLIST_INDEX 100 
       #else 
         #define __SYSPLIST_INDEX 128
       #endif 
     #endif
 
     #define __sysplist_i   12
 
     #define __sysplist ( (void * const *) \
               *((void ** const) (*(__gtab(__sysplist_i))) ) )
 
     #if __TARGET_LIB__ >= __EDC_LE
        #define __R1 ((void *) *((void **) (*(__gtab(__sysplist_i)))))
        #define __osplist ( (void **) __R1)
     #endif
 
  #endif  /* __sysplist */
 
  #ifdef _EXT
 
 
    #ifdef __AE_BIMODAL_F
      #pragma map (__fetch_a,    "\174\174A00180")
      #pragma map (__fetch_e,    "\174\174FETCH")
    #endif /* __AE_BIMODAL_F */
 
    #ifdef __NATIVE_ASCII_F
      #pragma map (fetch,    "\174\174A00180")
    #endif /* __NATIVE_ASCII_F */
 
    #ifdef _NO_PROTO
      void (*  fetch())();
      void (*  fetchep ())();
      int    release ();
    #else
      void (*  fetch (const char *))();
      void (*  fetchep (void (*)()))();
      int    release (void (*)());
    #endif /* _NO_PROTO */
 
    #ifdef __AE_BIMODAL_F
      __new4102(void,(*  __fetch_a (const char *)),());
      __new4102(void,(*  __fetch_e (const char *)),());
    #endif /* __AE_BIMODAL_F */
 
    #ifndef _LP64
      #ifdef __cplusplus
        inline int fortrc (void)
          {  return (*( (int *)((char *)_gtca() + 568) ))/4; }
      #else
        #if !defined(__clang__)
          #pragma linkage(__fortrc, builtin)
          #ifdef _NO_PROTO
            int     (__fortrc) () ;
          #else
            int     (__fortrc) (void) ;
          #endif
        #endif
        #define fortrc __fortrc
      #endif
    #endif /* _LP64 */
 
    #ifdef __AE_BIMODAL_F
 
      #pragma map (__rpmatch_a, "\174\174A00091")
      #pragma map (__csid_a,    "\174\174A00019")
      #pragma map (__wcsid_a,   "\174\174A00021")
 
      #pragma map (__rpmatch_e, "\174\174RPMTCH")
      #pragma map (__csid_e,    "\174\174CSID")
      #pragma map (__wcsid_e,   "\174\174WCSID")
 
    #endif /* __AE_BIMODAL_F */
 
    #ifdef __NATIVE_ASCII_F
      #pragma map (rpmatch, "\174\174A00091")
      #pragma map (csid,    "\174\174A00019")
      #pragma map (wcsid,   "\174\174A00021")
 
    #else
      /* remap name that conflicts with FORTRAN - for ILC calls   */
      #pragma map (rpmatch, "\174\174RPMTCH")
      #pragma map (csid,    "\174\174CSID")
      #pragma map (wcsid,   "\174\174WCSID")
    #endif  /* __NATIVE_ASCII_F */
 
    #ifdef _NO_PROTO
      int __librel ();
      #ifndef __envclr 
        int clearenv ();
        #define __envclr 1 
      #endif 
      int rpmatch();
      int csid();
      int wcsid();
    #else
      int __librel (void);
      #ifndef __envclr 
        int clearenv (void);
        #define __envclr 1 
      #endif 
      int rpmatch(const char *);
      int csid(const char *);
      int wcsid(const wchar_t);
    #endif /* _NO_PROTO */
 
    #ifdef __AE_BIMODAL_F
      __new4102(int,__rpmatch_a,(const char *));
      __new4102(int,__rpmatch_e,(const char *));
      __new4102(int,__csid_a,(const char *));
      __new4102(int,__csid_e,(const char *));
      __new4102(int,__wcsid_a,(const wchar_t));
      __new4102(int,__wcsid_e,(const wchar_t));
    #endif /* __AE_BIMODAL_F */
 
    #if !defined(__clang__) || defined(_EXT_CS)
      #ifndef __cs_t
        typedef unsigned int cs_t;
        #define __cs_t 1
      #endif
 
      #ifndef __cds_t
        typedef union {
          struct {
            unsigned int first_word;
            unsigned int second_word;
          } double_word;
          double alignment_dummy;
        } cds_t;
        #define __cds_t 1
      #endif   /* __cds_t */
 
      #ifdef __COMPILER_VER__
        #ifdef __cplusplus
          extern "builtin"
        #else
          #pragma linkage(__cs, builtin)
        #endif
      #endif
 
      #ifdef _NO_PROTO
        int     __cs ();
        int     (cs) ();
      #else
        int     __cs (cs_t *, cs_t *, cs_t);
        int     (cs) (cs_t *, cs_t *, cs_t);
      #endif /* _NO_PROTO */
 
      #if __COMPILER_VER__ >= 0x41020000
        #ifdef __cplusplus
          extern "builtin"
        #else
          #pragma linkage(__cs1, builtin)
        #endif
 
        #ifdef _NO_PROTO
          int     __cs1 ();
        #else
          int     __cs1 (void *, void *, void *);
        #endif /* _NO_PROTO */
        #define __cs(x, y, z) __cs1(x, y, &(z))
      #endif
 
      #define cs(x, y, z) __cs(x, y, z)
 
      #ifndef __CS1
      #undef __cs
      #endif
 
      #ifdef __COMPILER_VER__
        #ifdef __cplusplus
          extern "builtin"
        #else
          #pragma linkage(__cds, builtin)
        #endif
      #endif
 
      #ifdef _NO_PROTO
        int     __cds ();
        int     (cds) ();
      #else
        int     __cds (cds_t *, cds_t *, cds_t);
        int     (cds) (cds_t *, cds_t *, cds_t);
      #endif /* _NO_PROTO */
 
      #if __COMPILER_VER__ >= 0x41020000
        #ifdef __cplusplus
          extern "builtin"
        #else
          #pragma linkage(__cds1, builtin)
        #endif
 
        #ifdef _NO_PROTO
          int     __cds1 ();
        #else
          int     __cds1 (void *, void *, void *);
        #endif /* _NO_PROTO */
 
        #define __cds(x, y, z) __cds1(x, y, &(z))
      #endif
 
      #define cds(x, y, z) __cds(x, y, z)
 
      #ifndef __CDS1
      #undef __cds
      #endif
    #endif /* __clang */
  #endif   /* _EXT */
 
  #if __TARGET_LIB__ >= __EDC_LE
    #ifndef __gtab
      #define __gtab(x) _Gtab(x)
      #if !defined(__clang__)
        #ifdef __cplusplus
          extern "builtin"
        #else
          #pragma linkage(_Gtab, builtin)
        #endif
        void **_Gtab(int);
      #endif
    #endif
 
    #ifndef __abnd_i
       #define __abnd_i   14
    #endif
 
    #ifndef __rsn_i
       #define __rsn_i    15
    #endif
 
    #ifndef __abendcode
      #define __abendcode \
             ( *((int * const) (*(__gtab(__abnd_i))) ) )
    #endif
 
    #ifndef __rsncode
       #define __rsncode \
               ( *((int * const) (*(__gtab(__rsn_i))) ) )
    #endif
 
    /* Prototype the environment variable table access stubs.  These
     * stubs provide access to the environment variable table directly
     * through the LE control blocks.
     */
 
    #pragma map(__EnvnA, "\174\174ENVNA")
 
    char *** __EnvnA(void); 
    char *** __Envn(void); 
 
    /* Define _a and _e versions of environ for mixed-mode applications
     * only for LE4102 target and XPLINK compilations.
     */
 
    #ifdef __AE_BIMODAL_F
       #define  __environ_a  (*(__EnvnA()))
       #define  __environ_e  (*(__Envn()))
    #endif  /* __AE_BIMODAL_F */
 
    /* Always map environ to __EnvnA for an ASCII compile unit to
     * ensure usage of the environ external variable always accesses
     * the ASCII table.
     */
 
    #if defined(__NATIVE_ASCII_F) && !defined(environ)
       #define  environ  (*(__EnvnA()))
    #elif (defined(_SHARE_EXT_VARS) || defined(_SHR_ENVIRON))  \
             &&  !defined(environ) 
       #define  environ  (*(__Envn()))
    #endif
 
    #if (defined(_SHARE_EXT_VARS) || defined(_SHR_ENVIRON))  \
             &&  !defined(environ) 
       char  ***__Envn();
       #define  environ  (*(__Envn()))
    #endif
 
    #ifdef _EXT
      #if __COMPILER_VER__ >= 0x22060000
        #ifndef alloca
          #define alloca(x) __alloca(x)
          #if !defined(__clang__)
            #ifdef __cplusplus
              extern "builtin"
            #else
              #pragma linkage(__alloca,builtin)
            #endif
            void *__alloca(unsigned int x);
          #endif /* !__clang__ */
        #endif
      #endif
    #endif
 
    #ifdef __XPG4
    /*
     *
     * X/Open Issue 4 (XPG4)
     *
     */
 
      /* Constants                                                  */
 
      #define WNOHANG    0x0001
      #define WUNTRACED  0x0002
 
      /* Macros                                                     */
 
      #define WIFEXITED(stat_val)   \
        ( ((stat_val) & 0x000000FF) ? 0 : 1)
 
      #define WEXITSTATUS(stat_val) \
         ( WIFEXITED(stat_val) ? (((stat_val) & 0x0000FF00) >> 8) : 0)
 
      #define WIFSTOPPED(stat_val)  \
             ( (((stat_val) & 0x000000FF) == 0x0000007F)           \
                 ||  (((stat_val) & 0x000000FF) == 0x0000007E)      \
                   ||  (((stat_val) & 0x000000FF) == 0x0000007D)    \
                     ||  (((stat_val) & 0x000000FF) == 0x0000007B)  \
                       ||  (((stat_val) & 0x000000FF) == 0x0000007A)\
                       ||  (((stat_val) & 0x000000FF) == 0x00000078)\
                       ||  (((stat_val) & 0x000000FF) == 0x00000077))
 
      /* Signalled, not stopped and not continued */
      #define WIFSIGNALED(stat_val) \
        (  ((!(WIFSTOPPED(stat_val))) && ((stat_val) & 0x000000FF) ) \
           && !(((stat_val) & 0x000000FF) == 0x00000079) )
 
      #define WSTOPSIG(stat_val) ( ((stat_val) & 0x0000FF00) >> 8 )
 
      #define WTERMSIG(stat_val) ( (stat_val) & 0x0000007F )
 
      /* Function prototypes                                        */
 
      #ifdef __AE_BIMODAL_F
        #pragma map (__putenv_a,  "\174\174A00186")
        #pragma map (__putenv_e,  "PUTENV")
      #endif /* __AE_BIMODAL_F */
 
      #ifdef __NATIVE_ASCII_F
        #pragma map (putenv,      "\174\174A00186")
      #else
      #ifdef __LIBASCII_F
        #pragma map (putenv,   "\174\174PTENV\174")
      #endif /* __LIBASCII_F*/
      #endif /* __NATIVE_ASCII_F */
 
      #ifdef __LIBASCII_F
        #ifndef __XPG4_VM
          #pragma map (setkey,   "\174\174STKEY\174")
        #endif
      #endif /* __LIBASCII_F*/
 
      #ifdef _NO_PROTO
        double       drand48();
        double       erand48();
        long int     jrand48();
        void         lcong48();
        long int     lrand48();
        long int     mrand48();
        long int     nrand48();
        int          putenv();
        unsigned short int  *seed48();
        void         srand48();
        #ifndef __XPG4_VM
          void         setkey();
        #endif
      #else
        double       drand48(void);
        double       erand48(unsigned short int [3]);
        long int     jrand48(unsigned short int [3]);
        void         lcong48(unsigned short int [7]);
        long int     lrand48(void);
        long int     mrand48(void);
        long int     nrand48(unsigned short int [3]);
        #ifdef __SUSV3_XSI 
          __new4109(int,putenv,(char *)); 
        #else 
          int          putenv(const char *);
        #endif 
        unsigned short int  *seed48(unsigned short int [3]);
        void         srand48(long int);
        #ifndef __XPG4_VM
          void         setkey(const char *);
        #endif
      #endif /* _NO_PROTO */
 
      #ifdef __AE_BIMODAL_F
         #ifdef __SUSV3_XSI 
            __new4109(int,__putenv_a,(char *)); 
            __new4109(int,__putenv_e,(char *)); 
         #else 
            __new4102(int,__putenv_a,(const char *));
            __new4102(int,__putenv_e,(const char *));
         #endif 
      #endif /* __AE_BIMODAL_F */
 
    #endif                          /* End X/Open Issue 4           */
 
    #ifdef __UU
    /*
     *
     * X/Open Issue 4 Version 2 (XPG4 Extended)
     *
     */
 
      /* Function prototypes                                        */
 
      #ifndef _NO_PRAGMA
        #pragma map (getsubopt, "\174\174GSOPT")
        #pragma map (initstate, "\174\174ISTAT")
      #endif /* _NO_PRAGMA */
 
      #ifdef __AE_BIMODAL_F
        #pragma map (__a64l_a,    "\174\174A00172")
        #pragma map (__a64l_e,    "\174\174A64L")
        #pragma map (__l64a_a,    "\174\174A00176")
        #pragma map (__l64a_e,    "\174\174L64A")
        #pragma map (__ecvt_a,     "\174\174A00173")
        #pragma map (__ecvt_e,     "\174\174ECVT")
        #pragma map (__fcvt_a,     "\174\174A00174")
        #pragma map (__fcvt_e,     "\174\174FCVT")
        #pragma map (__gcvt_a,     "\174\174A00175")
        #pragma map (__gcvt_e,     "\174\174GCVT")
        #pragma map (__mkstemp_a,  "\174\174A00184")
        #pragma map (__mkstemp_e,  "\174\174MKSTE")
        #pragma map (__ptsname_a,  "\174\174A00185")
        #pragma map (__ptsname_e,  "\174\174PTSNA")
        #pragma map (__realpath_a, "\174\174A00187")
        #pragma map (__realpath_e, "\174\174RPATH")
        #pragma map (__mktemp_a,   "\174\174A00240")
        #pragma map (__mktemp_e,   "\174\174MKTMP")
      #endif /* __AE_BIMODAL_F */
 
      #ifdef __NATIVE_ASCII_F
        #pragma map (ecvt,     "\174\174A00173")
        #pragma map (fcvt,     "\174\174A00174")
        #pragma map (gcvt,     "\174\174A00175")
        #pragma map (a64l,     "\174\174A00172")
        #pragma map (l64a,     "\174\174A00176")
        #pragma map (mkstemp,  "\174\174A00184")
        #pragma map (ptsname,  "\174\174A00185")
        #pragma map (realpath, "\174\174A00187")
        #pragma map (mktemp,   "\174\174A00240")
      #else
        #ifdef __LIBASCII_F
          #pragma map (ecvt,     "\174\174ECVT\174")
          #pragma map (fcvt,     "\174\174FCVT\174")
          #pragma map (gcvt,     "\174\174GCVT\174")
          #pragma map (mktemp,   "\174\174MKTMP\174")
          #ifndef __UU_VM
            #pragma map (ptsname,  "\174\174PTSNA\174")
          #endif
        #endif /* __LIBASCII_F*/
      #endif /* __NATIVE_ASCII_F*/
 
      #ifdef _NO_PROTO
        long         a64l();
        char        *ecvt();
        char        *fcvt();
        char        *gcvt();
        int          getsubopt();
        char        *initstate();
        char        *l64a();
        int          mkstemp();
        char        *mktemp();
        long         random();
        char        *realpath();
        char        *setstate();
        void         srandom();
        #ifndef __SUSV3_WITHDRAWN
           int          ttyslot();
           void         *valloc();
        #endif
        #ifndef __UU_VM
          int          grantpt();
          char        *ptsname();
          int          unlockpt();
        #endif
      #else
        long         a64l(const char *);
        char        *ecvt(double, int, int * __restrict__,
                                       int * __restrict__); 
        char        *fcvt(double, int, int * __restrict__,
                                       int * __restrict__); 
        char        *gcvt(double, int, char *);
        int          getsubopt(char **, char *const *, char **);
        char        *initstate(unsigned, char *, size_t);
        char        *l64a(long);
        int          mkstemp(char *);
        char        *mktemp(char *);
        long         random(void);
        char        *realpath(const char * __restrict__,
                                    char * __restrict__); 
        char        *setstate(const char *);
        void         srandom(unsigned);
        #ifndef __SUSV3_WITHDRAWN
           int          ttyslot(void);
           void        *valloc(size_t);
        #endif
        #ifndef __UU_VM
          int          grantpt(int);
          char        *ptsname(int);
          int          unlockpt(int);
        #endif
      #endif /* _NO_PROTO */
 
      #ifdef __AE_BIMODAL_F
        __new4102(long,__a64l_a,(const char *));
        __new4102(long,__a64l_e,(const char *));
        __new4102(char *,__l64a_a,(long));
        __new4102(char *,__l64a_e,(long));
        __new4102(char *,__ecvt_a,(double, int, int * __restrict__,
                                                int * __restrict__)); 
        __new4102(char *,__ecvt_e,(double, int, int * __restrict__,
                                                int * __restrict__)); 
        __new4102(char *,__fcvt_a,(double, int, int * __restrict__,
                                                int * __restrict__)); 
        __new4102(char *,__fcvt_e,(double, int, int * __restrict__,
                                                int * __restrict__)); 
        __new4102(char *,__gcvt_a,(double, int, char *));
        __new4102(char *,__gcvt_e,(double, int, char *));
        __new4102(int,__mkstemp_a,(char *));
        __new4102(int,__mkstemp_e,(char *));
        __new4102(char *,__ptsname_a,(int));
        __new4102(char *,__ptsname_e,(int));
        __new4102(char *,__realpath_a,(const char * __restrict__,
                                             char * __restrict__)); 
        __new4102(char *,__realpath_e,(const char * __restrict__,
                                             char * __restrict__)); 
        __new4102(char *,__mktemp_a,(char *));
        __new4102(char *,__mktemp_e,(char *));
      #endif /* __AE_BIMODAL_F */
 
    #endif                          /* End __XPG4                   */
 
    #if defined(__U98)
      /*
       *
       * X/Open Issue 5 (UNIX 98)
       *
       */
       #ifndef _NO_PRAGMA
          #pragma map (rand_r,"\174\174RAND\174R")
       #endif
       __new28(int,rand_r,(unsigned int *));
    #endif
 
    /*
     *
     * Language Environment Extensions
     *
     */
 
    #ifndef _NO_PRAGMA
      #pragma map (__discarddata, "\174\174DDATA")
    #endif /* _NO_PRAGMA */
 
    __new210(int,__discarddata,(void *, size_t));
 
    #ifdef __OE_8
 
      /*
       *
       * itoa() extensions
       *
       */
 
      #ifndef __inttypes
        #include <inttypes.h>
      #endif
 
      /* constants for use with itoa() family of functions */
 
      #define OCTAL     8   /* octal radix */
      #define DECIMAL  10   /* decimal radix */
      #define HEX      16   /* hexadecimal radix */
 
      /* pragma maps */
 
      #ifdef __NATIVE_ASCII_F
        #pragma map (__itoa,      "\174\174A00417")
        #pragma map (__utoa,      "\174\174A00418")
        #pragma map (__ltoa,      "\174\174A00419")
        #pragma map (__ultoa,     "\174\174A00420")
        #ifdef __LL
          #pragma map (__lltoa,     "\174\174A00421")
          #pragma map (__ulltoa,    "\174\174A00422")
        #endif  /* __LL */
      #endif /* __NATIVE_ASCII_F */
 
      #ifdef __AE_BIMODAL_F
          #pragma map (__itoa_a,    "\174\174A00417")
          #pragma map (__itoa_e,    "\174\174ITOA")
          #pragma map (__utoa_a,    "\174\174A00418")
          #pragma map (__utoa_e,    "\174\174UTOA")
          #pragma map (__ltoa_a,    "\174\174A00419")
          #pragma map (__ltoa_e,    "\174\174LTOA")
          #pragma map (__ultoa_a,   "\174\174A00420")
          #pragma map (__ultoa_e,   "\174\174ULTOA")
          #ifdef __LL
            #pragma map (__lltoa_a,    "\174\174A00421")
            #pragma map (__lltoa_e,    "\174\174LLTOA")
            #pragma map (__ulltoa_a,   "\174\174A00422")
            #pragma map (__ulltoa_e,   "\174\174ULLTOA")
          #endif  /* __LL */
      #endif /* __AE_BIMODAL_F */
 
      /* prototypes */
 
      #define   itoa(x,y,z)     __itoa(x,y,z)
      #define   utoa(x,y,z)     __utoa(x,y,z)
      #define   ltoa(x,y,z)     __ltoa(x,y,z)
      #define  ultoa(x,y,z)    __ultoa(x,y,z)
      #ifdef __LL
        #define  lltoa(x,y,z)    __lltoa(x,y,z)
        #define ulltoa(x,y,z)   __ulltoa(x,y,z)
      #endif  /* __LL */
 
      __new4105(char *,__itoa,(int, char *, int));
      __new4105(char *,__utoa,(unsigned int, char *, int));
      __new4105(char *,__ltoa,(long, char *, int));
      __new4105(char *,__ultoa,(unsigned long, char *, int));
      #ifdef __LL
        __new4105(char *,__lltoa,(int64_t, char *, int));
        __new4105(char *,__ulltoa,(uint64_t, char *, int));
      #endif /* __LL */
 
      #ifdef __AE_BIMODAL_F
        __new4105(char *,__itoa_a,(int, char *, int));
        __new4105(char *,__itoa_e,(int, char *, int));
        __new4105(char *,__utoa_a,(unsigned int, char *, int));
        __new4105(char *,__utoa_e,(unsigned int, char *, int));
        __new4105(char *,__ltoa_a,(long, char *, int));
        __new4105(char *,__ltoa_e,(long, char *, int));
        __new4105(char *,__ultoa_a,(unsigned long, char *, int));
        __new4105(char *,__ultoa_e,(unsigned long, char *, int));
        #ifdef __LL
        __new4105(char *,__lltoa_a,(int64_t, char *, int));
        __new4105(char *,__lltoa_e,(int64_t, char *, int));
        __new4105(char *,__ulltoa_a,(uint64_t, char *, int));
        __new4105(char *,__ulltoa_e,(uint64_t, char *, int));
        #endif /* __LL */
      #endif /* __AE_BIMODAL_F */
 
    #endif  /* __OE_8 */
 
    #if (defined(__C99) || defined(__TR1) || __cplusplus >= 201103L) 
 
      #ifndef _NO_PRAGMA
        #if (__EDC_TARGET >= __EDC_LE4107) || \
            (!defined(_NO_NEW_FUNC_CHECK))
          #pragma map (_Exit, "\174\174EXIT99")
        #endif
      #endif

      #if __EDC_TARGET >= __EDC_LE4107 && __cplusplus >= 201103L
        [[noreturn]] void _Exit(int) noexcept;
      #else 
        __new4107(void,_Exit,(int)); 
      #endif
 
    #endif  /* __C99 OR __TR1 */
 
    #if defined(_EXT) || defined(__SUSV3) 
      #ifndef __envfns
        #ifdef _NO_PROTO 
          int setenv (); 
        #else 
          int setenv (const char *, const char *, int); 
        #endif /* _NO_PROTO */ 
    
        #ifdef __NATIVE_ASCII_F 
          #pragma map (setenv,  "\174\174A00188") 
        #else 
          #ifdef __LIBASCII_F 
            #pragma map (setenv,   "\174\174STENV\174") 
          #endif /* __LIBASCII_F*/ 
        #endif 
 
        #ifdef __AE_BIMODAL_F 
          #pragma map (__setenv_a,  "\174\174A00188") 
          #pragma map (__setenv_e,  "SETENV") 
        #endif 
 
        #ifdef __AE_BIMODAL_F 
          __new4102(int,__setenv_a,(const char *, const char *, int));
          __new4102(int,__setenv_e,(const char *, const char *, int));
        #endif  /* __AE_BIMODAL_F */ 
     
        #define __envfns 1
      #endif /* __envfns */
    #endif  /* _EXT  || __SUSV3*/ 
   
    #ifdef __SUSV3
      #ifdef __NATIVE_ASCII_F
        #pragma map(unsetenv,"\174\174A00471")
      #else
        #pragma map(unsetenv,"\174\174UNSTNV")
      #endif
 
      #ifdef __AE_BIMODAL_F
        #pragma map(__unsetenv_a,"\174\174A00471")
        #pragma map(__unsetenv_e,"\174\174UNSTNV")
      #endif
 
      __new4107(int,unsetenv,(const char *));
 
      #ifdef __AE_BIMODAL_F
        __new4107(int,__unsetenv_a,(const char *));
        __new4107(int,__unsetenv_e,(const char *));
      #endif  /* __AE_BIMODAL_F */
    #endif  /* __SUSV3 */
 
    #ifdef __SUSV3_XSI 
      #ifndef _NO_PRAGMA 
        #pragma map(posix_openpt,"\174\174PX\174OPT") 
      #endif  /* _NO_PRAGMA */ 
      __new4109(int,posix_openpt,(int)); 
    #endif 
 
    #ifdef __LE_DFP 
      #ifdef __NATIVE_ASCII_F 
        #pragma map (strtod32  , "\174\174A00477") 
        #pragma map (strtod64  , "\174\174A00478") 
        #pragma map (strtod128 , "\174\174A00479") 
      #else 
        #if !defined(_NO_PRAGMA) || __EDC_TARGET < __EDC_LE4109
          #pragma map (strtod32  , "\174\174STR\174D1") 
          #pragma map (strtod64  , "\174\174STR\174D2") 
          #pragma map (strtod128 , "\174\174STR\174D4") 
        #endif 
      #endif 
 
      #ifdef __AE_BIMODAL_F 
        #pragma map (__strtod32_a  , "\174\174A00477") 
        #pragma map (__strtod32_e  , "\174\174STR\174D1") 
        #pragma map (__strtod64_a  , "\174\174A00478") 
        #pragma map (__strtod64_e  , "\174\174STR\174D2") 
        #pragma map (__strtod128_a , "\174\174A00479") 
        #pragma map (__strtod128_e , "\174\174STR\174D4") 
      #endif 
 
      __new4108(_Decimal32,  strtod32,( const char * __restrict__,
                             char ** __restrict__)); 
      __new4108(_Decimal64,  strtod64,( const char * __restrict__,
                             char ** __restrict__)); 
      __new4108(_Decimal128, strtod128,(const char * __restrict__,
                             char ** __restrict__)); 
 
      #ifdef __AE_BIMODAL_F 
        __new4108(_Decimal32,  __strtod32_a,(const char * __restrict__,
                               char ** __restrict__)); 
        __new4108(_Decimal32,  __strtod32_e,(const char * __restrict__,
                               char ** __restrict__)); 
        __new4108(_Decimal64,  __strtod64_a,(const char * __restrict__,
                               char ** __restrict__)); 
        __new4108(_Decimal64,  __strtod64_e,(const char * __restrict__,
                               char ** __restrict__)); 
        __new4108(_Decimal128,__strtod128_a,(const char * __restrict__,
                               char ** __restrict__)); 
        __new4108(_Decimal128,__strtod128_e,(const char * __restrict__,
                               char ** __restrict__)); 
      #endif  /* __AE_BIMODAL_F */ 
    #endif /* __LE_DFP */ 
 
  #endif  /* __TARGET_LIB__ >= __EDC_LE */
 
  #ifdef __cplusplus
  }
  #endif
 
 
  #ifdef __cplusplus
  extern "C++" {
     #if defined(__intmax_imaxdiv_t) 
        #ifdef _LP64 
          #ifdef __LL 
             inline long long abs (long long x) 
             { return llabs(x);} 
             inline lldiv_t div (long long x, long long y) 
             { return lldiv(x,y); } 
          #endif 
        #else 
          inline long abs (long x) { return labs(x); } 
          inline ldiv_t div (long x, long y) 
          { return ldiv(x,y); } 
        #endif 
     #else 
        #if (defined(__TR1) || __cplusplus >= 201103L) && \
            (defined(__LL) || defined(_LP64))
           #define __intmax_imaxdiv_t 1 
        #endif 
        inline long abs (long x) { return labs(x); } 
        inline ldiv_t div (long x, long y) 
        { return ldiv(x,y); } 
        #if (defined(__TR1) || __cplusplus >= 201103L) && defined(__LL) 
          inline long long abs (long long x) 
          { return llabs(x);} 
          inline lldiv_t div (long long x, long long y) 
          { return lldiv(x,y); } 
        #endif 
     #endif 
  }
  #endif
 
 
                   #pragma checkout(resume)
                   ??=endif /* __stdlib */
