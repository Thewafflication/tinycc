/* Aligned allocation paired with _mm_free; no platform CRT extension required. */
#ifndef _MM_MALLOC_H_INCLUDED
#define _MM_MALLOC_H_INCLUDED
#include <stdlib.h>
#include <stdint.h>
static __inline__ void *_mm_malloc(size_t size, size_t alignment)
{
    void *base, *aligned;
    size_t extra;
    if (!alignment || (alignment & (alignment - 1))) return NULL;
    if (alignment < sizeof(void *)) alignment = sizeof(void *);
    extra = alignment - 1 + sizeof(void *);
    if (size > (size_t)-1 - extra) return NULL;
    base = malloc(size + extra);
    if (!base) return NULL;
    aligned = (void *)(((uintptr_t)base + extra) & ~(uintptr_t)(alignment - 1));
    ((void **)aligned)[-1] = base;
    return aligned;
}
static __inline__ void _mm_free(void *p)
{
    if (p) free(((void **)p)[-1]);
}
#endif
