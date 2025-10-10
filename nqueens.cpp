#include <bits/stdc++.h>
#include <unordered_set>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<bool> vbl;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vstr;
typedef vector<pll> vpll;

#define endl '\n'
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
constexpr ll mod = 1000000007;

template <class T> inline istream &operator>>(istream &in, vector<T> &v) {
    for (T &x : v) {
        in >> x;
    }
    return in;
}
template <class T> inline ostream &operator<<(ostream &out, vector<T> &v) {
    for (ll i = 0; i < v.size() - 1; i++) {
        out << v[i] << ' ';
    }
    out << v[v.size() - 1];
    return out;
}

void backtrack(ll row, unordered_set<ll> &cols, unordered_set<ll> &d1,
               unordered_set<ll> &d2, vector<vector<char>> &board,
               vector<vector<char>> &result) {
    // for (auto x : board) {
    //     cout << x << endl;
    // }
    if (row == board.size()) {
        result = board;
        return;
    }
    for (ll i = 0; i < board[0].size(); i++) {
        if (cols.contains(i) == false and d1.contains(row - i) == false and
            d2.contains(row + i) == false) {

            board[row][i] = 'Q';
            cols.insert(i);
            d1.insert(row - i);
            d2.insert(row + i);
            backtrack(row + 1, cols, d1, d2, board, result);
            board[row][i] = '*';
            cols.erase(i);
            d1.erase(row - i);
            d2.erase(row + i);
        }
    }
}
void solution() {
    ll n;
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n, '*')), result;
    unordered_set<ll> a, b, c;

    backtrack(0, a, b, c, board, result);
    for (auto x : result) {
        cout << x << endl;
    }
}
int main() {
    int T = 1;
    // cin >> T;
    while (T--) {
        solution();
    }
    return 0;
}
