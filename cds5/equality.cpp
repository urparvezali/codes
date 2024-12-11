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


void solution(ll& T){
	ll n; cin>>n;
	vll v(n); cin>>v;
	// if(n==1){
	// 	cout<<0<<endl;return;
	// } else if(n==0){
	// 	cout<<0<<endl;return;
	// }
	// ll sum=0;sum+=accumulate(all(v),0LL);
	// ll d1,d2;
	// if(sum%n==0){
	// 	d1=sum/n;
	// 	d2=sum/n;
	// } else{
	// 	d1=sum/n;
	// 	d2=d1+1;
	// }
	// ll ans1=0,ans2=0;
	// for(auto& x:v) ans1+=abs(x-d1);
	// for(auto& x:v) ans2+=abs(x-d2);
	// cout<<min(ans1,ans2)<<endl;

	sort(all(v));
	ll mid = (n)/2;
	// cout<<v<<endl;
	// cout<<mid<<endl;

	ll ans = 0;
	for(auto &i: v) ans+=abs(i-v[mid]);
	cout<<ans<<endl;
	
}

signed main(){
	Parvez();
	ll TT=1;
	// cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}