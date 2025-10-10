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
    string s,ss;
    cin>>s;
    ss=s;

    reverse(s.begin(),s.end());
    int token=0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]==ss[i])
        {
            continue;
        }
        token++;
        break;
    }
    if (token==0)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
    
    return 0;
}