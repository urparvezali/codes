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

unordered_map<ll,unordered_map<ll,ll>> memo;
ll rec(ll i,vll& v,ll sum){
	if(i == v.size()){
		return sum;
	}
	if(memo[i].count(sum)) return memo[i][sum];
	ll a=rec(i+1,v,sum + v[i]);
	ll b=rec(i+1,v,abs(sum + v[i]));

	return memo[i][sum]=max(a,b);
}

void solution(ll& T){
	ll n; cin>>n; vll v(n); cin>>v;
	memo.clear();
	ll ans=rec(0,v,0);
	cout << ans << endl;
}

signed main(){
	Parvez();
	ll TT=1;
	cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}
