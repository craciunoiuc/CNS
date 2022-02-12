# Hello service

Flag: CNS_CTF{5d96641cfea639e335c7124ebe905363}

Tools: [`IDA`, `gdb`, `pwntools`, ``]

Description:
I first ran the file and saw that, after a size it outputed more than required.
Then I opened it in IDA and saw that it used `string.h` functions to calculate sizes.
As such, if there as no Null byte, it would output some characters more (until a self applied null flag).
Then I saw that everything was wrote in the same place so, you could get access to the flag 1 character at a time.
Afterwards, I inspected the read_flag function and saw that it did a rolling xor on the flag.

All that was left was to write an exploit script that does `strlen(flag)` connections and reads the flag 1 byte at a time.
Then it would rolling xor the flag again and print it.
After doing this, it worked, and I was able to get the flag.

To get the flag:
```
    ./exploit.py
```

