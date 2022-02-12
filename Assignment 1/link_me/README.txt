Flag: CNS_CTF{Come_on_Yolanda_whats_Fonzie_like?}

Tools: GDB-peda, IDA, ldd, nm

As the name suggested, it was something related to linking.
So, I ran ldd on the file to check for any extra libraries.
Like this I found `libmumu.so`.

Afterwards I ran a nm to check for any symbols marked as U (unresolved).
Two were interesting: `array_sum` and `string_xor_with_key`.
I supposed these were part of the missing library.

Then I ran IDA to check on how these functions were used/called.
Here I found the calling format of them.

Finally I build a Source File + Makefile that creates a shared library with
that name and linked it in.
After I saw that it worked I went with my gut and started filling the two
functions.
`string_xor_with_key` does a xor on all elements of a string.
`array_sum` sums all elements in an array.

To run the program:
```
	make run
	make clean
```
