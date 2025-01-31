bulls_and_cows.out: not_guesser.o guesser.o
	gcc bulls_and_cows.c not_guesser.o guesser.o -o bulls_and_cows.out


guesser.o: guesser.c
	gcc guesser.c -c guesser.o

not_guesser.o: not_guesser.c
	gcc not_guesser.c -c not_guesser.o

clean:
	rm -f *.o *.out