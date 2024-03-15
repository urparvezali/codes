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
/*
1 2 3
4 5 6
8 9 10



 */

void solution(ll& T){
	ll n; input(n);
	if(n*n<(n*n-1)*2){
		print(-1); return;
	}
	ll cnt=2;

	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			if(i==0 and j==0){
				cout<<1<<' ';
			} else {
				cout<<cnt<<' ';cnt+=2;
			}
		}
		print();
	}

}

int32_t main(){
	Parvez();
	ll TT=1;
	cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}