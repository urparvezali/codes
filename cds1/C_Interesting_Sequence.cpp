#include "bits/stdc++.h"
using namespace std;
 
#define br cout<<"\n"
/*DEBUG*/
template <class T>
void what(T t) 
{
    cout<< " "<<t <<endl ;
}
template<class T,class... Args>
void what(T t,Args... args)
{
    cout<<" "<<t<<"; ";
    what(args...);
}
 
/*STL definations*/
#define pb push_back
#define ll long long
 
#define FOR(i,n) for(int i=0;i<n;i++)
#define FROM(a,i,n) for(int i=a;i<n;i++)
#define vin(macroVec) for(auto &macroA:macroVec) cin>>macroA;
 
/*Output macros*/
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define printCase(ck) cout<<"Case "<<ck<<": ";

vector <bool> get(ll n){
	vector <bool> a;
	for(int i=0;i<64;i++){
		a.pb((n>>i)&1);
	}
	reverse(a.begin(),a.end());
	return a;
}

void find(vector <bool> &a,vector <bool> &b,ll &t,ll x){
	int p=0;
	ll mk=0;
	ll ans=t;
	for(int i=63;i>=0;i--,p++){
		ll po=pow(2,p);
		if(a[i]==1&&b[i]==0){
			ll tb=po-mk;
			t+=tb;
			a=get(t);
			ans&=t;
		}
		if(ans==x){
			cout<<t;br;
			return;
		}
		mk+=a[i]*po;
	}
	cout<<-1;br;
}
void solve(int tcase){
	ll n,x,m;
	cin>>n>>x;
	m=n;
	vector <bool> a=get(n),b=get(x);
	find(a,b,m,x);
 }
int main(){
	int t,test_case=1;
	cin>>t;
	while(t--)
	solve(test_case++);
}