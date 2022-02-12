Encrypted flag: 2107891f0d3b9626d192b35f418a5bb5b1de1ad1450fceb6efc14502a620e07af106e888c7c11eedca9523864626c80b1feec116f54022b1b8654c65b94c3eb7ebf1507eaf406da69ad2ee3a93623254f268698ecc6e99cd37ded145540474f843bf0395
Decrypted flag: CNSCTF_{Stream_ciphers_for_the_win}
Flag: CNS_CTF{Stream_ciphers_for_the_win}

Tools: IDA, readelf, nm, gdb-peda

I used IDA to look inside the enc_init function to try to guess the algorithm.
After dissassembling and rewriting the code I had it in a readable state.
Then I started looking at all the encryption algorithms on the internet that
I could find.
Finally, from the endless ocean of algorithms, I found RC4 that looked very
similar.

Afterwards, to find the flag to decrypt, I used `nm` and saw a symbol named
"bonus_flag".
I used the address from `nm` and `readelf` to extract only the portion with
the flag.

Finally I cleaned up the output of the command and pasted it on a decryption
website and got the flag.

The main challenge here was to find a list with all usable encryption
algorithms.
This is harder than it sounds.

