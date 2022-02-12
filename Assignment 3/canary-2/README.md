# Canary 2

Flag: CNS_CTF{9bf632118c90f4c6e0f50d918493a56d}

Tools: [`peda`, `pwntools`, `checksec`, `IDA`]

Description:
The main difference between this and Canary 1 was that the `flaggy` function was removed.
To bypass this `system` had to be called from libc.
The solution to this was a combination between Canary 1 and Classic (from SIS assignment 2).
The solution is a 2 stage attack were you first leak the canary and puts@got (puts from libc).
With these you call main again and calculate the position of `/bin/sh` and `system` in libc.
Finally you call `system` from libc.

To get the flag:
```
    ./exploit.py
```
