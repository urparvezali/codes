#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

#define endl '\n'
#define Parvez ios_base::sync_with_stdio(false);
#define Ali cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()

const ll mod = 998244353;
//const ll nprime = 10000000;
//vector<bool> prime(nprime,true);
void Y(){cout<<"Yes"<<endl;}
void N(){cout<<"No"<<endl;}
void M(){cout<<-1<<endl;}
void vecin(vll &v){for(auto &i:v)cin>>i;}
void vecout(vll &v){for(auto &i:v)cout<<i<<" ";}

void solution(ll &tc){
	ll n; cin>>n; vll v(n),vv(n);
	vecin(v); vecin(vv);
	// vecout(v);cout<<endl;
	// vecout(vv);cout<<endl;
	for (ll i = 0; i < v.size()-1; i++){
		if(v[i]>v[n-1]) swap(v[i],vv[i]);
		if(vv[i]>vv[n-1] && vv[i]<v[n-1]) swap(vv[i],v[i]);
	}
	bool yes=true;
	for (ll i = 0; i < n; i++){
		if(v[i]>v[n-1] or vv[i]>vv[n-1]){
			yes=false; break;
		}
	}
	if(yes==false){
		yes=true;
		swap(v[n-1],vv[n-1]);
		for (ll i = 0; i < v.size()-1; i++){
			if(v[i]>v[n-1]) swap(v[i],vv[i]);
			if(vv[i]>vv[n-1] && vv[i]<v[n-1]) swap(vv[i],v[i]);
		}
		for (ll i = 0; i < n; i++){
			if(v[i]>v[n-1] or vv[i]>vv[n-1]){
				yes=false; break;
			}
		}
		if(yes==true){
			Y(); return;
		}
		else N();
	}
	else{
		Y();return;
	}
}
signed main(){
	Parvez Ali
	ll tcs; tcs=1;
	cin>>tcs;
	for(ll tc=1;tc<=tcs;tc++)
		solution(tc);
	return 0;
}