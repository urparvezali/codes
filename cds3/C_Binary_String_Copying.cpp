#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution(ll &T){
	ll n, q; cin>>n>>q;
	string s, ss; cin>>s;
	unordered_set<string> st;
	map<pair<ll, ll>, bool> mp;
	while (q--){
		ll l, r; cin>>l>>r;
		ss = s; // Corrected: Copy the original string 's' into 'ss'
		if (is_sorted(ss.begin()+l-1, ss.begin()+r)){
			st.insert(ss); // Corrected: Insert sorted 'ss' into the set instead of the unsorted 's'
		}
		else if (mp[{l, r}]) continue;
		else{
			sort(ss.begin()+l-1, ss.begin()+r);
			st.insert(ss);
			for (ll i = r-1; i < n-1; i++){
				if (ss[i] <= ss[i+1])
					mp[{l, i+2}] = 1;
				else
					break;
			}
		}
	}
	cout << st.size() << endl;
}

signed main(){
	ll TT = 1;
	cin >> TT;
	for (ll T = 1; T <= TT; T++)
		solution(T);
	return 0;
}
