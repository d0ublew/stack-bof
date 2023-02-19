#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

int bss_zero = 0;
int bss_uninit;
int data_ = 0x1337;
const int readonly = 0;

int main(int, char **);

void text_segment() {
    printf("main address: %p\n", main);
}

void rodata_segment() {
    printf("readonly address: %p\n", &readonly);
}

void data_segment() {
    static int stat = 5;
    printf("data_ address: %p\n", &data_);
    printf("stat address: %p\n", &stat);
}

void bss_segment() {
    printf("bss_zero address: %p\n", &bss_zero);
    printf("bss_uninit address: %p\n", &bss_uninit);
}

void heap_segment() {
    char *ptr = (char *)malloc(sizeof(char) * 8);
    printf("heap_ptr address: %p\n", ptr);
    free(ptr);
}

void mmap_segment() {
    void *mmap_1 = mmap(NULL, 8192, PROT_READ | PROT_WRITE,
                        MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    void *mmap_2 = mmap(NULL, 8192, PROT_READ | PROT_WRITE,
                        MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    void *mmap_3 = mmap(NULL, 8192, PROT_READ | PROT_WRITE,
                        MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    printf("mmap_1 address: %p\n", mmap_1);
    printf("mmap_2 address: %p\n", mmap_2);
    printf("mmap_3 address: %p\n", mmap_3);
}

void stack_segment() {
    char buf[8];
    printf("buf address: %p\n", buf);
}

void libc_function() {
    printf("printf address: %p\n", printf);
    printf("system address: %p\n", system);
}

int main(int argc, char **argv) {
    puts(".text segment");
    puts("=============");
    text_segment();
    puts("\n.rodata segment");
    puts("================");
    rodata_segment();
    puts("\n.data segment");
    puts("=============");
    data_segment();
    puts("\n.bss segment");
    puts("============");
    bss_segment();
    puts("\nheap segment");
    puts("============");
    heap_segment();
    puts("\nmmap segment");
    puts("=============");
    mmap_segment();
    puts("\nstack segment");
    puts("==============");
    stack_segment();
    puts("\nlibc function address");
    puts("======================");
    libc_function();
    return 0;
}
