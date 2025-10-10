// Library
#include <bits/stdc++.h>
using namespace std;

// Type Definition
typedef long long ll;
typedef vector<string> vstr;
typedef vector<ll> vll;

// STL Operation
#define pb push_back
#define pop pop_back
#define es(num) num.erase(num.begin()) // removing the array's first element
#define asc(v) sort(v.begin(), v.end())
#define dsc(v) sort(v.begin(), v.end(), greater<int>())
#define rev(v) reverse(v.begin(), v.end())
#define Fast_ios ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

// Loop
#define icr(i, n) for (ll i = 0; i < n; i++)
#define dcr(i, n) for (ll i = n - 1; i >= 0; i--)

// Printing Shortcut
#define dp(x) cout << x << endl
#define dp2(x, y) cout << x << " " << y << endl

// Solution
void solve()
{
    ll a, b, c, cnt = 0;
    cin >> a >> b >> c;
    vll v;
    v.pb(a);
    v.pb(b);
    v.pb(c);
    // // fight begin
    if (a <= 0)
    {
        dp("NO");
        return;
    }
    for (ll i = 0; i < 3; i++)
    {

        cnt++;
        if (min(v[i], v[i + 1]) == v[i + 1])
        {
            v[i] = (v[i] - v[i + 1]);
            v[i + 1] = 0;
        }
        else
        {
            v[i + 1] = (v[i + 1] - v[i]);
            v[i] = 0;
        }
        if (cnt = 2)
            break;
    }
    if (v[0] == v[2] && v[0] > 0)
    {
        dp("YES");
        return;
    }
    {
        if (min(v[0], v[2]) == v[2])
        {
            v[0] = (v[0] - v[2]);
            v[2] = 0;
        }

        else
        {
            v[2] = (v[2] - v[0]);
            v[0] = 0;
        }
    }
    if (v[0] > 0)
        dp("YES");
    else
        dp("NO");
}

int main()
{
    Fast_ios;
    ll t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}