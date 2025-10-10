 
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


void solution()
{
    ll x,y;
    cin>>x>>y;
    for (ll i = max(x,y); i < 1e8; i++)
    {
        if(((i+x)%y==0)&&((i+y)%x==0))
        {
            cout<<i<<endl;
            return;
        }
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