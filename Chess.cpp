#include <bits/stdc++.h>
using namespace std;

int main() {
    int tests;
    cin >> tests;

    while (tests--) {

        char r1, r2;
        int y1, y2;
        cin >> r1 >> y1 >> r2 >> y2;

        int x1 = r1 - 'A';
        int x2 = r2 - 'A';

        if ((x1 + y1) % 2 != (x2 + y2) % 2) { //same color

            cout << "Impossible\n";

        } else if (x1 == x2 && y1 == y2) { //same pos

            cout << "0 " << r1 << ' ' << y1 << '\n';

        } else if (abs(x1 - x2) == abs(y1 - y2)) { //same diag

            cout << "1 " << r1 << ' ' << y1 << ' ' << r2 << ' ' << y2 << '\n';

        } else {

            bool found = false;

            for (int x = 0; x < 8 && !found; x++) {
                for (int y = 1; y <= 8; y++) {
                    if (abs(x - x1) == abs(y - y1) && abs(x - x2) == abs(y - y2)) {
                        cout << "2 " << r1 << ' ' << y1 << ' ' << char('A' + x) << ' ' << y << ' ' << r2 << ' ' << y2 << '\n';
                        found = true;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
