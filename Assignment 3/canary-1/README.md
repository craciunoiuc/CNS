# Canary 1

Flag: CNS_CTF{516045e02cdd565262fecdcc3210f031}

Tools: [`peda`, `pwntools`, `checksec`, `IDA`]

Description:
I first ran the program and then opened it inside IDA.
I saw that it uses `gets` and it was clear that that is a vulnerability.
I then realized that it printed the output using `printf` and that was vulnerable to format string attacks.
Finally, I saw the `flaggy` function and tried to call it, but realized that the stack canary was used.
To leak the canary I had to first use the format string attack to print the canary.
Then I extracted the canary from the output and created a payload to call the `flaggy` function.

To get the flag:
```
    ./exploit.py
```
