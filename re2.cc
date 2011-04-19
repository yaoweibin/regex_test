
#include <assert.h>
#include <re2/re2.h>
#include <re2/stringpiece.h>

#include <string>
#include <iostream>

int main()
{
    int i;
    std::string s;
    const char *url = "http://www.google.com.hk/search?hl=zh-CN&newwindow=1&safe=strict&q=ipad&aq=f&aqi=g-s6g2g-s1g1&aql=&oq=";
    RE2 re("q=([^&]+)");

    assert(re.ok());

    for (i = 0; i < 1000000 ; i++) {
        if (RE2::PartialMatch(url, re, &s) == 1 ) {
            //std::cout << s << std::endl; 
        }
    }

    return 0;
}
