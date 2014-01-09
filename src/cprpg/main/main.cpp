#include "config.h"
#include <cstdio>

int main(void) {
    printf("%d.%d.%d\n", VersionMajor, VersionMinor, VersionMicro);
    return 0;
}
