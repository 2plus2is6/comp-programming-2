#include <iostream>
#include <string>
using namespace std;

int main() {

    string input, answer;
    cin >> input;
    for (char c : input) {
        if (c == '<') {
            if (!answer.empty()) answer.pop_back();
        } else answer.push_back(c);
    }
    cout << answer << endl;
    return 0;
}
