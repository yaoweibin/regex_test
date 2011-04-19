
#include <stdio.h>
#include <string.h>

int main()
{
    int i;
    char *pos, *p;
    char *substr = "q=";
    char *str = "http://www.google.com.hk/search?hl=zh-CN&newwindow=1&safe=strict&q=ipad&aq=f&aqi=g-s6g2g-s1g1&aql=&oq=";
    size_t len = strlen(substr);

    for (i = 0; i < 1000000; i++) {

        if (pos = strstr(str, substr)) {
            pos = pos + len;
            p = pos;

            while (*p != 0) {

                if (*p == '&') {
                    break;
                }

                p++;
            }
            /*printf("%.*s\n", p - pos, pos);*/
        }
    }

    return 0;
}
