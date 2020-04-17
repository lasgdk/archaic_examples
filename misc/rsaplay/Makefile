rsaplay: rsaplay.o randprime.o is_prime.o get_d.o get_coprime.o
	cc -o rsaplay -lm rsaplay.o randprime.o is_prime.o get_d.o get_coprime.o
rsaplay.o randprime.o is_prime.o get_d.o get_coprime.o: rsaplay.h
	cc -c $*.c

clean:
	rm -f rsaplay *.o
