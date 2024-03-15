#include <bits/stdc++.h>
using namespace std;
signed main(){
	long t;
	cin>>t;
	while (t--){
		long a,b; cin>>a>>b;
		if(abs(a)==abs(b))
			cout<<2*max(abs(a),abs(b))<<endl;
		else
			cout<<2*max(abs(a),abs(b))-1<<endl;
	}
}