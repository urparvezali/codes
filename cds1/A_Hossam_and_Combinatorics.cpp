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
    int t;
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
        sort(a,a+n);
        ll mitoken= count(a,a+n,a[0]);
        ll matoken=count(a,a+n,a[n-1]);

        if (mitoken==n)
        {
            cout<<n*(n-1)<<endl;
        }
        else
        cout << 2*mitoken*matoken << endl;
    }
    return 0;
}