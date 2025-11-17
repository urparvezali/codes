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



vll calculate(vll& v, ll l, ll r) {
	ll mx = 0, mn = 0;
	ll sum1 = 0, sum2 = 0;
	for (ll i = l; i < r; i++) {
		sum1 += v[i];
		sum2 += v[i];
		if (sum1 < 0) sum1 = 0;
		if (sum2 > 0) sum2 = 0;
		mx = max(mx, sum1);
		mn = min(mn, sum2);
	}
	return { mn, mx };
};

void solution(ll& T) {
	ll n; cin >> n; vll v(n); cin >> v;

	for (ll i = 0; i < n; i++) {
		if (v[i] != 1 and v[i] != -1) {
			set<ll> st;
			vll left = calculate(v, 0, i);
			vll right = calculate(v, i + 1, n);
			for (ll j = left[0]; j <= left[1]; j++) {
				st.insert(j);
			}
			for (ll j = right[0]; j <= right[1]; j++) {
				st.insert(j);
			}
			ll mnl = 0, mxl = 0, mnr = 0, mxr = 0;
			ll sum = 0;
			for (ll j = i - 1; j >= 0; j--) {
				sum += v[j];
				mnl = min(mnl, sum);
				mxl = max(mxl, sum);
			}
			sum = 0;
			for (ll j = i + 1; j < n; j++) {
				sum += v[j];
				mnr = min(mnr, sum);
				mxr = max(mxr, sum);
			}
			for (ll j = v[i] + mnl + mnr; j <= mxl + v[i] + mxr; j++) {
				st.insert(j);
			}
			print(st.size());
			for (auto& x : st) {
				cout << x << ' ';
			}
			print();
			return;
		}
	}
	vll res = calculate(v, 0, n);
	print(res[1] - res[0] + 1);
	for (ll i = res[0]; i <= res[1]; i++) {
		cout << i << ' ';
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