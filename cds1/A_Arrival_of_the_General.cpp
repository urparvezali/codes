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
    ll n;
    cin>>n;
    ll a[n];
    for (ll i = 0; i < n-1; i++)
    {
        cin>>a[i];
    }
    ll token=0;
    for (ll i = 0; i < n; i++)
    {
        int b=i;
        for (ll j = i+1; j < n; j++)
        {
            if (a[j]>a[b])
            {
                b=j;
            }
        }
        swap(a[i],a[b]);
        token+=(b-i);
    }
    cout<<token<<endl;
    return 0;
}