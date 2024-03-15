// Parvez Ali, ICE-13 of PUST
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<char> vchar;
typedef vector<string> vstr;
#define endl '\n'
#define mod (1e9+7)
void Y(){cout<<"YES"<<endl;}
void N(){cout<<"NO"<<endl;}
void IOS(){ios_base::sync_with_stdio(false); cin.tie(NULL);}

int main(){
    IOS();
    int t;
    cin>>t;
    while (t--)
    {
        float n;cin>>n;
        if (n>=38)
        {
            n/=5;
            if ((ceil(n)-n)<0.6)
            {
                cout<<5*round(n)<<endl;
            }
            else
            {
                cout<<round(5*n)<<endl;
            }
        }
        else
        {
            cout<<n<<endl;
        }
    }
    return 0;
}