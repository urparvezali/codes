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

template<class T>inline istream& operator>>(istream& in,vector<T>& v){ for(T& x:v){ in>>x; }return in; }template<class T>inline ostream& operator<<(ostream& out,vector<T>& v){ for(ll i=0;i<v.size()-1;i++){ out<<v[i]<<' '; }out<<v[v.size()-1];return out; }





void solution(ll& T){
	ll h,n; cin>>h>>n; vll a(n),c(n); cin>>a; cin>>c;
	vpll v(n);
	for(ll i=0; i < n; i++){
		v[i]={ a[i],c[i] };
	}
	sort(rall(v));
	vll tm(n,0); ll t=*max_element(all(c));
	ll ans=0;
	while(h>0){
		for(ll i=0; i < n; i++){
			if(v[i].second<=t-tm[i]){
				tm[i]=t;
				h-=v[i].first;
				break;
			}
		}
		ans++;
		t++;
	}
	cout<<ans<<endl;
}

signed main(){
	ll TT=1;
	cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}