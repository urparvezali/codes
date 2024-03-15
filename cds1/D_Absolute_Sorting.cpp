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
        ll n;cin>>n;
        ll a[n];
        for(auto &x:a){cin>>x;}
        ll mx = *max_element(a,a+n);
        for (ll i = 1; i <= 9999; i++)
        {
            ll d=abs(a[0]-i);
            for (ll j = 1; j < n; j++)
            {
                if(d!=abs(a[j]-i))
                {
                    break;
                }
                if (j==(n-1)&&d==abs(a[0]-i))
                {
                    cout<<i<<endl;
                    break;
                }
                
            }
            ll dn=abs(a[0]+i);
            for (ll j = 1; j < n; j++)
            {
                if (dn!=abs(a[j]+i))
                {
                    break;
                }
                if (j==(n-1)&&d==abs(a[0]+i))
                {
                    cout<<-i<<endl;
                    break;
                }
            }
            
        }
        
    }
    
    return 0;
}