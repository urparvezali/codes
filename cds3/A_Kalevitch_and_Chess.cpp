#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef vector<char> vchar;
typedef vector<string> vstr;

#define endl '\n'
#define Parvez ios_base::sync_with_stdio(false);
#define Ali cin.tie(NULL); cout.tie(NULL);

void print(){cout<<endl;}template<typename T,typename... A>void print(const T& a,const A&... z){cout<<a<<' ';print(z...);}
void input(){}template<typename T,typename... A>void input(T& a,A&... z){cin>>a;input(z...);}
template<typename T>void print(vector<T>& v){for(auto& i:v)cout<<i<<' ';cout<<endl;}
template<typename T,typename S>void print(vector<T>& v,S s){for(auto& i:v)cout<<i<<s;}
template<typename T>void input(vector<T> &v){for(auto& i:v)cin>>i;}

void solution(ll &T){
	vstr v(8);input(v);
	//print(v,"\n");
	ll mn=LONG_MAX,m=0;
	for (ll ii = 0; ii < 8; ii++)
	{
		for (ll i = 0; (i < 8); i++)
		{
			if(v[ii][i]=='W'){
				ll cnt=0;
					//cout<<"cnt"<<" ";
				for (ll j = 0; j < 8; j++)
				{
					if(v[ii][j]=='B') cnt++;
				}
				for (ll j = 0; j < 8; j++)
				{
					if(v[j][i]=='B') cnt++;
				}
				mn=min(mn,cnt);
			}
		}
		for (ll jj = 0; jj < 8; jj++)
		{
			if(v[ii][jj]=='B')
				m++;
		}
		
	}
	if(m==64)
		print(8);
	else if(mn==LONG_MAX)
		print(0);
	else
		print(mn);
}

signed main(){
	Parvez Ali
	ll TT=1;
	// cin>>TT;
	for(ll T=1;T<=TT;T++)
		solution(T);
	return 0;
}