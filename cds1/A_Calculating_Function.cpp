// Parvez Ali, ICE-13 of PUST
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef vector<ll> vll;
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL)

int main(){
    IOS;
    ll n;
    cin>>n;
    int sum=0;
    if (n%2==0)cout<<n/2<<endl;
    else cout<<-(n+1)/2<<endl;
    return 0;
}