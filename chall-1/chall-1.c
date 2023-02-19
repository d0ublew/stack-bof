#include <stdint.h>
#include <stdio.h>

int global_var = 5;

int main(int argc, char **argv) {
    uint8_t temp = 5;
    uint8_t ov_int = 10;
    char overflow[16];
    char buf[16];
    gets(buf);
    buf[15] = '\0';
    overflow[15] = '\0';
    printf("buf: %s\n", buf);
    printf("overflow: %s\n", overflow);
    printf("ov_int: %hhu\n", ov_int);
    printf("temp: %hhu\n", temp);
    if (ov_int == 97) {
        puts("Win!");
    }
    return 0;
}
