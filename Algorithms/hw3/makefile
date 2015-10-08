# Marci M. McBride
# CSE122 HW3
# 
# build an executable named permutation 
all: permutation russian
	make permutation
	make russian 

permutation: permutation.c
	gcc -g -lm permutation.c -o permutation
	
russian: russian.c
	gcc -g -lm russian.c -o russian


# remove the executable file, as well as old .o object files.
clean: 
	rm permutation
	rm russian 
	rm *.o