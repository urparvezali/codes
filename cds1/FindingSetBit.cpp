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
    ll n; cin>>n;
    int c = 0;
    for (int i = 0; i < 31; i++)
    {
        if(((n>>i)&1)) c++;
    }
    cout<<c<<endl;
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