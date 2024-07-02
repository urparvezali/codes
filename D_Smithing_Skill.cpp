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

	vll a(n), b(n), c(m);
	input(a, b, c);
	ll mx = *max_element(all(a)) + 1;

	vll best(mx, LLONG_MAX);
	vll calc(mx, 0);

	for (ll i = 0; i < n; ++i){
		best[a[i]] = min(best[a[i]], a[i] - b[i]);
	}
	for (ll v = 1; v < mx; ++v){
		best[v] = min(best[v], best[v - 1]);
	}

	for (ll v = 1; v < mx; ++v){
		if (v >= best[v]){
			calc[v] = 2 + calc[v - best[v]];
		}
	}

	ll ans = 0;
	for (ll v : c){
		ll cur = v;
		if (cur >= mx){
			ll k = (cur - mx + 1 + best[mx - 1]) / best[mx - 1];
			ans += 2LL * k;
			cur -= k * best[mx - 1];
		}
		ans += calc[cur];
	}
	cout << ans << endl;
}

signed main(){
	Parvez();
	ll TT = 1;
	// cin>>TT;
	for (ll T = 1;T<=TT;T++)
		solution(T);
	return 0;
}