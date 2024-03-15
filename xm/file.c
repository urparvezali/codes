#include<stdio.h>
int main()
{
	FILE *tr;
	tr= fopen("test.txt","w");
	int roll;
	char name[50];
	printf("Enter your name: ");
	scanf("%s",name);
	printf("Enter your roll: ");
	scanf("%d",&roll);
	fprintf(tr,"My name is %s\n",name);
	fprintf(tr,"My roll is %d",roll);

	fclose(tr);
	return 0;
}