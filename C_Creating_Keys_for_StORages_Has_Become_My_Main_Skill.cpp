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



int countbit(ll n) {
	if (n == 0) return 0;
	ll cnt = 0;
	for (ll i = 0; i < 32; i++) {
		if((n&(1<<i))!=0){
			cnt+=1;
		} else break;
	}
	return cnt;
}
void solution(ll& T) {
	ll n, x; inp(n, x);
	vll numbers;
	if (n == 1) {
		print(x); return;
	}

	ll cnt = countbit(x);
	// print(cnt);

	ll mx = 1 << cnt;
	ll i = 0;
	for (i = 0; i<mx and i + 2 < n; i++) {
		numbers.push_back(i);
	}

	ll lst = 1LL << (long long)log2(x);

	if (lst < i) {
		numbers.push_back(i);
	} else {
		numbers.push_back(x);
	}
	while (numbers.size() < n) {
		numbers.push_back(lst);
	}
	print(numbers);
}

signed main() {
	Parvez();
	ll TT = 1;
	cin >> TT;
	for (ll T = 1;T <= TT;T++)
		solution(T);
	// print(countbit(11));
	return 0;
}