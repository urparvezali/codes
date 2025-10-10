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
    ll a,b,k;
    cin>>a>>b>>k;
    if (a%k==0&&b%k==0)
    {
        cout<<"Both"<<endl;
    }
    else if (a%k==0)
    {
        cout<<"Memo"<<endl;
    }
    else if (b%k==0)
    {
        cout<<"Momo"<<endl;
    }
    else cout<<"No One"<<endl;
    return 0;
}