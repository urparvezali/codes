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

ll valued(char c){
	if (c=='A') return 1;
	if (c=='B') return 5;
	if (c=='C') return 10;
	if (c=='D') return 20;
	return 50;
}

// void rec(ll i, ll n, string& s,ll sum,string sums,ll k, vstr& ans){
// 	if(i==n){
// 		if(sum==k) ans.push_back(sums);
// 		return;
// 	}
// 	rec(i+1,n,s,sum+valued(s[i]),sums+s[i],k,ans);
// 	rec(i+2,n,s,sum+valued(s[i]),sums+s[i],k,ans);
// }

void solution(ll& T){
	string s; cin>>s;
	ll k; cin>>k;
	vll vals;
	for (auto& c: s){
		vals.push_back(valued(c));
	}
	print(accumulate(all(vals), 0LL));

	unordered_map<ll, ll> pre;
	pre[0] = -1;

	ll sum = 0, mx = 0, idx = -1;
	for (ll i = 0; i < vals.size(); i++){
		sum += vals[i];
		if (pre.find(sum-k)!=pre.end()){
			ll l = i-pre[sum-k];
			if (l>mx){
				mx = l;
				idx = pre[sum-k]+1;
			}
		}
		if (pre.find(sum)==pre.end()){
			pre[sum] = i;
		}
	}
	if (mx>0) print(s.substr(idx, mx));
	else print("NONE");

}

signed main(){
	Parvez();
	ll TT = 1;
	cin>>TT;
	for (ll T = 1;T<=TT;T++)
		solution(T);
	return 0;
}