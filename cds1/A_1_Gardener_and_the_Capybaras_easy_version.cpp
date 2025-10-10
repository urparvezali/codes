 
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
void Y(){cout<<"YES"<<endl;}
void N(){cout<<"NO"<<endl;}
void IOS(){ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
const ll mod = 1e9+7;


void solution()
{
    string s; cin>>s;
    string a,b,c;
    if (s[0]=='a'&&s[s.length()-1]=='a')
    {
        a=s[0];b=s.substr(1,s.length()-2);c=s[s.length()-1];
    }
    else if (s[1]=='b')
    {
        a=s[0];b=s.substr(1,s.length()-2);c=s[s.length()-1];
    }
    else if (s[1]=='a')
    {
        a=s[0];b=s[1];c=s.substr(2,s.length()-2);
    }
    
    cout<<a<<" "<<b<<" "<<c<<endl;
}


int main()
{
    IOS();
    ll tc; tc=1;
    cin>>tc;
    while(tc--)
        solution();
    return 0;
}