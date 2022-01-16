all: main.o BigInt.o
	g++ bin/*.o -o bin/test -I include

main.o: src/main.cpp bin
	g++ src/main.cpp -c -o bin/main.o -I include

BigInt.o: src/BigInt.cpp bin
	g++ src/BigInt.cpp -c -o bin/BigInt.o -I include

clean:
	rm bin

bin:
	mkdir bin

test: all
	bin/test

