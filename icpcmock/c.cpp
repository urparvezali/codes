#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<char> vchar;
typedef vector<string> vstr;
#define endl '\n'

void Y()
{
	cout << "YES" << endl;
}
void N() { cout << "NO" << endl; }
void IOS()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}
const ll mod = 1e9 + 7;
ll cs = 0;

void solution()
{
	cs++;
	ll n, a, b;
	cin >> n >> a >> b;
	vll v;

	for (ll i = 0; i < n; i++)
	{
		ll x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());
	ll l = 0, r = n - 1, L = 0;
	ll cn = 0;
	while (l < r){
		if (v[l] + v[r] < a){
			l++;
		} else if (v[l] + v[r] > b)
			r--;
		else {
			cn += r - l;
			L = l + 1;
			while (v[L] + v[l] < a && L < r){
				cn--;
				L++;
			}
			l++;
		}
	}

	cout << "Case " << cs << ": " << cn << endl;
}

int main()
{
	IOS();
	ll tc = 1;
	cin >> tc;

	while (tc--)
		solution();
	return 0;
}