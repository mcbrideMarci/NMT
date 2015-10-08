/**
 * @file fib_error.c
 * @brief Runs various values of n and times the results for each function.
 * @details The max values of n and the fragment for each function were given
 * Print out the values using the format n|sum|seconds.
 *
 * @author Marci McBride
 * @date Fall 2015
 * @bug For printpartd() each foo must be ran separatly because the code 
 * takes extremely long to execute. 
 */
#include <stdio.h>
#include <math.h>
#include <time.h>

unsigned long foo1(unsigned long n);
unsigned long foo2(unsigned long n);
unsigned long foo3(unsigned long n);
unsigned long foo4(unsigned long n);
unsigned long foo5(unsigned long n);
unsigned long foo6(unsigned long n);
unsigned printpartb(void);
unsigned printpartd(void);

int main()
{
        /* line 17 excecutes part b of the PDF given */
        // printpartb();
        /* lines 19 excecutes part d of the PDF given */
        printpartd();      

}

/**
* Runs each function with various values of n until max_n is reached.
* also times each function.
* @remarks  This is part b of the PDF
* @return 0
*/
unsigned printpartb(void)
{
        /* this function prints everyting the pdf wants in part b*/
        unsigned long max_n_array[6] = {1000000000, 100000, 1000,100000, 100, 100};
        /*unsigned long (*foo_array[6])(unsigned long) = {&foo1, &foo2, &foo3, &foo4, &foo5, &foo6};*/

        int i;
        unsigned long sum, n;
        int m = 0;

        printf("foo1\n");
        for (i = 0; i <= log10(max_n_array[m]); i++) {
                n = pow(10,i);
                clock_t start,end;  
                start = clock();
                sum = foo1(n);
                end = clock();
                printf("%lu|%lu|%2.6lf\n", n, sum, (double) (end - start) / CLOCKS_PER_SEC);
        }
        m += 1;
        
        printf("foo2\n");        
        for (i = 0; i <= log10(max_n_array[m]); i++){

                n = pow(10,i);
                clock_t start,end;  
                start = clock();
                sum = foo2(n);
                end = clock();
                printf("%lu|%lu|%2.6lf\n", n, sum, (double) (end - start) / CLOCKS_PER_SEC);
        }
        m += 1;

        printf("foo3\n");
        for (i = 0; i <= log10(max_n_array[m]); i++){
                n = pow(10,i);
                clock_t start,end;  
                start = clock();
                sum = foo3(n);
                end = clock();
                printf("%lu|%lu|%2.6lf\n", n, sum, (double) (end - start) / CLOCKS_PER_SEC);
        }
        m += 1;

        printf("foo4\n");
        for (i = 0; i <= log10(max_n_array[m]); i++){
                n = pow(10,i);
                clock_t start,end;  
                start = clock();
                sum = foo4(n);
                end = clock();
                printf("%lu|%lu|%2.6lf\n", n, sum, (double) (end - start) / CLOCKS_PER_SEC);
        }
        m += 1;

        printf("foo5\n");
        for (i = 0; i <= log10(max_n_array[m]); i++){
                n = pow(10,i);
                clock_t start,end;  
                start = clock();
                sum = foo5(n);
                end = clock();
                printf("%lu|%lu|%2.6lf\n", n, sum, (double) (end - start) / CLOCKS_PER_SEC);
        }
        m += 1;

        printf("foo6\n");
        for (i = 0; i <= log10(max_n_array[m]); i++){
                n = pow(10,i);
                clock_t start,end;  
                start = clock();
                sum = foo6(n);
                end = clock();
                printf("%lu|%lu|%2.6lf\n", n, sum, (double) (end - start) / CLOCKS_PER_SEC);
        }
        m += 1;
        return 0;
}

