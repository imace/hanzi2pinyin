#ifndef _HANZI_H
#define _HANZI_H

#include "unicode.h"

/* XXX In the implementation of hanzi_sqlite.c, the memory returned is managed
 * by sqlite3. Calling this function again will destroy previously returned
 * data.
 * The implementation in hanzi_bindata.c does not have this problem. */
const char *hz_pinyin_codepoint(UTF32 cp);

#endif /* _HANZI_H */