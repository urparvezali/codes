#include <bits/stdc++.h>
using namespace std;
bool flag=false;
int BS(vector<int>& arr,int low,int high,int find){
	int mid=(low+high)/2;
	if(high<low)
		return -1;
	if(arr[mid]==find)
		return mid;

	if(find<arr[mid])
		return BS(arr,low,mid-1,find);
	else
		return BS(arr,mid+1,high,find);

}

int main(){
	int n;
	cout << "Enter the length of the array:" << endl;
	cin >> n;

	vector<int> v(n);
	cout << "Enter the elements of the array:" << endl;
	for(int i=0; i < n; i++){
		cin >> v[i];
	}

	// Sorting the vector in ascending order
	sort(v.begin(),v.end());


	int toFind;
	cin>>toFind;
	int low=0,high=v.size()-1;

	int p=BS(v,low,high,toFind);

	if(p==-1)
		cout<<"Not found";
	else
		cout<<"Found at "<<p;


}