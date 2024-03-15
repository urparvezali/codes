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
void Y(){cout<<"YES"<<endl;}
void N(){cout<<"NO"<<endl;}
void IOS(){ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
const ll mod = 1e9+7;

ll cgcd(ll a,ll b){if(b==0)return a;else return cgcd(b,a%b);}
ll clcm(ll a,ll b){return a/cgcd(a,b)*b;}
ll lllen(ll n){ll res=0;while(n!=0){res++;n/=10;}return res;}
ll binExp(ll a,ll b){ll ans=1;while(b){if(b&1)ans=(ans*a)%mod;a=(a*a)%mod;b>>=1;}return ans;}
bool palin(string s){ll i=0;ll j=s.length()-1;while(i<=j){if(s[i]!=s[j])return false;i++;j--;}return true;}


void solution()
{
    int a,b;
    cin>>a>>b;
    ll p = pow(a,b);
    cout<<p<<endl;
}


int main()
{
    IOS();
    ll tc; tc=1;
    // cin>>tc;
    while(tc--)
        solution();
    return 0;
}