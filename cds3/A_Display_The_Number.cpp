#include <bits/stdc++.h>
using namespace std;
void solution(){
	long n; cin>>n;
	if(n%2 and n>2){
		cout<<7;
		n-=3;
	}
	string s(n/2,'1');
	cout<<s<<'\n';
}
int main(){
	long TT;
	cin>>TT;
	while(TT--)
		solution();
	return 0;
}