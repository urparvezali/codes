
#pragma unroll(3)
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
template<class T>inline istream& operator>>(istream& in, vector<T>& v) { for (T& x : v) { in >> x; }return in; }template<class T>inline ostream& operator<<(ostream& out, vector<T>& v) { for (ll i = 0;i < v.size() - 1;i++) { out << v[i]; }out << v[v.size() - 1];return out; }
inline void input() {}template<class H, class... T>inline void input(H&& h, T &&...t) { cin >> h;input(forward<T>(t)...); }inline void print() { cout << endl; }template<class H, class... T>inline void print(H&& h, T &&...t) { cout << h;if (sizeof...(t) != 0)cout << ' ';print(forward<T>(t)...); }

void solution(ll& T) {
	ll n; cin >> n;
	vpll v(n);
	ll l, r;
	vll counts(2 * n);

	for (ll i = 0; i < n; i++) {
		cin >> l >> r;
		v[i].first = l;v[i].second = r;
		if (l == r) {
			counts[l - 1] += 1;
		}
	}
	vll pfx(2 * n, 0);
	pfx[0] = counts[0] ? 1 : 0;
	for (size_t i = 1; i < 2 * n; i++) {
		if (counts[i]) {
			pfx[i] = 1;
		} else {
			continue;
		}
		pfx[i] += pfx[i - 1];
	}
	// print(counts);
	// print(pfx);
	string s(n, '0');
	for (ll i = 0; i < n; i++) {
		if (v[i].first == v[i].second) {
			if (counts[v[i].first - 1] == 1) {
				s[i] = '1';
			}
		} else if (pfx[v[i].second - 1] - pfx[v[i].first - 1] == v[i].second - v[i].first and pfx[v[i].first - 1] != 0) {
			s[i] = '0';
		} else {
			s[i] = '1';
		}
	}
	print(s);
}

signed main() {
	Parvez();
	ll TT = 1;
	cin >> TT;
	for (ll T = 1;T <= TT;T++)
		solution(T);
	return 0;
}