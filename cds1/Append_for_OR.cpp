 
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
    ll n; ll y; cin>>n>>y;
    vll v(n); for(auto &i:v) cin>>i;
    ll x=0;
    for (ll i = 0; i < n; i++)
    {
        x=(x | v[i]);
    }
    if(x>y||(y|x)!=y){
        cout<<-1<<endl;
        return;
    }
    cout<<(x xor y)<<endl;
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