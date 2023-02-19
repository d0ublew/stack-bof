all:
	gcc -fno-stack-protector -no-pie -o chall-3-64 chall-3.c
	gcc -fno-stack-protector -no-pie -m32 -o chall-3-32 chall-3.c
	clang --target=i386-pc-linux-elf -o chall-3-32-clang chall-3.c
