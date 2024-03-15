#include <bits/stdc++.h>
using namespace std;

int main(){
	string s; cin>>s;
	string user;
	for(int i=s.size()-1; i > 0; i--){
		if(!(s[i]>='0' and s[i]<='9')) break;
		if(s[i]!='0' and s.substr(0,i)!="user" and s.substr(0,i)!="us"){
			user=s.substr(0,i);
		}
	}
	cout<<user;
}
