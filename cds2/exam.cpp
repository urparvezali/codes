// make a function that takes two integer arguments and return their sum
int sum(int a, int b){
    int s = a+b;
    return s;
}

// make a function that takes two integer arguments and return their multiplication
int mul(int a, int b){
    int m = a*b;
    return m;
}

// make a function that takes two integer arguments which swap them
void swap(int a,int b){
    int temp=a;
    a=b;
    b=temp;
}

// make a function that returns the factorial of a arguments
int fact(int a){
    if(a<=1) return 1;
    else
        return a * fact(a-1);
}

// make a function that print all the numbers from one to n
void printotoh(int n){
    if(n==0) return;
    else
        printotoh(n-1);
    printf("%d ",n);
}

// create a programme to take input a character and print it using pointer
#include <stdio.h>
int main(){
	char c;
    scanf("%c",&c);
    char *ptr = &c;
	printf("%c",*ptr);
	return 0;
}

// create a programme to print sum of one to nth number using loop statement
#include <stdio.h>
int main(){
    int num,sum = 0;
    scanf("%d", &num);
    for(int i = 1; i <= num; ++i){
        sum += i;
    }
    printf("Sum = %d", sum);
    return 0;
}

// create a function to return the biggest number which takes three arguments as integer
#include <stdio.h>
int biggest(int a, int b, int c){
    if(a>b && a>c)
        return a;
    else if(b>a && b>c)
        return b;
    else
        return c;
}
int main(){
    int x,y,z;
    scanf("%d %d %d", &x,&y,&z);
    int big = biggest(x,y,z);
    printf("%d", big);
    return 0;
}

// create a function that takes two arguments and return their gcd
int gcd(int a, int b){
   if (b == 0)
        return a;
    return gcd(b, a % b);
}
// create a programme that designs a pyramid using "*"
#include <stdio.h>  
void main()  {  
    int rows;  
    printf (" Enter a number to define the rows: \n");  
    scanf ("%d", &rows);   
    for (int i =1; i <= rows; i++)  {  
        for (int j = 1; j <= rows - i; j++){  
            printf (" ");   
        }  
        for (int k = 1; k <= ( 2 * i - 1); k++){  
            printf ("*");  
        }  
        printf ("\n");  
    }
}

// create a programme that takes two same dimensional metrix and print their sum
#include <stdio.h>
int main() {
	int r,c;
	scanf("%d %d",&r,&c);
	int a[r][c],b[r][c],sum[r][c];
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			scanf("%d",&a[i][j]);
		}
	}
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			scanf("%d",&a[i][j]);
		}
	}
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			sum[i][j]=a[i][j]+b[i][j];
			printf("%d ",sum[i][j]);
		}
		printf("\n");
	}
	return 0;
}

// create a programme that takes input as pi and print its value only 2 digit after point
#include <stdio.h>
int main() {
	float r;
	scanf("%f",&r);
	printf("%.2f",r);
	return 0;
}

// 