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
#define mod (1e9+7)
void Y(){cout<<"YES"<<endl;}
void N(){cout<<"NO"<<endl;}
void IOS(){ios_base::sync_with_stdio(false); cin.tie(NULL);}

int main(){
    IOS();
    string s; cin>>s;
    set <char> sc;
    for (int i = 0; i < s.length(); i++)
    {
        sc.insert(s[i]);
    }
    int a[sc.size()];
    for (int i = 0; i < sc.size(); i++)
    {
        char ch = *next(sc.begin(),i);
        a[i]=count(s.begin(),s.end(),ch);
    }

    list <char> ls; 
    for (ll i = sc.size()-1; i <= 0; i--)
    {
        for (int j = 0; j < a[i]; j++)
        {
            if (j%2==0)
            {
                ls.push_back(*next(sc.begin(),i));
            }
            else ls.push_front(*next(sc.begin(),i));
        }
        
    }
    
    string ss;

    for (ll i = 0; i < s.length(); i++)
    {
        ss+=ls.front();
        ls.pop_front();
    }
    cout<<ss<<endl;

    return 0;
}