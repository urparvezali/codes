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
	ll n,c,d; input(n,c,d);
	vll v(n*n); input(v);
	sort(all(v));
	vvll cons(n+1,vll(n+1,0));

	cons[1][1]=v[0];
	for(ll i=1; i < n+1; i++){
		for(ll j=1; j < n+1; j++){
			if(i==1 and j==1) continue;
			if(j==1){
				cons[i][j]=cons[i-1][j]+c;continue;
			}
			cons[i][j]=cons[i][j-1]+d;
		}
	}
	// for(auto& i: cons){
	// 	print(i);
	// }
	vll got;
	for(ll i=1; i < n+1; i++){
		for(ll j=1; j < n+1; j++){
			got.push_back(cons[i][j]);
		}
	}
	sort(all(got));
	if(got!=v){
		print("NO");
	} else {
		print("YES");
	}
}

signed main(){
	Parvez();
	ll TT=1;
	cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}