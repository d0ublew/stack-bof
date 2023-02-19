#include <stdint.h>
#include <stdio.h>

int global_var = 5;

int main(int argc, char **argv) {
    uint8_t temp = 0;
    int16_t ov_int_2 = 1337;
    uint16_t ov_int_1 = 1337;
    char overflow[16];
    char buf[16];
    gets(buf);
    buf[15] = '\0';
    overflow[15] = '\0';
    printf("buf: %s\n", buf);
    printf("overflow: %s\n", overflow);
    printf("ov_int_1: %hu\n", ov_int_1);
    printf("ov_int_2: %hd\n", ov_int_2);
    if (ov_int_1 == 31337 && ov_int_2 == -31337) {
        puts("Win!");
    }
    return 0;
}
