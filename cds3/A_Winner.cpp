#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solution(ll &T){
	ll n; cin>>n;
	unordered_map<string,ll> score;
	vector<pair<string,ll>> v(n);
	string s; ll x=0;
	for (ll i = 0; i < n; i++)
	{
		cin>>s>>x;
		score[s]+=x;
		v[i]=make_pair(s,score[s]);
	}
	ll mx=LONG_MIN;
	for(auto i:score) mx=max(mx,i.second);
	for(auto [nm,sc]:v){
		if(sc>=mx){
			cout<<nm<<endl;
			return;
		}
	}
}

signed main(){
	ll TT=1;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}



