/****
*Marci McBride
*CSE 122 
*Using Newton’s method this program will find the cube root 
*of the numbers from 1 to 100
********/
#include <stdio.h>
#include <math.h>

void findSqrt(int num)
{
        double epsilon = 0.00000001;
        double test = 0;
        double estimate = num; 
        int cnt = 0;
        while (fabs(num - test) > epsilon) {
                cnt++;
                //Newtons formula:
                estimate = estimate - (test - num) / (3 * estimate * estimate);
                test = estimate * estimate * estimate;
        }
        printf("%d|%d|%3.10f\n", cnt, num, estimate);
}

int main()
{

        int i;
        for (i = 1; i <= 100; i++) {
         findSqrt(i);
        }
        return 0;
}