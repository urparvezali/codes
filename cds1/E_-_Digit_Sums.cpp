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
    string s; ll sum=0;
    cin>>s;
    for (int i = 0; i < s.length(); i++)
    {
        stringstream ss;
        ss<<s[i];
        int n;
        ss>>n;
        sum=sum+n;
    }
    int num= stoi(s);
    if (num%sum==0)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    
    
    return 0;
}