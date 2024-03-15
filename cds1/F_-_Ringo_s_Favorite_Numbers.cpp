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
    ll d,num;
    cin>>d>>num;
    if ((d==0||d==1||d==2)&&(num>=0&&num<=100))
    {

        if (d==0)
        {
            cout<<num<<endl;
        }
        else
        {
            cout<<num*pow(100,d)<<endl;
        }
        
    
    }
    
    return 0;
}