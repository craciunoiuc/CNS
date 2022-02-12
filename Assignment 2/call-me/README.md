# call-me

Flag: CNS_CTF{9c93fd0146341991b637611e8662953e}

Tools: [`IDA`, `gdb`, `python`, `objdump`, `hexeditor`]

Description:

This challenge was very similar to the ones in the previous assignment.
The first step was to find the call me function in the binary. Found it as `__call_me`.
Afterwards, I used `objdump` + `IDA` to find the exact place where to overwrite some code.
Decided to overwrite the `validate_hash` function as it served no purpose and it was at the end.
Used `python` + `objdump` (as shown below) to find the address to write over `validate_has` with `hexeditor`.
Finally, as nothing was outputted, I used `gdb` to go over `__call_me` and see things of interest.
That's when I spotted the flag on the stack and I was able to get it.

To calculate the offset and check if it is correct, you can use the following:
```
hex(0xffffffff - (0x4014eb - 0x401561 -1))
objdump -D -M intel ./call_me | grep -B 10 "<__libc_csu_init>" | grep call -A 1
```

To get the flag, in gdb:
```
start flag
b __call_me
r
n 10 (spam and look at the top of the stack)
```