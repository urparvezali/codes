#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define endl '\n'
#define Parvez ios_base::sync_with_stdio(false);
#define Ali cin.tie(NULL); cout.tie(NULL);

void Y(){cout<<"Yes"<<endl;}
void N(){cout<<"No"<<endl;}
signed main(){
	Parvez Ali
	ll tcs;
	cin>>tcs;
	for(ll tc=1;tc<=tcs;tc++){

		ll n,x,p; cin>>n>>x>>p;
		bool yeap=0;
		for (ll i = 1; i <=min(p,2*n); i++){
			if((i*(i+1)/2)%n==(n-x)%n){
				yeap=1; break;
			}
		}

		if(yeap)Y(); else N();
	}
	return 0;
}