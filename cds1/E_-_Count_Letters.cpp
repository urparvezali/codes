// // Parvez Ali, ICE-13 of PUST
// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// typedef unsigned long long ull;
// typedef vector<int> vint;
// typedef vector<ll> vll;
// typedef vector<char> vchar;
// typedef vector<string> vstr;
// #define endl '\n'
// #define mod (1e9+7)
// void Y(){cout<<"YES"<<endl;}
// void N(){cout<<"NO"<<endl;}
// void IOS(){ios_base::sync_with_stdio(false); cin.tie(NULL);}

// int main(){
//     IOS();
//     string s; cin>>s;
//     set <char> sc;
//     for (int i = 0; i < s.length(); i++)
//     {
//         sc.insert(s[i]);
//     }

//     int a[sc.size()];
//     //set<char>::iterator it;
//     for (int i = 0; i < sc.size(); i++)
//     {
//         char ch = *next(sc.begin(),i);
//         a[i]=count(s.begin(),s.end(),ch);
//     }
    
//     for (int i = 0; i < sc.size(); i++)
//     {
//         cout<<*next(sc.begin(),i)<<" : "<<a[i]<<endl;
//     }
//     return 0;
// }








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

ll cgcd(ll a,ll b){if(b==0)return a;else return cgcd(b,a%b);}
ll clcm(ll a,ll b){return a/cgcd(a,b)*b;}
ll lllen(ll n){ll res=0;while(n!=0){res++;n/=10;}return res;}
ll binExp(ll a,ll b){ll ans=1;while(b){if(b&1)ans=(ans*a)%mod;a=(a*a)%mod;b>>=1;}return ans;}
bool palin(string s){ll i=0;ll j=s.length()-1;while(i<=j){if(s[i]!=s[j])return false;i++;j--;}return true;}


void solution()
{
    map<char,ll> mp;
    string s; cin>>s;
    for (ll i = 0; i < s.size(); i++)
    {
        // mp[s[i]]++;
        mp.insert({s[i],count(s.begin(),s.end(),s[i])});
    }

    // map<char,ll> :: iterator it;
    // for (auto it = mp.begin(); it != mp.end(); it++)
    // {
    //     cout<<(*it).first<<" : "<<(*it).second<<endl;
    // }

    // for (int i = 0; i < mp.size(); i++)
    // {
    //     cout<<(*next(mp.begin(),i)).first<<" : "<<(*next(mp.begin(),i)).second<<endl;
    // }
    for(auto &i: mp)cout<<i.first<<" : "<<i.second<<endl;
    
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