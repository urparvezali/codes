#include <bits/stdc++.h>
#include <math.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<bool> vbl;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vstr;
typedef vector<pll> vpll;

#define endl '\n'
#define all(x) x.begin(),x.end()
constexpr ll mod = 1000000007;

ll rec(ll x, vll& dp){
	if(x<7) return ll(pow(2, x-1))%mod;

	ll z=0;
	for (ll i=1; i<7; i++) {
		if(dp[x-i]!=-1)
			z=(z+dp[x-i])%mod;
		else{
			dp[x-i]=rec(x-i,dp);
			z=(z+dp[x-i])%mod;
		}
	}
	return z;
}
void solution(ll &T){
	ll n; cin>>n;
	vll dp(1000000,-1);
	cout<<rec(n,dp)<<endl;
}

signed main(){
	ll TT=1;
	// cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}