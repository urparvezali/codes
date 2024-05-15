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

ll dsum(ll x){
	ll sum=0;
	while(x){
		sum+=x%10;
		x/=10;
	}
	return sum;
}

map<pair<ll,ll>,pair<ll,ll>> mp;

void solution(ll& T){
	int q; cin>>q;
	cout<<"Case "<<T<<": "<<endl;
	while(q--){
		int n,m;cin>>n>>m;
		if(m<6){
			cout<<"0 0\n";
			continue;
		}
		int kk,mm;
		if(n<=6)kk=6;
		else{
			kk=((n-6)/9)*9 +6;
			if(kk<n)kk+=9;
		}
		mm=((m-6)/9)*9 +6;
		if(mm<n){
			cout<<"0 0\n";
			continue;
		}
		m=(mm-kk)/9;
		cout<<m+1<<' ';
		if(mm%6==0 or kk%6==0)cout<<(m/2)+1<<endl;
		else cout<<m/2<<endl;
	}
}

signed main(){
	Parvez();
	ll TT=1;
	cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}