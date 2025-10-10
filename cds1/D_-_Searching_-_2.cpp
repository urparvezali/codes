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
    ll n,q;
    cin>>n>>q;
    ll a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll b[q];
    for (int i = 0; i < q; i++)
    {
        cin>>b[i];
    }
    
    for (int i = 0; i < q; i++)
    {
        int token=0;
        for (int j = 0; j < n; j++)
        {
            if (b[i]==a[j])
            {
                token++;
            }
        }
        if (token!=0)
        {
            cout<<"found"<<endl;
        }
        else
        {
            cout<<"not found"<<endl;
        }
    }
    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// typedef vector<int> vint;
// typedef vector<string> vstr;
// typedef vector<ll> vll;
// #define endl '\n'
// #define IOS ios_base::sync_with_stdio(false);cin.tie(NULL)
// #define mod (1e9+7)

// int main(){
//     IOS;

//     int n,q;
//     cin>>n>>q;
//     string s;
//     getline(cin,s);

//     string num;
//     for (int i = 0; i < q; i++)
//     {
//         cin>>num;
//         if (s.find(num)>=0)
//         {
//             cout<<"found"<<endl;
//         }
//         else
//         {
//             cout<<"not found"<<endl;
//         }
//     }
//     return 0;
// }