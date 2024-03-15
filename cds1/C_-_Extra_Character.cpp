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
    string a;
    string b;
    cin>>a; cin>>b;

    for (int i = 0; i < b.length(); i++)
    {
        if (a[i]!=b[i])
        {
            cout<<i+1<<endl;
            break;
        }
    }
    return 0;
}