#include <stdio.h>

void win() {
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
    /* char buf[16]; */
    /* gets(buf); */
    vuln();
    return 0;
}
