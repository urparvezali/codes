// Parvez Ali, ICE-13 of PUST
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
    ll t;
    cin>>t;
    while (t--)
    {
        float k,n;
        cin>>k>>n;
        for (ll i = 1; i <= k; i++)
        {
            cout<<round((n/k)*i)<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}