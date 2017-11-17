all:
	gcc fork.c

run: all
	./a.out

clean:
	rm -rf *.out
	rm -rf *#
	rm -rf *~
