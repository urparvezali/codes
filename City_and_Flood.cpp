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

struct dsu {
	vll size;
public:
	vll parent;
	dsu(ll n) {
		parent.resize(n + 1, 0);
		size.resize(n + 1, 0);
		iota(all(parent), 0);
		parent[0] = -1;
	}
	void make_set(ll x) {
		parent[x] = x;
	}
	ll find_set(ll x) {
		if (parent[x] == x) return x;
		return find_set(parent[x]);
	}
	void union_set(ll x, ll y) {
		parent[find_set(y)] = find_set(x);
	}
	ll count_set() {
		ll cnt = 0;
		for (ll i = 0; i < parent.size(); i++) {
			cnt += parent[i] == i;
		}
		return cnt;
	}
};

void solution(ll& T) {
	ll n; cin >> n;
	dsu d(n);
	ll q; cin >> q;
	while (q--) {
		ll i, j;
		cin >> i >> j;
		d.union_set(i, j);
	}
	print(d.count_set());
}

signed main() {
	Parvez();
	ll TT = 1;
	// cin>>TT;
	for (ll T = 1;T <= TT;T++)
		solution(T);
	return 0;
}