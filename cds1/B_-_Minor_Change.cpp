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
    string s;
    string ss;
    cin>>s;
    cin>>ss;

    int count=0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]!=ss[i])
        {
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}