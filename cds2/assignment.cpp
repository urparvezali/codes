#include <iostream>
#include <numeric>
using namespace std;
class Result {
	string name;
	double points[10];
	double credits[10]={3.00,1.50,3.00,1.50,3.00,0.75,3.00,3.00,0.75,0.75};;
	double GPA;

	public:
	void setName(){
		cin >> name;
	}
	string getName(){
		return name;
	}
	void setPoints(){
		for (int i = 0; i < 10; i++){
			cin>>points[i];
		}
	}
	double getCGPA(){
		GPA=0.00;
        for (int i = 0; i < 10; i++){
            GPA+=points[i]*credits[i];
        }
		return GPA/accumulate(credits,credits+10,0.00);
	}
};
signed main(){
	cout<<"Enter the number of students want to calculalate CGPA"<<endl;
	int numStu;
	cin >> numStu;
	Result stu[numStu];
	for (int i = 0; i < numStu; i++){
		cout<<"Enter the name of "<<i+1<<"th student"<<endl;
		stu[i].setName();
		cout<<"Enter the points of "<<stu[i].getName()<<" of 10 subjects acording to the syllabus"<<endl;
        stu[i].setPoints();
		cout<<"The CGPA of "<<stu[i].getName()<<" is "<<stu[i].getCGPA()<<"\n---------"<<endl;
	}
	return 0;
}