/**
 * @file fib_error.c
 * @brief A brief description of what the file does).
 * @details
 *
 * @author Marci McBride
 * @date Fall 2015
 * @bug None 
 */
 #include <stdio.h>
 #include <limits.h>
 #include <math.h>
 #include <stdlib.h>

unsigned int max_n(void);
double fib(unsigned int n);
unsigned long * fib_array(unsigned int n);
int main()
{
        printf("Max n before overflow occurs >> %d\n", max_n());
        return 0;
}
unsigned int max_n(void)
{
        unsigned long n;
        double formula = 0;
        for(n=0; n<ULONG_MAX; n++) {
                formula = 1/(sqrt(5)) * pow(((1+sqrt(5))/2) , (n + 1));
                if (formula == INFINITY)
                        break;
        }
        return (unsigned int) (n-1);
}
double fib(unsigned int n)
{
        double fn = 0;
        fn = 1/(sqrt(5)) * (pow(((1+sqrt(5))/2) , (n + 1)) - pow(((1-sqrt(5))/2) , (n + 1)));
        return n;
}
unsigned long * fib_array(unsigned int n)
{
        unsigned long *array = (unsigned long*)malloc(sizeof(unsigned long) * n);
        array[0] = 0;
        array[1] = 1;
        int i = 2;
        for(; i < n; i++){
                array[i] = fib(i - 1);
        }
        return array;


}