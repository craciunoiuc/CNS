# Fibonacci

Tools: [`peda`, `pwntools`, `checksec`, `IDA`, `ROPgadget`]

Flag: CNS_CTF{2923b48b850742e1ec7c096e3d617cb5}

Description:
This task was extremely similar to Canary 2.
You had to call `system` from libc with `/bin/sh` from libc too.
The solution was to first call `puts@plt` to leak `puts@got` to see the address of `puts@libc`.
Then with this you could calculate the offset of `system@libc`.
The only difference from Canary 2 was that you needed to send some extra numbers to make the program exist the while loop.

To get the flag:
```
    ./exploit.py
```
