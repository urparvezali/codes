// Parvez Ali, ICE-13 of PUST
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef vector<ll> vll;
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod (1e9+7)

int main(){
    IOS;
    int t;
    cin>>t;
    while (t--)
    {
        int a,b;
        cin>>a>>b;
        if (a==b)
        {
            cout<<"NEUTRAL"<<endl;
        }
        else if (a>b)
        {
            cout<<"LOSS"<<endl;
        }
        else cout<<"PROFIT"<<endl;
    }
    
    return 0;
}