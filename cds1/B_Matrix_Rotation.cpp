// Parvez Ali, ICE-13 of PUST
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
    ll t;
    cin>>t;
    while (t--)
    {
        ll a,b,c,d;
        cin>>a>>b;
        cin>>c>>d;
        int token=0;
        for (int i = 0; i < 4; i++)
        {
            if (a>b||a>c||c>d||b>d)
            {
                swap(a,c);
                swap(c,d);
                swap(b,d);
            }
            else
            {
                token++;
                break;
            }
        }

        if (token==0)
        {
            N();
        }
        else
        {
            Y();
        }
        
    }
    
    return 0;
}