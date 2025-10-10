


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


ll dp[105][10010];
void iter_knapsack(ll n, ll capacity, vll& currency, vll& weight) {
	// vvll dp(n + 1, vll(capacity + 1, 0));
	for (ll i = 0; i <= n; i++) {
		for (ll w = 0; w <= capacity; w++) {
			if (i == 0 || w == 0) {
				dp[i][w] = 0;
			} else if (weight[i - 1] <= w) {
				dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weight[i - 1]] + currency[i - 1]);
			} else {
				dp[i][w] = dp[i - 1][w];
			}
		}
	}
	print(dp[n][capacity]);
}

void solution(ll& T) {
	for (ll i = 0; i < 105; i++) {
		for (ll j = 0; j < 10005; j++) {
			dp[i][j] = 0LL;
		}
	}

	ll n, capacity;
	cin >> n >> capacity;
	vll weight(n), currency(n);
	for (ll i = 0; i < n; i++) {
		cin >> weight[i] >> currency[i];
	}
	ll ans = 0LL;
	// rec_knapsack(n - 1, capacity, currency, weight, 0LL, ans);

	iter_knapsack(n, capacity, currency, weight);
}


signed main() {
	Parvez();
	ll TT = 1;
	// cin>>TT;
	for (ll T = 1;T <= TT;T++)
		solution(T);
	return 0;
}