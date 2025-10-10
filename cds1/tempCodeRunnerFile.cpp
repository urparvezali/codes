int rec(int n){
    if(n==0) return 0;
    return rec(n-1);
    printf("%d ",n);
    printf("\n");
}