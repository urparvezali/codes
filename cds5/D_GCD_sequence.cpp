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




void solution(ll& T){
	ll n; cin>>n; vll v(n); cin>>v;
	vll g(n-1);
	for(ll i=0; i < n-1; i++){
		g[i]=gcd(v[i],v[i+1]);
	}
	if(is_sorted(all(g))){
		print("YES"); return;
	}
	// print(g);
	vll pre(g.size());
	ll mx=g[g.size()-1];
	for(ll i=g.size()-1; i >=0; i--){
		pre[i]=mx;
		mx=min(mx,g[i]);
	}
	// print(pre);
	ll cnt=0;
	for(ll i=0; i < g.size(); i++){
		if(g[i]>pre[i]) cnt++;
	}
	if(cnt>1){
		print("NO"); return;
	}



	bool flag=false;
	for(ll i=0; i < n-2; i++){
		if(i==g.size()-2){
			continue;
		} else if(i==0 and i+1<g.size() and g[i]>g[i+1]){
			flag=true;
		} else if(g[i]>g[i+1] and !flag){
			if(i-1>=0 and i+1<g.size() and gcd(v[i-1],v[i+1])<g[i+1]){
				flag=true;
			}
			if(i+2<g.size() and gcd(v[i],v[i+2])<g[i+1]){
				flag=true;
			}
		} else if(g[i]>g[i+1] and flag){
			print("NO"); return;
		}
	}
	print("YES");
}

signed main(){
	Parvez();
	ll TT=1;
	cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}