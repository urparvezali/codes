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
    ll t;cin>>t;
    while (t--)
    {
        ll n; cin>>n; vll v;
        for (int i = 0; i < n; i++)
        {
            int tmp; cin>>tmp; v.push_back(tmp);
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());

        for (int i = n-1; i >= 1; i--)
        {
            if (abs(v[i]-v[i-1])<=1)
            {
                v.pop_back();
            }
        }

        v.size()<=1? Y(): N();
    }
    
    return 0;
}