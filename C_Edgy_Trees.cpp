#include <bits/stdc++.h>
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
#define rall(x) x.rbegin(),x.rend()
constexpr ll mod=1000000007;

inline void Parvez(){ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); }
template<class T>inline istream& operator>>(istream& in,vector<T>& v){ for(T& x:v){ in>>x; }return in; }template<class T>inline ostream& operator<<(ostream& out,vector<T>& v){ for(ll i=0;i<v.size()-1;i++){ out<<v[i]<<' '; }out<<v[v.size()-1];return out; }
inline void input(){}template<class H,class... T>inline void input(H&& h,T &&...t){ cin>>h;input(forward<T>(t)...); }inline void print(){ cout<<endl; }template<class H,class... T>inline void print(H&& h,T &&...t){ cout<<h;if(sizeof...(t)!=0)cout<<' ';print(forward<T>(t)...); }


ll mbpow(ll a, ll b){
	a %= mod;
	ll r = 1;
	while (b > 0){
		if (b & 1)
			r = r * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return r;
}

void dfs(ll s, vvll& v, vbl& vs, ll& cnt){
	if(vs[s]) return;
	cnt++;
	vs[s]=true;
	for(auto& i: v[s])
		dfs(i,v,vs,cnt);
}

void solution(ll& T){
	ll n,k; cin>>n>>k;
	vvll v(n+1,vll());
	for(ll i=0; i < n-1; i++){
		ll x,y,z; cin>>x>>y>>z;
		if(z!=1){
			v[x].push_back(y);
			v[y].push_back(x);
		}
	}
	vbl vs(n+1); vs[0]=true;
	ll ans = mbpow(n,k);
	ll sum = 0;
	for (ll i = 1; i < n+1; i++)
	{	ll cnt=0;
		if(!vs[i]){
			dfs(i,v,vs,cnt);
		}
		// cout<<cnt<<endl;
		ans -=mbpow(cnt,k);
		ans+=mod;
		ans%=mod;
	}
	
	print(ans);

	// for(ll i=1; i < v.size(); i++){
	// 	cout<<i<<": ";
	// 	for(ll j=0; j < v[i].size(); j++){
	// 		cout<<v[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
}

signed main(){
	Parvez();
	ll TT=1;
	// cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}