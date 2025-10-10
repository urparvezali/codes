#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define Parvez ios_base::sync_with_stdio(false);
#define Ali cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
void solution(ll &tc){
	ll l,r; cin>>l>>r;
	string le=to_string(l),ri=to_string(r);
	ll maxi=-1,a=0;
	for (ll i = max(l,r-100); i <= r; i++){
		string s=to_string(i);
		char lo=*min_element(all(s));
		char hi=*max_element(all(s));
		ll maxd=hi-48;
		ll mind=lo-48;
		if(maxi<=maxd-mind){
			maxi=maxd-mind;
			a=i;
		}
	}
	cout<<a<<endl;
}


signed main(){
	Parvez Ali
	ll tcs; tcs=1;
	cin>>tcs;
	for(ll tc=1;tc<=tcs;tc++)
		solution(tc);
	return 0;
}