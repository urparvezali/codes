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
    ll n;
    cin>>n;
    string love = "I love", hate = "I hate",s;
    for (int i = 0; i < n; i++)
    {
        if (i%2==0)
        {
            s+= hate;
        }
        else
        {
            s+= love;
        }
        if (i<n-1)
        {
            s+=" that ";
        }
    }
    s+=" it";
    cout<<s<<endl;
    return 0;
}