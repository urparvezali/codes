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
    int t,a,b,o=0;
    cin>>t;
    while (t--)
    {
        cin>>a>>b;
        if (a<=b-2)
        {
            o++;
        }
    }
    cout<<o<<endl;
    return 0;
}