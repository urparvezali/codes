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



void dfs(ll x, vpll &v, string& s, ll cnt, ll& ans){
	// print(x,cnt,ans);
	if(cnt>=ans) return;
	if(v[x].first==0 and v[x].second==0){
		ans=min(ans,cnt);
		return;
	}

	if(v[x].first!=0 and s[x-1]=='L') dfs(v[x].first,v,s,cnt,ans);
	if(v[x].first!=0 and s[x-1]!='L') dfs(v[x].first,v,s,cnt+1,ans);
	if(v[x].second!=0 and s[x-1]=='R') dfs(v[x].second,v,s,cnt,ans);
	if(v[x].second!=0 and s[x-1]!='R') dfs(v[x].second,v,s,cnt+1,ans);
}

void solution(ll &T){
	ll n; input(n); string s; input(s);
	vpll v(n+1);
	ll ans=INT_MAX;
	for (ll i = 0; i < n; i++){
		ll x,y; input(x,y);
		v[i+1]={x,y};
	}

	dfs(1,v,s,0,ans);
	print(ans);
	// for(auto& i:v) print(i.first,i.second);print();
}

int32_t main(){
	Parvez();
	ll TT=1;
	cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}

