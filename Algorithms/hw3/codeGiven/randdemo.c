#include <stdio.h>
#include "randint.h"

int main(void)
{
        int i = 0;
        seed(); 
        for (i = 0; i < 10; i++) 
                printf("%d\n", nrandint(10));

        return 0;
}

