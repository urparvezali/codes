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
void Y(){cout<<"YES"<<endl;}
void N(){cout<<"NO"<<endl;}
void IOS(){ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
const ll mod = 1e9+7;


void solution()
{
    ll n; cin>>n; vll v(n);
    for(auto &x: v)
        cin>>x;
    
    for (ll i = 0; i < n-1; i++)
    {
        for (ll j = i+1; j < n; j++)
        {
            if (v[i]>v[j]){
                swap(v[i],v[j]);
                for (ll k = 0; k < n-1; k++)
                {
                    if (v[k]>v[k+1])
                    {
                        cout<<"no"<<endl;
                        return;
                    }
                }
                cout<<"yes"<<endl;
                cout<<i+1<<" "<<j+1<<endl;
                return;
            }
        }
    }
}


int main()
{
    IOS();
    ll tc; tc=1;
    // cin>>tc;
    while(tc--)
        solution();
    return 0;
}