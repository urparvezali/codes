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
template<class T>inline istream& operator>>(istream& in, vector<T>& v) { for (T& x : v) { in >> x; }return in; }template<class T>inline ostream& operator<<(ostream& out, vector<T>& v) { for (ll i = 0;i < v.size() - 1;i++) { out << v[i] << ' '; }out << v[v.size() - 1];return out; }
inline void inp() {}template<class H, class... T>inline void inp(H&& h, T &&...t) { cin >> h;inp(forward<T>(t)...); }inline void print() { cout << endl; }template<class H, class... T>inline void print(H&& h, T &&...t) { cout << h;if (sizeof...(t) != 0)cout << ' ';print(forward<T>(t)...); }




void solution(ll& T) {
	string s; cin >> s;
	ll n = s.length();
	ll cnt = 0;
	for (ll i = 0; i < s.length() - 3; i++) {
		if (s.substr(i, 4) == "1100") cnt += 1;
	}

	ll q; cin >> q;
	ll idx; char c;
	ll cnt1;
	while (q--) {
		// print(s);
		cin >> idx >> c; idx--;
		if (s[idx] == c) {
			print(cnt ? "YES" : "NO");continue;
		}
		ll l = max(0LL, idx - 3), r = min(n - 1, idx);
		for (ll i = l; i <= r; i++) {
			if (s.substr(i, 4) == "1100") cnt -= 1;
		}
		s[idx] = c;
		for (ll i = l; i <= r; i++) {
			if (s.substr(i, 4) == "1100") cnt += 1;
		}
		print(cnt ? "YES" : "NO");
	}
}

signed main() {
	Parvez();
	ll TT = 1;
	cin >> TT;
	for (ll T = 1;T <= TT;T++)
		solution(T);
	return 0;
}