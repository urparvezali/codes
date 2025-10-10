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
    int t;
    cin>>t;
    vector<int> v;
    for (int i = 0; i < t; i++)
    {
        int m;
        cin>>m;
        v.push_back(m);
    }
    int c=1;
    for (int i = 0; i < t-1; i++)
    {
        if (v[i]==v[i+1])
        {
            continue;
        }
        c++;
    }
    cout<<c<<endl;
    return 0;
}