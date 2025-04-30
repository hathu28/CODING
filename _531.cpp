#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int dim[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap(int a) {
    return (a % 400 == 0 || (a % 4 == 0 && a % 100 != 0));
}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, d, m, y;
    cin >> x >> d >> m >> y;

    int epoch = d;
    for (int i = 1; i < m; ++i) epoch += dim[i - 1];
    if (leap(y) && m > 2) ++epoch;

    --y;
    epoch += y * 365 + y / 4 - y / 100 + y / 400;
    epoch += x;

    int Y = (epoch / 146097) * 400;
    epoch %= 146097;

    int yy = 1, D, M;
    while (epoch > 0) {

        int dd = (leap(yy) ? 366 : 365);
        if (epoch >= dd) {

            epoch -= dd;
            ++yy;
            continue;
        }

        dim[1] = (leap(yy) ? 29 : 28);
        D = epoch, M = 1;

        for (int i = 0; i < 12; ++i) {

            if (D <= dim[i]) {
                M = i + 1;
                break;
            }
            D -= dim[i];
        }
        break;
    }

    cout << D << ' ' << M << ' ' << (Y + yy);
}