#include <stdio.h>
int max(int a, int b)
{
    if (a>b)
        return a;
    else
        return b;
}
void print(int a)
{
    for (int i = 0; i < a; i++)
    {
        printf("%d ",i);
    }
    printf("\n");
}
int main(){
    int m,n;
    scanf("%d %d", &m, &n);
    int ma = max(m,n);
    int mi = min(m,n);
    printf("%d %d",ma,mi);
    print(mi);
    return 0;
}















int rec(int n){
    if(n==0) return 0;
    return rec(n-1);
    printf("%d ",n);
    printf("\n");
}
void printname(){
    printf("Parvez Ali\n");
}

void printdept(){
    printf("Department of ICE!\n");
}