#include<stdio.h>
#include <math.h>
int main(){
    int height,width,result;
    printf("Enter height and weight of rectangle \n");
    scanf("%d %d",&height,&width);
	int re = (height*height) + (width * width);
	int res = sqrt(re);
    printf("Corno is: %d\n",res);
    return 0;
}