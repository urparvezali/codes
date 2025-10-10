#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void Y(){cout<<"YES"<<endl;}
void N(){cout<<"NO"<<endl;}

void solution(ll &T){
	ll s,n;
	cin>>s>>n;
	vector<pair<ll,ll>> v(n);
	for (ll i = 0; i < n; i++)
	{
		cin>>v[i].first>>v[i].second;
		//cout<<v[i].first<<" "<<v[i].second<<endl;
	}
	sort(v.begin(),v.end());
	for (ll i = 0; i < n; i++)
	{
		if(s>v[i].first){
			s+=(v[i].second);
		}
		else{
			N();return;
		}
	}
	Y();
}


signed main(){
	ll TT=1;
	// cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}