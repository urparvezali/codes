#include <bits/stdc++.h>

using namespace std;

int main() {
    double a, b, c;
    cin >> a >> b >> c;

    double dtr = b * b - 4 * a * c;
    if(a==b&&b==c&&c==0){
		cout<<-1;
		return 0;
	}
	if(a==0){
		if(b==0){
			cout<<0<<endl;
			return 0;
		}
		double ans=-1.0*c/b;
		printf("1\n%.20lf",ans);
		return 0;
	}

    if (dtr > 0) {
        cout << 2 << endl;
        double y = 1.0*(-b + sqrt(dtr)) / (2 * a);
        double x = 1.0*(-b - sqrt(dtr)) / (2 * a);
		cout << fixed << setprecision(10) << min(x,y) << endl;
		cout << fixed << setprecision(10) << max(x,y) << endl;
    } else if (dtr == 0) {
        cout << 1 << endl;
		cout << fixed << setprecision(10) << 1.0*(-b) / (2 * a) << endl;
    } else if(dtr<0) {
        cout << 0 << endl;
    } else cout<<-1<<endl;

    return 0;
}