/**
* The value of each max n has been changed by a value of 10
* and the loop starts with the previous max n term and increment by that value
* @remarks Do the test for one function at a time. 
* This is part d of the PDF
* @return 0
*/
unsigned printpartd(void){
        unsigned long max_n_array[6] = {1000000000, 100000, 1000,100000, 100, 100};
        int i;
        unsigned long sum, n, place;
        int m = 0;
        place = max_n_array[m];
        FILE *fp;

        /* stdout info into file*/
        fp = freopen ("foo1.out","w", stdout);
        printf("foo1\n", stdout);
        for (i = place ; i <= place * 10; i += place ){
                clock_t start,end;  
                start = clock();
                sum = foo1(i);
                end = clock();
                printf("%d|%lu|%2.6lf\n", i, sum, (double) (end - start) / CLOCKS_PER_SEC);
        }
        m += 1;
        fclose(fp);

        printf("foo2\n", stdout);
        for (i = place ; i <= place * 10; i += place ){
                clock_t start,end;  
                start = clock();
                sum = foo2(i);
                end = clock();
                fp = freopen ("foo2.out", "a", stdout);
                printf( "%d|%lu|%2.6lf\n", i, sum, (double) (end - start) / CLOCKS_PER_SEC);
                fclose(fp);
        }
        m += 1; 

        printf("foo3\n", stdout);
        for (i = place ; i <= place * 10; i += place ){
                clock_t start,end;  
                start = clock();
                sum = foo3(i);
                end = clock();
                fp = freopen ("foo3.out", "a", stdout);
                printf("%d|%lu|%2.6lf\n", i, sum, (double) (end - start) / CLOCKS_PER_SEC);
                fclose(fp);
        }
        m += 1;
     
        printf("foo4\n", stdout);
        for (i = place ; i <= place * 10; i += place ){
                clock_t start,end;  
                start = clock();
                sum = foo4(i);
                end = clock();
                fp = freopen ("foo4.out", "a", stdout);
                printf("%d|%lu|%2.6lf\n", i, sum, (double) (end - start) / CLOCKS_PER_SEC);
                fclose(fp);
        }
        m += 1;
     
        printf("foo5\n", stdout);
        for (i = place ; i <= place * 10; i += place ){
                clock_t start,end;  
                start = clock();
                sum = foo5(i);
                end = clock();
                fp = freopen ("foo5.out", "a", stdout);
                printf( "%d|%lu|%2.6lf\n", i, sum, (double) (end - start) / CLOCKS_PER_SEC);
                fclose(fp);
        }
        m += 1;
     
        printf("foo6\n",stdout);
        for (i = place ; i <= place * 10; i += place ){
                clock_t start,end;  
                start = clock();
                sum = foo6(i);
                end = clock();
                fp = freopen ("foo6.out", "a", stdout);
                printf("%d|%lu|%2.6lf\n", i, sum, (double) (end - start) / CLOCKS_PER_SEC);
                fclose(fp);
        }

        return 0;
}

/**
* Calculates the sum for a given n
* @param various n's will be passed in until the max_n is reached.
* @return the sum of the function
*/
unsigned long foo1(unsigned long n)
{
        unsigned long sum = 0;
        int i; 
        for (i = 0; i < n; i++) { 
                sum++;
        }
        return sum;
}

/**
* Calculates the sum for a given n
* @param various n's will be passed in until the max_n is reached.
* @return the sum of the function
*/
unsigned long foo2(unsigned long n)
{
        unsigned long sum = 0;
        int i, j;
        for (i = 0; i < n; i++)
             for (j = 0; j < n; j++)
                sum++;
        return sum;
}

/**
* Calculates the sum for a given n
* @param various n's will be passed in until the max_n is reached.
* @return the sum of the function
*/
unsigned long foo3(unsigned long n)
{
        unsigned long sum = 0;
        int i, j;
        for (i = 0; i < n; i++)
             for (j = 0; j < n * n; j++)
                 sum++;
        return sum;
}

/**
* Calculates the sum for a given n
* @param various n's will be passed in until the max_n is reached.
* @return the sum of the function
*/
unsigned long foo4(unsigned long n)
{
        unsigned long sum = 0;
        int i, j;
        sum = 0;
        for (i = 0; i < n; i++)
             for(j = 0; j < i; j++)
                sum++;

        return sum;
}

/**
* Calculates the sum for a given n
* @param various n's will be passed in until the max_n is reached.
* @return the sum of the function
*/
unsigned long foo5(unsigned long n)
{
        unsigned long sum = 0;
        int i, j, k;
        sum = 0;
        for (i = 0; i < n; i++)
             for(j = 0; j < i * i; j++)
                 for(k = 0; k < j; k++)
                        sum++;

        return sum;
}

/**
* Calculates the sum for a given n
* @param various n's will be passed in until the max_n is reached.
* @return the sum of the function
*/
unsigned long foo6(unsigned long n)
{
        unsigned long sum = 0;
        int i, j, k;
        sum = 0;
        for (i = 1; i < n; i++)
             for(j = 1; j < i * i; j++)
                 if (j % i == 0)
                     for(k = 0; k < j; k++)
                         sum++;

        return sum;
}
