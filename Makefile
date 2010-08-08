CFLAGS = -g -O0

prime: main.o bits.o
	$(CC) $(CFLAGS) -o $@ main.o bits.o

main.o: main.c
	$(CC) $(CFLAGS) -c -o main.o main.c

bits.o: bits.c
	$(CC) $(CFLAGS) -c -o bits.o bits.c

clean:
	rm -rf prime main.o bits.o autom4te.cache config.log config.status configure *~
