# Pure shellcode

Flag: CNS_CTF{c57d8b44974ea272c516614b5c168e7d}

Tools: [`peda`, `nasm`, `pwntools`, `checksec`, `objdump`]

Description:
This challenge was more difficult than I thought.
This was because of 2 reasons.
 1. That I got to solving it too early and the binary was broken.
 2. Because it was particularly hard to find a working shellcode.
Now, getting back to it:

The binary was very simple and featured only the main function with a read and a write.
No interesting rop gadgets were to be found, but thankfully the stack was pushed in `_start` and it was executable.
Because of this the attack was done in 2 stages.

The first stage builds a payload to leak rbp + rip + rsp and overwrites the rip with the address of main.
The program now restarts from main.
The second stage contains the shellcode itself padded with a lot of nops and the address to the shellcode (the leaked rsp).

The shellcode does a simple `execve('/bin//sh')`, but it was very hard to build a working one as most would either ruin the stack or plain not work.

With the payloads built and the shellcode done, I could get the flag.

To get the flag:
```
    ./exploit.py
```
