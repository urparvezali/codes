#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

#define endl '\n'
#define Parvez ios_base::sync_with_stdio(false);
#define Ali cin.tie(NULL); cout.tie(NULL);
void vecin(vll &v){for(auto &i:v)cin>>i;}

void solution(ll &tc){
	ll n,k,d,w; cin>>n>>k>>d>>w;
	vll v(n); vecin(v);
	ll ot=v[0],cd=0,c=1;
	for (ll i = 0; i < n; i++)
	{
		if(cd<k and v[i]-ot-w<=d){
			cd++;
		}
		else{
			c++; ot=v[i]; cd=1;
		}
	}
	cout<<c<<endl;
}
signed main(){
	Parvez Ali
	ll tcs; tcs=1;
	cin>>tcs;
	for(ll tc=1;tc<=tcs;tc++)
		solution(tc);
	return 0;
}