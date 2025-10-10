#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<char> vchar;
typedef vector<string> vstr;
typedef vector<pll> vpll;
typedef map<ll,ll> mll;
typedef map<string,ll> mstrl;

signed main(){
	ll b,g; cin>>b>>g;
	if(b>g){
		ll bd=b/g;
		ll cnt=0;
		for (ll i = 0; i < bd; i++)
		{
			for (ll j = 0; j < bd; j++) {
				cout << 'B';
			}
			cout << 'G';
			cnt+=bd+1;
		}
		if(b+g!=cnt){
			for (ll i = 0; i < b+g-cnt; i++) {
				cout << 'B';
			}
		}
		cout << endl;
	}
	else if(g>b){
		ll gd=g/b;
		ll cnt=0;
		for (ll i = 0; i < gd; i++)
		{
			for (ll j = 0; j < gd; j++) {
				cout << 'G';
			}
			cout << 'B';
			cnt+=gd+1;
		}
		if(b+g!=cnt){
			for (ll i = 0; i < b+g-cnt; i++) {
				cout << 'G';
			}
		}
		cout<<endl;
	}
	else{
		for (ll i = 0; i < (b+g)/2; i++)
		{
			cout<<"GB";
		}
		cout<<endl;
	}
}
