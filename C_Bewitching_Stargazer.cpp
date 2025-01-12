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
inline void input() {}template<class H, class... T>inline void input(H&& h, T &&...t) { cin >> h;input(forward<T>(t)...); }inline void print() { cout << endl; }template<class H, class... T>inline void print(H&& h, T &&...t) { cout << h;if (sizeof...(t) != 0)cout << ' ';print(forward<T>(t)...); }

ll k = 0LL;
inline pair<ll, ll> rec(ll l, ll r) {
	if (k == 1 and r == l) return { l, 1 };
	if (r - l + 1LL < k) {
		return { 0, 0 };
	}
	ll m = (l + r) / 2LL;
	if ((r - l + 1) & 1 == 1) {
		pair<ll, ll> tpl = rec(l, m - 1);

		return { m + 2 * tpl.first + m * tpl.second, 2 * tpl.second + 1 };
	}
	pair<ll, ll> tpl = rec(l, m);

	return { 2 * tpl.first + m * tpl.second, 2 * tpl.second };
}

void solution(ll& T) {
	ll n; cin >> n >> k;
	print(rec(1LL, n).first);
}

signed main() {
	Parvez();
	ll TT = 1;
	cin >> TT;
	for (ll T = 1;T <= TT;T++)
		solution(T);
	return 0;
}