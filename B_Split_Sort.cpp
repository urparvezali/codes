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

void Parvez(){ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);}

void print(){cout<<endl;}template<typename T,typename... A>void print(const T& a,const A&... z){cout<<a<<' ';print(z...);}void input(){}template<typename T,typename... A>void input(T& a,A&... z){cin>>a;input(z...);}template<typename T>void print(vector<T>& v){for(auto& i:v)cout<<i<<' ';cout<<endl;}template<typename T,typename S>void print(vector<T>& v,S s){for(auto& i:v)cout<<i<<s;}template<typename T>void input(vector<T>& v){for(auto& i:v)cin>>i;}

void solution(ll &T){
	ll n,ans=0; input(n); vll v(n); input(v);
	vll comp(n+2);
	for (ll i = 0; i < n; i++)
		comp[v[i]]=i;
	for (ll i = 0; i < n; i++)
		if(comp[i]>comp[i+1])
			ans++;
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