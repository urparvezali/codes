#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<bool> vbl;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vstr;
typedef vector<pll> vpll;

#define endl '\n'
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
constexpr ll mod = 1000000007;

inline void Parvez(){ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); }
template<class T>inline istream& operator>>(istream& in, vector<T>& v){ for (T& x:v){ in>>x; }return in; }template<class T>inline ostream& operator<<(ostream& out, vector<T>& v){ for (ll i = 0;i<v.size()-1;i++){ out<<v[i]<<' '; }out<<v[v.size()-1];return out; }
inline void input(){}template<class H, class... T>inline void input(H&& h, T &&...t){ cin>>h;input(forward<T>(t)...); }inline void print(){ cout<<endl; }template<class H, class... T>inline void print(H&& h, T &&...t){ cout<<h;if (sizeof...(t)!=0)cout<<' ';print(forward<T>(t)...); }




void solution(ll& T){
	ll N; cin>>N;
	ll n = N;
	vll v;

	v.push_back(n);

	// print(ceil(log2(n)));

	while (n){
		ll lg = ceil(log2(n));
		for (ll i = 0; i <= lg; i++){
			ll shifted = (1<<i);
			if (n&shifted){
				ll num = n^shifted;
				if (num<N and (num|v.back())==N)
					v.push_back(num);
				else continue;;
			}
		}
		n = n>>1;
	}
	sort(rall(v));
	if (v.back()==0) v.pop_back();
	reverse(all(v));
	print(v.size());
	for (auto i: v) cout<<i<<' ';
	cout<<endl;
}

signed main(){
	Parvez();
	ll TT = 1;
	cin>>TT;
	for (ll T = 1;T<=TT;T++)
		solution(T);
	// print(21|22);
	return 0;
}