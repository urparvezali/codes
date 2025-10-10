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
	// print();
	ll n; cin>>n;
	vll a(n),b(n+1);
	input(a); input(b);

	ll ans=0;
	ll dig=a[0];

	for(ll i=0; i < n; i++){
		ans+=abs(a[i]-b[i]);
		if(abs(b[n]-a[i])<abs(dig-b[n])){
			dig=a[i];
		}
		if(abs(b[n]-b[i])<abs(dig-b[n])){
			dig=b[i];
		}
		if((b[n]>=a[i] and b[n]<=b[i]) or (b[n]<=a[i] and b[n]>=b[i])){
			dig=b[n];
		}
	}
	// print(dig);
	ans++;
	if(dig!=b[n]){
		ans+=abs(dig-b[n]);
	}
	print(ans);
}

signed main(){
	Parvez();
	ll TT=1;
	cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}