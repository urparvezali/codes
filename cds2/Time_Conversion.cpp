#include <iostream>
using namespace std;

int main() {
    int8_t hh,mm,ss;
    char s[2] = {0, };
    scanf("%2d:%2d:%2d%s", &hh, &mm, &ss, s);
    if (s[0] == 'P'){
        if (hh != 12)
            hh += 12;
    }
    else if (hh == 12)
        hh = 0;
    printf("%02d:%02d:%02d", hh, mm, ss);
    return 0;
}