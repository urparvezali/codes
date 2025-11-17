#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<bool> vbl;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vstr;
typedef vector<pll> vpll;

#define endl '\n'
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
constexpr ll mod = 1000000007;

inline void Parvez() { ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); }
template<class T>inline istream& operator>>(istream& in, vector<T>& v) { for (T& x : v) { in >> x; }return in; }template<class T>inline ostream& operator<<(ostream& out, vector<T>& v) { if (v.empty()) return out;for (ll i = 0;i < v.size() - 1;i++) { out << v[i] << ' '; }out << v[v.size() - 1];return out; }
inline void inp() {}template<class H, class... T>inline void inp(H&& h, T &&...t) { cin >> h;inp(forward<T>(t)...); }inline void print() { cout << endl; }template<class H, class... T>inline void print(H&& h, T &&...t) { cout << h;if (sizeof...(t) != 0)cout << ' ';print(forward<T>(t)...); }

double cros(double ox, double oy, double ax, double ay, double bx, double by) {
    return (ax - ox) * (by - oy) - (ay - oy) * (bx - ox);
}

bool strictlyInside(double px, double py, double ax, double ay, double bx, double by, double cx, double cy) {
    double cp1 = cros(ax, ay, bx, by, px, py);
    double cp2 = cros(bx, by, cx, cy, px, py);
    double cp3 = cros(cx, cy, ax, ay, px, py);

    double eps = 1e-9;
    return (cp1 > eps && cp2 > eps && cp3 > eps) || (cp1 < -eps && cp2 < -eps && cp3 < -eps);
}

ll counter(double px, double py, double cx, double cy,
    vector<double>& lmx, vector<double>& lmy) {
    ll cnt = 0;
    ll m = lmx.size();
    for (ll j = 0; j < m; j++) {
        for (ll k = j + 1; k < m; k++) {
            if (strictlyInside(px, py, cx, cy, lmx[j], lmy[j], lmx[k], lmy[k])) {
                cnt++;
            }
        }
    }
    return cnt;
}

void solution(ll& T) {
    ll n, m;
    inp(n, m);

    vector<double> cx(n), cy(n);
    for (ll i = 0; i < n; i++) {
        cin >> cx[i] >> cy[i];
    }

    vector<double> lmx(m), lmy(m);
    for (ll i = 0; i < m; i++) {
        cin >> lmx[i] >> lmy[i];
    }

    ll ans = 0;

    for (ll i = 0; i < n; i++) {
        ll b = 0;

        vector<pair<double, double>> cands;

        cands.push_back({ cx[i], cy[i] });

        for (ll j = 0; j < m; j++) {
            cands.push_back({ lmx[j], lmy[j] });
        }

        for (ll j = 0; j < m; j++) {
            for (ll w = 1; w <= 9; w++) {
                double t = w / 10.0;
                double px = cx[i] * (1 - t) + lmx[j] * t;
                double py = cy[i] * (1 - t) + lmy[j] * t;
                cands.push_back({ px, py });
            }
        }

        for (ll j = 0; j < m; j++) {
            for (ll k = j + 1; k < m; k++) {
                for (ll w1 = 1; w1 <= 3; w1++) {
                    for (ll w2 = 1; w2 <= 3; w2++) {
                        double s = w1 + w2 + 1.0;
                        double px = (cx[i] + w1 * lmx[j] + w2 * lmx[k]) / s;
                        double py = (cy[i] + w1 * lmy[j] + w2 * lmy[k]) / s;
                        cands.push_back({ px, py });
                    }
                }
            }
        }

        for (auto& p : cands) {
            b = max(b, counter(p.first, p.second, cx[i], cy[i], lmx, lmy));
        }

        ans = max(ans, b);
    }

    print(ans);
}

signed main() {
    Parvez();
    ll TT = 1;
    cin >> TT;
    for (ll T = 1;T <= TT;T++)
        solution(T);
    return 0;
}
