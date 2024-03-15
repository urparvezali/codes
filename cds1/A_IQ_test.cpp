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
#define rep(i,b) for(ll i=0;i<b;i++)
#define rrep(i,b) for(ll i=b-1;i>=0;i--)
#define repo(i,b) for(ll i=1;i<b;i++)
#define rrepo(i,b) for(ll i=b-1;i>=1;i--)
void Y(){cout<<"YES"<<endl;}
void N(){cout<<"NO"<<endl;}
ll gcd(ll a, ll b){return a?gcd(b%a,a):b;}
ll lcm(ll a, ll b){return a/gcd(a,b)*b;}
void IOS(){ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
const ll mod = 1e9+7; 


void solution()
{
    ll n,x,j=0,b=0; cin>>n; map<ll,ll> m; vll v;
    for (ll i = 0; i < n; i++)
    {
        cin>>x;
        v.push_back(x);
        if(x&1)b++; else j++;
    }
    if(j>b){
        for (ll i = 0; i < n; i++)
        {
            if((v[i]&1)){
                cout<<i+1<<endl; return;
            }
        }
    }
        for (ll i = 0; i < n; i++)
        {
            if(!(v[i]&1)){
                cout<<i+1<<endl; return;
            }
        }
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