PROGRAM = practice
C_FILES := $(wildcard *.c)
OBJS := $(patsubst %.c, %.o, $(C_FILES))
CC = cc
CFLAGS = -Wall -pedantic
LDFLAGS = 

all: $(PROGRAM)

$(PROGRAM): .depend $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(PROGRAM)

depend: .depend

.depend: cmd = gcc -MM -MF depend $(var); cat depend >> .depend;
.depend:
	@echo "Generating dependencies..."
	@$(foreach var, $(C_FILES), $(cmd))
	@rm -f depend

-include .depend

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f *.o *.out .depend

.PHONY: clean depend

list:
	@echo $(C_FILES)
