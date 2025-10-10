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
    vll a(4); for(auto &x: a) cin>>x;
    ll alice=0,bob=0,ans=0;

    if(a[0]==0)
    {
        cout<<1<<endl;
    }
    else
    {
        ans+=a[0];
        ans+=min(a[1],a[2])*2;
        ans+=min(a[0]+1,abs(a[2]-a[1]));
        if(a[0]+1>abs(a[2]-a[1]))
        {
            ans+=min(a[0]+1-abs(a[2]-a[1]),a[3]);
        }
        cout<<ans<<endl;
    }
}


int main()
{
    IOS();
    ll tc; tc=1;
    cin>>tc;
    while(tc--)
        solution();
    return 0;
}