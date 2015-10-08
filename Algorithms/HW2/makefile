# Marci M. McBride
# CSE122 HW2
# 
# build an executable named fib_error from fib_error.c
# build an executable named fib from fib.c
# build an executable named foo from foo.c
all:
	gcc -g -lm fib_error.c -o fib_error
	gcc -g -lm fib.c -o fib
	gcc -g -lm foo.c -o foo

# remove the executable file, as well as old .o object files and *~ backup files:
clean: 
	rm fib_error
	rm fib
	rm foo
	rm *.o *~