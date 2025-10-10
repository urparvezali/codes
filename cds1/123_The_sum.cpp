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

// 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144

    int n,a=1,b=0,sum=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        a+=b;
        sum+=a;
        b=a;
    }
    cout<<sum<<endl;
    return 0;
}