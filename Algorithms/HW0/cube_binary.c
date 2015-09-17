/****
*Marci McBride
*CSE 122 
*Find the cube root of the numbers 1 to 100 using a binary search approach.
********/
#include <stdio.h>
#include <math.h>

void findCube(int num)
{
        double epsilon = 0.00000001;
        double test = 0;
        double lower = 0;
        double high = num;
        double medium = 0;
        int cnt = 0;
        
        while (fabs(num - test) > epsilon) {
                cnt++;
                medium = (lower + high) / 2;
                test = medium * medium * medium;
                if (num > test)
                        lower = medium;
                else if (num < test)
                        high = medium;
        }
        printf("%d|%d|%3.10f\n", cnt, num, medium);
}

int main()
{
        int i;
        for (i = 1; i <= 100; i++) {
         findCube(i);
        }
        return 0;
}