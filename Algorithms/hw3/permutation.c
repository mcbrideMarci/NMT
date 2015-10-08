/**
 * @permutation.c
 * @brief This program generates random permutations of the first n integers.
 * @details We will use three different algorithms to generate the random
 * permutations and time them.
 *
 * @author Marci McBride
 * @date Fall 2015
 * @bug none 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "randint.h"

int *lucky(int n);
int *used(int n);
int *knuth(int n);
void swap(int *one, int *two);

int main()
{
        seed();
        int n[4] = {250, 500, 1000, 2000};
        int b[6] = {2500, 5000, 10000, 20000, 40000, 80000};
        int c[7] = {10000, 20000, 40000, 80000, 160000, 320000, 640000};
        int i, j;
        double cnt;
        int *a;

        for (i = 0; i<=3; i++) {

                printf("run       n        time\n");
                for (j=1; j<11; j++) {
                        clock_t start,end;
                        start = clock();
                        a = lucky(n[i]);
                        end = clock();
                        cnt += ((double)(end - start) / CLOCKS_PER_SEC);
                        free(a);
                        printf("%-7d  %-7d   ", j, n[i]);
                        printf("%-7.4lf\n", (double) (end - start) / CLOCKS_PER_SEC);
                }
                cnt /= 10;
                printf("avg for n = %d for lucky is %0.4lf seconds\n", a[i], cnt);
        }
        

        for (i = 0; i<=5; i++) {

                printf("run       n        time\n");
                for (j=1; j<11; j++) {
                        clock_t start,end;
                        start = clock();
                        a = used(b[i]);
                        end = clock();
                        cnt += ((double)(end - start) / CLOCKS_PER_SEC);
                        free(a);
                        printf("%-7d  %-7d   ", j, b[i]);
                        printf("%-7.4lf\n", (double) (end - start) / CLOCKS_PER_SEC);
                }
                cnt /= 10;
                printf("avg for n = %d for used is %0.4lf seconds\n", b[i], cnt);
        }

        for (i = 0; i<=6; i++) {

                printf("run       n        time\n");
                for (j=1; j<11; j++) {
                        clock_t start,end;
                        start = clock();
                        a = knuth(c[i]);
                        end = clock();
                        cnt += ((double)(end - start) / CLOCKS_PER_SEC);
                        free(a);
                        printf("%-7d  %-7d   ", j, c[i]);
                        printf("%-7.4lf\n", (double) (end - start) / CLOCKS_PER_SEC);
                }
                cnt /= 10;
                printf("avg for n = %d for knuth is %0.4lf seconds\n", c[i], cnt);
        }

        return 0;   
}

/**
* Function fills the array A with random numbers that have not been used.
* @param n is the length of the array. 
* @return The pointer to the array A 
*/
int *lucky(int n)
{
        int i, j, rnum, here = 0;
        int *A = (int *) malloc(sizeof(int) *n);
        //A is an array
        for (i = 0; i < n; i++){
                A[i] = -1;
        }
        for (i = 0; i < n; i++) {
                while (A[i] == -1){
                        rnum = nrandint(n);
                        here = 0;
                        for (j = 0; j < i; j++) {
                                if (A[j] == rnum)
                                        here = 1;
                        }
                        if (here != 1)
                                A[i] = rnum;     
                }        
        }
        return A;
}

/**
* Function fills the array A with random numbers that have not been used 
* and keeps track of which numbers have been used.
* @param n is the length of the array. 
* @return The pointer to the array A 
*/
int *used(int n)
{
        int i, j, rnum;
        int *A = (int *) malloc(sizeof(int) *n);
        int *taken = (int *) malloc(sizeof(int) *n);
        for (i = 0; i < n; i++){
                A[i] = -1;
                taken[i] = 0;
        }
        for (i = 0; i < n; i++) {
                while (A[i] == -1){
                        rnum = nrandint(n);
                        if (taken[rnum] == 0) {
                                taken[rnum] = 1;
                                A[i] = rnum;
                        }
                }        
        }

        free(taken);
        return A;
}

/**
* Function Fills the array A with random numbers that have not been used.
* using swap
* @param n is the length of the array. 
* @return The pointer to the array a
*/
int *knuth(int n)
{
        int i;
        int *a = (int *) malloc(sizeof(int) *n);
        for (i = 0; i < n; i++){
                a[i] = i + 1;
        }
        for (i = 0; i < n; i++)
                swap(&a[i], &a[nrandint(n-1)]);

        return a;
}

/**
* Function waps the first number with the second one.
* @param one is the first number inputed
* @param two is the second number inputed. 
*/
void swap(int *one, int *two)
{
        int temp;
        temp = *one;
        *one = *two;
        *two = temp;
}
 
/**
 * returns a uniform random integer between 0 <= rand num <= range
 * @param range, defines the range of the random number [1,range]  
 * @return the generated random number
 */
int nrandint(int range) 
{
        return rand() % (range + 1);
}

/**
 * call this to seed the random number generator rand()
 * uses a simple seed -- the number of seconds since the epoch 
 * call once before using nrandint and similiar functions that call rand()
 */
void seed(void) 
{
        srand((unsigned int)time(NULL));
}