/**
 * @russian.c
 * @brief implements the Russian Peasant Algorithm
 * http://mathforum.org/dr.math/faq/faq.peasant.html
 * @details the first value is m and the second value is n 
 * and  m · n will be calculated. m and n are positive integers.
 * 
 * @author Marci McBride
 * @date Fall 2015
 * @bug none
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 4096

int multiplication(int m, int n);

int main()
{

        char s[MAX];
        int cnt = 0;
        while (fgets(s, MAX, stdin) != NULL) {
                int m = atoi(strtok(s, " "));
                int n = atoi(strtok(NULL, " "));
                if (cnt == 0)
                        printf("%d * %d = %d", m, n, multiplication(m,n));
                else 
                        printf("\n%d * %d = %d", m, n, multiplication(m,n));
                cnt +=1;
        }
        return 0;
}

/**
* Function adds m whenever n is odd, doubles m and halfs n until n is 1
* @param m the first number that will be doubled
* @param n the second number that will be halfed 
* @return  the sum which is m * n
*/
int multiplication(int m, int n)
{
        /* m is the first number
         n is the second number
         */
        int sum;
        sum = 0;

        // will excecute if the number is odd
        while (n != 0){
                if (n%2) 
                        sum += m;
                m += m; 
                n /= 2;
        }
        return sum;
}