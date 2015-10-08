/**
 * @file fib.c
 * @brief This program calculates the n-th Fibonacci term using command line arguments.
 *
 * @author Marci McBride
 * @date Fall 2015
 * @bug None 
 */

#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h> /* getopt and optarg */

unsigned int func_max(void);
unsigned long *fib_array(unsigned int n);
int check_n(unsigned int n, unsigned int *max_n);

int main(int argc, char **argv)
{
        int n;
        int c;
        while((c = getopt(argc, argv, "n:")) != -1) {
                if (c == 'n') 
                        n = (unsigned int)atoi(optarg);
        }
        unsigned int max_n = func_max();
        // if check_n returns 0 then it can calculate the Fibonacci number
        if (check_n(n, &max_n) == 0){
                unsigned long *array = fib_array(n+1);
                printf("The %d Fibonacci term is %lu \n", n, array[n]);
                /* Freed the memory allocated */
                free(array);
        }
        else {
                printf("n is too large -- overflow will occur\n");
                printf("the largest Fibonacci term that can be calculated is %u \n", max_n);
        }
}

/**
* Function determines if you can calculate the n-th Fibonacci term or not.
* @param n is the nth term the user inputs
* @param max_n is the max number the n specified can calculate
* @return returns 0 if the given n is less than or equal to the maximum value and -1 if not.
*/
int check_n(unsigned int n, unsigned int *max_n)
{
        if (n <= *max_n)
                return 0; 
        else
                return -1;
}

/**
* Calculates the measured valeu of tthe fibonacci sequence for each n passed in.
* @param n is the largest n before overflow occurs. n was calculated in the max_n funciton.
* @return the value the formula calulates
*/
unsigned int func_max(void)
{
        unsigned long n;
        double formula = 0;

        for (n = 0; n < ULONG_MAX; n++) {
                formula = 1 / (sqrt(5)) * (pow(((1 + sqrt(5)) / 2) , (n + 1)) - pow(((1 - sqrt(5)) / 2) , (n + 1)));
                if ((unsigned long)formula == 0)
                        break;
        }
        return (unsigned int) n;
}

/**
* Calculates the ture fibonacci sequence using an array for each n passed in.
* @param n is the largest n before overflow occurs. n was calculated in the max_n funciton.
* @return the array
*/
unsigned long *fib_array(unsigned int n)
{
        unsigned long *array = (unsigned long*)malloc(sizeof(unsigned long) * n);
        array[0] = 0;
        array[1] = 1;
        int i = 2;
        for (; i < n; i++) {
                array[i] = array[i - 1] + array[i - 2];
        }
        return array;
}