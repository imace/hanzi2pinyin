#include "hanzi.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// How to test UTF-16 version

void test_onechar(const char *s, const char *expected_pinyin) {
    int n;
    UTF32 cp = hz_utf8_to_utf32(s, &n);

    /*
     *int i;
     *for (i = 0; i < n; i++)
     *    printf("%x ", s[i]);
     *puts("");
     */

    const char *pinyin = hz_pinyin_codepoint(cp);
    if (!pinyin) {
        printf("No pinyin found for: %s cp: %d\n", s, cp);
        return;
    }

    printf("%s %x %s\n", s, cp, pinyin);
    if (strcmp(pinyin, expected_pinyin) != 0) {
        printf("ERROR, expected_pinyin is: %s\n", expected_pinyin);
    }
}

int main(int argc, char* argv[])
{
    test_onechar("你", "ni");
    test_onechar("陈", "chen");
    test_onechar("苹", "ping");
    test_onechar("单", "dan");

    /* 0x4E06 has no pinyin */
    const char *pinyin = hz_pinyin_codepoint(0x4E06);
    assert(!pinyin);
    return 0;
}

