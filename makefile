.phony: all
all: subdirs play test doxy

subdirs:
	mkdir -p src catch tests bin
	+$(MAKE) -C src
	+$(MAKE) -C catch
	+$(MAKE) -C tests

play:
	g++ -std=c++2a src/tower.o src/main.o -o bin/play

test:
	g++ -std=c++2a src/tower.o catch/catchmain.o tests/tests.o -o bin/test

doxy:
	doxygen

clean:
	rm -f src/*.o catch/*.o test/*.o
	rm -rf html bin