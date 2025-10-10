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
const ll mod = 1000000007;

inline void Parvez(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}
inline void YES(){cout<<"YES"<<endl;}
inline void NO(){cout<<"NO"<<endl;}
inline void MINUS(){cout<<-1<<endl;}

inline void print(){cout<<endl;}template<typename T,typename... A>inline void print(const T& a,const A&... z){cout<<a<<' ';print(z...);}inline void input(){}template<typename T,typename... A>inline void input(T& a,A&... z){cin>>a;input(z...);}template<typename T>inline void print(vector<T>& v){for(auto& i:v)cout<<i<<' ';cout<<endl;}template<typename T,typename S>inline void print(vector<T>& v,S s){for(auto& i:v)cout<<i<<s;}template<typename T>inline void input(vector<T>& v){for(auto& i:v)cin>>i;}

void solution(ll &T){
	ll n; input(n);
	vector<vector<char>> v(n,vector<char> (n));

	for (ll i = 0; i < n; i++){
		for (ll j = 0; j < n; j++){
			input(v[i][j]);
		}
	}
	ll ans=0;
	ll it=0;
	for (ll i = 0; i < n/2; i++){
		for (ll j = it; j < n-it-1; j++){
			// cout<<i<<j<<" ";
			char mx;
			mx=max({v[i][j],v[j][n-i-1],v[n-i-1][n-j-1],v[n-j-1][i]});
			ans+=4*ll(mx)-ll(v[i][j])-ll(v[j][n-i-1])-ll(v[n-i-1][n-j-1])-ll(v[n-j-1][i]);
		}
		it++;
		// print('/');
	}
	print(ans);
}

signed main(){
	Parvez();
	ll TT=1;
	cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	cout<<"HELLO"<<endl;
	return 0;
}