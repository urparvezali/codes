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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if (a == c)
    {
        Y();
    }
    else
    {
        for (int i = 0; i < 1e8; i++)
        {
            if (a == c)
            {
                Y();
                return 0;
            }
            a += b;
            c += d;
        }
        N();
    }
    return 0;
}