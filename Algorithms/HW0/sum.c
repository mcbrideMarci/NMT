/***********
* Marci M. McBride 
* CSE 122 HW0
* This program calculates the sum of (3k-1). k will have the following values: 
* 1, 10, 10**2, 10**3, 10**4, 10**5, 10**6, 10**7, 10**8 and 10**9
************/
#include <stdio.h>
#include <math.h>
#include <time.h>

void sum(unsigned int k, unsigned int arrayValues[3])
{
        unsigned int total = 0;
        int i;
        for (i = 1; i <= k; i++) {
            /* formula given */
           total += ((3 * i) - 1);
        }
        arrayValues[0] = i;
        arrayValues[1] = k;
        arrayValues[2] = total;
}

void results(unsigned int k)
{
        unsigned int arrayValues[3];
        /*timing the algorithm*/
        clock_t start,end;
        start = clock();
        sum(k, arrayValues);
        end = clock();
        /*print the values in the array and how long the algorithm took*/
        printf("%d|%d|%d|", arrayValues[0], arrayValues[1], arrayValues[2]);
        printf("%3.24lf\n", (double) (end - start) / CLOCKS_PER_SEC);
}

int main()
{
        /*keep calling the function results with the desired input*/
        results(1);
        results(10);
        results(pow(10,2));
        results(pow(10,3));
        results(pow(10,4));
        results(pow(10,5));
        results(pow(10,6));
        results(pow(10,7));
        results(pow(10,8));
        results(pow(10,9));
        return 0;
}