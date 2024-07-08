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
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
constexpr ll mod = 1000000007;

inline void Parvez(){ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
template<class T> inline istream& operator>>(istream& in, vector<T>& v){ for (T& x : v){ in >> x; } return in; }
template<class T> inline ostream& operator<<(ostream& out, vector<T>& v){ for (ll i = 0; i < v.size() - 1; i++){ out << v[i] << ' '; } out << v[v.size() - 1]; return out; }
inline void input(){}
template<class H, class... T> inline void input(H&& h, T&&... t){ cin >> h; input(forward<T>(t)...); }
inline void print(){ cout << endl; }
template<class H, class... T> inline void print(H&& h, T&&... t){ cout << h; if (sizeof...(t) != 0) cout << ' '; print(forward<T>(t)...); }

class sparse_table{
	vector<vector<ll>> table;
	ll n;
	ll m;
public:
	sparse_table(vector<ll>& v){
		n = v.size();
		m = log2(n) + 1;
		table.resize(m, vector<ll>(n));

		// Initialize the first row of the table
		table[0] = v;

		// Build the sparse table for sums
		for (ll i = 1; i < m; i++){
			for (ll j = 0; j + (1 << i) <= n; j++){
				table[i][j] = table[i - 1][j] + table[i - 1][j + (1 << (i - 1))];
			}
		}
	}

	ll sum_query(ll L, ll R){
		ll sum = 0;
		for (ll k = m - 1; k >= 0; k--){
			if ((1 << k) <= R - L + 1){
				sum += table[k][L];
				L += 1 << k;
			}
		}
		return sum;
	}

	void print(){
		cout << n << ' ' << m << endl;
		for (auto& row : table){
			for (auto& value : row){
				cout << setw(2) << value<<' ';
			}
			cout << endl;
		}
	}
};

void solution(ll& T){
	ll n, q; input(n, q);
	vll v(n); input(v);
	sparse_table st(v);
	while (q--){
		ll l, r; input(l, r);
		print(st.sum_query(l - 1, r - 1));
	}
	st.print();
}

signed main(){
	Parvez();
	ll TT = 1;
	// cin >> TT;
	for (ll T = 1; T <= TT; T++)
		solution(T);
	return 0;
}
