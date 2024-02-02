# PROG is the name of the executable file we want to generate
PROG = strings 

# OBJS is the list of .o files we want the C compiler to generate
OBJS = strings.o

# Pattern rule which compiles all .c files into .o equivalent
%.o: %.c
	gcc -c -g -o $@ $<

# Linker rule which combines all .o files and C RTL into executable
$(PROG): $(OBJS)
	gcc -g -o $@ $^

clean:
	rm -rf $(PROG) $(OBJS)
