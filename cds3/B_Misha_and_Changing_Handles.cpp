#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

string dfs(string a, unordered_map<string, bool>& vs, unordered_map<string, string>& d) {
    vs[a] = true;
    // cout << a << endl;
    if (!d[a].empty()) {
        return dfs(d[a], vs, d);
    }
    return a;
}

int main() {
    int q;
    cin >> q;
    unordered_map<string, string> d;
    unordered_map<string, bool> vs;
    
    for (int i = 0; i < q; i++) {
        string a, b;
        cin >> a >> b;
        d[a] = b;
        vs[a] = false;
        vs[b] = false;
    }

    int cnt = 0;
    vector<pair<string, string>> l;
    for (const auto& el : d) {
        if (!vs[el.first]) {
            cnt++;
            string fi = el.first;
            string la = dfs(el.first, vs, d);
            l.push_back(make_pair(fi,la));
        }
    }

    cout << cnt << endl;
    for (const auto& i : l) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}
