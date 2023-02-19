#include <stdio.h>
#include <string.h>

void win(int arg1, int arg2) {
    if (arg1 != 31337) {
        puts("wrong");
        return;
    }

    if (arg2 != -1337) {
        puts("wrong");
        return;
    }

    puts("Win!");
}

void vuln() {
    char buf[16];
    printf("Buf: ");
    gets(buf);
}

void setup() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

int main(void) {
    setup();
    vuln();
    return 0;
}
