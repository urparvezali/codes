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
    ll n;
    cin>>n;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int token=-1;
    ll o;
    cin>>o;
    for (int i = 0; i < n; i++)
    {
        if (a[i]==o)
        {
            cout<<i<<endl;
            token++;
            break;
        }
        else
        {
            token=-1;
        }
    }
    if (token==-1)
    {
        cout<<-1<<endl;
    }
    
    return 0;
}