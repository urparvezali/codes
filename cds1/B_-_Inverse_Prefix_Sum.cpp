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
    int n;
    cin>>n;
    ll a[n],ar[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        ar[i]=a[i];
    }
    
    for (int i = 0; i < n-1; i++)
    {
        ar[i+1]=a[i+1]-a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<ar[i]<<" ";
    }
    
    return 0;
}