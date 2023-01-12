CC=gcc
FLAGS=-Wall -Wextra

main: main.o
	$(CC) -o $@ $^ $(FLAGS)

main.o: main.c
	$(CC) -c $@ $^ $(FLAGS)

clean:
	rm main main.o
