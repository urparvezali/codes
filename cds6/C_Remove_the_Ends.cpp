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
	ll n; cin >> n;
	deque<ll> v;
	for (ll i = 0; i < n; i++) {
		ll x; cin >> x;
		v.push_back(x);
	}
	ll sum = 0;

	while (v.size()) {
		while (v.size() > 0 and v.front() > 0) {
			sum += v.front();
			v.pop_front();
		}
		while (v.size() > 0 and v.back() < 0) {
			sum += abs(v.back());
			v.pop_back();
		}
		ll leftpositive = 0, leftnegative = 0;
		ll rightpositive = 0, rightnegative = 0;
		ll i = 0;
		for (; i < v.size() and v[i] < 0; i++) {
			leftnegative += abs(v[i]);
		}
		for (;i < v.size() and v[i]>0; i++) {
			leftpositive += abs(v[i]);
		}
		ll j = v.size() - 1;
		for (; j >= 0 and v[j] > 0; j--) {
			rightpositive += abs(v[j]);
		}
		for (; j >= 0 and v[j] < 0; j--) {
			rightnegative += abs(v[j]);
		}
		// print(leftpositive, leftnegative, rightpositive, rightnegative);
		if (leftpositive > leftnegative) {
			sum += leftpositive;
			while (v.size() and v.front() < 0) v.pop_front();
			while (v.size() and v.front() > 0) v.pop_front();
		} else if (rightnegative > rightpositive) {
			sum += rightnegative;
			while (v.size() and v.back() > 0) v.pop_back();
			while (v.size() and v.back() < 0) v.pop_back();
		} else {
			sum += leftnegative;
			break;
		}
	}
	print(sum);
}

signed main() {
	Parvez();
	ll TT = 1;
	cin >> TT;
	for (ll T = 1;T <= TT;T++)
		solution(T);
	return 0;
}