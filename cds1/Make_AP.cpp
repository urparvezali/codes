// Parvez Ali, ICE-13 of PUST
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef vector<ll> vll;
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod (1e9+7)

int main(){
    IOS;
    int t;
    cin>>t;
    while (t--)
    {
        int a,b,token=0;
        cin>>a>>b;
        for (int i = 1; i <= b; i++)
        {
            if (a-i==i-b)
            {
                cout<<i<<endl;
                token++;
                break;
            }
        }
        if (token==0)
        {
            cout<<-1<<endl;
        }
    }
    
    return 0;
}