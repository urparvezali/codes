 
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
bool isPrime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
ll mod_pow(ll base, ll pow)
{
    ll res = 1;
    while (pow)
    {
        if (pow & 1)
        {
            res = (res * base) % mod;
            pow--;
        }
        base = (base * base) % mod;
        pow /= 2;
    }
    return res % mod;
}

void solution()
{
    ll n; cin>>n;
    vll v(n); for(auto &x: v) cin>>x;
    for (ll i = 0; i < n-2; i++)
        for (ll j = i+1; j < n-1; j++)
            for (ll k = j+1; k < n; k++)
                if ((v[i]+v[j]+v[k])%2!=0)
                {
                    Y();
                    cout<<i+1<<" "<<j+1<<" "<<k+1<<endl;
                    return;
                }
    N();
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