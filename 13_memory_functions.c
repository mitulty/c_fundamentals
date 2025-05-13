/**
 * @author: Mitul Tyagi
 * @description: Memory Functions in libc
 */
/*
- The functions memcmp, memcpy, memmove and memset are vital for our system and
are used throughout the standard libaries (e.g. calloc, realloc). These
functions are also used during the startup process, when code move any
relocatable sections and initialize variables in the bss section to 0.
- The memset() function is used to set all the bytes in a block memory to
particular value. This is used to set a memory location to null character '\0'.
            void *memset(void *dest,int c,size_t count);
- The memcpy() function is used to copies bytes of data between memory blocks.
This will copy "count" characters from the string "src" into the memory pointed
to by "dest".
            void *memcpy(void *dest,void *src,size_t count);
- The memmove() function moves block of memory.
            void *memmove(void *dest,void *src,size_t count);
- The C library memcmp() function can be used to compare two blocks of memory.
In general, it is used to compare the binary data or raw data. It returns a
value < 0 if str1<str2 ; value > 0 if st2 < str1 and value ==0 if both are
equivalent. The paramter n defines the number of bytes to be compared.
            int memcmp(const void *str1, const void *str2, size_t n)
- A weak symbol can be overridden by another function definition.
- Weak symbols allow you to keep a generic implementation that is portable
across platforms. If you have an optimized version valid only for specific
platforms, you can override the default implementation and get the optimization
benefits for that platform.

*/
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int memcmp(const void *p1, const void *p2, size_t n)
{
    size_t i;

    /**
     * p1 and p2 are the same memory? easy peasy! bail out
     */
    if (p1 == p2)
    {
        return 0;
    }

    // This for loop does the comparing and pointer moving...
    for (i = 0; (i < n) && (*(uint8_t *)p1 == *(uint8_t *)p2);
         i++, p1 = 1 + (uint8_t *)p1, p2 = 1 + (uint8_t *)p2)
        ;

    // if i == length, then we have passed the test
    return (i == n) ? 0 : (*(uint8_t *)p1 - *(uint8_t *)p2);
}
int memcmp_new(const void *vl, const void *vr, size_t n)
{
    const unsigned char *l = vl, *r = vr;
    for (; n && *l == *r; n--, l++, r++)
        ;
    return n ? *l - *r : 0;
}
void *__attribute__((weak)) memset_new(void *dest, int c, size_t n)
{
    unsigned char *s = dest;
    size_t k;

    /* Fill head and tail with minimal branching. Each
     * conditional ensures that all the subsequently used
     * offsets are well-defined and in the dest region. */

    if (!n)
        return dest;
    s[0] = s[n - 1] = c;
    if (n <= 2)
        return dest;
    s[1] = s[n - 2] = c;
    s[2] = s[n - 3] = c;
    if (n <= 6)
        return dest;
    s[3] = s[n - 4] = c;
    if (n <= 8)
        return dest;

    /* Advance pointer to align it at a 4-byte boundary,
     * and truncate n to a multiple of 4. The previous code
     * already took care of any head/tail that get cut off
     * by the alignment. */

    k = -(uintptr_t)s & 3;
    s += k;
    n -= k;
    n &= -4;
    n /= 4;

    uint32_t *ws = (uint32_t *)s;
    uint32_t wc = c & 0xFF;
    wc |= ((wc << 8) | (wc << 16) | (wc << 24));

    /* Pure C fallback with no aliasing violations. */
    for (; n; n--, ws++)
        *ws = wc;

    return dest;
}
void *__attribute__((weak)) memmove(void *s1, const void *s2, size_t n)
{
    return memcpy(s1, s2, n);
}
char message1[60] = "Four score and seven years ago ...";
char message2[60] = "abcdefghijklmnopqrstuvwxyz";
char temp[60];

int main(int argc, char *argv[])
{
    printf("\nmessage1[] before memset():\t%s", message1);
    memset(message1 + 5, '@', 10);
    printf("\nmessage1[] after memset():\t%s", message1);

    strcpy(temp, message2);
    printf("\n\nOriginal message: %s", temp);
    memcpy(temp + 4, temp + 16, 10);
    printf("\nAfter memcpy() without overlap:\t%s", temp);
    strcpy(temp, message2);
    memcpy(temp + 6, temp + 4, 10);
    printf("\nAfter memcpy() with overlap:\t%s", temp);

    strcpy(temp, message2);
    printf("\n\nOriginal message: %s", temp);
    memmove(temp + 4, temp + 16, 10);
    printf("\nAfter memmove() without overlap:\t%s", temp);
    strcpy(temp, message2);
    memmove(temp + 6, temp + 4, 10);
    printf("\nAfter memmove() with overlap:\t%s\n", temp);
    {
        char str1[15];
        char str2[15];
        int ret;

        memcpy(str1, "abcdef", 6);
        memcpy(str2, "ABCDEF", 6);

        ret = memcmp(str1, str2, 5);

        if (ret > 0)
        {
            printf("str2 is less than str1");
        }
        else if (ret < 0)
        {
            printf("str1 is less than str2");
        }
        else
        {
            printf("str1 is equal to str2");
        }
        printf("\n");
    }
    return 0;
}
