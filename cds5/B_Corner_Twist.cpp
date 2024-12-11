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

inline void Parvez(){ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); }
template<class T>inline istream& operator>>(istream& in, vector<T>& v){ for (T& x:v){ in>>x; }return in; }template<class T>inline ostream& operator<<(ostream& out, vector<T>& v){ for (ll i = 0;i<v.size()-1;i++){ out<<v[i]<<' '; }out<<v[v.size()-1];return out; }
inline void input(){}template<class H, class... T>inline void input(H&& h, T &&...t){ cin>>h;input(forward<T>(t)...); }inline void print(){ cout<<endl; }template<class H, class... T>inline void print(H&& h, T &&...t){ cout<<h;if (sizeof...(t)!=0)cout<<' ';print(forward<T>(t)...); }




void solution(ll& T){
	ll n, m; input(n, m);
	vvll a, b;
	for (ll i = 0; i < n; i++){
		string s; cin>>s;
		vll t;
		for (ll j = 0; j < m; j++){
			t.push_back(ll(s[j]-'0'));
		}
		a.push_back(t);
		// print(t);
	}
	for (ll i = 0; i < n; i++){
		string s; cin>>s;
		vll t;
		for (ll j = 0; j < m; j++){
			t.push_back(s[j]-'0');
		}
		b.push_back(t);
		// print(t);
	}

	ll t1 = 0, t2 = 0;
	for (ll i = 0; i < n; i++){
		for (ll j = 0; j < m; j++){
			t1 += a[i][j];
			t2 += b[i][j];
		}
		if (t1%3!=t2%3){
			print("NO"); return;
		}
	}
	for (ll j = 0; j < m; j++){
		ll t3 = 0, t4 = 0;
		for (ll i = 0; i < n; i++){
			t3 += a[i][j];
			t4 += b[i][j];
		}
		if (t3%3!=t4%3){
			print("NO");return;
		}
	}
	print("YES");
}

signed main(){
	Parvez();
	ll TT = 1;
	cin>>TT;
	for (ll T = 1;T<=TT;T++)
		solution(T);
	return 0;
}