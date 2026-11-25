// #include <bits/stdc++.h>
#include <iostream> 
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    int multiplier = 1;
    int streak = 0;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x == 0) {
            streak = 0;
            multiplier = max(multiplier / 2, 1);
        } else {
            streak++;

            if (multiplier < 8 && streak == 2 * multiplier) {
                multiplier *= 2;
                streak = 0;
            }
        }

        ans += x * multiplier;
    }

    cout << ans;
    return 0;
}
