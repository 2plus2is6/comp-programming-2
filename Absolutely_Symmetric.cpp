#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    vector<vector<long long>> arr(n, vector<long long>(n));

    //building the matrix

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }


    // check if atl 1 decomposition exists
    bool oneMatrix = true;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((arr[i][j] - arr[j][i]) % 2 != 0) {
                cout << -1;
                return 0;
            }

            if (abs(arr[i][j]) != abs(arr[j][i])) {
                oneMatrix = false;
            }
        }
    }

    if (oneMatrix) {
        cout << 1 << '\n';

        for (const auto &row : arr) {
            for (int j = 0; j < n; j++) {
                if (j > 0) {
                    cout << ' ';
                }
                cout << row[j];
            }
            cout << '\n';
        }

        return 0;
    }

    //symmetric and asymmetric 
    vector<vector<long long>> first(n, vector<long long>(n));
    vector<vector<long long>> second(n, vector<long long>(n));

    for (int i = 0; i < n; i++) {
        first[i][i] = arr[i][i];

        for (int j = i + 1; j < n; j++) {
            long long sum = (arr[i][j] + arr[j][i]) / 2;
            long long diff = (arr[i][j] - arr[j][i]) / 2;

            first[i][j] = first[j][i] = sum;
            second[i][j] = diff;
            second[j][i] = -diff;
        }
    }

    cout << 2 << '\n';

    for (auto row : first) {
        for (int j = 0; j < n; j++) {
            if (j > 0) {
                cout << ' ';
            }
            cout << row[j];
        }
        cout << '\n';
    }

    for (auto row : second) {
        for (int j = 0; j < n; j++) {
            if (j > 0) {
                cout << ' ';
            }
            cout << row[j];
        }
        cout << '\n';
    }

    return 0;
}
