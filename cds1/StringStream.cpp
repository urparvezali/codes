 
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
    string s; cin>>s; s+=',';
    stringstream ss;
    long a;
    long j;
    while (!s.empty())
    {
        for (long i = 0; s[i]!=','; i++)
        {
            j=i;
        }
        cout<<s.substr(0,j+1)<<endl;
        s.erase(0,j+2);
    }
    
    
}


int main()
{
    IOS();
    ll tc; tc=1;
    // cin>>tc;
    while(tc--)
        solution();
    return 0;
}