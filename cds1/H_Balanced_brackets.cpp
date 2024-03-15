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
    getline(cin,s);
    stack <char> v;
    for (int i = 0; i < s.size(); i++)
    {
        char c=s[i];
        v.push(c);
    }
    int token =0;
    for (int i = 0; i < s.size(); i++)
    {
        if (v.top()=='(')
        {
            token++;
        }
        else if(v.top()==')')
        {
            token--;
        }
        v.pop();
    }
    if (token==0)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
    return 0;
}