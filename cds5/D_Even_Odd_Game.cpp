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
	ll n; cin>>n; vll v(n); cin>>v;
	deque<ll> ev, od;
	for (auto& u: v){
		if (u&1) od.push_back(u);
		else ev.push_back(u);
	}
	sort(all(ev));sort(all(od));
	ll a = 0, b = 0;
	for (ll i = 0;ev.size() or od.size(); i++){
		if (i%2==0){
			if (od.size() and ev.size()){
				if (ev.back()<od.back()){
					od.pop_back();
				} else{
					a += ev.back();
					ev.pop_back();
				}
			} else if (od.size()){
				od.pop_back();
			} else{
				a += ev.back();
				ev.pop_back();
			}
		} else{
			if (od.size() and ev.size()){
				if (ev.back()>od.back()){
					ev.pop_back();
				} else{
					b += od.back();
					od.pop_back();
				}
			} else if (ev.size()){
				ev.pop_back();
			} else{
				b += od.back();
				od.pop_back();
			}
		}
	}

	if (a>b){
		print("Alice");
	} else if (b>a){
		print("Bob");
	} else print("Tie");
}

signed main(){
	Parvez();
	ll TT = 1;
	cin>>TT;
	for (ll T = 1;T<=TT;T++)
		solution(T);
	return 0;
}