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
constexpr ll mod=1000000007;

inline void Parvez(){ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); }
template<class T>inline istream& operator>>(istream& in,vector<T>& v){ for(T& x:v){ in>>x; }return in; }template<class T>inline ostream& operator<<(ostream& out,vector<T>& v){ for(ll i=0;i<v.size()-1;i++){ out<<v[i]<<' '; }out<<v[v.size()-1];return out; }
inline void input(){}template<class H,class... T>inline void input(H&& h,T &&...t){ cin>>h;input(forward<T>(t)...); }inline void print(){ cout<<endl; }template<class H,class... T>inline void print(H&& h,T &&...t){ cout<<h;if(sizeof...(t)!=0)cout<<' ';print(forward<T>(t)...); }




void solution(ll& T){
	ll n,m,k; input(n,m,k);
	vll a(n),b(m); input(a,b);
	vll freq(k);
	set<ll> st1,st2;
	ll cnt1=0,cnt2=0;
	for(auto& i:a){
		if(i<=k){
			freq[i-1]++;
			if(st1.find(i)==st1.end()){
				cnt1++;
				st1.insert(i);
			}
		}
	}
	for(auto& i:b){
		if(i<=k){
			freq[i-1]++;
			if(st2.find(i)==st2.end()){
				st2.insert(i);
				cnt2++;
			}
		}
	}
	// cout<<freq<<endl;
	// print(cnt1,cnt2);
	if(find(all(freq),0)==freq.end() and cnt1>=k/2 and cnt2>=k/2){
		print("YES");
	} else{
		print("NO");
	}
}

int32_t main(){
	Parvez();
	ll TT=1;
	cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}