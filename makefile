FILES = src/*.c

rover: $(FILES)
	gcc $(FILES) -o rover.out
