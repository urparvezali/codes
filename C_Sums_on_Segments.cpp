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




void solution(ll& T) {
	ll n; cin >> n; vll v(n); cin >> v;
	set<ll> st;
	ll other = 0;
	ll sum = 0;
	ll mxo = 0;
	for (ll i = 0; i < n; i++) {
		if (v[i] == 1) sum += 1;
		else sum = 0;
		mxo = max(mxo, sum);
		if (v[i] != -1 && v[i] != 1) other = v[i];
	}
	sum = 0;
	ll mxno = 0;
	for (ll i = 0; i < n; i++) {
		if (v[i] == -1) sum += 1;
		else sum = 0;
		mxno = max(mxno, sum);
	}
	bool got = false;
	ll mnl = 0, mnr = 0, mxl = 0, mxr = 0;
	for (ll i = 0; i < n; i++) {
		if (v[i] != -1 and v[i] != 1) {
			got = true;
			sum = 0;
			for (ll j = i - 1; j >= 0; j--) {
				sum += v[j];
				mxl = max(mxl, sum);
				mnl = min(mnl, sum);
			}
			sum = 0;
			for (ll j = i + 1; j < n; j++) {
				sum += v[j];
				mxr = max(mxr, sum);
				mnr = min(mnr, sum);
			}
			// print(mnl, mnr);
			for (ll j = v[i] + min(mnl, mnr); j <= v[i] + max(mxr, mxl); j++) {
				st.insert(j);
				// cout<<j<<' ';
			}
			sum = 0;
			for (ll j = 0; j < i; j++) {
				sum += v[j];
				mxl = max(mxl, sum);
				mnl = min(mnl, sum);
			}
			sum = 0;
			for (ll j = n - 1; j > i; j--) {
				sum += v[j];
				mxr = max(mxr, sum);
				mnr = min(mnr, sum);
			}
			for (ll j = min(mnl, mnr); j <= max(mxr, mxl); j++) {
				st.insert(j);
				// cout<<j<<' ';
			}
		}
	}
	if (!got) {
		for (ll i = 0; i < mxno; i++) {
			st.insert(-mxno + i);
		}
		st.insert(0);
		for (ll i = 0; i < mxo; i++) {
			st.insert(i + 1);
		}
	}


	print(st.size());
	for (auto& x : st) {
		cout << x << ' ';
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