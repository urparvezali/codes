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


vvll v;

bool cmp(ll a, ll b) {
	return a < b? v[a][b] == 1 : v[b][a] == 0;
}
void solution(ll& T) {
	ll n; cin >> n;
	vll p(n);
	for (ll i = 0; i < n; i++) {
		p[i] = i;
	}
	v.clear();
	v.resize(n, vector<ll>(n, 0));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			char c; cin >> c;
			c=='1'? v[i][j]=1: v[i][j]=0;
		}

	}


	sort(all(p), cmp);
	for (size_t i = 0; i < n; i++) {
		cout << p[i] + 1 << ' ';
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
// 0 0 1 0 1
// 0 0 1 0 1
// 1 1 0 0 1
// 0 0 0 0 1
// 1 1 1 1 0