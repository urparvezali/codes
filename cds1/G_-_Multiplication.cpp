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
    ll num;
    double b;
    cin>>num>>b;
    ll total = round(100*b);
    cout<<fixed<<setprecision(0)<<total*num/100<<endl;
    return 0;
}