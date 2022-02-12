# Piece of cake

Tools: [`peda`, `IDA`, `pwntools`, `ROPgadget`, `checksec`]

Flag: CNS_CTF{db70613f2f45109dfbb301ca1bdcdcd5}

Description:
This task was very straight-forward, but I lost a huge amount of time on complicated solutions.

What I tried in order, before realizing how easy it was:
 * Writing `/bin/sh` on the stack and using it to call system - didn't work because the stack was mapped at a different address.
 * Using `libc.so.6` from other tasks to leak address offsets with `printf` - didn't work because `fgets` read too little data. (88 bytes vs 80 max)
 * Pivoting the stack to `.data` with a fixed address to know exactly where `/bin/sh` is written - didn't work because of unknown reasons. Probably the addresses were mapped diferently (I tried bruteforcing ~10k pages and there were no write permissions)

Finally, I realized there was an `sh` already in the binary and I used that to call `system` and it worked.

To get the flag:
```
    ./exploit.py
```
