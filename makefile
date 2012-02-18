FILES = src/*.c

reverse: $(FILES)
	cc $(FILES) -o reverse.out
