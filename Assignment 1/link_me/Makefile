
build: libmumu.so

libmumu.so: mumu.o
	gcc -shared -o $@ $^

mumu.o: mumu.c
	gcc -c -Wall -Werror -fpic $^

run: build
	LD_LIBRARY_PATH=~/cns-assignments/assignment-1/link_me ./link_me

clean:
	rm -f mumu.o libmumu.so

