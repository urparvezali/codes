#include <stdio.h>

float get_gpa(float mark);

int main(){
	int stu_num;
	int sub_num;

	FILE *file;
	file = fopen("students.txt", "w");

	printf("Enter the number of students : \n");
	scanf("%d", &stu_num);

	printf("Enter the number of subjects : \n");
	scanf("%d", &sub_num);

	struct Student{
		char name[100];
		int roll;
		float marks[sub_num];
		float gpa;
	};
	struct Student stu[stu_num];

	for (int i = 0; i < stu_num; i++){
		printf("Enter stu-%d name : \n", i + 1);
		scanf("%s", &stu[i].name);

		printf("Enter the Roll of %s : \n", stu[i].name);
		scanf("%d", &stu[i].roll);

		float sum=0;
		for (int j = 0; j < sub_num; j++){
			printf("Enter mark of subject %d: \n", j+1);
			scanf("%f",&stu[i].marks[j]);
		}
		for (int j = 0; j < sub_num; j++){
			sum+=get_gpa(stu[i].marks[j]);
		}
		stu[i].gpa = sum/sub_num;

		fprintf(file, "Name : %s\nRoll : %d\nMarks : ", stu[i].name, stu[i].roll);
		for (int j = 0; j < sub_num; j++){
			fprintf(file, "%0.2f ", stu[i].marks[j]);
		}
		fprintf(file, "\nGPA : %0.2f\n", stu[i].gpa);
		printf("\n");
	}
	fclose(file);

	file = fopen("students.txt", "r");
	char c;
	while ((c = getc(file)) != EOF){
		printf("%c", c);
	}
	printf("\n");
	fclose(file);

	file = fopen("marksheet.txt","w");
	for (int i = 0; i < stu_num; i++){
		fprintf(file,"roll: %d \t gpa: %.2f \n",stu[i].roll,stu[i].gpa);
	}
	fclose(file);

	FILE *mfile;
	mfile = fopen("marksheet.txt","r");
	while ((c=getc(file))!=EOF){
		printf("%c",c);
	}
	fclose(mfile);

	return 0;
}


float get_gpa(float mark){
	if(mark>=80) return 4;
	else if(mark>=75) return 3.75;
	else if(mark>=70) return 3.50;
	else if(mark>=65) return 3.25;
	else if(mark>=60) return 3.00;
	else if(mark>=55) return 2.75;
	else if(mark>=50) return 2.50;
	else if(mark>=45) return 2.25;
	else if(mark>=40) return 2.00;
	else return 0;
}