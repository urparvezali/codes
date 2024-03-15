#include <iostream>
using namespace std;

struct Point {
    int x, y;
};

bool areParallel(Point a, Point b, Point c, Point d) {
    return (b.y - a.y) * (d.x - c.x) == (d.y - c.y) * (b.x - a.x);
}

int main() {
    Point a, b, c, d;

    cin >> a.x >> a.y;

    cin >> b.x >> b.y;

    cin >> c.x >> c.y;

    cin >> d.x >> d.y;

    if (areParallel(a, b, c, d)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}