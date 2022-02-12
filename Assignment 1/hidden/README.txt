Flag found: CNS_CTF{The_zombies_were_having_fun_the_party_had_just_begun}

Tools used: GDB-peda, IDA, nm, strings

Steps to solve:

First I ran the program and nothing happend.
I then tried to use GDB and saw that the main function was empty.
This means that everything happens in another function.

After running strings and nm I saw that the flag is encoded inside the file.
Afterwards I started IDA and loaded the binary.
There were multiple potentially useful functions, but, to not waste I tried to run them all by setting the `$rip` inside GDB.
`set $rip = 0x...`

One of them printed the message that the function with the flag has 4 arguments.
Luckily only one function had 4 arguments so I focused on that.

After disassembling the function I saw that the 4 arguments are:
```
	RCX: 0x601144 --> 0x5a4c5552 ('RULZ')
	RDX: 0x4654 ('TF')
	RSI: 0x4353 ('SC')
	RDI: 0x4e43 ('CN')
```

I lost some time without realizing that fastcall was used while I tried to write to the stack.

Finally after filling as above, it worked.

To replicate, the peda commands are:
```
	start
	n
	n
	set $rip = 0x400599
	set $rcx = 0x601144
	set $rdx = 0x4654
	set $rsi = 0x4353
	set $rdi = 0x4e43
	context
	c
```

