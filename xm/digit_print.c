#include<stdio.h>
int main()
{
	int c=1;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			printf("%d ",c); 
			c++;
		}
		printf("\n");
	}
	
	return 0;
}