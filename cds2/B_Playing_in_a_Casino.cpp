#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define endl '\n'
#define Parvez ios_base::sync_with_stdio(false);
#define Ali cin.tie(NULL); cout.tie(NULL);

void solution(ll &tc){
	ll n,m; cin>>n>>m;
	ll a[n][m];
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
			cin>>a[i][j];
	ll sum=0;
	for (ll i = 0; i < n-1; i++)
		for (ll j = i+1; j < n; j++)
			for (ll k = 0; k < m; k++)
				sum+=abs(a[i][k]-a[j][k]);
	cout<<sum<<endl;
}


signed main(){
	Parvez Ali
	ll tcs; tcs=1;
	cin>>tcs;
	for(ll tc=1;tc<=tcs;tc++)
		solution(tc);
	return 0;
}