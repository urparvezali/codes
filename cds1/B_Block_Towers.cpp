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
        ll n;
        cin>>n;
        ll a[n];
        for (ll i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        
        sort(a+1,a+n);
        for (ll i = 1; i < n; i++)
        {
            while (a[0]<a[i])
            {
                if (a[i]-a[0]>10000)
                {
                    a[0]+=5000;
                    a[i]-=5000;
                }
                a[0]++;
                a[i]--;
            }
        }
        cout<<a[0]<<endl;
    }
    
    return 0;
}