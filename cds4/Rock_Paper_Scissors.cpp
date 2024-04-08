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

inline void Parvez(){ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); }
inline void print(){ cout<<endl; }template<class H,class... T>inline void print(H&& h,T &&...t){ cout<<h;if(sizeof...(t)!=0)cout<<' ';print(forward<T>(t)...); }template<class T>inline void print(vector<T>& v){ for(auto& i:v){ cout<<i;if(&i!=&v.back())cout<<' '; }cout<<endl; }inline void input(){}template<class H,class... T>inline void input(H&& h,T &&...t){ cin>>h;input(forward<T>(t)...); }template<class T>inline void input(vector<T>& v){ for(auto& i:v)cin>>i; }

/* prs */


void solution(ll& T){
	ll n; input(n);
	string s; input(s);
	string r(n,'*');
	ll cnt=0;
	for(ll i = n-1; i >= 0; i--,cnt++){
		if(cnt<=n/2){
			if(s[i]=='R'){
				r[i]='P';
			} else if(s[i]=='P'){
				r[i]='S';
			} else{
				r[i]='R';
			}
		} else{
			r[i]='P';
		}
	}
	cnt=0;
	for(ll i = 0; i < n; i++){
		if(s[i]=='R' and r[i]=='P') cnt++;
		else if(s[i]=='P' and r[i]=='S') cnt++;
		else if(s[i]=='S' and r[i]=='R') cnt++;
	}
	if(cnt>ll(n/2)+1){
		cnt=cnt-ll(n/2)-1;

		for(ll i = 0; i < n and cnt; i++){
			if(r[i]=='S' and s[i]=='P'){
				r[i]='P';cnt--;
			} else if(r[i]=='R' and s[i]=='S'){
				r[i]='P'; cnt--;
			}
		}
	}
	print(r);
}

int32_t main(){
	Parvez();
	ll TT=1;
	cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}