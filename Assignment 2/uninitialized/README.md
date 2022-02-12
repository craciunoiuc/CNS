# Uninitialized

Flag: CNS_CTF{d1511f0a9fc717c859885f3456c161c2}

Tools: [`gdb`, `pwntools`]

Description:

The trick for this challenge was to find the offset of the uninitialized n to overwrite.
The value to overwrite had to point to the last byte, the null byte.

Read 1: The offset to overwrite at.
In our case this is the offset on the stack to n@verify_idx: -2148
Read 2: The value to overwrite with.
In our case this need to be +19 (so that `strlen` returns 0): pack(19)

I lost a lot of time here because my payload got blocked as `fgets` waits for EOF or newline.
Also, it seems basic arithmetics is not my strong suite.


To get the flag:
```
	./exploit.py
```

