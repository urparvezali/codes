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
	ll n,k,ans=0; input(n,k); k--;
	vll v(n); input(v);
	vll vn=v;
	swap(v[0],v[k]);
	ll cnt=0;
	for(long long i=1; i < n; i++){
		if(v[i]<v[0]) cnt++;
		else break;
	}
	ans=max(ans,cnt);cnt=0;
	///////
	ll mxidx=-1;
	for(ll i=0; i < k; i++){
		if(vn[k]<vn[i]){
			mxidx=i;break;
		}
	}
	if(mxidx==-1) {
		print(ans);return;
	}
	swap(vn[mxidx],vn[k]);
	if(mxidx>0) cnt+=1;
	for(ll i=mxidx+1; i < n; i++){
		if(vn[mxidx]>vn[i]) cnt++;
		else break;
	}
	ans=max(ans,cnt);


	print(ans);
}

signed main(){
	Parvez();
	ll TT=1;
	cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}