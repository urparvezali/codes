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

inline void Parvez() { ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); }
template<class T>inline istream& operator>>(istream& in, vector<T>& v) { for (T& x : v) { in >> x; }return in; }template<class T>inline ostream& operator<<(ostream& out, vector<T>& v) { for (ll i = 0;i < v.size() - 1;i++) { out << v[i] + 1 << ' '; }out << v[v.size() - 1] + 1;return out; }
inline void inp() {}template<class H, class... T>inline void inp(H&& h, T &&...t) { cin >> h;inp(forward<T>(t)...); }inline void print() { cout << endl; }template<class H, class... T>inline void print(H&& h, T &&...t) { cout << h;if (sizeof...(t) != 0)cout << ' ';print(forward<T>(t)...); }




void solution(ll& T) {
	ll n, m; inp(n, m);
	vvll v(n, vll(m));
	for (auto& u : v) inp(u);
	for (ll i = 0; i < n; i++) {
		sort(all(v[i]));
	}
	// vll o(n);
	// iota(all(o), 0);

	// do {
	// 	bool ok = 1;
	// 	ll cnt = 0;
	// 	for (ll mm = 0; mm < m; mm++) {
	// 		for (ll i = 0; i < n; i++) {
	// 			if(v[o[i]][mm]!=cnt){
	// 				ok = 0;
	// 				break;
	// 			}
	// 			cnt+=1;
	// 		}
	// 		if(!ok) break;
	// 	}
	// 	if(ok){
	// 		print(o);return;
	// 	}

	// } while (next_permutation(all(o)));
	// print("-1");
	bool ok = 1;
	for (ll i = 0; i < n; i++) {
		for (ll mm = 0; mm < m - 1; mm++) {
			if (v[i][mm + 1] - v[i][mm] != n) {
				ok = 0;break;
			}
		}
		if (!ok) break;
	}
	if(!ok){
		print(-1);return;
	}
	ll cnt = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			if(cnt==v[j][0]){
				cout<<j+1<<' ';
				cnt+=1;
			}
		}
	}
	print();
}

signed main() {
	Parvez();
	ll TT = 1;
	cin >> TT;
	for (ll T = 1;T <= TT;T++)
		solution(T);
	return 0;
}