 
// Parvez Ali, ICE-13 of PUST
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<char> vchar;
typedef vector<string> vstr;
#define endl '\n'
#define Parvez ios_base::sync_with_stdio(false);
#define Ali cin.tie(NULL); cout.tie(NULL);
void Y(){cout<<"YES"<<endl;}
void N(){cout<<"NO"<<endl;}
void IOS(){ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
const ll mod = 1e9+7;


    ll n; vll a(200010); vll s(200010);
void solution()
{
	cin>>n;
	for(ll i=1;i<=n;i++)
		cin>>a[i],s[i]=s[i-1]+a[i];
	ll ans=0;
	for(ll i=1;i<n;i++)
		ans=max(ans,gcd(s[i],s[n]));
	cout<<ans<<endl;
}


signed main()
{
    Parvez Ali
    ll tc; tc=1;
    cin>>tc;
    while(tc--)
        solution();
    return 0;
}