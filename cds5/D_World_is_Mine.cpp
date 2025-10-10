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
	ll n; cin>>n; vll a(n); cin>>a;

	map<ll, ll> counts;
	for (auto u: a) counts[u]++;
	vll v;
	unordered_set<ll> st;
	for (auto [i, j]: counts){
		v.push_back(j);

	}
	n = v.size();
	// print(v);


	ll ans = 0;
	while (v.size()){
		v.erase(v.begin());
		ans++;
		bool ok = false;
		for (ll i = v.size()-1; i >= 0; i--){
			if (v[i]==1){
				v.erase(v.begin()+i);
				ok = true;
				break;
			}
		}
		if (!ok and v.size()){
			ll mn = v[0];
			ll idx = 0;
			for (ll i = 0; i < v.size(); i++){
				if (v[i]<mn){
					idx = i;
					mn = v[i];
				}
			}
			v[idx] -= 1;
		}
		// if (v.size())
		// 	print(v, ":", ans);
	}

	print(ans);
}

signed main(){
	Parvez();
	ll TT = 1;
	cin>>TT;
	for (ll T = 1;T<=TT;T++)
		solution(T);
	return 0;
}