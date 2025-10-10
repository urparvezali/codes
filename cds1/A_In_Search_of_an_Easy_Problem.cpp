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
    int n,p,temp=0;
    cin>>n;
    while(n--)
    {
        cin>>p;
        if (p!=0)
        {
            temp=1;
            break;
        }
    }
    if (temp==0)
    {
        cout<<"EASY"<<endl;
    }
    else
    {
        cout<<"HARD"<<endl;
    }
    
    
    return 0;
}