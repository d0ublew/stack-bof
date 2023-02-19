#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int global_var = 1;

void modify_global_var() {
    global_var *= 2;
}

void win(int arg1, int arg2) {
    if (global_var != 8) {
        puts("wrong");
        return;
    }

    puts("Win!");
}

void fun2(const char *buf) {
    char tmp[64];
    strcpy(tmp, buf);
}

void fun1() {
    char buf[512];
    printf("Buf: ");
    int nbytes = read(STDIN_FILENO, buf, sizeof(buf));
    if (nbytes < 0) {
        perror("read() error");
        exit(EXIT_FAILURE);
    }
    fun2(buf);
}

void setup() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

int main(void) {
    setup();
    fun1();
    return 0;
}
