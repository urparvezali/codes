// Parvez Ali, ICE-13 of PUST
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef vector<ll> vll;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod (1e9+7)

int main(){
    IOS;
    ll t;
    cin>>t;
    while (t--)
    {
        ll x1,y1; cin>>x1>>y1;
        ll x2,y2; cin>>x2>>y2;
        ll x3,y3; cin>>x3>>y3;
        if ((x1==x2&&y2==y3)||(x2==x3&&y3==y1)||(x3==x1&&y1==y2)||(x1==x2&&y1==y3)||(x2==x3&&y2==y1)||(x3==x1&&y3==y2))
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
        
    }
    
    return 0;
}