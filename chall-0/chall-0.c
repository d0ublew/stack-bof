#include <stdio.h>
#include <string.h>

int global_var = 5;

int main(int argc, char **argv) {
    int temp = 0;
    char overflow[16];
    char buf[16];
    char safe[] = {"ItIsSafeHere!!!"};
    memset(overflow, 0, sizeof(overflow));
    gets(buf);
    buf[15] = '\0';
    overflow[15] = '\0';
    printf("buf: %s\n", buf);
    printf("overflow: %s\n", overflow);
    printf("safe: %s\n", safe);
    int result = memcmp(overflow, safe, 16);
    if (result == 0) {
        puts("Win!");
    }
    return 0;
}
