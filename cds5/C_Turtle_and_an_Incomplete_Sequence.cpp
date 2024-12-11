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

bool rec(ll i,ll n,vll& v,ll val){
	if(i+1==n-1){
		v[n-1]=val*2;
		return true;
	}
	if(v[i+1]!=-1) return false;
	if(v[i+1]==val*2){
		v[i+1]=val*2;
		return true;
	}
	if(v[i+1]==val/2){
		v[i+1]=val/2;
		return true;
	}

	bool res=false;
	if(val/2>=1)
		res=rec(i+1,n,v,2*v[i])|
		rec(i+1,n,v,v[i]/2);
	else res=rec(i+1,n,v,2*v[i]);

	if(res==true){
		v[i]=val;
		return true;
	} else{
		return false;
	}
}
bool recl(ll i,ll n,vll& v,ll val){
	if(i-1==0){
		v[0]=val*2;
		return true;
	}
	if(v[i-1]!=-1) return false;
	if(v[i-1]==val*2){
		v[i-1]=val*2;
		return true;
	}
	if(v[i-1]==val/2){
		v[i-1]=val/2;
		return true;
	}
	bool res=false;
	if(val/2>=1)
		res=recl(i-1,n,v,2*v[i])|
		recl(i-1,n,v,v[i]/2);
	else res=recl(i-1,n,v,2*v[i]);

	if(res==true){
		v[i]=val;
		return true;
	} else{
		return false;
	}
}


void solution(ll& T){
	ll n; cin>>n; vll v(n); cin>>v;
	vll genuine=v;

	ll cnt=count(all(v),-1);
	if(cnt==n){
		ll cnter=1;
		for(ll i=0; i < n; i++){
			v[i]=cnter;
			if(cnter>1000000000)
				cnter/=2;
			else
				cnter*=2;
		}
		print(v); return;
	}


	cnt=1;
	for(ll i=0; i < n; i++){
		if(v[i]==-1){
			v[i]=cnt;
			cnt*=2;
		} else{
			cnt=2*v[i];
		}
	}
	for(ll i=n-2; i >= 0; i--){
		if(genuine[i]!=-1){
			continue;
		}
		if(v[i]>v[i+1]*2){
			v[i]=2*v[i+1];
		}
		if(v[i]<v[i+1]/2){
			v[i]=v[i+1]/2;
		}
	}

	print(v);
}


signed main(){
	Parvez();
	ll TT=1;
	cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}