/***********
* Marci M. McBride 
* CSE 122 HW0
* This program prints numbers from 1 to 100. For multiples of three prints Fizz,
* for the multiples of five prints Buzz and for multiples of both prints FizzBuzz
************/
#include <stdio.h>

int main()
{
        int i;
        for (i = 1 ; i <= 100; i++) {
                /*if the number (i) is a multiple of 5 and 3, FizzBuzz will be displayed*/
                if (((i % 3) == 0) && ((i % 5) == 0))
                        printf("FizzBuzz\n");
                
                /*if the number (i) is a multiple of 3, Fizz will be displayed */
                else if ((i % 3) == 0)
                        printf("Fizz\n");
                
                /*if the number (i) is a multiple of 5, Buzz will be displayed*/
                else if ((i % 5) == 0)
                        printf("Buzz\n");
                
                /*if the number (i) is a neither a multiple of 3 or 5 then the
                number will be displayed*/
                else
                        printf("%d\n", i);
        }
        return 0;
}