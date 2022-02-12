Flag: CNS_CTF{Asta-i_tuica_de_Tulcea}

Tools: gdb, objdump, nm, hexeditor, IDA

First, I assumed it was similar to `call_me` so I went to look inside `main`.
There I found again plenty of NOPs for a `call` and 2 extra movs.

I opened the file inside IDA and saw the `call_me` function.
I edited the NOPs to jump to the function, but I got a segmentation fault.
I saw that it also needed 2 arguments to be set correctly.

The first argument was easy to set, it was just a number (0x1337).
The second one was a bit harder.
As you can see when running, I overwrote the message displayed by the program.
This is because I needed space to write 3 bytes ('CNS') and give an address.
After writing, I gave the address (instead of 0x12345678) and it worked.

The binary now prints the flag.
```
	./call_me_reloaded
```
