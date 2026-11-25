#include <bits/stdc++.h>
using namespace std;

int main() {

    unordered_map<string, int> count;
    queue<unordered_map<string, int>> days;
    set<pair<int, string>> ranked;

    string input;

    while (cin >> input) {
        if (input == "<text>") {
            unordered_map<string, int> today;

            while (cin >> input && input != "</text>") {
                if (input.size() >= 4) {
                    today[input]++;
                    count[input]++;
                }
            }

            days.push(today);

            if (days.size() > 7) {
                auto old = days.front();
                days.pop();

                for (auto [word, amount] : old) {
                    count[word] -= amount;
                }
            }

        }
        else if (input == "<top") {
            int n;
            cin >> n >> input;

            cout << "<top " << n << ">\n";

            

            cout << "</top>\n";
        }
    }

    return 0;
}
