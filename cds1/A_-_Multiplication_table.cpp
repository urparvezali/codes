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
    for (int i = 1; i <= 12; i++)
    {
        cout<<n<<" * "<<i<<" = "<<n*i<<endl;
    }
    
    return 0;
}