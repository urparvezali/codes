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

ll ncr(ll n,ll r){
	ll t=1;
	for(ll i=1; i <= r; i++,n--){
		t*=n;
	}
	ll d=1;
	for(ll i=2; i <= r; i++){
		d*=i;
	}
	return t/d;
}

void solution(ll& T){
	ll n; input(n);
	vll v(n); input(v);
	if(n<3){ print(0);return; }
	sort(all(v));

	// print(v);
	map<ll,ll> mp;
	for(auto& u:v)mp[u]++;
	vpll p;
	for(auto& u:mp)p.push_back(make_pair(u.first,u.second));
	ll ans=0;
	ll cnt=0;
	for(ll i=0; i < p.size(); i++){
		if(i==0){
			cnt+=p[i].second;
			if(p[i].second>=3){
				ans+=ncr(p[i].second,3);
			}
			continue;
		}
		if(p[i].second==2){
			ans+=cnt;
		} else if(p[i].second>2){
			ans+=ncr(p[i].second,3);
			ans+=ncr(p[i].second,2)*cnt;
		}
		
		cnt+=p[i].second;
	}
	print(ans);
}

int32_t main(){
	Parvez();
	ll TT=1;
	cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}

