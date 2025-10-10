#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<bool> vbl;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vstr;
typedef vector<pll> vpll;

#define endl '\n'
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
constexpr ll mod = 1000000007;

inline void Parvez(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
template<class T>inline istream& operator>>(istream& in,vector<T>& v){for(T& x:v){in>>x;}return in;}template<class T>inline ostream& operator<<(ostream& out,vector<T>& v){for(ll i=0;i<v.size()-1;i++){out<<v[i]<<' ';}out<<v[v.size()-1];return out;}
inline void input(){}template<class H,class... T>inline void input(H&& h,T &&...t){cin>>h;input(forward<T>(t)...);}inline void print(){cout<<endl;}template<class H,class... T>inline void print(H &&h,T &&...t){cout<<h;if(sizeof...(t)!=0)cout<<' ';print(forward<T>(t)...);}




class segtree{
	ll size;
	vll sums;
public:
	segtree(ll n){
		size = 1;
		while (size < n)
			size *= 2;
		sums.assign(2 * size, 0LL);
		cout<<2*size<<endl;
	}
	void set(ll i, ll v, ll x, ll lx, ll rx){
		if (rx - lx == 1){
			sums[x] = v;
			return;
		}
		ll m = (lx + rx) / 2;
		if (i < m){
			set(i, v, 2 * x + 1, lx, m);
		}
		else{
			set(i, v, 2 * x + 2, m, rx);
		}
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}
	void set(ll i, ll v) { set(i, v, 0, 0, size); }
	ll sum(ll l, ll r, ll x, ll lx, ll rx){
		if (lx >= r or l >= rx)
			return 0;
		if (lx >= l and rx <= r)
			return sums[x];
		ll m = (lx + rx) / 2;
		return sum(l, r, 2 * x + 1, lx, m) + sum(l, r, 2 * x + 2, m, rx);
	}
	ll sum(ll l, ll r) { return sum(l, r, 0, 0, size); }
};

signed main(){
	segtree st(4);

	return 0;
}