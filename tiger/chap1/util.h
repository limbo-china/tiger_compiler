//util.h

#include <assert.h>

typedef char *string;
string String(char *s);

typedef char bool;
#define TRUE 1
#define FALSE 0

void *checked_malloc(int);