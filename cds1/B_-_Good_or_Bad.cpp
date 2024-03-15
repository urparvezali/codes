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
    ll t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        int cnt=0;
        if(s.length()>=3){
            for (ll i = 0; i < s.length(); i++)
            {
               if ("101"==s.substr(i,3)||"010"==s.substr(i,3)){
                cnt++;break;
               }
            //    else
            //    {
            //     s.erase(0,1);
            //    }
            }


            if (cnt)
            {
                cout<<"Good"<<endl;
            }
            else cout<<"Bad"<<endl;
        }
        else cout<<"Bad"<<endl;
    }
    return 0;
}