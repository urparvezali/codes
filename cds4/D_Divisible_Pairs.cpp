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

inline void Parvez(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
template<class T>
inline istream& operator>>(istream& in,vector<T>& v){
	for(T& x:v)
		in>>x;
	return in;
}
template<class T>
inline ostream& operator<<(ostream& out,vector<T>& v){
	for(ll i=0;i<v.size()-1;i++)
		out<<v[i]<<' ';
	out<<v[v.size()-1];
	return out;
}

void solution(ll& T){
	ll n,x,y; cin>>n>>x>>y;
	vll v(n); cin>>v;

	map<ll,ll> mp;
	for(auto& i:v)mp[i]++;

	ll cnt=0;

	for(auto [i,j]:mp){
		ll ned;
		if(i>x){
			ned=ceil(1.0*i/x)*i-i;
		} else{
			ned=x-i;
		}
		auto q1=mp[ned];
		if(ned and q1 and (ned+i)%x==0 and abs(i-ned)%y==0){
			cnt+=j*q1;
		}
		cout<<i<<' '<<j<<' '<<ned<<' '<<q1<<' '<<cnt<<endl;
	}


	cout<<cnt<<endl;
}

int32_t main(){
	Parvez();
	ll TT=1;
	cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}