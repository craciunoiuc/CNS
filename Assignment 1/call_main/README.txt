Flag: CNS_CTF{They're_coming_to_take_me_away_ha_ha}

Tools: objdump, gdb, nm, hexeditor

First I tried to use gdb but saw that main is not being reached.
This means, usually, that `_start` was modified to call something else.
I added a breakpoint in `_start` and after stepping I saw that `dummy` is called.

Afterwards I found the address of `main` with `nm` and edited the address set
in the rdi register with hexeditor to the `main` one.

Now the binary works and prints the flag:
```
	./call_main
```

