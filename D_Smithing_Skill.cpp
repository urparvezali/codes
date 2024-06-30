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
	ll n, m; input(n, m);
	vll a(n), b(n), c(m); input(a, b, c);
	vpll v(n);
	ll mn = *min_element(all(a));
	for (ll i = 0; i < n; i++){
		v[i] = { a[i]-b[i],a[i] };
	}
	sort(all(v));
	// for (ll i = 0; i < n; i++){
	// 	cout<<v[i].first<<'='<<v[i].second<<",";
	// }
	// print();
	ll ans = 0;
	unordered_map<ll, ll> dp;
	for (ll i = 0; i < m; i++){
		if (dp.count(c[i])){
			ans += dp[c[i]];
			continue;
		}
		ll local = 0;
		for (ll j = 0; j < n; j++){
			if (c[i]<mn){
				break;
			}
			if (c[i]>=v[j].second){
				local += (c[i]-v[j].second+v[j].first)/v[j].first;
				c[i] -= local*v[j].first;
			}
		}
		ans += local;
		dp[c[i]] = local;
	}

	print(ans*2);

}

signed main(){
	Parvez();
	ll TT = 1;
	// cin>>TT;
	for (ll T = 1;T<=TT;T++)
		solution(T);
	return 0;
}