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
    ll n; cin>>n; vll v(n);
    for(auto &x:v)
        cin>>x;
    set<ll> s;
    for(auto &y:v)
        s.insert(y);
    s.size()!=2?cout<<n<<endl: cout<<n/2+1<<endl;
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