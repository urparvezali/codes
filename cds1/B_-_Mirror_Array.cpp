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
    ll a,b; cin>>a>>b;
    vector<vector<ll>> v;

    vll vn(b);
    for (ll i = 0; i < a; i++)
    {
        for (ll j = 0; j < b; j++)
        {
            cin>>vn[j];
        }
        v.push_back(vn);
    }
    for (ll i = 0; i < a; i++)
    {
        reverse(v[i].begin(),v[i].end());
    }
    for (ll i = 0; i < a; i++)
    {
        for (ll j = 0; j < b; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
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