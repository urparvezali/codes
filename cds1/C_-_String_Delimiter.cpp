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
    string s;
    int n;
    cin>>n;
    cin>>s;
    int tok=1;
    for (int i = 0; i < n; i++)
    {
        if (s[i]=='"')
        {
            tok++;
        }
        if (tok%2!=0)
        {
            if (s[i]==',')
            {
                s[i]='.';
            }
        }
    }
    cout<<s<<endl;
    return 0;
}