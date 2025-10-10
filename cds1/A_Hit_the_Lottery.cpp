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
    ll n;cin>>n;
    int c=0;
        if (n/100>=1)
        {
            c+=n/100;
            n%=100;
        }
        if (n/20>=1)
        {
            c+=n/20;
            n%=20;
        }
        if (n/10>=1)
        {
            c+=n/10;
            n%=10;
        }
        if (n/5>=1)
        {
            c+=n/5;
            n%=5;
        }
        if(n/1>=1)
        {
            c+=n/1;
            n%=1;
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