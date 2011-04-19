
#include <pcre.h>
#include <stdio.h>
#include <string.h>

#define OVECCOUNT 120

int main()
{
    const char *error;
    int   erroffset;
    pcre *re;
    int   rc;
    int   i;
    int   ovector[OVECCOUNT];

    char *regex = "q=([^&]+)";
    char str[]  = "http://www.google.com.hk/search?hl=zh-CN&newwindow=1&safe=strict&q=ipad&aq=f&aqi=g-s6g2g-s1g1&aql=&oq=";

    re = pcre_compile (
            regex,                /* the pattern */
            0,                    /* default options */
            &error,               /* for error message */
            &erroffset,           /* for error offset */
            0);                   /* use default character tables */

    if (!re) {
        printf("pcre_compile failed (offset: %d), %s\n", erroffset, error);
        return -1;
    }

    for (i = 0; i < 1000000; i++) {

        rc = pcre_exec (
                re,                   /* the compiled pattern */
                0,                    /* no extra data - pattern was not studied */
                str,                  /* the string to match */
                strlen(str),          /* the length of the string */
                0,                    /* start at offset 0 in the subject */
                PCRE_PARTIAL,         /* default options */
                ovector,              /* output vector for substring information */
                OVECCOUNT);           /* number of elements in the output vector */

        if (rc < 0) {
            switch (rc) {
            case PCRE_ERROR_NOMATCH:
                printf("String didn't match");
                break;
            case PCRE_ERROR_PARTIAL:
                printf("String patial match");
                break;

            default:
                printf("Error while matching: %d\n", rc);
                break;
            }
            free(re);
            return -1;
        }
    }

    /*
    for (i = 0; i < rc; i++) {
        printf("%2d: %.*s\n", i, ovector[2*i+1] - ovector[2*i], str + ovector[2*i]);
    }
    */
}
