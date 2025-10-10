#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<bool> vbl;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vstr;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

#define endl '\n'
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
constexpr ll mod = 1000000007;

inline void Parvez(){ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); }

inline void input(){}template<class H, class... T>inline void input(H&& h, T &&...t){ cin>>h;input(forward<T>(t)...); }
inline void print(){ cout<<endl; }template<class H, class... T>inline void print(H&& h, T &&...t){ cout<<h;if (sizeof...(t)!=0)cout<<' ';print(forward<T>(t)...); }

void solution(ll& T){
	string a, b; cin>>a>>b;
	reverse(all(a)); reverse(all(b));
	string s;
	ll carry = 0;

	for (ll i = 0; i < max(a.size(), b.size()); i++){
		ll x = 0, y = 0;
		if (i < a.size()){
			if (isdigit(a[i])) x = a[i] - '0';
			else x = a[i] - 'A' + 10;
		}
		if (i < b.size()){
			if (isdigit(b[i])) y = b[i] - '0';
			else y = b[i] - 'A' + 10;
		}

		ll sum = x + y + carry;
		carry = sum / 36;
		sum %= 36;

		if (sum < 10) s.push_back(sum + '0');
		else s.push_back(sum - 10 + 'A');
		carry = 0;
	}

	if (carry) s.push_back(carry + '0');
	reverse(all(s));
	cout<<s<<endl;
}

signed main(){
	Parvez();
	ll TT = 1;
	cin>>TT;
	for (ll T = 1; T <= TT; T++)
		solution(T);
	return 0;
}
