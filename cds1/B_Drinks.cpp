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
    int n;
    cin>>n;
    ll a[n];
    float sum=0;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        sum=sum+a[i];
    }
    cout<<fixed<<setprecision(12)<<sum/n<<endl;
    return 0;
}