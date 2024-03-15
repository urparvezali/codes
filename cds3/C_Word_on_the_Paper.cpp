#include <bits/stdc++.h>
using namespace std;

void solution(){
	string s;char c;
	for (int i = 0; i < 64; i++){
		cin>>c;
		if(c!='.')
		s+=c;
	}
	cout<<s<<endl;
}

signed main(){
	long TT=1;
	cin>>TT;
	for(long T=1;T<=TT;T++)
		solution();
	return 0;
}