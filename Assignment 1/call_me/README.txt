Flag: CNS_CTF{You_talk_the_talk_do_you_walk_the_walk}

Tools: objdump, hexeditor, nm, gdb-peda

First I ran the program in gdb and saw that there are a lot of nop operations
at the end of the main file.
This shouldn't happen so that means that something was overwritten there.

The name of the challenge is `call_me`, this means that we need to call
something.
I used `nm` and found a function called `call_me`.

I tried overwriting the NOPs with the Call (E8) and the address, but I lost a
lot of time as I did not realize that the call address is relative.
After realizing this I calculated the relative address and wrote it once more.

The binary now does the call correctly.
```
	./call_me
```

