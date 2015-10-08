/**
 * @file fib_error.c
 * @brief This program finds the largest value of n it can use before overflow occurs
 *and investigate the error between finding Fibonacci terms using an equation 
 *and finding it using an array, Fn = Fn−1 + Fn−2
 * @details The equation that will be used to calculate Fibonacci sequence is
 *1/(sqrt(5)) * (pow(((1+sqrt(5))/2) , (n + 1)) - pow(((1-sqrt(5))/2) , (n + 1)));
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
        unsigned long *array = fib_array(theMax);
        int i;

        for (i = 0; i < theMax; i++) { 
                printf("f[%d] = %ld\n", i, array[i]);
        }
        for (i = 1; i < theMax; i++) {
                /* the array value is the true value */
                /* and the fib value measured value */
                if  (array[i] != (unsigned long) fib(i - 1)) {
                        printf("error in %d term of formula Fibonacci\n", i);
                        printf("term deffer by %lu\n", (unsigned long)fib(i - 1) - (unsigned long)array[i]);
                        relative_error(fib(i-1), array[i]);
                }
        }
        /* made sure to free the array */
        free(array);
        return 0;

}

/**
* Calculates and prints the relavitive error, two paramaters are passed into it.
* @param MeasValue is the measured value we calculated by using the equation
* @param trueValue is the true value we clculated using an array.
* @return 0
*/
unsigned long relative_error(double MeasValue, unsigned long trueValue)
{
         double re = 0;
         re = ((MeasValue - trueValue) / (trueValue)) * 100;
         printf("percentage error %.18f %%\n", re);
         return 0;
}

/**
* Determines the largest n before overflow occurs.
* @remarks fourmula keeps the calculated total of the formula for each n
* @return the largest n before overflow occurs
*/
unsigned int max_n(void)
{
        unsigned long n;
        double formula = 0;
        for (n = 0; n < ULONG_MAX; n++) {
                formula = 1 / (sqrt(5)) * (pow(((1 + sqrt(5)) / 2) , (n + 1)) - pow(((1 - sqrt(5)) / 2) , (n + 1)));
                if ((unsigned long)formula == 0)
                        break;
        }
        return (unsigned int) (n);
}

/**
* Calculates the measured valeu of tthe fibonacci sequence for each n passed in.
* @param n is the largest n before overflow occurs. n was calculated in the max_n funciton.
* @return the value the formula calulates
*/
double fib(unsigned int n)
{
        double fn = 0;
        fn = 1 / (sqrt(5)) * (pow(((1 + sqrt(5)) / 2) , (n + 1)) - pow(((1 - sqrt(5)) / 2) , (n + 1)));
        return fn;
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
        for(; i < n; i++){
                array[i] = array[i - 1] + array[i - 2];
        }
        return array;
}