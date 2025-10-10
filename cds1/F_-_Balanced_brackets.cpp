#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef vector<ll> vll;
#define endl '\n'
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod (1e9+7)

int main(){
    string s;
    cin>>s;
    stack <char> v;
    for (int i = s.size()-1; i >= 0; i--)
    {
        char c=s[i];
        v.push(c);
    }
    int token1 =0,token2=0;
    for (int i = 0; i < s.size(); i++)
    {
        if (v.top()=='(')
        {
            token1++;
        }
        else if(v.top()==')')
        {
            token2++;
        }
        v.pop();

        if (token2>token1)
        {
            break;
        }
    }
    if (token1==token2)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}