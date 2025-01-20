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


void show_terrain(vvll& v) {
	for (auto&& u : v) {
		for (auto& uu : u) cout << uu << ' ';
		print();
	}
	print();
}

void solution(ll& T) {
	ll n, m; inp(n, m);
	string s; inp(s);
	vvll v(n, vll(m, 0));

	ll wholesum = 0;

	for (auto& u : v) {
		for (auto& uu : u) { inp(uu);wholesum += uu; }
	}
	// vll rowsum(m, 0), colsum(n, 0);
	// for (ll i = 0; i < n; i++) {
	// 	for (ll j = 0; j < m; j++) {
	// 		rowsum[j] += v[i][j];
	// 		colsum[i] += v[i][j];
	// 	}
	// }
	// // print(rowsum);
	// // print(colsum);
	// ll rowmax = *max_element(all(rowsum)), colmax = *max_element(all(colsum));

	// // print("=>", colmax, rowmax);
	// ll trace1 = 0, trace2 = 0;
	// for (ll i = 0, ii = 0, jj = 0; i < s.length(); i++) {
	// 	ll x = colmax - colsum[ii];
	// 	ll y = rowmax - rowsum[jj];
	// 	print(x, y);
	// 	// print(trace1, trace2);

	// 	if (s[i] == 'R') jj += 1;else ii += 1;
	// }

	// // print(trace1, trace2);

	print(wholesum);
	// print();
}

signed main() {
	Parvez();
	ll TT = 1;
	cin >> TT;
	for (ll T = 1;T <= TT;T++)
		solution(T);
	return 0;
}