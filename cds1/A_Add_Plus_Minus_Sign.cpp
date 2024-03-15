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
    int t;
    cin>>t;
    while (t--)
    {
        ll n;
        cin>>n;
        string s,ss;
        cin>>s;
        ll token=0;
        for (int i = 0; i < n; i++)
        {
            if (i==0)
            {
                if (s[i]=='1')
                {
                    token++;
                }
                
            }
            else if (s[i]=='0'&&n>1)
            {
                ss+='+';
            }
            else if (s[i]=='1'&&n>1)
            {
                token++;
                if (token%2!=0)
                {
                    ss+='+';
                }
                else
                {
                    ss+='-';
                }
            }
        }
        cout<<ss<<endl;
    }
    return 0;
}