/***********
* Marci M. McBride 
* CSE 122 HW0
* This program calculates the sum of (3k-1). k will have the following values: 
* 1, 10, 10**2, 10**3, 10**4, 10**5, 10**6, 10**7, 10**8 and 10**9
* same as sum.c except without using for loops
************/
#include <stdio.h>
#include <math.h>
#include <time.h>

void sum(unsigned int k, unsigned int arrayValues[2])
{
        unsigned int total = 0;
        int i;

        arrayValues[0] = k;
        arrayValues[1] = ((3 * k * (k + 1)) / 2) - k;
}

void results(unsigned int k)
{
        unsigned int arrayValues[2];
        clock_t start,end;
        start = clock();
        sum(k, arrayValues);
        end = clock();
        
        printf("%d|%d|", arrayValues[0], arrayValues[1]);
        printf("%3.24lf\n", (double) (end - start) / CLOCKS_PER_SEC);
}
int main()
{
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
        
        

