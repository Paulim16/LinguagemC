#include <stdio.h>
#include <math.h>
int main()
{
 
    int hip;
    int c1, c2, n, aux1;
    double aux2;
 
    scanf("%d", &n);
 
    for (hip = 5; hip <= n; hip++)
    {
        for (c1 = 1; c1 <= n; c1++)
        {
            for (c2 = 1; c2 <= n; c2++)
            {
                if ((hip * hip) == ((c1 * c1) + (c2 * c2)))
                {
                    if (c1 < c2)
                    {
                        printf("hipotenusa = %d, catetos %d e %d\n", hip, c1, c2);
                    }
                }
            }
        }
    }
 
    return 0;
}