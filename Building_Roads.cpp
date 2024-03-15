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
constexpr ll mod = 1000000007;

inline void Parvez(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
inline void YES(){cout<<"YES"<<endl;}
inline void NO(){cout<<"NO"<<endl;}
inline void MINUS(){cout<<-1<<endl;}

inline void print(){cout<<endl;}template<class H,class... T>inline void print(H &&h,T &&...t){cout<<h;if(sizeof...(t)!=0)cout<<' ';print(forward<T>(t)...);}template<class T>inline void print(vector<T> &v){for(auto &i:v){cout<<i;if(&i!=&v.back())cout<<' ';}cout<<endl;}inline void input(){}template<class H,class... T>inline void input(H &&h,T &&...t){cin>>h;input(forward<T>(t)...);}template<class T>inline void input(vector<T> &v){for(auto &i:v)cin>>i;}
#define print(...) print(__VA_ARGS__);
#define input(...) input(__VA_ARGS__);

void dfs(ll s, vbl &vs, vvll &v){
	if (vs[s])
		return;
	vs[s] = 1;
	for (auto &c : v[s])
		dfs(c, vs, v);
}
void solution(ll &T){
	ll v,e; input(v,e);
	vvll g(v,vll ());
	for (ll i = 0; i < e; i++){
		ll x,y; input(x,y);
		g[x-1].push_back(y-1);
		g[y-1].push_back(x-1);
	}

	// for(auto& u:g) print(u);
	vbl vs(v,false);
	vll starts;
	for (ll i = 0; i < v; i++){
		if(!vs[i]){
			starts.push_back(i);
			dfs(i,vs,g);
		}
	}
	print(starts.size()-1);
	for (ll i = 0; i < starts.size()-1; i++){
		print(starts[i]+1,starts[i+1]+1);
	}
}

signed main(){
	Parvez();
	ll TT=1;
	// cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}