// Parvez Ali, ICE-13 of PUST
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rfor(i,var) for(int i:var)
int main(){
    IOS;
    string s,ss;
    cin>>s>>ss;
    reverse(s.begin(),s.end());
    if (s==ss)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}