#include<stdio.h>
int main()
{
	int b,a;
	for(a=1;a<=4; a++)
	{
		for(b=1;b<=a;b++)
		{
			printf("%d ",b);
		}
		printf("\n");
	}
	for(int i=0; i<4;i++)
	printf("5 ");
	return 0;
}