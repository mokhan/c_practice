SRCDIR 		:= src/
OBJDIR 		:= obj/
BINDIR 		:= bin/

PROGRAM 	:= practice
EXE 			:= $(BINDIR)$(PROGRAM)

C_FILES 	:= $(wildcard *.c) $(wildcard */*.c)
OBJS 			:= $(patsubst src/%.c, obj/%.o, $(C_FILES))
CC 				:= gcc
CFLAGS 		:= -Wall -pedantic
LDFLAGS 	:= 

all: init $(EXE)

$(EXE): .depend $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(EXE)

depend: .depend

.depend: cmd = gcc -MM -MF depend $(var); cat depend >> .depend;
.depend:
	@echo "Generating dependencies..."
	@$(foreach var, $(C_FILES), $(cmd))
	@rm -f depend

-include .depend

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SRCDIR)/%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	@echo 'cleaning...'
	@rm -fr *.o *.out .depend $(BINDIR) $(OBJDIR)

init: clean
	@echo 'initializing...'
	@mkdir bin obj

run: all
	$(EXE)

.PHONY: clean init depend

list:
	@echo $(C_FILES)
