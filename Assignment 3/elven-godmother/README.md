# Elven Godmother

Tools: [`peda`, `pwntools`, `IDA`, `checksec`]

Flag: CNS_CTF{7d68968119deb2413ab2041f698aa6d6}

Description:
This challenge was very similar to the others.
It was a classic ret-to-libc challenge.
I won't go into detail related to ret-to-libc, because I explained the steps in code comments and in the other challenges.
Its twist was that, unlike the other challenges, it was on 32 bits.
This made the overwriting of addresses a bit harder as I was out of touch.
There was no need for any ropchains as no registers needed to be set.
I lost a bit of time with buffer sizes and parsing the output.

To get the flag:
```
    ./exploit.py
```
