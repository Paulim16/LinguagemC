#include <stdio.h>

int main() {
    int i,z, n1, n2;
    scanf("%d",&n1);
    scanf("%d",&n2);

    int *q1 = NULL;
    int *q2 = NULL;
    q1 = (int *) malloc(n1*sizeof(int));
    q2 = (int *) malloc(n2*sizeof(int));

    for (i=0;i<n1;i++) scanf("%d",&q1[i]);
    for (i=0;i<n2;i++) scanf("%d",&q2[i]);


    for(i=0;i<=999999;i++){
        for(z=0;z<n1;z++){
            if(q1[z]==i) printf("%d\n",q1[z]);
        }
        for(z=0;z<n2;z++){
            if(q2[z]==i) printf("%d\n",q2[z]);
        }
    }


    free(q1);
    free(q2);
    return 0;
}