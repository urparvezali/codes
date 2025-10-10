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
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        int x;
        int l=0;
        cin>>n>>x;
        l=pow(2,x);
        for (int i = 0; i < n; i++)
        {
            l=l/2;
        }
        cout<<l<<endl;
    }
    
    return 0;
}