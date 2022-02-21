TARGET=bin/test
CC=g++
CPPFLAGS=-Iinclude -Wall
OBJECTS = $(patsubst src/%.cpp,bin/%.o,$(wildcard src/*.cpp))

$(TARGET): $(OBJECTS)
	$(CC) $(CPPFLAGS) -o $@ $^

bin/%.o: src/%.cpp bin
	$(CC) $(CPPFLAGS) -c -o $@ $<

clean:
	rm bin/*

bin:
	mkdir bin

test: all
	$(TARGET)
