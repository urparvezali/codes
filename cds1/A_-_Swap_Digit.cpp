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
void IOS(){ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
const ll mod = 998244353;


void solution()
{
    ll n; cin>>n;
    string s,ss; cin>>s>>ss;
    ll a,b; a=stoll(s); b=stoll(ss);
    if (a>b)
    {
        for (ll i = 0; i < n; i++)
        {
            if (s[i]<ss[i])
            {
                swap(s[i],ss[i]);
            }
        }
    }
    else
    {
        for (ll i = 0; i < n; i++)
        {
            if (s[i]>ss[i])
            {
                swap(s[i],ss[i]);
            }
        }
    }
    a=stoll(s);b=stoll(ss);
    cout<<(a*b)%mod<<endl;
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