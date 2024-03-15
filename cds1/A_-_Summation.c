#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdalign.h>

int main(){
    long int n; scanf("%ld",&n);
    long int ar[n];
    long int sum = 0;
    for (long int i = 0; i < n; i++)
    {
        scanf("%ld",&ar[i]);
        sum+=ar[i];
    }
    long int s = labs(sum);
    printf("%ld\n",s);
    return 0;
}