#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<string> vstr;

#define endl '\n'
#define Parvez ios_base::sync_with_stdio(false);
#define Ali cin.tie(NULL); cout.tie(NULL);
void print(){cout<<endl;}template<typename T,typename... A>void print(const T& a,const A&... z){cout<<a<<' ';print(z...);}void input(){}template<typename T,typename... A>void input(T& a,A&... z){cin>>a;input(z...);}template<typename T>void print(vector<T>& v){for(auto& i:v)cout<<i<<' ';cout<<endl;}template<typename T,typename S>void print(vector<T>& v,S s){for(auto& i:v)cout<<i<<s;}template<typename T>void input(vector<T>& v){for(auto& i:v)cin>>i;}

void dfsl(ll i, ll j, ll n, vstr& v){
	if(i<0 or i>=n or j<0 or j>=n)
		return;
	for (ll ii = i; ii < n; ii++){
		v[ii][j]=='1'?v[ii][j]='0':v[ii][j]='1';
	}
	dfsl(i+1,j-1,n,v);
}
void dfsr(ll i, ll j, ll n, vstr& v){
	if(i<0 or i>=n or j<0 or j>=n)
		return;
	for (ll ii = i; ii < n; ii++){
		v[ii][j]=='1'?v[ii][j]='0':v[ii][j]='1';
	}
	dfsr(i+1,j+1,n,v);
}
void solution(ll &T){
	ll n; input(n); vstr v(n);
	input(v);
	ll ans=0;
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < n; j++)
		{
			if(v[i][j]=='1'){
				ans++;
				dfsl(i,j,n,v);
				dfsr(i+1,j+1,n,v);
			}
		}
	}
	print(ans+1);
}

signed main(){
	Parvez Ali
	ll TT=1;
	cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}