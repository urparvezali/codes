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
    ll N;
    cin>>N;
    ll sum=1,i;
    for ( i = 1; (sum%N!=0); i++)
    {
        sum*=i;
    }
    cout<<i-1<<endl;
    return 0;
}