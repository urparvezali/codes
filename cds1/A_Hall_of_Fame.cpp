 
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
    ll n; cin>>n;
    string s; cin>>s;
    ll r=0,l=0;
    for (ll i = 0; i < s.length(); i++)
    {
        s[i]=='L'? l++:r++;
        if(l>1&&r>1)
            break;
        
    }
        if (s=="R")
        {
            cout<<-1<<endl;
        }
        
        else if (l>0&&r>0)
        {
            cout<<1<<endl;
            return;
        }
        else{

            cout<<-1<<endl;
            return;
        }
    
    
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