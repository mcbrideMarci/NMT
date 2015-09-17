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
unsigned long relative_error(double MeasValue, unsigned long trueValue);
int main()
{
        unsigned int theMax = max_n();
        // printf("%ld\n", theMax);
        unsigned long *array = fib_array(theMax);
        int i;
        for (i=0; i< theMax; i++){
                printf("f[%d] = %ld\n", i, array[i]);
        }
        for (i=1; i< theMax; i++){
                // the array value is the true value
                // and the fib value measured value
                if  (array[i] != (unsigned long) fib(i-1)) {
                        printf("error in %d term of formula Fibonacci\n", i);
                        printf("term deffer by %lu\n", (unsigned long)fib(i-1) - (unsigned long)array[i]);
                        relative_error(fib(i-1), array[i]);
                }
        }
        free(array);
        return 0;

}
unsigned long relative_error(double MeasValue, unsigned long trueValue)
{
         double re = 0;
         re = ((MeasValue - trueValue) / (trueValue)) * 100;
         printf("percentage error %.18f %%\n", re);
         return 0;
}
unsigned int max_n(void)
{
        unsigned long n;
        double formula = 0;
        for(n=0; n<ULONG_MAX; n++) {
                formula = 1/(sqrt(5)) * (pow(((1+sqrt(5))/2) , (n + 1)) - pow(((1-sqrt(5))/2) , (n + 1)));
                if ((unsigned long)formula == 0)
                        break;
        }
        return (unsigned int) (n);
}
double fib(unsigned int n)
{
        double fn = 0;
        fn = 1/(sqrt(5)) * (pow(((1+sqrt(5))/2) , (n + 1)) - pow(((1-sqrt(5))/2) , (n + 1)));
        return fn;
}
unsigned long *fib_array(unsigned int n)
{
        unsigned long *array = (unsigned long*)malloc(sizeof(unsigned long) * n);
        array[0] = 0;
        array[1] = 1;
        int i = 2;
        for(; i < n; i++){
                array[i] = array[i - 1] + array[i - 2];
        }
        return array;
}