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
    int t,e=0,o=0,p=0,ne=0;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        if (n%2==0)
        {
            e++;
        }
        if (n%2!=0)
        {
            o++;
        }
        if (n>0)
        {
            p++;
        }
        if (n<0)
        {
            ne++;
        }
    }
    cout<<"Even: "<<e<<endl;
    cout<<"Odd: "<<o<<endl;
    cout<<"Positive: "<<p<<endl;
    cout<<"Negative: "<<ne<<endl;
    return 0;
}