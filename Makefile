CFLAGS = -Wall -g

simple_brute: simple_brute.c
	gcc $(CFLAGS) simple_brute.c -o simple_brute

clean:
	rm -f simple_brute
