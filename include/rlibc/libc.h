/// Avoid needless header complexity.
/// #include "libc.h"

#pragma once
#pragma lib "libc.a"

typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef unsigned short uint16_t;
typedef signed int int32_t;
typedef unsigned int uint32_t;
typedef signed long int64_t;
typedef unsigned long uint64_t;
typedef int64_t intptr_t;
typedef uint64_t uintptr_t;
typedef uint64_t size_t;
typedef int64_t ssize_t;
typedef int64_t off_t;
typedef int32_t pid_t;
typedef uint32_t uid_t;
typedef uint32_t gid_t;
typedef unsigned long clock_t;
typedef long time_t;

#define nelem(x)        (sizeof(x)/sizeof((x)[0]))
#define offsetof(s, m)  (size_t)(&(((s*)0)->m))

/* Types */
int isalnum(int);
int isalpha(int);
int isblank(int);
int iscntrl(int);
int isdigit(int);
int isgraph(int);
int islower(int);
int isprint(int);
int ispunct(int);
int isspace(int);
int isupper(int);
int isxdigit(int);
int tolower(int);
int toupper(int);

/* Memory */
void *memchr(const void *, int, size_t);
int memcmp(const void *, const void *, size_t);
void *memcpy(void *, const void *, size_t);
void *memmove(void *, const void *, size_t);
void *memset(void *, int, size_t);

/* String manipulation */
char *strcpy(char *dst, const char *src);
char *strncpy(char *dst, const char *src, size_t n);
char *strcat(char *dst, const char *src);
char *strncat(char *dst, const char *src, size_t n);
int strcmp(const char *m1, const char *m2);
int strncmp(const char *m1, const char *m2, size_t n);
char *strerror(int);
size_t strnlen(const char *, size_t);
size_t strlen(const char *);

/* I/O */
int puts(const char *);

/* Filesystem */
typedef struct FILE FILE;

extern FILE __stdin;
extern FILE __stdout;
extern FILE __stderr;

#define stdin  &__stdin
#define stdout &__stdout
#define stderr &__stderr

#define _IOFBF 0
#define _IOLBF 1
#define _IONBF 2

#define BUFSIZ 8192

#define EOF (-1)

#define FOPEN_MAX 16
#define FILENAME_MAX 4096
#define L_tmpnam 20

#define SEEK_SET 0
#define SEEK_CUR 1
#define SEEK_END 2

#define TMP_MAX 238328

int close(int);
ssize_t read(int, void *, size_t);
ssize_t write(int, const void *, size_t);
ssize_t pread(int, void *, size_t, off_t);
ssize_t pwrite(int, const void *, size_t, off_t);
off_t lseek(int, off_t, int);
int remove(const char *);
int rename(const char *, const char *);
int rmdir(const char*);
int unlink(const char *);
int utime(const char *, void *);

/* Process Management */
void exit(int);
void _exit(int);
void abort(void);
int atexit(void (*)(void));

/* Memory Management */
void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
int munmap(void *addr, size_t length);
int brk(void *);
void *sbrk(intptr_t);

/* Environment */
extern int errno;
char *getenv(const char *);
pid_t getpid(void);
uid_t getuid(void);
uid_t geteuid(void);
pid_t setsid(void);
int setgid(gid_t);
int setuid(uid_t);

/* Math */
float ldexpf(float x, int exp);
float floorf(float x);
float ceilf(float x);
float truncf(float x);
float roundf(float x);
float fmaf(float x, float y, float z);
float fmodf(float x, float y);
float fdimf(float x, float y);
float fmaxf(float x, float y);
float fminf(float x, float y);
float logf(float x);
float log2f(float x);
float log10f(float x);
float log1pf(float x);
float sqrtf(float x);
float cbrtf(float x);
float expf(float x);
float exp2f(float x);
float expm1f(float x);
float powf(float mant, float expo);
float sinf(float x);
float cosf(float x);
float tanf(float x);
float asinf(float x);
float acosf(float x);
float atanf(float x);
float acoshf(float x);
float asinhf(float x);
float atanhf(float x);
float coshf(float x);
float sinhf(float x);
float tanhf(float x);

double ldexp(double x, int exp);
double floor(double x);
double ceil(double x);
double trunc(double x);
double round(double x);
double fma(double x, double y, double z);
double fmod(double x, double y);
double fdim(double x, double y);
double fmax(double x, double y);
double fmin(double x, double y);
double log(double x);
double log2(double x);
double log10(double x);
double log1p(double x);
double sqrt(double x);
double cbrt(double x);
double exp(double x);
double exp2(double x);
double expm1(double x);
double pow(double mant, double expo);
double sin(double x);
double cos(double x);
double tan(double x);
double asin(double x);
double acos(double x);
double atan(double x);
double acosh(double x);
double asinh(double x);
double atanh(double x);
double cosh(double x);
double sinh(double x);
double tanh(double x);

double gauss(double x);
double erf(double x);
double erfc(double x);

/* Time */
struct tm {
	int	tm_sec;		/* seconds after the minute [0-60] */
	int	tm_min;		/* minutes after the hour [0-59] */
	int	tm_hour;	/* hours since midnight [0-23] */
	int	tm_mday;	/* day of the month [1-31] */
	int	tm_mon;		/* months since January [0-11] */
	int	tm_year;	/* years since 1900 */
	int	tm_wday;	/* days since Sunday [0-6] */
	int	tm_yday;	/* days since January 1 [0-365] */
	int	tm_isdst;	/* Daylight Savings Time flag */
	long	tm_gmtoff;	/* offset from CUT in seconds */
	char	*tm_zone;	/* timezone abbreviation */
};
time_t time(time_t*);
struct tm *gmtime(const time_t *);
struct tm *gmtime_r(const time_t *);
struct tm *localtime(const time_t *);
struct tm *localtime_r(const time_t *);
time_t timegm(struct tm * const);
time_t mktime(struct tm *);

/* Dynamic loading */
void *dlopen(const char *filename, int flag);
char *dlerror(void);
void *dlsym(void *handle, const char *symbol);
int dlclose(void *handle);
int dladdr(void *addr, void *info);

/* Signals */
typedef void (*sighandler_t)(int);
int raise(int);
sighandler_t signal(int, sighandler_t);

/* System calls */
int sys_exit(int);
int sys_write(int, const char *, unsigned long);
int sys_read(int, char *, unsigned long);
int sys_fork(void);
