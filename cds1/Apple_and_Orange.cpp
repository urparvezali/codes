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
#define mod (1e9+7)
void Y(){cout<<"YES"<<endl;}
void N(){cout<<"NO"<<endl;}
void IOS(){ios_base::sync_with_stdio(false); cin.tie(NULL);}

int main(){
    IOS();
    int s,t; cin>>s>>t;
    int a,b; cin>>a>>b;
    int m,n; cin>>m>>n; int app[m],orr[n];
    for(int &i:app)cin>>i;
    for(int &j:orr)cin>>j;
    int ac=0,oc=0;
    for (int i = 0; i < m; i++)
    {
        if (app[i]+a>=s&&app[i]+a<=t)
        {
            ac++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (orr[i]+b<=t&&orr[i]+b>=s)
        {
            oc++;
        }
    }
    cout<<ac<<endl<<oc<<endl;  
    return 0;
}