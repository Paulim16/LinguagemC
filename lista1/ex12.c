#include <stdio.h>
int main()
{
    int n, i, a, b = -1, seq = 0, seqf = 0;
    scanf("%d", &n);
 
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
 
        if (a > b)
        {
            seq++;
        }
        else
        {
            if (seq > seqf)
            {
                seqf = seq;
            }
            seq = 1;
        }
 
        b = a;
    }
 
    if (seq > seqf)
    {
        seqf = seq;
    }
    printf("O comprimento do segmento crescente maximo e: %d\n", seqf);
    return 0;
}